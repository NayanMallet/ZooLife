//
// Created by Nayan Mallet on 24/02/2023.
//

#include "Coq.h"
#include "../Functions/functions.h"

Coq::Coq(string name, int age): IAnimal(std::move(name), 'M', age, AnimalType::POULE){};

void Coq::show() {
    printf("-------- %s --------\n"
           "=> Age: %s\n"
           "=> Alimentation: Viande, %.2fkg/j\n"
           "=> Faim: %s\n"
           "=> Reproduction: %s\n" // Reproduction
           "%s"
           "=> Esperance de vie: %s\n"
           "=> Remarque: Fidele\n"
           "---------------------\n",
           getName().c_str(),
           dateConverter(getAge()).c_str(),
           m_AlimentationJour,
           (getFed() ? "Oui" : "Non"),
           (getReproduction() ? "Oui" : "Non"),
           (getMaladie() > 0 ? "=> Maladie: Oui\n" : ""),
           dateConverter(m_esperanceDeVie).c_str()
    );
}

void Coq::resetDaysBeforeFed() { m_joursAvantFaim = 2; }

bool Coq::fedAnimal(Aliment* food) {
    if (food->getFoodType() != FoodType::GRAINES) {
        return true;
    }
    if (food->getQuantite() < m_AlimentationJour) {
        return true;
    }
    food->subQuantite(m_AlimentationJour);
    resetDaysBeforeFed();
    return false;
}

int Coq::getMaturingTime() {
    return m_maturiteSexuelle;
}

void Coq::setMaturingTime(int days) {
    m_maturiteSexuelle = days;
}

void Coq::update(Aliment* food) {
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

FoodType Coq::getFoodType() {
    return FoodType::GRAINES;
}

float Coq::getFoodQuantity() {
    return m_AlimentationJour;
}

int Coq::getGestation() {
    return 0;
}

void Coq::setGestation(int gestation) {
    return;
}

bool Coq::getPortee() {
    return false;
}

void Coq::setPortee(bool portee) {
    return;
}

int Coq::getEndMaturingTime() {
    return m_finDeReprod;
}

Coq::~Coq() {
    setDead(true);
}


