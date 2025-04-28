#include "Commande.h"

int Commande::nbTotalCommandes = 0;

Commande::Commande(string code, int qteCmd, string dateCmd)
    : codeCommande(code), qteCommande(qteCmd), dateCommande(dateCmd) {
    nbTotalCommandes++;
}

Commande::Commande(const Commande& c)
    : codeCommande(c.codeCommande), qteCommande(c.qteCommande), dateCommande(c.dateCommande) {
    for (unsigned int i = 0; i < c.medicaments.size(); i++) {
        Medicament* med = nullptr;
        if (typeid(*c.medicaments[i]) == typeid(Medicament))
            med = new Medicament(*c.medicaments[i]);
        else if (typeid(*c.medicaments[i]) == typeid(Antibiotique))
            med = new Antibiotique(dynamic_cast<const Antibiotique&>(*c.medicaments[i]));
        else if (typeid(*c.medicaments[i]) == typeid(AntiInflammatoire))
            med = new AntiInflammatoire(dynamic_cast<const AntiInflammatoire&>(*c.medicaments[i]));
        else if (typeid(*c.medicaments[i]) == typeid(Vitamine))
            med = new Vitamine(dynamic_cast<const Vitamine&>(*c.medicaments[i]));
        medicaments.push_back(med);
    }
    nbTotalCommandes++;
}

Commande::~Commande() {
    for (unsigned int i = 0; i < medicaments.size(); i++)
        delete medicaments[i];
    nbTotalCommandes--;
}

string Commande::getCodeCommande() const { return codeCommande; }
string Commande::getDateCommande() const { return dateCommande; }
int Commande::getQteCommande() const { return qteCommande; }

float Commande::calculerMontantTotal() {
    float s = 0;
    for (unsigned int i = 0; i < medicaments.size(); i++)
        s += medicaments[i]->getPrixMedicament();
    return s;
}

bool Commande::verifierMedicamentDansCommande(const string& nom) {
    for (unsigned int i = 0; i < medicaments.size(); i++) {
        if (medicaments[i]->getNomMedicament() == nom) {
            return true;
        }
    }
    return false;
}

int Commande::nombreDeMedicamentsDansCommande() const {
    return medicaments.size();
}

Medicament*& Commande::operator[](int index) {
    if (index < 0 || index >= (int)medicaments.size()) {
        throw out_of_range("Indice invalide!");
    }
    return medicaments[index];
}

Commande Commande::operator+(const Commande& other) const {
    Commande resultat = *this;
    for (unsigned int i = 0; i < other.medicaments.size(); i++) {
        resultat.ajouterMedicamentACommande(other.medicaments[i]);
    }
    return resultat;
}

void Commande::ajouterMedicamentACommande(Medicament* med) {
    medicaments.push_back(med);
}

void Commande::supprimerMedicamentDeCommande(const string& nomMedicament) {
    bool found = false;
    for (unsigned int i = 0; i < medicaments.size(); ++i) {
        if (medicaments[i]->getNomMedicament() == nomMedicament) {
            delete medicaments[i];
            medicaments.erase(medicaments.begin() + i);
            found = true;
            cout << "Médicament " << nomMedicament << " supprimé de la commande." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Médicament non trouvé dans la commande." << endl;
    }
}

void Commande::afficherCommande() {
    cout << codeCommande << endl;
    cout << qteCommande << endl;
    cout << dateCommande << endl;
    cout << nbTotalCommandes << endl;
    for (unsigned int i = 0; i < medicaments.size(); i++) {
        cout << medicaments[i]->getIdMedicament() << "\t"
             << medicaments[i]->getNomMedicament() << "\t"
             << medicaments[i]->getPrixMedicament() << "\t"
             << medicaments[i]->getDateExpiration() << endl;
    }
}

void Commande::creer(fstream& f) {
    f.open("Commande.txt", ios::in | ios::out | ios::trunc);
    if (!f.is_open()) { exit(-1); }
}

void Commande::enregistrer_fichier() {
    fstream f("Commande.txt", ios::out | ios::app);
    if (!f.is_open()) {
        cout << "\nErreur fichier Commande ";
        return;
    }
    f << this;
    f.close();
}

void Commande::lire_fichier(vector<Commande*>* commandes) {
    fstream fi("Commande.txt", ios::in);
    if (!fi.is_open()) {
        cout << "\nErreur fichier Commande";
        return;
    }
    while (!fi.eof()) {
        Commande* cmd = new Commande();
        fi >> cmd;
        if (commandes) {
            commandes->push_back(cmd);
        } else {
            delete cmd;
        }
    }
    fi.close();
}

void Commande::enregistrerCommandesDansFichierDepuisTableau(vector<Commande*>& commandes) {
    fstream f("Commande.txt", ios::out | ios::trunc);
    if (!f) {
        cout << "Erreur lors de l'ouverture du fichier pour réécriture!" << endl;
        return;
    }
    for (unsigned int i = 0; i < commandes.size(); ++i) {
        f << commandes[i];
    }
    f.close();
    cout << "Fichier mis à jour avec succès!" << endl;
}

void Commande::chargerCommandesDansTableauDepuisFichier(vector<Commande*>& commandes) {
    fstream fi("Commande.txt", ios::in);
    if (!fi) {
        cout << "Erreur lors de l'ouverture du fichier!" << endl;
        return;
    }
    Commande* cmd;
    while (fi >> cmd) {
        commandes.push_back(cmd);
    }
    fi.close();
}

void Commande::modifierCommande(const string& codeCommandeRecherche, const string& newCode, const string& newDate, int newQteCommande, Medicament* medToAdd, const string& medToRemove) {
    Commande cmd1;
    vector<Commande*> commandes;
    cmd1.lire_fichier(&commandes);
    for (unsigned int i = 0; i < commandes.size(); ++i) {
        if (commandes[i]->codeCommande == codeCommandeRecherche) {
            commandes[i]->codeCommande = newCode;
            commandes[i]->dateCommande = newDate;
            commandes[i]->qteCommande = newQteCommande;
            cout << "Commande modifiée avec succès!" << endl;
            if (medToAdd != nullptr) {
                commandes[i]->ajouterMedicamentACommande(medToAdd);
                cout << "Médicament ajouté à la commande." << endl;
            }
            if (!medToRemove.empty()) {
                commandes[i]->supprimerMedicamentDeCommande(medToRemove);
            }
            Commande::enregistrerCommandesDansFichierDepuisTableau(commandes);
            return;
        }
    }
    cout << "Commande non trouvée." << endl;
}

void Commande::supprimerCommande(const string& codeCommandeASupprimer) {
    Commande cmd1;
    vector<Commande*> commandes;
    cmd1.lire_fichier(&commandes);
    for (unsigned int i = 0; i < commandes.size(); ++i) {
        if (commandes[i]->codeCommande == codeCommandeASupprimer) {
            delete commandes[i];
            commandes.erase(commandes.begin() + i);
            cout << "Commande supprimée avec succès!" << endl;
            Commande::enregistrerCommandesDansFichierDepuisTableau(commandes);
            return;
        }
    }
    cout << "Commande non trouvée." << endl;
}

// Opérateurs

ostream& operator<<(ostream& os, const Commande& cmd) {
    os << "Code commande: " << cmd.codeCommande << endl;
    os << "Quantité commande: " << cmd.qteCommande << endl;
    os << "Date commande: " << cmd.dateCommande << endl;
    os << "Nombre total de médicaments: " << cmd.medicaments.size();

