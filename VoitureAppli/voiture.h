#ifndef VOITURE_H
#define VOITURE_H
#include <QString>

// On va écrire des tests et au fur et à mesure on remplira la classe voiture

class Voiture
{
public:
    Voiture();
    virtual ~Voiture();
// dans le cadre d'un destructeur le virtual permet d'appeler tous les destructeurs spécialisés quand on fait un delete

    Voiture (QString modele);
// constructeur intermédiaire

    Voiture(QString modele, int kilometrage, int jaugeCarburant); // constructeur complet
// constructeur complet

    Voiture(QString modele, int kilometrage, int jaugeCarburant, QString couleur); // constructeur complet
// constructeur complet

    QString modele() const;
    void setModele(const QString &modele);

    int kilometrage() const;
    void setKilometrage(int kilometrage);

    int jaugeCarburant() const;
    void setJaugeCarburant(int jaugeCarburant);

    QString couleur() const;
    void setCouleur(const QString &couleur);

    void rouler(int kilometre);

    int km() const;
    void setKm(int km);

private:
    QString mModele;
    int mKilometrage;
    int mJaugeCarburant; // en centilitres
    QString mCouleur;
    int mKm;
};

#endif // VOITURE_H
