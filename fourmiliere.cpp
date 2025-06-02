#include <cstdio>
#include <cstring>
#include <cstdlib>

// Version simplifiée sans STL pour éviter les problèmes de liaison

struct Etat {
    int vestibule, s1, s2, dortoir, etapes;
    
    Etat(int v = 0, int s1_val = 0, int s2_val = 0, int d = 0, int e = 0) 
        : vestibule(v), s1(s1_val), s2(s2_val), dortoir(d), etapes(e) {}
    
    bool estFinal(int total) const {
        return dortoir == total;
    }
    
    void afficher() const {
        printf("Vestibule: %d, S1: %d, S2: %d, Dortoir: %d, Etapes: %d\n", 
               vestibule, s1, s2, dortoir, etapes);
    }
    
    bool equals(const Etat& autre) const {
        return vestibule == autre.vestibule && s1 == autre.s1 && 
               s2 == autre.s2 && dortoir == autre.dortoir;
    }
};

class FileEtats {
private:
    Etat* donnees;
    int debut, fin, taille, capacite;
    
public:
    FileEtats(int cap = 1000) : debut(0), fin(0), taille(0), capacite(cap) {
        donnees = new Etat[capacite];
    }
    
    ~FileEtats() {
        delete[] donnees;
    }
    
    void ajouter(const Etat& etat) {
        if (taille < capacite) {
            donnees[fin] = etat;
            fin = (fin + 1) % capacite;
            taille++;
        }
    }
    
    Etat retirer() {
        if (taille > 0) {
            Etat resultat = donnees[debut];
            debut = (debut + 1) % capacite;
            taille--;
            return resultat;
        }
        return Etat();
    }
    
    bool estVide() const {
        return taille == 0;
    }
};

class EnsembleEtats {
private:
    Etat* etats;
    int taille, capacite;
    
public:
    EnsembleEtats(int cap = 1000) : taille(0), capacite(cap) {
        etats = new Etat[capacite];
    }
    
    ~EnsembleEtats() {
        delete[] etats;
    }
    
    bool contient(const Etat& etat) const {
        for (int i = 0; i < taille; i++) {
            if (etats[i].equals(etat)) {
                return true;
            }
        }
        return false;
    }
    
    void ajouter(const Etat& etat) {
        if (taille < capacite && !contient(etat)) {
            etats[taille++] = etat;
        }
    }
};

int min(int a, int b) {
    return a < b ? a : b;
}

void resoudreFourmiliere(int nb_fourmis) {
    printf("=== RESOLUTION FOURMILIERE ===\n");
    printf("Fourmis: %d\n", nb_fourmis);
    printf("Structure: Sv -> {S1, S2} -> Sd\n\n");
    
    FileEtats file;
    EnsembleEtats visites;
    
    Etat initial(nb_fourmis, 0, 0, 0, 0);
    file.ajouter(initial);
    visites.ajouter(initial);
    
    while (!file.estVide()) {
        Etat actuel = file.retirer();
        
        if (actuel.estFinal(nb_fourmis)) {
            printf("=== SOLUTION TROUVEE ===\n");
            printf("Nombre minimum d'etapes: %d\n", actuel.etapes);
            actuel.afficher();
            return;
        }
        
        // Génération des états suivants
        int max_v_to_s1 = min(actuel.vestibule, 1 - actuel.s1);
        int max_v_to_s2 = min(actuel.vestibule, 1 - actuel.s2);
        
        for (int v_s1 = 0; v_s1 <= max_v_to_s1; v_s1++) {
            for (int v_s2 = 0; v_s2 <= max_v_to_s2; v_s2++) {
                for (int s1_d = 0; s1_d <= actuel.s1; s1_d++) {
                    for (int s2_d = 0; s2_d <= actuel.s2; s2_d++) {
                        
                        if (v_s1 + v_s2 <= actuel.vestibule) {
                            Etat nouveau(
                                actuel.vestibule - v_s1 - v_s2,
                                actuel.s1 + v_s1 - s1_d,
                                actuel.s2 + v_s2 - s2_d,
                                actuel.dortoir + s1_d + s2_d,
                                actuel.etapes + 1
                            );
                            
                            if (nouveau.s1 >= 0 && nouveau.s1 <= 1 &&
                                nouveau.s2 >= 0 && nouveau.s2 <= 1 &&
                                nouveau.vestibule >= 0 && nouveau.dortoir >= 0 &&
                                !visites.contient(nouveau)) {
                                
                                file.ajouter(nouveau);
                                visites.ajouter(nouveau);
                                
                                // Affichage du mouvement
                                if (v_s1 + v_s2 + s1_d + s2_d > 0) {
                                    printf("Etape %d: ", nouveau.etapes);
                                    if (v_s1 > 0) printf("f Sv->S1 ");
                                    if (v_s2 > 0) printf("f Sv->S2 ");
                                    if (s1_d > 0) printf("f S1->Sd ");
                                    if (s2_d > 0) printf("f S2->Sd ");
                                    printf("-> ");
                                    nouveau.afficher();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("Aucune solution trouvee!\n");
}

int main() {
    printf("Algorithme Fourmiliere - Version Simplifiee\n");
    printf("==========================================\n\n");
    
    resoudreFourmiliere(2);
    
    return 0;
}