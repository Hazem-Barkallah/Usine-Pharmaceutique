#ifndef VITAMINE_H
#define VITAMINE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Medicament.h"
//#include "Pharmacien.h"
using namespace std;

class Vitamine : public Medicament {
    vector<string*> typesSupplementaires;
public:
    Vitamine(int id, string nom, float p, int s, string date);
    Vitamine();

    friend ostream& operator<<(ostream& os, const Vitamine& vit);
    friend istream& operator>>(istream& is, Vitamine& vit);
    friend istream& operator>>(istream& is, Vitamine* vit);
    friend ostream& operator<<(ostream& os, const Vitamine* v);

    void creer(fstream& f);
    void enregistrer_fichier();
    void lire_fichier(vector<Vitamine*>* vitamines = nullptr);

    static void enregistrerVitaminesDansFichierDepuisTableau(vector<Vitamine*>& vitamines);
    static void chargerVitaminesDansTableauDepuisFichier(vector<Vitamine*>& vitamines);

    static void modifierVitamine(int idMedicamentRecherche, const string& newNom, int newPrix, int newQteStock, Pharmacien* pharToAdd = nullptr, const string& pharToRemove = "");
    static void supprimerVitamine(int idMedicamentASupprimer);

    void afficherMedInfo();
    void modifierMedInfo(string nom, float prix, int stock, string dateExp);

    void ajoutertypeSupplementaire(string* typeSupp);
    void supprimertypeSupp(string* typeSupp);

    ~Vitamine();
};

#endif // VITAMINE_H
