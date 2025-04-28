#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include "Commande.h"
using namespace std;

class Client {
private:
    string nomClient;
    string prenomClient;
    string CINClient;
    string numTel;
    string emailClient;
    list<Commande> commandes;

public:
    Client(string nom, string prenom, string CIN, string tel, string email);

    void ajouterCommande(const Commande& cmd);
    void afficherCommandes();
    Commande* trouverCommandeParCode(const string& code);
    bool supprimerCommandeParCode(const string& code);
};

#endif // CLIENT_H

