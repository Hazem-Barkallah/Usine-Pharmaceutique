
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employe {
protected:
    string nom;
    string prenom;
    int salaire;
    static int nombreEmployes;
    int nombreCompetences;
    string* competences;

public:
    Employe(string n, string p, int s,int nc);
    Employe(const Employe& e);
    virtual ~Employe();
    Employe & operator=(const Employe&);
    string& operator[](int);
    class Exception_Indice{
        public :
        int indice;
        Exception_Indice (int i){indice = i;}};
    friend ostream& operator<<(ostream&, Employe& );
    friend istream& operator>>(istream&, Employe& );
    /*void ajouterCompetence(string competence);//m
    void supprimerCompetence(string competence);//m
    void modifierCompetence(string ancienneComp, string nouvelleComp);//m
    void afficherCompetences();//m*/
    void augmenterSalaire(int pourcentage);
    int obtenirSalaire() ;
    static int obtenirNombreEmployes();
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
    Responsable(string n, string p, int s,int nc,string d);
    virtual ~Responsable();
    friend ostream& operator<<(ostream&, Responsable& );
    friend istream& operator>>(istream&, Responsable& );
    string getDepartement();
    void setDepartement(string d);
};
class Test {
protected:
    string codeTest;

public:
    Test(string code);
    Test(const Test* T);
    virtual ~Test();
    friend ostream& operator<<(ostream&, Test& );
    friend istream& operator>>(istream&, Test& );
    string getCodeTest();
    void setCodeTest(string code);
};
class Pharmacien : public Employe {
    vector<Test*> tabTests;
public:
    Pharmacien(string n="", string p="", int s=0,int nc=0);
    Pharmacien (const Pharmacien& P);
    ~Pharmacien();
    static void creer(fstream&);
    Pharmacien & operator=(const Pharmacien&);
    friend istream & operator>>(istream &,Pharmacien& );
    friend ostream& operator<<(ostream&, Pharmacien& );
    friend ostream & operator<<(ostream &,Pharmacien *);
    friend istream & operator>>(istream &, Pharmacien*);
    void lire_fichier();
    void enregistrer_fichier();
    int rechercher (string code);
    Test* & operator[](int);
    Pharmacien operator+(const Test* t);
    void supprimerTest(string code);
    void modifierTest(string code, Test* nouveauTest);
    //void afficherTests();
};

class TestEnvironnement : public Test {
    int temperature;
    int humidite;
    int pression;
public:
    TestEnvironnement(string code, int t, int h, int p);
    friend ostream& operator<<(ostream&, TestEnvironnement& );
    friend istream& operator>>(istream&, TestEnvironnement& );
    virtual ~TestEnvironnement() {}
    void verifierConditions();
    int getTemperature() const { return temperature; }
    int getHumidite() const { return humidite; }
    int getPression() const { return pression; }
};

class TestPurete : public Test {
    int pH;
    int viscosite;
    int densite;
public:
    TestPurete(string code, int p, int v, int d);
    friend istream& operator>>(istream& in, TestPurete& tp);
    friend ostream& operator<<(ostream&, TestPurete& );
    virtual~TestPurete() {}
    void estConforme() ;
    int getPH() const { return pH; }
    int getViscosite() const { return viscosite; }
    int getDensite() const { return densite; }
};

class TestMicroBiologique : public Test {
    int pourcentageBacterie;
public:
    TestMicroBiologique(string code, int pb);
    virtual ~TestMicroBiologique() {}
    friend ostream& operator<<(ostream&, TestMicroBiologique& );
    friend istream& operator>>(istream&, TestMicroBiologique& );
    bool estSterile();
    int getPourcentageBacterie() const { return pourcentageBacterie; }
    void controleSterilite();
};
class Etudiant {
    string nom;
    string prenom;
    string CIN;
    string mention;
    //static vector<Employe> listeEmployes;
public:
    Etudiant(string n, string p, string CIN, string m);
    ~Etudiant();
    friend ostream& operator<<(ostream&, Etudiant& );
    friend istream& operator>>(istream&, Etudiant& );
    void postulerStage();
    string getNom() ;
    void setNom(string n);
    string getPrenom();
    void setPrenom(string p);
    string getCIN();
    void setCIN(string cin);
    string getMention();
    void setMention(string m);
};

class Stagiaire:public Etudiant,public Employe{
    int dureeStage;
public:
    Stagiaire(string n, string p, string ci, string m, int s, int nc, int d);
    ~Stagiaire();
    friend ostream& operator<<(ostream&, Stagiaire&);
    friend istream& operator>>(istream&, Stagiaire&);
    //string getNom() ;
    //void setNom(string n);
    string getPrenom() ;
    void setPrenom(string p);
    int getDureeStage() ;
    void setDureeStage(int d);
};
