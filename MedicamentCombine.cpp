#include "MedicamentCombine.h"

MedicamentCombine::MedicamentCombine(int id, const string& nom, float p, int s, const string& date, const string& spectre, bool steroidien)
    : Medicament(id, nom, p, s, date),
      Antibiotique(id, nom, p, s, date, spectre),
      AntiInflammatoire(id, nom, p, s, date, steroidien)
{}

MedicamentCombine::~MedicamentCombine() {}

void MedicamentCombine::ajouterPrincipeActif(const string& nom, const string& description) {
    principesActifs[nom] = description;
}

void MedicamentCombine::supprimerPrincipeActif(const string& nom) {
    principesActifs.erase(nom);
}

void MedicamentCombine::afficherPrincipesActifs() const {
    if (principesActifs.empty()) {
        cout << "Aucun principe actif." << endl;
        return;
    }
    for (const auto& p : principesActifs) {
        cout << "Principe Actif: " << p.first << " - Description: " << p.second << endl;
    }
}

const map<string, string>& MedicamentCombine::getPrincipesActifs() const {
    return principesActifs;
}

void MedicamentCombine::afficherParTailleNom() const {
    vector<pair<string, string>> temp(principesActifs.begin(), principesActifs.end());

    sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
        return a.first.size() < b.first.size();
    });

    for (const auto& p : temp) {
        cout << p.first << " - " << p.second << endl;
    }
}

void MedicamentCombine::rechercherPrincipeActifParMotCle(const string& motCle) const {
    bool trouve = false;
    for (const auto& p : principesActifs) {
        if (p.first.find(motCle) != string::npos) {
            cout << "Trouvé: " << p.first << " - " << p.second << endl;
            trouve = true;
        }
    }
    if (!trouve) {
        cout << "Aucun principe actif correspondant au mot-clé: " << motCle << endl;
    }
}
