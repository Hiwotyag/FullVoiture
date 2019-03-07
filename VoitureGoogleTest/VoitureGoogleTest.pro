include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread

HEADERS += \
    tst_testvoitureconstructor.h \
    tst_testvoitureroule.h

SOURCES += \
        main.cpp

include(../VoitureAppli/voiture.pri)
#remonte d'un cran et redescend dans voiture.pri

INCLUDEPATH+=../VoitureAppli
