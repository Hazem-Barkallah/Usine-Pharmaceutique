#include "AntiInflammatoire.h"

AntiInflammatoire::AntiInflammatoire(int id, string nom, float p, int s, string date, bool steroidien)
    : Medicament(id, nom, p, s, date) {
    estSteroidien = steroidien;
}

AntiInflammatoire::~AntiInflammatoire() {}

void AntiInflammatoire::afficherMedInfo() {
    Medicament::afficherMedInfo();
    cout << estSteroidien << endl;
}

void AntiInflammatoire::modifierMedInfo(string nom, float prix, int stock, string dateExp, bool steroidien) {
    Medicament::modifierMedInfo(nom, prix, stock, dateExp);
    estSteroidien = steroidien;
}
