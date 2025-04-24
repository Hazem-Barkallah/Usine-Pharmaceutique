class Antibiotique : virtual public Medicament {
    string spectreAction;
public:
    Antibiotique(int id, string nom, float p, int s, string date, string spectre)
    void afficherMedInfo()
    void modifierMedInfo(string nom, float prix, int stock, string dateExp,string spectre)
    ~Antibiotique()
    string getSpectre()
    void setSpectre(string spectre)
