#include <iostream>

using namespace std;

struct Cellule {
    char nom;
    Cellule *suiv;
    Cellule *précédent;
};

class ListeChainee {
    private:
        Cellule* tete; //tête
        Cellule* fourmi;

    public:
        ListeChainee() {
            tete = nullptr;
            fourmi = nullptr;
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
            if (tete == nullptr) {
                //cas ou la liste est vide.
                ajouterEnTete(nom);
            }
            else {
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
        }

    void allerAuDebut() {
        if (fourmi == nullptr) {
            fourmi = tete;
        }
         else {
             while (fourmi->précédent != nullptr) {
                 fourmi = fourmi->précédent;
             }
         }
        }

    void allerALaFin() {
        if (fourmi == nullptr) {
            fourmi = tete;
        }
            while (fourmi->suiv != nullptr) {
                fourmi = fourmi->suiv;
            }
    }

    void allerSuivant() {
            if (fourmi != nullptr && fourmi->suiv != nullptr) {
                //Cas ou la liste et vide et/ou la fourmi est au dernier élément.
                fourmi = fourmi->suiv;
            }
            else {cout << "Pas possible." << endl;}
    }

    void allerPrecedent() {
            if (fourmi != nullptr && fourmi->précédent != nullptr) {
                fourmi = fourmi->précédent;
            }
            else {cout << "Pas possible" << endl;}
        }

    void estvide() {
       if (tete == nullptr) {
           cout << "Vide." << endl;;
       }
       else {
           cout << "Non vide" << endl;
       }
    }

    void estPremier(Cellule* nom) {
            if (nom->précédent == nullptr) {
                cout << nom << " " << "est la premiere Cellule." << endl;
            }
    }

    void estDernier() {

    }

    void insererAvant() {

    }

    void remplacer() {

    }

    void supprimer() {

    }

    void supprimer_liste() {
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

    void position_fourmi() {
            cout << "La fourmi est dans la Cellule : " << fourmi->nom << endl;
        }
};

int main() {
    ListeChainee liste;
    liste.afficher();
    liste.ajouterEnTete('A');
    liste.afficher();
    liste.ajouterEnQueue('B');
    liste.afficher();
    liste.ajouterEnTete('C');
    liste.afficher();
    liste.ajouterEnQueue('D');
    liste.afficher();
    liste.allerAuDebut();
    liste.position_fourmi();
    liste.allerSuivant();
    liste.position_fourmi();
    liste.allerSuivant();
    liste.position_fourmi();
    liste.allerPrecedent();
    liste.position_fourmi();
    liste.allerALaFin();
    liste.position_fourmi();
    liste.afficher();
    return 0;
}