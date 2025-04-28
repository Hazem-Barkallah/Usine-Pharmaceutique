#include "Medicament.h"
#include <iostream>



Medicament::Medicament(const Medicament& med)
    : idMedicament(med.idMedicament), nomMedicament(med.nomMedicament), prix(med.prix), stock(med.stock), dateExpiration(med.dateExpiration) {
    Pharmacien* phar;
    for (unsigned int i = 0; i < med.pharmaciens.size(); ++i) {
        phar = new Pharmacien(*med.pharmaciens[i]);
        pharmaciens.push_back(phar);
    }
}
Medicament::Medicament(int id, string nom, float prix, int stock, string dateExp)
    : idMedicament(id), nomMedicament(nom), prix(prix), stock(stock), dateExpiration(dateExp) {}

Medicament& Medicament::operator=(const Medicament& med) {
    if (this != &med) {
        for (unsigned int i = 0; i < pharmaciens.size(); ++i) {
            delete pharmaciens[i];
        }
        pharmaciens.clear();
        for (unsigned int i = 0; i < med.pharmaciens.size(); ++i) {
            Pharmacien* phar = new Pharmacien(*med.pharmaciens[i]);
            pharmaciens.push_back(phar);
        }
        idMedicament = med.idMedicament;
        nomMedicament = med.nomMedicament;
        prix = med.prix;
        stock = med.stock;
        dateExpiration = med.dateExpiration;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Medicament& med) {
    os << med.idMedicament << " "
       << med.nomMedicament << " "
       << med.prix << " "
       << med.stock << " "
       << med.dateExpiration << " ";
    return os;
}

istream& operator>>(istream& is, Medicament& med) {
    cout << "Entrer l'ID du medicament: ";
    is >> med.idMedicament;
    cout << "Entrer le nom du medicament: ";
    is >> med.nomMedicament;
    cout << "Entrer le prix du medicament: ";
    is >> med.prix;
    cout << "Entrer le stock du medicament: ";
    is >> med.stock;
    cout << "Entrer la date d'expiration du medicament: ";
    is >> med.dateExpiration;
    return is;
}

istream& operator>>(istream& is, Medicament* med) {
    is >> med->idMedicament >> med->nomMedicament >> med->prix >> med->stock >> med->dateExpiration;
    return is;
}

ostream& operator<<(ostream& os, Medicament* m) {
    os << m->getIdMedicament() << " "
       << m->getNomMedicament() << " "
       << m->getPrixMedicament() << " "
       << m->getStockMedicament() << " "
       << m->getDateExpiration() << " ";
    return os;
}

void Medicament::creer(fstream &f) {
    f.open("Medicament.txt", ios::in | ios::out | ios::trunc);
    if (!f.is_open()) { exit(-1); }
}

void Medicament::enregistrer_fichier() {
    fstream f("Medicament.txt", ios::out | ios::app);
    if (!f.is_open()) {
        cout << "\nErreur fichier Commande ";
        return;
    }
    f << this;
    f.close();
}

void Medicament::lire_fichier(vector<Medicament*>* medicaments) {
    fstream fi("Medicament.txt", ios::in);
    if (!fi.is_open()) {
        cout << "\nErreur fichier Commande";
        return;
    }
    while (!fi.eof()) {
        Medicament* med = new Medicament();
        fi >> med;
        if (medicaments) {
            medicaments->push_back(med); // ajouter au vecteur si fourni
        } else {
            delete med;
        }
    }
    fi.close();
}

static void Medicament::enregistrerMedicamentsDansFichierDepuisTableau(vector<Medicament*>& medicaments) {
    fstream f("Medicament.txt", ios::out | ios::trunc);
    if (!f) {
        cout << "Erreur lors de l'ouverture du fichier pour réécriture!" << endl;
        return;
    }

    for (unsigned int i = 0; i < medicaments.size(); ++i) {
        f << medicaments[i];
    }

    f.close();
    cout << "Fichier mis à jour avec succès!" << endl;
}

static void Medicament::chargerMedicamentsDansTableauDepuisFichier(vector<Medicament*>& medicaments) {
    fstream fi("Medicament.txt", ios::in);
    if (!fi) {
        cout << "Erreur lors de l'ouverture du fichier!" << endl;
        return;
    }
    Medicament* med;
    while (fi >> med) {
        medicaments.push_back(med);
    }
    fi.close();
}

void Medicament::ajouterPharmacienAMedicament(Pharmacien* phar) {
    pharmaciens.push_back(phar);
}

void Medicament::supprimerPharmaciendeMedicament(const string& nomPharmacien) {
    bool found = false;
    for (unsigned int i = 0; i < pharmaciens.size(); ++i) {
        if (pharmaciens[i]->getNom() == nomPharmacien) {
            pharmaciens.erase(pharmaciens.begin() + i);
            found = true;
            cout << "Pharmacien " << nomPharmacien << " supprimé du medicament." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Pharmacien non trouvé dans le medicament." << endl;
    }
}

void Medicament::afficherPharmacien() {
    if (pharmaciens.empty()) {
        cout << "Aucun pharmacien associe a ce medicament" << endl;
    } else {
        for (unsigned int i = 0; i < pharmaciens.size(); ++i) {
            cout << "Pharmacien " << i + 1 << " : " << pharmaciens[i]->getNom() << ", "
                 << pharmaciens[i]->getPrenom() << endl;
        }
    }
}



void Medicament::modifierMedInfo(string nom, float prix, int stock, string dateExp) {
    nomMedicament = nom;
    this->prix = prix;
    this->stock = stock;
    dateExpiration = dateExp;
}

Medicament::~Medicament() {
    for (unsigned int i = 0; i < pharmaciens.size(); i++) {
        delete pharmaciens[i];
    }
}

int Medicament::getIdMedicament() {
    return idMedicament;
}

void Medicament::setIdMedicament(int id) {
    idMedicament = id;
}

string Medicament::getNomMedicament() {
    return nomMedicament;
}

void Medicament::setNomMedicament(string nom) {
    nomMedicament = nom;
}

float Medicament::getPrixMedicament() {
    return prix;
}

void Medicament::setPrixdMedicament(float prix) {
    this->prix = prix;
}

int Medicament::getStockMedicament() {
    return stock;
}

void Medicament::setStockdMedicament(int stock) {
    this->stock = stock;
}

string Medicament::getDateExpiration() {
    return dateExpiration;
}

void Medicament::setDateExpiration(string dateExpiration) {
    this->dateExpiration = dateExpiration;
}

bool Medicament::estEnStock() {
    return stock > 0;
}

void Medicament::miseAJourStock(int quantite) {
    if (stock - quantite >= 0) {
        stock -= quantite;
    } else {
        cout << "Stock insuffisant !" << endl;
    }
}

bool Medicament::estPerime(string dateActuelle) {
    return dateExpiration < dateActuelle;
}
