#pragma once    // autre façon de gérer les if &def

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
// #include <gmock/gmock-matchers.h> est un ensemble de macro pour fabriquer des tests plus ou moins compliqués
// Pour faire des tests unitaires on test des blocks.
// Pour pouvoir tester un ensemble on va créer des mocks, i.e une simulation des blocks de programme.
#include "voiture.h"

using namespace testing;

TEST(TestVoitureConstructor, Default)
// nous fabrique une classe de test
// default est un setname
// le couple TestVoitureConstructor, Default doit être unique
// je peux avoir autant de TestVoitureConstructor du moment que le label (ex.default) soit différent
{
    Voiture voiture;
    EXPECT_EQ(voiture.modele(),"");
    EXPECT_EQ(voiture.kilometrage(), 0);        // expectations. Quelque soit le scénario, le test continu et les erreurs sont loggées.
    // je vérifie que mon kilométrage est bien égal à 0.
    EXPECT_EQ(voiture.jaugeCarburant(), 0);

    ASSERT_THAT(0, Eq(0));  // assertions. Si une assertion n'est pas vérifiée ça arrête le test.
}

TEST(TestVoitureConstructor, Complet)
// nous fabrique une classe de test
// le couple TestVoitureConstructor, Default doit être unique
// je peux avoir autant de TestVoitureConstructor du moment que le label (ex.default) soit différent
{
    QString modele = "Ferrari F40";
    int km = 20000;
    int jauge = 5000;
    Voiture voiture(modele, km, jauge);
    EXPECT_EQ(voiture.modele(), modele);
    // Pour les chaines de caractères on doit utiliser EXPECT_STREQ(voiture.modele(), modele);
    // == par défaut les opérateurs sur les objets comparent les adresse mémoire. Pour QString ils comparent le contenu.
    // faire attention ici au QString
    EXPECT_EQ(voiture.kilometrage(), km);        // expectations. Quelque soit le scénario, le test continu et les erreurs sont loggées.
    // je vérifie que mon kilométrage est bien égal à 0.
    EXPECT_EQ(voiture.jaugeCarburant(), jauge);
    // il existe un EXPECT_DOUBLE_EQ spécifique pour les doubles

    // ASSERT_THAT(0, Eq(0));  // assertions. Si une assertion n'est pas vérifiée ça arrête le test.
}

