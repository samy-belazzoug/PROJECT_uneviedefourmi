#include <iostream>
#include <vector>

using namespace std;

struct Cellule {
    char nom;
    int taille;
    vector<Cellule*> presence = {};
    Cellule *suiv;
    Cellule *suiv2;
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

    void estPremier(char nom) {
            if (tete->nom == nom) {cout << nom << " " << "est la premiere Cellule." << endl;}
            else {
                cout << nom << " " << "n'est pas la premiere Cellule" << endl;
            }
    }

    void estDernier(char nom) {
            Cellule* current;
            while (current->suiv != nullptr) {
                current = current->suiv;
            }
            if (current->nom == nom) {
                cout << nom << " " << "est la derniere Cellule." << endl;
            }
            else {
                cout << nom << " " << "n'est pas la derniere Cellule" << endl;
            }
    }

    void ajouterSuivant(char cible, char nom) {
            Cellule* current = tete;
            Cellule* nouvelle = new Cellule;
            nouvelle->nom = nom;

            while (current->nom != cible) {
                current = current->suiv;
            }

            if (current->suiv == nullptr) {
                current->suiv = nouvelle;
            }

            else {
                Cellule* suivant = current->suiv;
                current->suiv = nouvelle;
                suivant->précédent = nouvelle;
            }
        }

    void ajouterSuivant2(char cible, char nom) {
            Cellule* current = tete;
            Cellule* nouvelle = new Cellule;
            nouvelle->nom = nom;

            while (current->nom != cible) {
                current = current->suiv;
            }

            if (current->suiv == nullptr) {
                current->suiv2 = nouvelle;
            }

            else {
                Cellule* suivant = current->suiv;
                current->suiv2 = nouvelle;
                suivant->précédent = nouvelle;
            }

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
            if (tete == nullptr) {
                cout << "La liste est vide : 0" << endl;
            }
            else {
                Cellule* current = tete;
                int count = 1 ;
                while (current->suiv != nullptr) {
                    current = current->suiv;
                    count ++;
                }
                cout << "La taille de la liste chainee est de : " << count << endl;
            }
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

ListeChainee fourmiliereZero;

int main() {


    return 0;
}