#pragma once    // autre façon de gérer les if &def

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
// #include <gmock/gmock-matchers.h> est un ensemble de macro pour fabriquer des tests plus ou moins compliqués
// Pour faire des tests unitaires on test des blocks.
// Pour pouvoir tester un ensemble on va créer des mocks, i.e une simulation des blocks de programme.
#include "voiture.h"
#include <QDebug>

using namespace testing;

TEST(TestVoitureRouler, OldCar)
//OldCar est ce que l'on appel un set name
{

    int kmStart = 160000;
    int jaugeStart = 1500;
    Voiture voiture("Ferrari F40", kmStart, jaugeStart);
    int distance = 100;

    //when
    voiture.rouler(distance);
    EXPECT_EQ(voiture.kilometrage(), kmStart + distance) << "kilometrage incorrect";        // expectations. Quelque soit le scénario, le test continu et les erreurs sont loggées.
    // je vérifie que mon kilométrage est bien égal à 0.
    EXPECT_EQ(voiture.jaugeCarburant(), jaugeStart - distance *10) << "Jauge Carburant incorrecte";

    // ASSERT_THAT(0, Eq(0));  // assertions. Si une assertion n'est pas vérifiée ça arrête le test.
}

TEST(TestVoitureRouler, NewCar)
{

    int kmStart = 10000;
    int jaugeStart = 1500;
    Voiture voiture("Ferrari F40", kmStart, jaugeStart);
    int distance = 100;

    //when
    voiture.rouler(distance);
    EXPECT_THAT(voiture.kilometrage(), Eq(kmStart + distance)) << "kilometrage incorrect";        // expectations. Quelque soit le scénario, le test continu et les erreurs sont loggées.
    // je vérifie que mon kilométrage est bien égal à 0.
    // On confronte une valeur à un matcher
    // Les matchers sont des éléments de tests déjà définis utilisés pour des expressions plus complexes que EXPECT_EQ.
    // EQ est un matcher
    EXPECT_THAT(voiture.jaugeCarburant(), Eq(jaugeStart - distance *5)) << "Jauge Carburant incorrecte";
    // EXPECT_THAT on prend une prend une valeur et on le compare avec un matcher sur une valeur de mm type
    // EXPECT_EQ compare toujours 2 types similaires

    // ASSERT_THAT(0, Eq(0));  // assertions. Si une assertion n'est pas vérifiée ça arrête le test.
}


TEST(TestVoitureRouler, RoulerImpossible)
// Faire exprès de déclencher une erreur pour voir que le code est bien protégé en déclenchant des cas d'erreur
// ce test doit échouer pour être valide
{
    int kmStart = 160000;
    int jaugeStart = 1500;
    Voiture voiture("Ferrari F40", kmStart, jaugeStart);
    int distance = 200; // trop de km par rapport au niveau de la jauge

    //when
    EXPECT_THROW(
                voiture.rouler(distance), // on déclenche de rouler et on lui demande en mm temps de vérifier le type d'exception
                std::invalid_argument);// ce à quoi je m'attend
// on met le std parce qu'on n'a pas défini namespace std
// EXPECT_THROW gère des scénarios d'erreur avec le résultat qui est attendu
}



/* ------------------PARAMETRES----------------------*/



class TestVoitureRecenteRouler:public TestWithParam<int>
// Comment faire pour jouer plusieurs fois ce test sur des valeurs différente ?
// 1- Créer la classe et la faire hériter de public TestWithParam<int>
// 2- Instancier les valeurs du range
// 3- Ecrire le test
{

};

TEST_P(TestVoitureRecenteRouler, Range) // Test_p est un test avec paramètres
{
    int kmStart = GetParam();
    int jaugeStart = 500;
    Voiture voiture("Ferrari F40", kmStart, jaugeStart);
    int distance = 100;

    //when
    voiture.rouler(distance);
    EXPECT_THAT(voiture.kilometrage(), Eq(kmStart + distance)) << "kilometrage incorrect";        // expectations. Quelque soit le scénario, le test continu et les erreurs sont loggées.
    // je vérifie que mon kilométrage est bien égal à 0.
    // On confronte une valeur à un matcher
    // Les matchers sont des éléments de tests déjà définis utilisés pour des expressions plus complexes que EXPECT_EQ.
    // EQ est un matcher
    EXPECT_THAT(voiture.jaugeCarburant(), Eq(jaugeStart - distance *5)) << "Jauge Carburant incorrecte";
    // EXPECT_THAT on prend une prend une valeur et on le compare avec un matcher sur une valeur de mm type
    // EXPECT_EQ compare toujours 2 types similaires

    // ASSERT_THAT(0, Eq(0));  // assertions. Si une assertion n'est pas vérifiée ça arrête le test.
}

INSTANTIATE_TEST_SUITE_P(GroupeVoitureRecente,
                         TestVoitureRecenteRouler,
                         Range (0, 150000,10000) //Values(0,10000,149999,150000,150001)
                         );
// Premier label doit être le nom de tout les test
// Deuxième label doit être le nom du test (donc classe)
// Troisième label défini les valeurs
// 'Values' permet de tester des valeurs précises (0,10000,149999,150000,150001)
// On peut aussi metre 'Range' (min, max, pas) qui défini une V de départ une valeur d'arriver en sautant le pas
// Range (0, 150000,10000) va de 0 à 150000 en allant de (avec un pas de) 10000 à 10000



/* ------------------FIXTURE----------------------*/



// 1- Créer la classe et la faire hériter de public Test
class TestOldVoitureRouler:public Test // on fait les fixture
{
protected:
    int kmStart;
    int jaugeStart;
    Voiture oldCar;

    void SetUp() override // permet d'initialiser les variables
    {
        kmStart = 160000;
        jaugeStart = 1500;
        oldCar.setKilometrage(kmStart);
        oldCar.setJaugeCarburant(jaugeStart);
        oldCar.setModele("Ford Mustang 1967");
    }

    void TearDown() override {qDebug()<<"Do some cleaning";}
};

TEST_F(TestOldVoitureRouler, OK) // Test_f est un test avec fixture
{
    //given
    int distance = 100;

    //when
    oldCar.rouler(distance);
    EXPECT_EQ(oldCar.kilometrage(), kmStart + distance) << "kilometrage incorrect";        // expectations. Quelque soit le scénario, le test continu et les erreurs sont loggées.
    // je vérifie que mon kilométrage est bien égal à 0.
    EXPECT_EQ(oldCar.jaugeCarburant(),jaugeStart - distance *10) << "Jauge Carburant incorrecte";
    // EXPECT_THAT on prend une prend une valeur et on le compare avec un matcher sur une valeur de mm type
    // EXPECT_EQ compare toujours 2 types similaires
}

TEST_F(TestOldVoitureRouler, NoGaz) // Test_f est un test avec fixture
{
    //given
    int distance = 200;

    //when
    oldCar.rouler(distance);
    EXPECT_THROW(oldCar.rouler(distance), std::invalid_argument);
    EXPECT_THAT(oldCar.kilometrage(), Eq(kmStart));
    EXPECT_THAT(oldCar.jaugeCarburant(), Eq(jaugeStart));
}


