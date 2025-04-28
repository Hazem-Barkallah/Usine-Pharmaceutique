#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <string>
#include <fstream>
#include <istream>
#include <iostream>
#include<vector>
#include"headersAziz.h"
#include <typeinfo>
using namespace std;
class Medicament {
    int idMedicament;
    string nomMedicament;
    int prix;
    int stock;
    string dateExpiration;
    vector<Pharmacien*> pharmaciens;
public:
    Medicament(int id=0, string nom="", float prix=0, int stock=0, string dateExp="01/01/2000"){
        idMedicament=id;
        nomMedicament=nom;
        prix=prix;
        stock=stock;
        dateExpiration=dateExp;
        };
    Medicament(Medicament const& med):
        idMedicament(med.idMedicament),nomMedicament(med.nomMedicament),prix(med.prix),stock(med.stock),dateExpiration(med.dateExpiration){
            Pharmacien* phar;
            for (unsigned int i=0;i<med.pharmaciens.size();i++){
                phar=new Pharmacien(*med.pharmaciens[i]);
                pharmaciens.push_back(phar);
        }
    }
    Medicament& operator=(const Medicament& med) {
        Pharmacien* phar;
    if (this != &med) {
        for(unsigned int i=0;i<pharmaciens.size();i++){
            delete pharmaciens[i];
        }
        pharmaciens.clear();
        for(unsigned int i=0;i<med.pharmaciens.size();i++){
            phar=new Pharmacien(*med.pharmaciens[i]);
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
    /*friend ostream& operator<<(ostream& os, const Medicament& m) {
    os<< "ID: " << m.idMedicament <<endl;
    os<< "Nom: " << m.nomMedicament << endl;
    os<< "Prix: " << m.prix <<endl;
    os<< "Stock: " << m.stock << endl;
    os<< "Date d'expiration: " << m.dateExpiration << endl;
    os << "Pharmaciens qui ont fabriqué ce medicament: " << endl;
    for (unsigned int i = 0; i < m.pharmaciens.size(); i++) {
        os<<"-Pharmacien(ne) "<< *m.pharmaciens[i] << endl;
    }
    return os;
}*/
friend ostream& operator<<(ostream& os, const Medicament& med) {
    os << med.idMedicament << " "
       << med.nomMedicament << " "
       << med.prix << " "
       << med.stock << " "
       << med.dateExpiration << " ";
    return os;
}

    /*friend istream& operator>>(istream& is, Medicament& m) {
    cout<< "Entrer l'ID: ";
    is>> m.idMedicament;
    cout<< "Entrer le nom: ";
    is>> m.nomMedicament;
    cout<< "Entrer le prix: ";
    is>> m.prix;
    cout<< "Entrer le stock: ";
    is>> m.stock;
    cout<< "Entrer la date d'expiration: ";
    is>> m.dateExpiration;
    int nbPharmaciens;
    cout<< "Combien de pharmaciens voulez-vous ajouter ? ";
    is >> nbPharmaciens;
    for (int i = 0; i < nbPharmaciens; i++) {
        Pharmacien* phar = new Pharmacien();
        is >> *phar;
        m.pharmaciens.push_back(phar);
    }
    return is;
}*/
// À mettre dans Medicament
friend istream& operator>>(istream& is, Medicament& med) {
    cout<<"Entrer l'ID du medicament: ";
    is >> med.idMedicament;
    cout<<"Entrer le nom du medicament: ";
    is >> med.nomMedicament;
    cout<<"Entrer le prix du medicament: ";
    is >> med.prix;
    cout<<"Entrer le stock du medicament: ";
    is>> med.stock;
    cout<<"Entrer la date d'expiration du medicament: ";
    is>> med.dateExpiration;
    return is;
}
friend istream& operator>>(istream& is, Medicament* med) {
    is >> med->idMedicament
       >> med->nomMedicament
       >> med->prix
       >> med->stock
       >> med->dateExpiration;
    if (med->idMedicament<=0 || med->prix <= 0 || med->nomMedicament.empty()) {
        cout << "" << endl;
        return is;}
    cout << "ID: " << med->idMedicament << endl;
    cout << "Nom: " << med->nomMedicament << endl;
    cout << "Prix: " << med->prix << endl;
    cout << "Stock: " << med->stock << endl;
    cout << "Date Expiration: " << med->dateExpiration << endl;
    return is;
}
friend ostream& operator<<(ostream& os, Medicament* m) {
    os << m->getIdMedicament() << " "
       << m->getNomMedicament() << " "
       << m->getPrixMedicament() << " "
       << m->getStockMedicament() << " "
       << m->getDateExpiration() << " ";
    return os;
}
void creer(fstream &f){
    f.open("Medicament.txt", ios ::in | ios ::out |ios ::trunc) ;
    if( ! f.is_open()) {exit(-1);}}

void enregistrer_fichier() {
    fstream f("Medicament.txt", ios::out | ios::app);
    if (!f.is_open()) {
        cout << "\nErreur fichier Commande ";
        return;
    }
    f << this;
    f.close();
}
void lire_fichier() {
    fstream fi("Medicament.txt", ios::in);
    if (!fi.is_open()) {
        cout << "\nErreur fichier Commande";
        return;
    }
    while (!fi.eof()) {
        Medicament* med = new Medicament();
        fi >> med;
        delete med;
    }
    fi.close();
};
    int rechercher(string nomEmployee) {
        for (size_t i = 0; i < pharmaciens.size(); ++i) {
            if (pharmaciens[i]->getNom() == nomEmployee) {
                return i;
            }
        }
        return -1;
    }
     void ajouterPharmacien(Pharmacien* phar) {
        pharmaciens.push_back(phar);
    }
    void supprimerPharmacien(string codeEmploye) {
        int index = rechercher(codeEmploye);
        if (index != -1) {
            pharmaciens.erase(pharmaciens.begin() + index);
            cout << "Pharmacien supprime avec succes" << endl;
        } else {
            cout << "Pharmacien non trouve" << endl;
        }
    }
    void modifierPharmacien(string code, Pharmacien* nouveauPharmacien) {
        int index = rechercher(code);
        if (index != -1) {
            pharmaciens[index] = nouveauPharmacien;
            cout << "Pharmacien modifie avec succes" << endl;
        } else {
            cout << "Pharmacien non trouve" << endl;
        }
    }
    void afficherPharmacien() {
        if (pharmaciens.empty()) {
            cout << "Aucun pharmacien associe a ce medicament" << endl;
        } else {
            for (unsigned int i = 0; i < pharmaciens.size(); ++i) {
                cout << "Pharmacien " << i + 1 << " : " << pharmaciens[i]->getNom() << ", "
                     << pharmaciens[i]->getPrenom() << endl;
            }
        }
    }

    void afficherMedInfo() {
        cout << "ID: " << idMedicament << ", Nom: " << nomMedicament<< ", Prix: " << prix << ", Stock: " << stock<< ", Expiration: "<<dateExpiration<<endl;
    }
    virtual void modifierMedInfo(string nom, float prix, int stock, string dateExp) {
        nomMedicament=nom;
        this->prix=prix;
        this->stock=stock;
        dateExpiration=dateExp;
    }
    virtual ~Medicament(){
    for (unsigned int i=0;i<pharmaciens.size();i++)
            delete pharmaciens[i];
    }
    int getIdMedicament(){
        return idMedicament;
    }
    void setIdMedicament(int id){
        idMedicament=id;
    }
    string getNomMedicament(){
        return nomMedicament;
    }
    void setNomMedicament(string nom){
        nomMedicament=nom;
    }
    float getPrixMedicament(){
        return prix;
    }
    void setPrixdMedicament(float prix){
        this->prix=prix;
    }
    int getStockMedicament(){
        return stock;
    }
    void setStockdMedicament(int stock){
        this->stock=stock;
    }
    string getDateExpiration(){
        return dateExpiration;
    }
    void setDateExpiration(string dateExpiration){
        this->dateExpiration=dateExpiration;
    }
     virtual bool estEnStock(){
        return stock > 0;
    }
    virtual void miseAJourStock(int quantite){
        if (stock - quantite >= 0) {
            stock -= quantite;
        } else {
            cout << "Stock insuffisant !" << endl;
        }
    }
    bool estPerime(string dateActuelle){
        return dateExpiration < dateActuelle;
    }
};

class Antibiotique : virtual public Medicament {
    string spectreAction;
public:
    Antibiotique(int id, string nom, float p, int s, string date, string spectre)
        : Medicament(id, nom, p, s, date) {
            spectreAction=spectre;
        }
    friend ostream& operator<<(ostream& os, const Antibiotique& antiB) {
    os << static_cast<const Medicament&>(antiB);
    os << "Spectre: " << antiB.spectreAction << endl;
    return os;
}
    friend istream& operator>>(istream& is, Antibiotique& antiB) {
    is >> static_cast<Medicament&>(antiB);
    cout << "Entrez Spectre: ";
    is >> antiB.spectreAction;
    return is;
}
    void afficherMedInfo(){
        Medicament::afficherMedInfo();
        cout << spectreAction << endl;
    };
    void modifierMedInfo(string nom, float prix, int stock, string dateExp,string spectre){
        Medicament::modifierMedInfo(nom, prix, stock, dateExp);
        spectreAction=spectre;
    }
    ~Antibiotique(){};
    string getSpectre(){return spectreAction;};
    void setSpectre(string spectre){spectreAction=spectre;};
};

class AntiInflammatoire : virtual public Medicament {
    bool estSteroidien;
public:
    AntiInflammatoire(int id, string nom, float p, int s, string date, bool steroidien)
        : Medicament(id, nom, p, s, date){
            estSteroidien=steroidien;
        };
    /*friend ostream& operator<<(ostream& os, const AntiInflammatoire& antiI) {
        os << static_cast<const Medicament&>(antiI);
        os << "Spectre: " << antiI.spectre << endl;
        return os;
}
    friend istream& operator>>(istream& is, AntiInflammatoire& antiI) {
        is >> static_cast<Medicament&>(antiI);
        cout << "Entrez Spectre: ";
        is >> antiI.spectre;
        return is;
}*/
    void afficherMedInfo(){
        Medicament::afficherMedInfo();
        cout << estSteroidien << endl;
    };
    void modifierMedInfo(string nom, float prix, int stock, string dateExp,bool steroidien){
        Medicament::modifierMedInfo(nom, prix, stock, dateExp);
        estSteroidien=steroidien;
    }
    ~AntiInflammatoire(){};
};

class MedicamentCombine :public Antibiotique, public AntiInflammatoire {
    int nbPrincipesActifs;
    string* principesActifs;
public:
    MedicamentCombine(int id, string nom, float p, int s, string date, string spectre, bool steroidien,int nb):
          Medicament(id, nom, p, s, date),
          Antibiotique(id, nom, p, s, date, spectre),
          AntiInflammatoire(id, nom, p, s, date, steroidien)
          {nbPrincipesActifs=nb;
            principesActifs = new string[nbPrincipesActifs];}

     void ajouterPA(string principeActif) {
        string* newPrincipesActifs = new string[nbPrincipesActifs + 1];
        for (int i = 0; i < nbPrincipesActifs; i++) {
            newPrincipesActifs[i] = principesActifs[i];
        }
        newPrincipesActifs[nbPrincipesActifs] = principeActif;
        delete[] principesActifs;
        principesActifs = newPrincipesActifs;
        nbPrincipesActifs++;
    }
      void supprimerPA(string principeActif) {
        for (int i = 0; i < nbPrincipesActifs; i++) {
            if (principesActifs[i] == principeActif) {
                string* newPrincipesActifs = new string[nbPrincipesActifs - 1];
                for (int j = 0, k = 0; j < nbPrincipesActifs; j++) {
                    if (j != i) {
                        newPrincipesActifs[k++] = principesActifs[j];
                    }
                }
                delete[] principesActifs;
                principesActifs = newPrincipesActifs;
                nbPrincipesActifs--;
                break;
            }
        }
    }
    void modifierPA(string ancienPA, string nouveauPA) {
        for (int i = 0; i < nbPrincipesActifs; i++) {
            if (principesActifs[i] == ancienPA) {
                principesActifs[i] = nouveauPA;
                break;
            }
        }
    }
    void afficherPA() {
        cout << "Principes Actifs: " << endl;
        for (int i = 0; i < nbPrincipesActifs; i++) {
            cout << "- " << principesActifs[i] << endl;
        }
    }
    void modifierMedInfo(int id, string nom, float p, int s, string date, string spectre, bool steroidien){
        Medicament::modifierMedInfo(nom,p,s,date);
    }
    void afficherMedInfo(){
        Antibiotique::afficherMedInfo();
        AntiInflammatoire::afficherMedInfo();
    }
     virtual ~MedicamentCombine() {
         delete[] principesActifs;
         }
};
class Vitamine : public Medicament {
    vector<string*> typesSupplementaires;
public:
    Vitamine(int id, string nom, float p, int s, string date)
    : Medicament(id, nom, p, s, date) {}

    // --- Lecture/Ecriture brut sans affichage
friend ostream& operator<<(ostream& os, const Vitamine& vit) {
    os << static_cast<const Medicament&>(vit) << " "; // Appeler opérateur<< de Medicament
    os << vit.typesSupplementaires.size() << " ";
    for (unsigned int i = 0; i < vit.typesSupplementaires.size(); ++i) {
        os << *vit.typesSupplementaires[i] << " ";
    }
    return os;
}

friend istream& operator>>(istream& is, Vitamine& vit) {
    is >> static_cast<Medicament&>(vit); // Lire partie Medicament

    int nbTypes;
    is >> nbTypes;
    vit.typesSupplementaires.clear();

    for (int i = 0; i < nbTypes; ++i) {
        string* type = new string;
        is >> *type;
        vit.typesSupplementaires.push_back(type);
    }
    return is;
}

// --- Lecture avec affichage pour l'exécution
friend istream& operator>>(istream& is, Vitamine* vit) {
    is >> static_cast<Medicament&>(*vit);

    int nbTypes;
    is >> nbTypes;
    vit->typesSupplementaires.clear();

    cout << "\nLecture Vitamine :" << endl;
    cout << "ID: " << vit->getIdMedicament() << endl;
    cout << "Nom: " << vit->getNomMedicament() << endl;
    cout << "Prix: " << vit->getPrixMedicament() << endl;
    cout << "Stock: " << vit->getStockMedicament() << endl;
    cout << "Date Expiration: " << vit->getDateExpiration() << endl;
    cout << "Nombre de types supplementaires: " << nbTypes << endl;

    for (int i = 0; i < nbTypes; i++) {
        string* type = new string;
        is >> *type;
        cout << "- " << *type << endl;
        vit->typesSupplementaires.push_back(type);
    }
    return is;
}
friend ostream& operator<<(ostream& os, const Vitamine* v) {
    os << static_cast<const Medicament&>(*v) << " ";
    os << v->typesSupplementaires.size() << " ";
    for (const auto& type : v->typesSupplementaires) {
        os << *type << " ";  // Affiche les types supplémentaires
    }
    return os;
}
void creer(fstream &f){
    f.open("Vitamine.txt", ios ::in | ios ::out |ios ::trunc) ;
    if( ! f.is_open()) {exit(-1);}
}
void lire_fichier(){
    fstream fi("Vitamine.txt");
    if (!fi) cout<<"\n erreur fichier Vitamine";
    fi>>this;
    fi.close();
}
void enregistrer_fichier(){
    fstream f("Vitamine.txt");
    if (!f) {cout<<"\n erreur fichier Vitamine "; }
    f<<this;
    f.close();
}
    void afficherMedInfo() {
        Medicament::afficherMedInfo();
        for (unsigned int i=0; i<typesSupplementaires.size();i++) {
            cout << *typesSupplementaires[i];
        }
}
    void modifierMedInfo(string nom, float prix, int stock, string dateExp) {
        Medicament::modifierMedInfo(nom, prix, stock, dateExp);
}
    void ajoutertypeSupplementaire(string* typeSupp) {
        typesSupplementaires.push_back(typeSupp);
}
    void supprimertypeSupp(string* typeSupp) {
    for (int i = 0; i < typesSupplementaires.size(); i++) {
        if (*typesSupplementaires[i] == *typeSupp) {
            delete typesSupplementaires[i];
            typesSupplementaires.erase(typesSupplementaires.begin() + i);
            break;
        }
    }
}
    ~Vitamine() {
    for (int i = 0; i < typesSupplementaires.size(); ++i) {
        delete typesSupplementaires[i];
    }
}
};
class Commande{
    static int nbTotalCommandes;
    string codeCommande;
    int qteCommande;
    string dateCommande;
    vector<Medicament*> medicaments;

public:
    Commande(string code, int qteCmd, string dateCmd){
        codeCommande=code;
        qteCommande=qteCmd;
        dateCommande=dateCmd;
    };
    Commande() : codeCommande(""), qteCommande(0), dateCommande("") {}
    Commande(const Commande& c): codeCommande(c.codeCommande),qteCommande(c.qteCommande),dateCommande(c.dateCommande){
        for (unsigned int i=0;i<c.medicaments.size();i++){
                Medicament* med;
            if (typeid(*c.medicaments[i])==typeid(Medicament))
                med=new Medicament(*c.medicaments[i]);
            else if (typeid(*c.medicaments[i])==typeid(Antibiotique))
                med=new Antibiotique(dynamic_cast<const Antibiotique&>(*c.medicaments[i]));
            else if (typeid(*c.medicaments[i])==typeid(AntiInflammatoire))
                med=new AntiInflammatoire(dynamic_cast<const AntiInflammatoire&>(*c.medicaments[i]));
            else if (typeid(*c.medicaments[i])==typeid(Vitamine))
                med=new Vitamine(dynamic_cast<const Vitamine&>(*c.medicaments[i]));
            medicaments.push_back(med);
}
    }
friend ostream& operator<<(ostream& os, const Commande& cmd) {
    os << "Code commande: " << cmd.codeCommande << endl;
    os << "Quantité commande: " << cmd.qteCommande << endl;
    os << "Date commande: " << cmd.dateCommande << endl;
    os << "Nombre total de médicaments: " << cmd.medicaments.size() << endl;

    for (unsigned int i = 0; i < cmd.medicaments.size(); ++i) {
        os << "\tMédicament " << i + 1 << ":\n";
        os << *cmd.medicaments[i];
    }
    return os;
}
friend ostream& operator<<(ostream& os, const Commande* cmd) {
    os << cmd->codeCommande << " ";
    os << cmd->qteCommande << " ";
    os << cmd->dateCommande << " ";
    os << cmd->medicaments.size() << "\n";

    for (unsigned int i = 0; i < cmd->medicaments.size(); ++i) {
        os << *cmd->medicaments[i]<<"\n";
    }
    return os;
}
friend istream& operator>>(istream& is, Commande& cmd) {
    cout << "Entrer le code commande: ";
    is >> cmd.codeCommande;
    cout << "Entrer la quantité: ";
    is >> cmd.qteCommande;
    cout << "Entrer la date: ";
    is >> cmd.dateCommande;
    int nbMeds;
    cout << "Combien de medicaments dans cette commande ? ";
    is >> nbMeds;
    cmd.medicaments.clear();
    for (int i = 0; i < nbMeds; ++i) {
        cout << "*Saisie du medicament num*" << i + 1 << " :" << endl;
        Medicament* m = new Medicament();
        is >> *m;
        cmd.medicaments.push_back(m);
    }
    return is;
}
friend istream& operator>>(istream& is, Commande* cmd) {
    int nbMeds;
    is >> cmd->codeCommande >> cmd->qteCommande >> cmd->dateCommande >> nbMeds;
    cmd->medicaments.clear();
    if (cmd->codeCommande.empty() || cmd->qteCommande <= 0 || cmd->dateCommande.empty()) {
        cout << "" << endl;
        return is;
    }
    cout << "Code Commande: " << cmd->codeCommande << "\n";
    cout << "Quantite: " << cmd->qteCommande << endl;
    cout << "Date de commande: " << cmd->dateCommande << endl;
    cout<<"***************************************\n";

    for (unsigned int i = 0; i < nbMeds; i++) {
        Medicament* m = new Medicament();
        is >> m;
        cmd->medicaments.push_back(m);
        cout<<"----------------------------\n";
    }
        cout<<"***************************************\n";
    return is;
}
    Commande operator+(const Commande& other) const {
    Commande resultat = *this;
    for (unsigned int i=0;i<other.medicaments.size();i++) {
        resultat.ajouterMedicamentACommande(other.medicaments[i]);
    }
    return resultat;
}

    Medicament*& operator[](int index) {
    if (index < 0 || index >= medicaments.size()) {
        throw out_of_range("Indice invalide!");
    }
    return medicaments[index];
}
void creer(fstream &f){
    f.open("Commande.txt", ios ::in | ios ::out |ios ::trunc) ;
    if( ! f.is_open()) {exit(-1);}}

void enregistrer_fichier() {
    fstream f("Commande.txt", ios::out | ios::app);
    if (!f.is_open()) {
        cout << "\nErreur fichier Commande ";
        return;
    }
    f << this;
    f.close();
}
void lire_fichier(vector<Commande*>* commandes = nullptr) {
    fstream fi("Commande.txt", ios::in);
    if (!fi.is_open()) {
        cout << "\nErreur fichier Commande";
        return;
    }
    while (!fi.eof()) {
        Commande* cmd = new Commande();
        fi >> cmd;
        if (commandes) {
            commandes->push_back(cmd); // ajouter au vecteur si fourni
        } else {
            delete cmd;
    }}
    fi.close();
};

static void enregistrerCommandesDansFichierDepuisTableau(vector<Commande*>& commandes) {
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
static void chargerCommandesDansTableauDepuisFichier(vector<Commande*>& commandes) {
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
    static void modifierCommande(const string& codeCommandeRecherche, const string& newCode, const string& newDate, int newQteCommande, Medicament* medToAdd = nullptr, const string& medToRemove = "") {
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
static void supprimerCommande(const string& codeCommandeASupprimer) {
    Commande cmd1;
    vector<Commande*> commandes;
    cmd1.lire_fichier(&commandes);

    for (unsigned int i = 0; i < commandes.size(); ++i) {
        if (commandes[i]->codeCommande == codeCommandeASupprimer) {
            delete commandes[i];                   // Libérer la mémoire
            commandes.erase(commandes.begin() + i); // Enlever du vecteur
            cout << "Commande supprimée avec succès!" << endl;

            Commande::enregistrerCommandesDansFichierDepuisTableau(commandes);
            return;
        }
    }
    cout << "Commande non trouvée." << endl;
}

    ~Commande(){
        for (unsigned int i=0;i<medicaments.size();i++)
            delete medicaments[i];
            nbTotalCommandes--;
    };
    void afficherCommande(){
      cout<<codeCommande<<endl;
      cout<<qteCommande<<endl;
      cout<<dateCommande<<endl;
      cout<<nbTotalCommandes<<endl;
      for (unsigned int i=0;i<medicaments.size();i++)
        cout<<medicaments[i]->getIdMedicament()<<"\t"<<medicaments[i]->getNomMedicament()<<"\t"<<medicaments[i]->getPrixMedicament()<<"\t"<<medicaments[i]->getDateExpiration()<<"\t"<<endl;
    };
    void ajouterMedicamentACommande(Medicament* med){
        medicaments.push_back(med);
    }
    void supprimerMedicamentDeCommande(const string& nomMedicament) {
    bool found = false;
    for (unsigned int i = 0; i < medicaments.size(); ++i) {
        if (medicaments[i]->getNomMedicament() == nomMedicament) {
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

    float calculerMontantTotal(){
        float s=0;
        for (unsigned int i=0;i<medicaments.size();i++)
            s+=medicaments[i]->getPrixMedicament();
        return s;
    };
    bool verifierMedicamentDansCommande(const string& nom){
        for (unsigned int i = 0; i < medicaments.size(); i++){
            if (medicaments[i]->getNomMedicament() == nom){
                return true;
            }
        }
        return false;
    }
    int nombreDeMedicamentsDansCommande() const {
        return medicaments.size();
    }
};

class Client{
    string nomClient;
    string prenomClient;
    string CINClient;
    string numTel;
    string emailClient;
    Commande* commandes;
    int nbCommandes;
    int capacite;
public:
    Client(string nom, string prenom, string CIN, string tel, string email,int cap=2) {
        nomClient=nom;
        prenomClient=prenom;
        CINClient=CIN;
        numTel=tel;
        emailClient=email;
        capacite = cap;
        nbCommandes = 0;
        commandes = new Commande[capacite];
}
    void afficherDetailsClient(){
        cout << "Nom: " << nomClient << ", Prénom: " << prenomClient<< ", CIN: " << CINClient << ", Téléphone: " << numTel<< ", Email: " << emailClient << endl;
};
    void modifierClientInfos(string nom,string prenom,string tel, string email){
        nomClient=nom;
        prenomClient=prenom;
        numTel=tel;
        emailClient=email;
};
    ~Client(){
        for (int i = 0; i < nbCommandes; i++)
            delete[] commandes;
    };
    void passerCommande(Commande cmd) {
        if (nbCommandes < capacite) {
            commandes[nbCommandes++] = cmd;
        }
    }


};

#endif // HEADERS_H_INCLUDED
