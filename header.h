#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include<vector>
#include <typeinfo>
using namespace std;
class Employe {
    string nom;
    string prenom;
    int salaire;
    static int nombreEmployes;


public:
    Employe(string n, string p, int s);
    virtual ~Employe();
    virtual void afficherDetails() ;
    void augmenterSalaire(int pourcentage);
    int obtenirSalaire() ;
    static int obtenirNombreEmployes();
    void supprimerEmploye(int index);
    void afficherEmployes();
    void ajouterEmploye(const Employe& emp);
    string getNom() ;
    void setNom(string n);
    string getPrenom();
    void setPrenom(string p);
    int getSalaire();
    void setSalaire(int s);
};

class Responsable : public Employe {
    string departement;
public:
    Responsable(string n, string p, int s, string d);
    ~Responsable();
    void afficherDetails();
    string getDepartement();
    void setDepartement(string d);
};
class Test {
    string codeTest;

public:
    Test(string code);
    virtual ~Test();
    virtual void effectuer() = 0;
    string getCodeTest();
    void setCodeTest(string code);
};

class Pharmacien : public Employe {
    vector<Test*> tabTests;
public:
    Pharmacien(string n, string p, int s);
    ~Pharmacien();
    void afficherDetails();
    Pharmacien(const Pharmacien& P);
    int rechercher (string code);
    void ajouterTest(Test* test);
    void supprimerTest(string code);
    void modifierTest(string code, Test* nouveauTest);
    void afficherTests();
};


class TestEnvironnement : public Test {
    int temperature;
    int humidite;
    int pression;
public:
    TestEnvironnement(string code, int t, int h, int p);
    void effectuer();
    void verifierConditions();
};

class TestPurete : public Test {
    int pH;
    int viscosite;
    int densite;
public:
    TestPurete(string code, int p, int v, int d);
    void effectuer() ;
    void estConforme() ;
};

class TestMicroBiologique : public Test {
    int pourcentageBacterie;
public:
    TestMicroBiologique(string code, int pb);
    void effectuer();
    bool estSterile();
    void controleSterilite();
};

class Medicament {
    int idMedicament;
    string nomMedicament;
    float prix;
    int stock;
    string dateExpiration;
    vector<Pharmacien*> pharmaciens;
public:
    Medicament(int id, string nom, float prix, int stock, string dateExp){
        idMedicament=id;
        nomMedicament=nom;
        prix=prix;
        stock=stock;
        dateExpiration=dateExp;
        };
    Medicament(Medicament const& med):
        idMedicament(med.idMedicament),nomMedicament(med.nomMedicament),prix(med.prix),stock(med.stock),dateExpiration(med.dateExpiration){
            for (unsigned int i=0;i<med.pharmaciens.size();i++){
                Pharmacien* phar;
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
    friend ostream& operator<<(ostream& os, const Medicament& m) {
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
}
    friend istream& operator>>(istream& is, Medicament& m) {
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
        med.pharmaciens.push_back(phar);
    }
    return is;
}

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
    os << "Spectre: " << antiB.spectre << endl;
    return os;
}
    friend istream& operator>>(istream& is, Antibiotique& antiB) {
    is >> static_cast<Medicament&>(antiB);
    cout << "Entrez Spectre: ";
    is >> antiB.spectre;
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
         for (int i = 0; i < nbPrincipesActifs; i++)
         delete[] principesActifs;
         }
};
class Vitamine : public Medicament {
    vector<string*> typesSupplementaires;
public:
    Vitamine(int id, string nom, float p, int s, string date)
    : Medicament(id, nom, p, s, date) {}

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
    int numCommande;
    int qteCommande;
    string dateCommande;
    vector<Medicament*> medicaments;
public:
    Commande(string code, int qteCmd, string dateCmd){
        codeCommande=code;
        qteCommande=qteCmd;
        dateCommande=dateCmd;
        numCommande = ++nbTotalCommandes;
    };
    Commande() : codeCommande(""), qteCommande(0), dateCommande(""), numCommande(++nbTotalCommandes) {}
    Commande(const Commande& c): codeCommande(c.codeCommande),numCommande(c.numCommande),qteCommande(c.qteCommande),dateCommande(c.dateCommande){
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
    ostream& operator<<(ostream& os, const Commande& cmd) {
    os << "Code commande: " << cmd.codeCommande << endl;
    os << "Numéro commande: " << cmd.numCommande << endl;
    os << "Quantité commande: " << cmd.qteCommande << endl;
    os << "Date commande: " << cmd.dateCommande << endl;
    os << "Nombre total de médicaments: " << cmd.medicaments.size() << endl;

    for (unsigned int i = 0; i < cmd.medicaments.size(); ++i) {
        os << "\tMédicament " << i + 1 << ":\n";
        os << *cmd.medicaments[i];
    }

    return os;
}
    istream& operator>>(istream& is, Commande& cmd) {
        cout << "Entrer le code commande:";
        is >> cmd.codeCommande;
        cout << "Entrer la quantité:";
        is >> cmd.qteCommande;
        cout << "Entrer la date:";
        is >> cmd.dateCommande;
        cmd.numCommande = ++Commande::nbTotalCommandes;
        return is;
}
    Medicament*& operator[](int index) {
    if (index < 0 || index >= medicaments.size()) {
        throw out_of_range("Index invalide !");
    }
    return medicaments[index];
}

    ~Commande(){
        for (unsigned int i=0;i<medicaments.size();i++)
            delete medicaments[i];
            nbTotalCommandes--;
    };
    void afficherCommande(){
      cout<<codeCommande<<endl;
      cout<<numCommande<<endl;
      cout<<qteCommande<<endl;
      cout<<dateCommande<<endl;
      cout<<nbTotalCommandes<<endl;
      for (unsigned int i=0;i<medicaments.size();i++)
        cout<<medicaments[i]->getIdMedicament()<<"\t"<<medicaments[i]->getNomMedicament()<<"\t"<<medicaments[i]->getPrixMedicament()<<"\t"<<medicaments[i]->getDateExpiration()<<"\t"<<endl;
    };
    void modifierCommande(string newCode, string newDate, Medicament* med, int index){
        codeCommande=newCode;
        dateCommande=newDate;
        bool test=false;
        int i=0;
        while(!test && i<medicaments.size()){
            (i=index-1)? test=true : i++;
        }
        if (test){
                medicaments[i]=med;
        };
    };
    void ajouterMedicamentACommande(Medicament* med){
        medicaments.push_back(med);
    }
    void supprimerMedicamentDeCommande(Medicament* med){
        bool test=false;
        int i=0;
        while(!test && i<medicaments.size()){
            (medicaments[i]->getNomMedicament()==med->getNomMedicament())? test=true : i++;
        }
        if (test)
            medicaments.erase(medicaments.begin()+i);
        else
            cout<<"Medicament non existant dans la commande"<<endl;
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



#endif
