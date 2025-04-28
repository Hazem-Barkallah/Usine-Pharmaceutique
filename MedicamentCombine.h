#ifndef MEDICAMENTCOMBINE_H
#define MEDICAMENTCOMBINE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "Antibiotique.h"
#include "AntiInflammatoire.h"
using namespace std;

class MedicamentCombine : public Antibiotique, public AntiInflammatoire {
private:
    map<string, string> principesActifs;

public:
    MedicamentCombine(int id, const string& nom, float p, int s, const string& date, const string& spectre, bool steroidien);
    virtual ~MedicamentCombine();

    void ajouterPrincipeActif(const string& nom, const string& description);
    void supprimerPrincipeActif(const string& nom);
    void afficherPrincipesActifs() const;
    const map<string, string>& getPrincipesActifs() const;

    void afficherParTailleNom() const;
    void rechercherPrincipeActifParMotCle(const string& motCle) const;
};

#endif // MEDICAMENTCOMBINE_H

