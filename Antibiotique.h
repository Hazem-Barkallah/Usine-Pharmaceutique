#ifndef ANTIBIOTIQUE_H
#define ANTIBIOTIQUE_H

#include <iostream>
#include <string>
#include "Medicament.h"
using namespace std;

class Antibiotique : virtual public Medicament {
    string spectreAction;
public:
    Antibiotique(int id, string nom, float p, int s, string date, string spectre);
    virtual ~Antibiotique();

    friend ostream& operator<<(ostream& os, const Antibiotique& antiB);
    friend istream& operator>>(istream& is, Antibiotique& antiB);

    void afficherMedInfo();
    void modifierMedInfo(string nom, float prix, int stock, string dateExp, string spectre);

    string getSpectre();
    void setSpectre(string spectre);
};

#endif // ANTIBIOTIQUE_H
