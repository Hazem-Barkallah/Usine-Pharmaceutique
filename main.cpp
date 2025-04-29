#include"headers.h"
#include <vector>
using namespace std;


void menuMedicament() {
    int choix;
    Medicament medicament;

    do {
        cout << "\n===== MENU MEDICAMENT =====" << endl;
        cout << "1. Creer/Reinitialiser le fichier de medicaments" << endl;
        cout << "2. Saisir et ajouter un nouveau medicament" << endl;
        cout << "3. Lire touts les medicament enregistrees" << endl;
        cout << "4. Modifier un medicament" << endl;
        cout << "5. Supprimer un medicament" << endl;
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
                 int idMedicamentRecherche, newPrix, newQteStock;
                string newNom, pharToRemove;
                cout << "Entrer l'ID du medicament à modifier: ";
                cin >> idMedicamentRecherche;
                cout << "Entrer le nouveau nom du medicament: ";
                cin >> newNom;
                cout << "Entrer le nouveau prix du medicament: ";
                cin >> newPrix;
                cout << "Entrer la nouvelle quantité en stock: ";
                cin >> newQteStock;
                char ajouterPharmacien;
                cout << "Souhaitez-vous ajouter un pharmacien à ce medicament ? (o/n) ";
                cin >> ajouterPharmacien;
                Pharmacien* pharToAdd = nullptr;
                if (ajouterPharmacien == 'o' || ajouterPharmacien == 'O') {
                    pharToAdd = new Pharmacien();
                    cin >> *pharToAdd;
                }
                char supprimerPharmacien;
                cout << "Souhaitez-vous supprimer un pharmacien de ce medicament ? (o/n) ";
                cin >> supprimerPharmacien;
                if (supprimerPharmacien == 'o' || supprimerPharmacien == 'O') {
                    cout << "Entrer le nom du pharmacien à supprimer: ";
                    cin >> pharToRemove;
                }

            Medicament::modifierMedicament(idMedicamentRecherche, newNom, newPrix, newQteStock, pharToAdd, pharToRemove);
            break;
        }
                    case 5:{
                        int idMedicamentRecherche;
                        cout << "Entrer l'ID du medicament a supprimer: ";
                        cin >> idMedicamentRecherche;
                        Medicament::supprimerMedicament(idMedicamentRecherche);
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
void menuVitamine() {
    int choix;
    Vitamine vit;

    do {
        cout << "\n===== MENU VITAMINE =====" << endl;
        cout << "1. Creer/Reinitialiser le fichier de vitamines" << endl;
        cout << "2. Saisir et ajouter un nouveau vitamine" << endl;
        cout << "3. Lire touts les vitamines enregistrees" << endl;
        cout << "4. Modifier un vitamine" << endl;
        cout << "5. supprimer un vitamine" << endl;
        cout << "0. Retour au menu principal" << endl;
        cout << "Votre choix: ";
        cin >> choix;

        switch (choix) {
            case 1: {
                fstream fichier;
                vit.creer(fichier);
                cout << "Fichier 'Vitamine.txt' cree/reinitialise avec succes.\n";
                fichier.close();
                break;
            }
            case 2: {
                cout << "Saisie de la commande:\n";
                cin >> vit;
                vit.enregistrer_fichier();
                cout << "Commande ajoutee dans 'Vitamine.txt'.\n";
                break;
            }
            case 3: {
                cout << "Lecture des vitamines:\n";
                vit.lire_fichier();
                break;
            }
            case 4: {
                 int idMedicamentRecherche, newPrix, newQteStock;
                string newNom, pharToRemove;
                cout << "Entrer l'ID du vitamine à modifier: ";
                cin >> idMedicamentRecherche;
                cout << "Entrer le nouveau nom du vitamine: ";
                cin >> newNom;
                cout << "Entrer le nouveau prix du vitamine: ";
                cin >> newPrix;
                cout << "Entrer la nouvelle quantité en stock: ";
                cin >> newQteStock;
            Vitamine::modifierVitamine(idMedicamentRecherche, newNom, newPrix, newQteStock);
            break;
        }
        case 5: {
                int codeVitamineRecherche;
                cout << "Entrer le code du vitamine a supprimer: ";
                cin >> codeVitamineRecherche;
                Vitamine::supprimerVitamine(codeVitamineRecherche);
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
                char ajouterMed;
                cout << "Souhaitez-vous ajouter un médicament à cette commande ? (o/n) ";
                cin >> ajouterMed;
                Medicament* medToAdd = nullptr;
                if (ajouterMed == 'o' || ajouterMed == 'O') {
                }

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
                cout << "Entrer le code de la commande a supprimer: ";
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
        cout << "=== Menu Principal ===" << endl;
        cout << "1 - Surcharge" << endl;
        cout << "2 - Fichiers" << endl;
        cout << "3 - Exception" << endl;
        cout << "4 - STL" << endl;
        cout << "0 - Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
    int sousChoix;
    do {
        cout << "--- Surcharge d'operateurs ---" << endl;
        cout << "1 - operator <<" << endl;
        cout << "2 - operator >>" << endl;
        cout << "3 - operator +" << endl;
        cout << "0 - Retour au menu principal" << endl;
        cout << "Votre choix : ";
        cin >> sousChoix;

        switch (sousChoix) {
            case 1:{
                cout << "Vous avez choisi operator <<." << endl;
                Medicament m(1, "Sanofi", 0, 0,"10/10/2025");
                cout << m << endl;
                break;}
            case 2:{
                cout << "Vous avez choisi operator >>." << endl;
                Medicament m;
                    cout << "Entrez les informations du medicament :" << endl;
                    cin >> m;
                    cout << "Vous avez saisi :" << endl;
                    cout << m << endl;

                break;}
            case 3:{
                cout << "Vous avez choisi operator +." << endl;
                Commande m1;
                cin>>m1;
                Commande m2;
                cin>>m2;
                Commande m3 = m1 + m2;
                cout << "Stock total après addition : " << endl;
                cout << m3<< endl;

                break;}
            case 0:
                cout << "Retour au menu principal..." << endl;
                break;
            default:
                cout << "Sous-choix invalide, veuillez réessayer." << endl;
                break;
        }

        cout << endl;
    } while (sousChoix != 0);

    break;
}

case 2: {
    int sousChoixFichiers;
    do {
        cout << "--- Gestion des Fichiers ---" << endl;
        cout << "1 - Commandes" << endl;
        cout << "2 - Medicaments" << endl;
        cout << "3 - Vitamines" << endl;
        cout << "0 - Retour au menu principal" << endl;
        cout << "Votre choix : ";
        cin >> sousChoixFichiers;

        switch (sousChoixFichiers) {
            case 1: { menuCommande();
    break;
}

            case 2:{ menuMedicament();
    break;
}
case 3: { menuVitamine();
    break;
}
            case 0:
                cout << "Retour au menu principal..." << endl;
                break;
            default:
                cout << "Sous-choix invalide, veuillez réessayer." << endl;
                break;
        }
        cout << endl;
    } while (sousChoixFichiers != 0);

    break;
}
            case 3:{
                cout << "Vous avez choisi Exception." << endl;
                try {
        cout << "Création d'un médicament valide :" << endl;
        Medicament m1(1,"Doliprane", 2.5,14,"01/11/2020");
        cout<<m1;
        cout << "\nCréation d'un médicament avec prix négatif :" << endl;
        Medicament m2(2,"Aspirine", -3.0,14,"01/11/2020");
        cout<<m2;

    } catch (const invalid_argument& e) {
        cout << "Exception attrapée : " << e.what() << endl;
    }
                break;}
            case 4: {
    int choixSTL;
    do {
        cout << "--- Menu STL ---" << endl;
        cout << "1 - Affichage du List" << endl;
        cout << "2 - Affichage et algorithmes Map" << endl;
        cout << "0 - Retour" << endl;
        cout << "Votre choix : ";
        cin >> choixSTL;

        switch (choixSTL) {
            case 1:{
                cout << "Affichage List..." << endl;
                Client c1("Doe", "John", "C123456", "0601020304", "john.doe@email.com");
    c1.ajouterCommande(Commande("CMD001",10,"10/10/2025"));
    c1.ajouterCommande(Commande("CMD002",20,"10/10/2025"));
    c1.afficherClient();
                break;}
            case 2:{
                cout << "Ajout et Algorithmes Map..." << endl;
                MedicamentCombine med(1, "MédicamentCombine1", 10.5, 2, "2025-04-28", "Spectre1", true);
    med.ajouterPrincipeActif("Paracétamol", "Antalgique et antipyrétique");
    med.ajouterPrincipeActif("Ibuprofène", "Anti-inflammatoire non stéroïdien");
    med.ajouterPrincipeActif("Aspirine", "Anti-inflammatoire et anticoagulant");
    cout << "Affichage des principes actifs:" << endl;
    med.afficherPrincipesActifs();
    cout << "\nAffichage trié des principes actifs (par taille du nom):" << endl;
    med.afficherParTailleNom();
    cout << "\nRecherche par mot-clé (\"MultiVitamine\"):" << endl;
    med.rechercherPrincipeActifParMotCle("MultiVitamine");
                break;}
            case 3:
                cout << "Utilisation des algorithmes STL..." << endl;
                break;
            case 0:
                cout << "Retour au menu précédent..." << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
                break;
        }

        cout << endl;
    } while (choixSTL != 0);
    break;
}
            case 0:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
                break;
        }

        cout << endl;
    } while (choix != 0);
    return 0;
};

