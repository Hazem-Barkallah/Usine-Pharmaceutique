#ifndef MEDICAMENT_H_INCLUDED
#define MEDICAMENT_H_INCLUDED

class Medicament {
    int idMedicament;
    string nomMedicament;
    float prix;
    int stock;
    string dateExpiration;
    vector<Pharmacien*> pharmaciens;
public:
    Medicament(int id, string nom, float prix, int stock, string dateExp)
    Medicament(Pharmacien const& phar);
    int rechercher (string codeEmploye);
    void ajouterPharmacien(Pharmacien* phar);
    void supprimerPharmacien(string codeEmploye);
    void modifierPharmacien(string code, Pharmacien* nouveauPharmacien);
    void afficherPharmacien();
    void afficherMedInfo()
    virtual void modifierMedInfo(string nom, float prix, int stock, string dateExp)
    virtual ~Medicament()
    void setIdMedicament(int id)
    string getNomMedicament()
    void setNomMedicament(string nom)
    float getPrixMedicament()
    void setPrixdMedicament(float prix)
    int getStockMedicament()
    void setStockdMedicament(int stock)
    string getDateExpiration()
     void setDateExpiration(string dateExpiration)
     virtual bool estEnStock()
     virtual void miseAJourStock(int quantite)
     bool estPerime(string dateActuelle)



#endif // MEDICAMENT_H_INCLUDED
