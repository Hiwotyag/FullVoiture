#include <QCoreApplication>
#include <QDebug>

#include "voiture.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"Welcome to Voiture Application";
    Voiture oldCar("Ford Mustang 1967", 160000, 500);
    qDebug()<<"My car:" << oldCar.modele();
    return a.exec();
}
