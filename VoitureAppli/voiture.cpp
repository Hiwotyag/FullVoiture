#include "voiture.h"

Voiture::Voiture():Voiture("",0,0)
{

}

Voiture::~Voiture()
{

}

Voiture::Voiture(QString modele):
    Voiture(modele,0,0)
// on force l'initialisation des cases en mémoire
{

}

Voiture::Voiture(QString modele, int kilometrage, int jaugeCarburant):
    mModele(modele), mKilometrage(kilometrage), mJaugeCarburant(jaugeCarburant)
// nom de l'attribut et ce par quoi on l'appelle
{

}

Voiture::Voiture(QString modele, int kilometrage, int jaugeCarburant, QString couleur):
    mModele(modele), mKilometrage(kilometrage), mJaugeCarburant(jaugeCarburant), mCouleur(couleur)
{

}

QString Voiture::modele() const
{
    return mModele;
}

void Voiture::setModele(const QString &modele)
{
    mModele = modele;
}

int Voiture::kilometrage() const
{
    return mKilometrage;
}

void Voiture::setKilometrage(int kilometrage)
{
    mKilometrage = kilometrage;
}

int Voiture::jaugeCarburant() const
{
    return mJaugeCarburant;
}

void Voiture::setJaugeCarburant(int jaugeCarburant)
{
    mJaugeCarburant = jaugeCarburant;
}

QString Voiture::couleur() const
{
    return mCouleur;
}

void Voiture::setCouleur(const QString &couleur)
{
    mCouleur = couleur;
}

void Voiture::rouler(int km)
{
    // la méthode n'est pas encore écrite. C'est pour ça que nos test échoue.
    // on a fait en sorte que ça échoue avec throw std::invalid_argument("pas assez d'essence");
    // if precondition pas verifiee
    // throw std::invalid_argument("pas assez d'essence");
    // throw fait dérailler pour gérer une exception

    int conso = (kilometrage()<150000) ? km * 5 : km * 10;
    // Si conso <150 000 alors distance *5, sinon distance *10
    if(conso > jaugeCarburant())
    {
         throw std::invalid_argument("pas assez d'essance");
    }
    else
    {
        setKilometrage(kilometrage()+ km);
        setJaugeCarburant(jaugeCarburant()-conso);
    }
}

int Voiture::km() const
{
    return mKm;
}

void Voiture::setKm(int km)
{
    mKm = km;
}
