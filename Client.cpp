#include "Client.h"

Client::Client(string nom, string prenom, string CIN, string tel, string email)
    : nomClient(nom), prenomClient(prenom), CINClient(CIN), numTel(tel), emailClient(email) {}

void Client::ajouterCommande(const Commande& cmd) {
    commandes.push_back(cmd);
}

void Client::afficherCommandes() {
    if (commandes.empty()) {
        cout << "Aucune commande en cours." << endl;
        return;
    }
    for (const auto& cmd : commandes) {
        cout << "Code Commande: " << cmd.getCodeCommande()
             << ", Date: " << cmd.getDateCommande()
             << ", Quantité: " << cmd.getQteCommande() << endl;
    }
}

Commande* Client::trouverCommandeParCode(const string& code) {
    auto it = find_if(commandes.begin(), commandes.end(),
        [&code](const Commande& cmd) {
            return cmd.getCodeCommande() == code;
        });
    if (it != commandes.end()) {
        return &(*it);
    } else {
        cout << "Commande avec le code " << code << " non trouvée." << endl;
        return nullptr;
    }
}

bool Client::supprimerCommandeParCode(const string& code) {
    auto it = find_if(commandes.begin(), commandes.end(),
        [&code](const Commande& cmd) {
            return cmd.getCodeCommande() == code;
        });
    if (it != commandes.end()) {
        commandes.erase(it);
        cout << "Commande " << code << " supprimée avec succès." << endl;
        return true;
    } else {
        cout << "Commande avec le code " << code << " non trouvée." << endl;
        return false;
    }
}
