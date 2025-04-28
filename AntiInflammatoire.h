#ifndef ANTIINFLAMMATOIRE_H
#define ANTIINFLAMMATOIRE_H

#include <iostream>
#include <string>
#include "Medicament.h"
using namespace std;

class AntiInflammatoire : virtual public Medicament {
    bool estSteroidien;
public:
    AntiInflammatoire(int id, string nom, float p, int s, string date, bool steroidien);
    virtual ~AntiInflammatoire();

    void afficherMedInfo();
    void modifierMedInfo(string nom, float prix, int stock, string dateExp, bool steroidien);
};

#endif // ANTIINFLAMMATOIRE_H
