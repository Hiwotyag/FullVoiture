#pragma once    // autre façon de gérer les if &def

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
// #include <gmock/gmock-matchers.h> est un ensemble de macro pour fabriquer des tests plus ou moins compliqués
// Pour faire des tests unitaires on test des blocks.
// Pour pouvoir tester un ensemble on va créer des mocks, i.e une simulation des blocks de programme.
#include "pilote.h"
#include <QDebug>

using namespace testing;

TEST(TestPiloteConstructor, Default)
//Default est ce que l'on appel un set name
{
    Pilote pilote;
    //todo
    ASSERT_TRUE(false);
}
