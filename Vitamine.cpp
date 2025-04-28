#include "Vitamine.h"

Vitamine::Vitamine(int id, string nom, float p, int s, string date)
    : Medicament(id, nom, p, s, date) {}

Vitamine::Vitamine() : Medicament() {}

ostream& operator<<(ostream& os, const Vitamine& vit) {
    os << static_cast<const Medicament&>(vit) << " ";
    return os;
}

istream& operator>>(istream& is, Vitamine& vit) {
    is >> static_cast<Medicament&>(vit);
    return is;
}

istream& operator>>(istream& is, Vitamine* vit) {
    is >> static_cast<Medicament&>(*vit);
    if (vit->getIdMedicament() <= 0 || vit->getPrixMedicament() <= 0 || vit->getNomMedicament().empty()) {
        cout << "" << endl;
        return is;
    }

    cout << "\nLecture Vitamine :" << endl;
    cout << "ID: " << vit->getIdMedicament() << endl;
    cout << "Nom: " << vit->getNomMedicament() << endl;
    cout << "Prix: " << vit->getPrixMedicament() << endl;
    cout << "Stock: " << vit->getStockMedicament() << endl;
    cout << "Date Expiration: " << vit->getDateExpiration() << endl;

    return is;
}

ostream& operator<<(ostream& os, const Vitamine* v) {
    os << static_cast<const Medicament&>(*v) << " ";
    os << v->typesSupplementaires.size() << " ";
    return os;
}

void Vitamine::creer(fstream& f) {
    f.open("Vitamine.txt", ios::in | ios::out | ios::trunc);
    if (!f.is_open()) { exit(-1); }
}

void Vitamine::enregistrer_fichier() {
    fstream f("Vitamine.txt", ios::out | ios::app);
    if (!f.is_open()) {
        cout << "\nErreur fichier Commande ";
        return;
    }
    f << this;
    f.close();
}

void Vitamine::lire_fichier(vector<Vitamine*>* vitamines) {
    fstream fi("Vitamine.txt", ios::in);
    if (!fi.is_open()) {
        cout << "\nErreur fichier Commande";
        return;
    }
    while (!fi.eof()) {
        Vitamine* vit = new Vitamine();
        fi >> vit;
        if (vitamines) {
            vitamines->push_back(vit);
        } else {
            delete vit;
        }
    }
    fi.close();
}

void Vitamine::enregistrerVitaminesDansFichierDepuisTableau(vector<Vitamine*>& vitamines) {
    fstream f("Vitamine.txt", ios::out | ios::trunc);
    if (!f) {
        cout << "Erreur lors de l'ouverture du fichier pour réécriture!" << endl;
        return;
    }
    for (unsigned int i = 0; i < vitamines.size(); ++i) {
        f << vitamines[i];
    }
    f.close();
    cout << "Fichier mis à jour avec succès!" << endl;
}

void Vitamine::chargerVitaminesDansTableauDepuisFichier(vector<Vitamine*>& vitamines) {
    fstream fi("Vitamine.txt", ios::in);
    if (!fi) {
        cout << "Erreur lors de l'ouverture du fichier!" << endl;
        return;
    }
    Vitamine* vit;
    while (fi >> vit) {
        vitamines.push_back(vit);
    }
    fi.close();
}

void Vitamine::modifierVitamine(int idMedicamentRecherche, const string& newNom, int newPrix, int newQteStock, Pharmacien* pharToAdd, const string& pharToRemove) {
    Vitamine vit;
    vector<Vitamine*> vitamines;
    vit.lire_fichier(&vitamines);

    for (unsigned int i = 0; i < vitamines.size(); ++i) {
        if (vitamines[i]->getIdMedicament() == idMedicamentRecherche) {
            vitamines[i]->setNomMedicament(newNom);
            vitamines[i]->setPrixdMedicament(newPrix);
            vitamines[i]->setStockdMedicament(newQteStock);

            cout << "Vitamine modifie avec succes!" << endl;

            Vitamine::enregistrerVitaminesDansFichierDepuisTableau(vitamines);
            return;
        }
    }
    cout << "Vitamine non trouve." << endl;
}

void Vitamine::supprimerVitamine(int idMedicamentASupprimer) {
    Vitamine vit;
    vector<Vitamine*> vitamines;
    vit.lire_fichier(&vitamines);

    for (unsigned int i = 0; i < vitamines.size(); ++i) {
        if (vitamines[i]->getIdMedicament() == idMedicamentASupprimer) {
            delete vitamines[i];
            vitamines.erase(vitamines.begin() + i);
            cout << "Vitamine supprime avec succes!" << endl;

            Vitamine::enregistrerVitaminesDansFichierDepuisTableau(vitamines);
            return;
        }
    }
    cout << "Vitamine non trouve." << endl;
}

void Vitamine::afficherMedInfo() {
    Medicament::afficherMedInfo();
    for (unsigned int i = 0; i < typesSupplementaires.size(); i++) {
        cout << *typesSupplementaires[i];
    }
}

void Vitamine::modifierMedInfo(string nom, float prix, int stock, string dateExp) {
    Medicament::modifierMedInfo(nom, prix, stock, dateExp);
}

void Vitamine::ajoutertypeSupplementaire(string* typeSupp) {
    typesSupplementaires.push_back(typeSupp);
}

void Vitamine::supprimertypeSupp(string* typeSupp) {
    for (int i = 0; i < typesSupplementaires.size(); i++) {
        if (*typesSupplementaires[i] == *typeSupp) {
            delete typesSupplementaires[i];
            typesSupplementaires.erase(typesSupplementaires.begin() + i);
            break;
        }
    }
}

Vitamine::~Vitamine() {
    for (int i = 0; i < typesSupplementaires.size(); ++i) {
        delete typesSupplementaires[i];
    }
}
