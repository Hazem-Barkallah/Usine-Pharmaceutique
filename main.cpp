#include "headers.h"
#include <vector>
using namespace std;

int Commande::nbTotalCommandes = 0;
void menuMedicament() {
    int choix;
    Medicament medicament;

    do {
        cout << "\n===== MENU COMMANDE =====" << endl;
        cout << "1. Creer/Reinitialiser le fichier de medicaments" << endl;
        cout << "2. Saisir et ajouter un nouveau medicament" << endl;
        cout << "3. Lire touts les medicament enregistrees" << endl;
        cout << "4. Modifier un medicament" << endl;
        cout << "0. Retour au menu principal" << endl;
        cout << "Votre choix: ";
        cin >> choix;

        switch (choix) {
            case 1: {
                fstream fichier;
                medicament.creer(fichier);
                cout << "Fichier 'Medicament.txt' cree/reinitialise avec succes.\n";
                fichier.close();
                break;
            }
            case 2: {
                cout << "Saisie de la commande:\n";
                cin >> medicament;
                medicament.enregistrer_fichier();
                cout << "Commande ajoutee dans 'Medicament.txt'.\n";
                break;
            }
            case 3: {
                cout << "Lecture des Medicaments:\n";
                medicament.lire_fichier();
                break;
            }
            case 4: {
                /*Commande::chargerCommandesDansTableauDepuisFichier;
                string codeCommandeRecherche, newCode, newDate, medToRemove;
                int newQteCommande;
                cout << "Entrer le code de la commande à modifier: ";
                cin >> codeCommandeRecherche;
                cout << "Entrer le nouveau code commande: ";
                cin >> newCode;
                cout << "Entrer la nouvelle date commande: ";
                cin >> newDate;
                cout << "Entrer la nouvelle quantité: ";
                cin >> newQteCommande;

                // Option pour ajouter un médicament
                char ajouterMed;
                cout << "Souhaitez-vous ajouter un médicament à cette commande ? (o/n) ";
                cin >> ajouterMed;
                Medicament* medToAdd = nullptr;
                if (ajouterMed == 'o' || ajouterMed == 'O') {
                    // Demander à l'utilisateur de saisir les informations du médicament
                    // Exemple simple d'ajout de médicament
                    // medToAdd = new Medicament("Nom", 10, 50.0, "01/01/2024");
                }

                // Option pour supprimer un médicament
                char supprimerMed;
                cout << "Souhaitez-vous supprimer un médicament de cette commande ? (o/n) ";
                cin >> supprimerMed;
                if (supprimerMed == 'o' || supprimerMed == 'O') {
                    cout << "Entrer le nom du médicament à supprimer: ";
                    cin >> medToRemove;
                }

                Commande::modifierCommande(codeCommandeRecherche, newCode, newDate, newQteCommande, medToAdd, medToRemove);
                Commande::enregistrerCommandesDansFichierDepuisTableau();*/
                break;
            }
            case 0:
                cout << "Retour au menu principal...\n";
                break;
            default:
                cout << "Choix invalide. Veuillez ressayer.\n";
        }
    } while (choix != 0);
}

void menuCommande() {
    int choix;
    Commande commande;

    do {
        cout << "\n===== MENU COMMANDE =====" << endl;
        cout << "1. Creer/Reinitialiser le fichier de commandes" << endl;
        cout << "2. Saisir et ajouter une nouvelle commande" << endl;
        cout << "3. Lire toutes les commandes enregistrees" << endl;
        cout << "4. Modifier une commande" << endl;
        cout << "5. Supprimer une commande" << endl;
        cout << "0. Retour au menu principal" << endl;
        cout << "Votre choix: ";
        cin >> choix;

        switch (choix) {
            case 1: {
                fstream fichier;
                commande.creer(fichier);
                cout << "Fichier 'Commande.txt' cree/reinitialise avec succes.\n";
                fichier.close();
                break;
            }
            case 2: {
                cout << "Saisie de la commande:\n";
                cin >> commande;
                commande.enregistrer_fichier();
                cout << "Commande ajoutee dans 'Commande.txt'.\n";
                break;
            }
            case 3: {
                cout << "Lecture des commandes:\n";
                commande.lire_fichier();
                break;
            }
            case 4: {
                string codeCommandeRecherche, newCode, newDate, medToRemove;
                int newQteCommande;
                cout << "Entrer le code de la commande à modifier: ";
                cin >> codeCommandeRecherche;
                cout << "Entrer le nouveau code commande: ";
                cin >> newCode;
                cout << "Entrer la nouvelle date commande: ";
                cin >> newDate;
                cout << "Entrer la nouvelle quantité: ";
                cin >> newQteCommande;

                // Option pour ajouter un médicament
                char ajouterMed;
                cout << "Souhaitez-vous ajouter un médicament à cette commande ? (o/n) ";
                cin >> ajouterMed;
                Medicament* medToAdd = nullptr;
                if (ajouterMed == 'o' || ajouterMed == 'O') {
                    // Demander à l'utilisateur de saisir les informations du médicament
                    // Exemple simple d'ajout de médicament
                    // medToAdd = new Medicament("Nom", 10, 50.0, "01/01/2024");
                }

                // Option pour supprimer un médicament
                char supprimerMed;
                cout << "Souhaitez-vous supprimer un médicament de cette commande ? (o/n) ";
                cin >> supprimerMed;
                if (supprimerMed == 'o' || supprimerMed == 'O') {
                    cout << "Entrer le nom du médicament à supprimer: ";
                    cin >> medToRemove;
                }

                Commande::modifierCommande(codeCommandeRecherche, newCode, newDate, newQteCommande, medToAdd, medToRemove);
                break;
            }
            case 5:{
                string codeCommandeRecherche;
                cout << "Entrer le code de la commande à modifier: ";
                cin >> codeCommandeRecherche;
                Commande::supprimerCommande(codeCommandeRecherche);
                break;
            }
            case 0:
                cout << "Retour au menu principal...\n";
                break;
            default:
                cout << "Choix invalide. Veuillez ressayer.\n";
        }
    } while (choix != 0);
}
int main() {
    int choix;

    do {
        cout << "\n========== MENU PRINCIPAL ==========" << endl;
        cout << "1. Gerer les commandes" << endl;
        cout << "2. Gerer les medicaments" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix: ";
        cin >> choix;

        switch (choix) {
            case 1:
                menuCommande();
                break;
            case 2:
                menuMedicament();
                break;
            case 0:
                cout << "Fermeture du programme...\n";
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while (choix != 0);
    return 0;
}


