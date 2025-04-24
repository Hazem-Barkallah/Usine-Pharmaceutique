class Etudiant {
    string nom;
    string prenom;
    string CIN;
    string mention;
    vector<Employe*> listeEmployes;
public:
    Etudiant(string n, string p, string CIN, string m);
    ~Etudiant();
    void afficherInfos() ;
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
