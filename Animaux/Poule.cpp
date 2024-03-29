#include "Poule.h"
#include "../Functions/functions.h"
#include <iostream>
#include <utility>

using namespace std;

Poule::Poule(string name, int age): IAnimal(std::move(name), 'F', age, AnimalType::POULE){};


void Poule::show() {
    printf("------- %s -------\n"
           "=> Age: %s\n"
           "=> Alimentation: Viande, %.2fkg/j\n"
           "=> Faim: %s\n"
           "=> Reproduction: %s\n" // Reproduction
           "%s"
           "=> Esperance de vie: %s\n"
           "=> Ponte: %s\n"
           "=> Gestation: %s\n"
           "=> Mortalité infantile: %.2f%%\n"
           "=> Remarque: Fidele\n"
           "---------------------\n",
           getName().c_str(),
           dateConverter(getAge()).c_str(),
           m_AlimentationJour,
           (getFed() ? "Oui" : "Non"),
           (getReproduction() ? "Oui" : "Non"),
           (getMaladie() > 0 ? "=> Maladie: Oui\n" : ""),
           dateConverter(m_esperanceDeVie).c_str(),
           (m_portee ? "Oui" : "Non"),
           dateConverter(m_gestation).c_str(),
           m_mortaliteInfantile
    );
}


//
//void Poule::show() {
//    printf("----- %s (%c) -----\n"
//           "=> Age: %s\n"
//           "=> Alimentation: Graines, %.2fkg/j\n"
//           "=> Jours avant faim: %s\n"
//           "=> Fin de reproduction: %s\n"
//           "=> Esperance de vie: %s\n"
//           "=> Maturite sexuelle: %s\n"
//           "=> Ponte / portée: %s\n"
//           "=> Gestation: %s\n"
//           "=> Mortalité infantile: %.2f%%\n"
//           "---------------------\n",
//           getName().c_str(), getSexe(),
//           dateConverter(getAge()).c_str(),
//           m_AlimentationJour,
//           dateConverter(m_joursAvantFaim).c_str(),
//           dateConverter(m_finDeReprod).c_str(),
//           dateConverter(m_esperanceDeVie).c_str(),
//           dateConverter(m_maturiteSexuelle).c_str(),
//           (m_portee ? "Oui" : "Non"),
//           dateConverter(m_gestation).c_str(),
//           m_mortaliteInfantile
//    );
//}

void Poule::resetDaysBeforeFed() { m_joursAvantFaim = 1; }

bool Poule::fedAnimal(Aliment* food) {
    if (food->getFoodType() != FoodType::GRAINES) {
        return true;
    }
    float alim = (getGestation() > 0 ? m_AlimentationJour * 2 : m_AlimentationJour);

    if (food->getQuantite() < alim) {
        return true;
    }
    food->subQuantite(alim);
    resetDaysBeforeFed();
    return false;
}

int Poule::getMaturingTime() {
    return m_maturiteSexuelle;
}

void Poule::setMaturingTime(int days) {
    m_maturiteSexuelle = days;
}

void Poule::update(Aliment* food) {
    m_joursAvantFaim--;
    setAge(getAge() + 1);
    if (getMaladie() > 0) {
        setMaladie(getMaladie() - 1);
    }

    // update de la faim
    if (m_joursAvantFaim == 0) {
        bool result = fedAnimal(food);
        setFed(result);
    }

    if (getAge() == m_esperanceDeVie || m_joursAvantFaim < 0) {
        setDead(true);
        return;
    }
}

FoodType Poule::getFoodType() {
    return FoodType::GRAINES;
}

float Poule::getFoodQuantity() {
    return m_AlimentationJour;
}

bool Poule::getPortee() {
    return m_portee;
}

void Poule::setPortee(bool portee) {
    m_portee = portee;
}

int Poule::getGestation() {
    return m_gestation;
}

void Poule::setGestation(int gestation) {
    m_gestation = gestation;

}

int Poule::getEndMaturingTime() {
    return m_finDeReprod;
}

Poule::~Poule() {
    setDead(true);
}
