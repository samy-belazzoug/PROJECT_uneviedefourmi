#include <iostream>

using namespace std;

struct Cellule {
    char nom;
    Cellule *suiv;
    Cellule *précédent;
    Cellule *fourmi;
};

class ListeChainee {
    private:
        Cellule* tete; //tête

    public:
        ListeChainee() {
            tete = nullptr;
        }

    void ajouterEnTete(char nom) {
            Cellule* new_tcell = new Cellule;
            new_tcell->nom = nom;
            new_tcell->précédent = nullptr;
            new_tcell->suiv = tete;

            //Mettre à jour le lien si ancienne tête à un nouveau précédent
            if (tete != nullptr) {
                tete->précédent = new_tcell;
            }

            tete = new_tcell;
        }

    void ajouterEnQueue(char nom) {
            Cellule* new_qcell = new Cellule;
            Cellule* current = tete;
            while (current->suiv != nullptr) {
                current = current->suiv;
            }
            current->suiv = new_qcell;

            new_qcell->nom = nom;
            new_qcell->précédent = current;
            new_qcell->suiv = nullptr;
        }

    void allerAuDebut() {

    }

    void allerALaFin() {

    }

    void allerSuivant() {

    }

    void allerPrecedent() {

    }

    void estvide() {
       if (tete == nullptr) {
           cout << "Vide." << endl;;
       }
       else {
           cout << "Non vide" << endl;
       }
    }

    void estPremier() {

    }

    void estDernier() {

    }

    void insererAvant() {

    }

    void remplacer() {

    }

    void supprimer() {

    }

    void supprimer_depuis() {
            Cellule* current = tete;
            Cellule* suivant = tete->suiv;

            while (suivant != nullptr) {
                delete current;
                current = suivant;
                suivant = suivant->suiv;
            }
            delete current; //Dernière cellule
        }


    void getTaille() {

    }

    void afficher() {
            Cellule* courant = tete;
            while (courant != nullptr) {
                cout << courant->nom << " -> ";
                courant = courant->suiv;
            }
            cout << "NULL" << endl;
        }

};

int main() {
    ListeChainee liste;
    liste.afficher();
    liste.estvide();
    liste.ajouterEnTete('A');
    liste.afficher();
    liste.ajouterEnQueue('B');
    liste.afficher();
    liste.ajouterEnTete('C');
    liste.afficher();
    liste.ajouterEnQueue('D');
    liste.afficher();
    liste.estvide();
    liste.supprimer_depuis();
    liste.estvide();
    return 0;
}