#include "header.h"
#include <vector>
using namespace std;

int Commande::nbTotalCommandes = 0;
int main() {
    // Création de quelques médicaments
    Medicament* med1 = new Antibiotique(1, "Amoxicilline", 12.5, 100, "2026-05-01", "Large spectre");
    Medicament* med2 = new AntiInflammatoire(2, "Ibuprofene", 8.2, 50, "2025-12-15", true);
    Medicament* med3 = new Vitamine(3, "Vitamine C", 5.0, 200, "2027-01-01");

    // Création d'une commande et ajout de médicaments
    Commande cmd1("CMD001", 3, "2025-04-23");
    cmd1.ajouterMedicamentACommande(med1);
    cmd1.ajouterMedicamentACommande(med2);

    // Affichage de la commande
    cout << "------ COMMANDE 1 ------" << endl;
    cmd1.afficherCommande();
    cout << "Montant total : " << cmd1.calculerMontantTotal() << " DT" << endl;

    // Création d'un client
    Client client1("Zana", "Lotfi", "12345678", "98765432", "zana@email.com");

    // Passage de la commande par le client
    client1.passerCommande(cmd1);

    // Affichage des infos client
    cout << "\n------ CLIENT ------" << endl;
    client1.afficherDetailsClient();

    // Création et ajout d'une autre commande
    Commande cmd2("CMD002", 2, "2025-04-24");
    cmd2.ajouterMedicamentACommande(med3);
    cmd2.ajouterMedicamentACommande(med2);

    cout << "\n------ COMMANDE 2 ------" << endl;
    cmd2.afficherCommande();
    cout << "Montant total : " << cmd2.calculerMontantTotal() << " DT" << endl;

    client1.passerCommande(cmd2);

    // Nettoyage mémoire (important)
    delete med1;
    delete med2;
    delete med3;

    return 0;

}
