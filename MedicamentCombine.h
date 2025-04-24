#ifndef MEDICAMENTCOMBINE_H_INCLUDED
#define MEDICAMENTCOMBINE_H_INCLUDED
class MedicamentCombine :public Antibiotique, public AntiInflammatoire {
    int nbPrincipesActifs;
    string* principesActifs;
public:
    MedicamentCombine(int id, string nom, float p, int s, string date, string spectre, bool steroidien,int nb)
    void ajouterPA(string principeActif);
    void supprimerPA(string principeActif);
    void modifierPA(string ancienPA, string nouveauPA);
    void afficherPA();
     void modifierMedInfo(int id, string nom, float p, int s, string date, string spectre, bool steroidien)
     void afficherMedInfo()
     virtual ~MedicamentCombine()


#endif // MEDICAMENTCOMBINE_H_INCLUDED
