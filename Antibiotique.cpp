#include "Antibiotique.h"

Antibiotique::Antibiotique(int id, string nom, float p, int s, string date, string spectre)
    : Medicament(id, nom, p, s, date) {
    spectreAction = spectre;
}

Antibiotique::~Antibiotique() {}

ostream& operator<<(ostream& os, const Antibiotique& antiB) {
    os << static_cast<const Medicament&>(antiB);
    os << "Spectre: " << antiB.spectreAction << endl;
    return os;
}

istream& operator>>(istream& is, Antibiotique& antiB) {
    is >> static_cast<Medicament&>(antiB);
    cout << "Entrez Spectre: ";
    is >> antiB.spectreAction;
    return is;
}

void Antibiotique::afficherMedInfo() {
    Medicament::afficherMedInfo();
    cout << spectreAction << endl;
}

void Antibiotique::modifierMedInfo(string nom, float prix, int stock, string dateExp, string spectre) {
    Medicament::modifierMedInfo(nom, prix, stock, dateExp);
    spectreAction = spectre;
}

string Antibiotique::getSpectre() {
    return spectreAction;
}

void Antibiotique::setSpectre(string spectre) {
    spectreAction = spectre;
}
