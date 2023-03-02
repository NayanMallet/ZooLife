#include "Poule.h"
#include "../Functions/functions.h"
#include <iostream>
#include <utility>

using namespace std;

Poule::Poule(string name, int age): IAnimal(std::move(name), 'F', age, AnimalType::POULE){};

void Poule::show() {
    printf("----- %s (%c) -----\n"
           "=> Age: %s\n"
           "=> Alimentation: Graines, %.2fkg/j\n"
           "=> Jours avant faim: %s\n"
           "=> Fin de reproduction: %s\n"
           "=> Esperance de vie: %s\n"
           "=> Maturite sexuelle: %s\n"
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
}

void Poule::resetDaysBeforeFed() { m_joursAvantFaim = 1; }

void Poule::fedAnimal(Aliment* food) {
    if (food->getFoodType() != FoodType::GRAINES) {
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
    cout << "L'animal " << getName() << " a ete nourri avec succes !" << endl;
    //
}