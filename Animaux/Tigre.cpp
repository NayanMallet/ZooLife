//
// Created by theos on 1/23/2023.
//

#include "Tigre.h"
#include "../Functions/functions.h"

#include <utility>

Tigre::Tigre(string name, char sexe, int age): IAnimal(std::move(name), sexe, age, AnimalType::TIGRE) {
    if (sexe == 'M') {
        m_AlimentationJour = 12;
        m_maturiteSexuelle = (365*6); // 6 ans
    } else if (sexe == 'F') {
        m_AlimentationJour = 10;
        m_maturiteSexuelle = (365*4); // 4 ans
        m_portee = "3 individus par portée / max 1 portée tous les 20 mois";
        m_gestation = (30*3); // 3 mois
        m_mortaliteInfantile = 33.33;
    } else {
        return;
    }
};


void Tigre::show() {
    if (getSexe() == 'M') {
        printf("----- %s (%c) -----\n"
               "=> Age: %s\n"
               "=> Alimentation: Viande, %.2fkg/j\n"
               "=> Jours avant faim: %s\n"
               "=> Fin de reproduction: %s\n"
               "=> Espérance de vie: %s\n"
               "=> Maturité sexuelle: %s\n"
               "---------------------\n",
               getName().c_str(), getSexe(),
               dateConverter(getAge()).c_str(),
               m_AlimentationJour,
               dateConverter(m_joursAvantFaim).c_str(),
               dateConverter(m_finDeReprod).c_str(),
               dateConverter(m_esperanceDeVie).c_str(),
               dateConverter(m_maturiteSexuelle).c_str()
        );
    } else if (getSexe() == 'F') {
        printf("----- %s (%c) -----\n"
               "=> Age: %s\n"
               "=> Alimentation: Viande, %.2fkg/j\n"
               "=> Jours avant faim: %s\n"
               "=> Fin de reproduction: %s\n"
               "=> Espérance de vie: %s\n"
               "=> Maturité sexuelle: %s\n"
               "=> Ponte / portée: %s\n"
               "=> Gestation: %s\n"
               "=> Mortalité infantile: %.2f%%\n"
               "---------------------\n",
               getName().c_str(), getSexe(),
               dateConverter(getAge()).c_str(),
               m_AlimentationJour,
               dateConverter(m_joursAvantFaim).c_str(),
               dateConverter(m_finDeReprod).c_str(),
               dateConverter(m_esperanceDeVie).c_str(),
               dateConverter(m_maturiteSexuelle).c_str(),
               m_portee.c_str(),
               dateConverter(m_gestation).c_str(),
               m_mortaliteInfantile
        );
    } else {
        printf("Tigre '%s'=> Error !", getName().c_str());
    }
}

void Tigre::resetDaysBeforeFed() { m_joursAvantFaim = 2; }


void Tigre::fedAnimal(Aliment* food) {
    if (food->getFoodType() != FoodType::VIANDE) {
        cout << food->getNom() << " ne conviens pas a " << getName() << " !" << endl;
        return;
    }
    if (food->getQuantite() < m_AlimentationJour) {
        cout << "Pas assez d'aliment pour nourrir " << getName() << endl;
        return;
    }
    food->subQuantite(m_AlimentationJour);
    resetDaysBeforeFed();
    //
    cout << "L'animal " << getName() << " a été nourri avec succès !" << endl;
    //
}