#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>

using namespace std;

// Structure pour représenter l'état de la fourmilière
struct EtatFourmiliere {
    int fourmis_vestibule;    // Nombre de fourmis dans le vestibule
    int fourmis_s1;           // Nombre de fourmis dans S1
    int fourmis_s2;           // Nombre de fourmis dans S2
    int fourmis_dortoir;      // Nombre de fourmis dans le dortoir
    int etapes;               // Nombre d'étapes pour atteindre cet état
    vector<string> mouvements; // Historique des mouvements
    
    // Constructeur
    EtatFourmiliere(int v = 0, int s1 = 0, int s2 = 0, int d = 0, int e = 0) 
        : fourmis_vestibule(v), fourmis_s1(s1), fourmis_s2(s2), fourmis_dortoir(d), etapes(e) {}
    
    // Opérateur de comparaison pour utiliser dans un set
    bool operator<(const EtatFourmiliere& autre) const {
        if (fourmis_vestibule != autre.fourmis_vestibule) return fourmis_vestibule < autre.fourmis_vestibule;
        if (fourmis_s1 != autre.fourmis_s1) return fourmis_s1 < autre.fourmis_s1;
        if (fourmis_s2 != autre.fourmis_s2) return fourmis_s2 < autre.fourmis_s2;
        return fourmis_dortoir < autre.fourmis_dortoir;
    }
    
    // Vérifier si c'est l'état final (toutes les fourmis au dortoir)
    bool estFinal(int total_fourmis) const {
        return fourmis_dortoir == total_fourmis;
    }
    
    // Afficher l'état
    void afficher() const {
        cout << "Vestibule: " << fourmis_vestibule 
             << ", S1: " << fourmis_s1 
             << ", S2: " << fourmis_s2 
             << ", Dortoir: " << fourmis_dortoir 
             << ", Etapes: " << etapes << endl;
    }
};

class SolveurFourmiliere {
private:
    int nb_fourmis;
    
public:
    SolveurFourmiliere(int f) : nb_fourmis(f) {}
    
    // Générer tous les états possibles à partir d'un état donné
    vector<EtatFourmiliere> genererEtatsSuivants(const EtatFourmiliere& etat_actuel) {
        vector<EtatFourmiliere> etats_suivants;
        
        // Pour chaque combinaison de mouvements possibles dans une étape
        // Mouvement 1: Vestibule -> S1
        // Mouvement 2: Vestibule -> S2  
        // Mouvement 3: S1 -> Dortoir
        // Mouvement 4: S2 -> Dortoir
        
        // Limites des mouvements possibles
        int max_v_to_s1 = min(etat_actuel.fourmis_vestibule, 1 - etat_actuel.fourmis_s1);
        int max_v_to_s2 = min(etat_actuel.fourmis_vestibule, 1 - etat_actuel.fourmis_s2);
        int max_s1_to_d = etat_actuel.fourmis_s1;
        int max_s2_to_d = etat_actuel.fourmis_s2;
        
        // Générer toutes les combinaisons valides
        for (int v_to_s1 = 0; v_to_s1 <= max_v_to_s1; v_to_s1++) {
            for (int v_to_s2 = 0; v_to_s2 <= max_v_to_s2; v_to_s2++) {
                for (int s1_to_d = 0; s1_to_d <= max_s1_to_d; s1_to_d++) {
                    for (int s2_to_d = 0; s2_to_d <= max_s2_to_d; s2_to_d++) {
                        
                        // Vérifier que le mouvement est cohérent
                        if (v_to_s1 + v_to_s2 <= etat_actuel.fourmis_vestibule) {
                            
                            // Créer le nouvel état
                            EtatFourmiliere nouvel_etat;
                            nouvel_etat.fourmis_vestibule = etat_actuel.fourmis_vestibule - v_to_s1 - v_to_s2;
                            nouvel_etat.fourmis_s1 = etat_actuel.fourmis_s1 + v_to_s1 - s1_to_d;
                            nouvel_etat.fourmis_s2 = etat_actuel.fourmis_s2 + v_to_s2 - s2_to_d;
                            nouvel_etat.fourmis_dortoir = etat_actuel.fourmis_dortoir + s1_to_d + s2_to_d;
                            nouvel_etat.etapes = etat_actuel.etapes + 1;
                            
                            // Copier l'historique des mouvements
                            nouvel_etat.mouvements = etat_actuel.mouvements;
                            
                            // Ajouter la description du mouvement actuel
                            string mouvement_desc = "Etape " + to_string(nouvel_etat.etapes) + ": ";
                            bool premier_mouvement = true;
                            
                            if (v_to_s1 > 0) {
                                if (!premier_mouvement) mouvement_desc += ", ";
                                mouvement_desc += "f" + to_string(etat_actuel.fourmis_vestibule - v_to_s1 + 1) + " Sv->S1";
                                premier_mouvement = false;
                            }
                            if (v_to_s2 > 0) {
                                if (!premier_mouvement) mouvement_desc += ", ";
                                mouvement_desc += "f" + to_string(etat_actuel.fourmis_vestibule - v_to_s2 + 1) + " Sv->S2";
                                premier_mouvement = false;
                            }
                            if (s1_to_d > 0) {
                                if (!premier_mouvement) mouvement_desc += ", ";
                                mouvement_desc += "f S1->Sd";
                                premier_mouvement = false;
                            }
                            if (s2_to_d > 0) {
                                if (!premier_mouvement) mouvement_desc += ", ";
                                mouvement_desc += "f S2->Sd";
                                premier_mouvement = false;
                            }
                            
                            if (premier_mouvement) {
                                mouvement_desc += "Attente";
                            }
                            
                            nouvel_etat.mouvements.push_back(mouvement_desc);
                            
                            // Vérifier que l'état est valide
                            if (nouvel_etat.fourmis_s1 >= 0 && nouvel_etat.fourmis_s1 <= 1 &&
                                nouvel_etat.fourmis_s2 >= 0 && nouvel_etat.fourmis_s2 <= 1 &&
                                nouvel_etat.fourmis_vestibule >= 0 &&
                                nouvel_etat.fourmis_dortoir >= 0) {
                                
                                etats_suivants.push_back(nouvel_etat);
                            }
                        }
                    }
                }
            }
        }
        
        return etats_suivants;
    }
    
    // Résoudre le problème avec BFS pour trouver la solution optimale
    void resoudre() {
        // État initial: toutes les fourmis dans le vestibule
        EtatFourmiliere etat_initial(nb_fourmis, 0, 0, 0, 0);
        
        queue<EtatFourmiliere> file;
        set<EtatFourmiliere> etats_visites;
        
        file.push(etat_initial);
        etats_visites.insert(etat_initial);
        
        cout << "=== RESOLUTION DU PROBLEME FOURMILIERE ===" << endl;
        cout << "Nombre de fourmis: " << nb_fourmis << endl;
        cout << "Structure: Sv -> {S1, S2} -> Sd" << endl;
        cout << "Contrainte: S1 et S2 ne peuvent contenir qu'1 fourmi maximum" << endl << endl;
        
        while (!file.empty()) {
            EtatFourmiliere etat_actuel = file.front();
            file.pop();
            
            // Vérifier si on a atteint l'état final
            if (etat_actuel.estFinal(nb_fourmis)) {
                cout << "=== SOLUTION TROUVEE ===" << endl;
                cout << "Nombre minimum d'etapes: " << etat_actuel.etapes << endl << endl;
                
                cout << "Detail des mouvements:" << endl;
                for (const string& mouvement : etat_actuel.mouvements) {
                    cout << mouvement << endl;
                }
                
                cout << "\nEtat final: ";
                etat_actuel.afficher();
                return;
            }
            
            // Générer tous les états suivants possibles
            vector<EtatFourmiliere> etats_suivants = genererEtatsSuivants(etat_actuel);
            
            for (const EtatFourmiliere& etat_suivant : etats_suivants) {
                if (etats_visites.find(etat_suivant) == etats_visites.end()) {
                    etats_visites.insert(etat_suivant);
                    file.push(etat_suivant);
                }
            }
        }
        
        cout << "Aucune solution trouvee!" << endl;
    }
};

int main() {
    // Résoudre le cas spécifique: f=2, structure Sv->{S1,S2}->Sd
    cout << "Algorithme de resolution pour fourmiliere" << endl;
    cout << "Cas specifique: 2 fourmis, structure en diamant" << endl << endl;
    
    SolveurFourmiliere solveur(2);
    solveur.resoudre();
    
    return 0;
}