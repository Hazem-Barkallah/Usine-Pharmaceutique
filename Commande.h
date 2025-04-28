#ifndef COMMANDE_H
#define COMMANDE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <typeinfo>
#include "Medicament.h"
#include "Antibiotique.h"
#include "AntiInflammatoire.h"
#include "Vitamine.h"

using namespace std;

class Commande {
    static int nbTotalCommandes;
    string codeCommande;
    int qteCommande;
    string dateCommande;
    vector<Medicament*> medicaments;

public:
    Commande(string code = "", int qteCmd = 0, string dateCmd = "");
    Commande(const Commande& c);
    ~Commande();

    string getCodeCommande() const;
    string getDateCommande() const;
    int getQteCommande() const;
    float calculerMontantTotal();
    bool verifierMedicamentDansCommande(const string& nom);
    int nombreDeMedicamentsDansCommande() const;

    Medicament*& operator[](int index);
    Commande operator+(const Commande& other) const;

    void ajouterMedicamentACommande(Medicament* med);
    void supprimerMedicamentDeCommande(const string& nomMedicament);
    void afficherCommande();

    void creer(fstream& f);
    void enregistrer_fichier();
    void lire_fichier(vector<Commande*>* commandes = nullptr);

    static void enregistrerCommandesDansFichierDepuisTableau(vector<Commande*>& commandes);
    static void chargerCommandesDansTableauDepuisFichier(vector<Commande*>& commandes);
    static void modifierCommande(const string& codeCommandeRecherche, const string& newCode, const string& newDate, int newQteCommande, Medicament* medToAdd = nullptr, const string& medToRemove = "");
    static void supprimerCommande(const string& codeCommandeASupprimer);

    friend ostream& operator<<(ostream& os, const Commande& cmd);
    friend ostream& operator<<(ostream& os, const Commande* cmd);
    friend istream& operator>>(istream& is, Commande& cmd);
    friend istream& operator>>(istream& is, Commande* cmd);
};

#endif // COMMANDE_H

