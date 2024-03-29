#include "Aigle.h"

#include <utility>
#include "../Functions/functions.h"

Aigle::Aigle(string name, char sexe, int age): IAnimal(std::move(name), sexe, age, AnimalType::AIGLE){
    if (sexe == 'M') {
        m_AlimentationJour = 0.25;
    } else if (sexe == 'F') {
        m_AlimentationJour = 0.3;
        m_mortaliteInfantile = 50;
    } else {
        return;
    }
};

void Aigle::show() {
    if (getSexe() == 'M') {
        printf("----- %s ------\n"
               "=> Age: %s\n"
               "=> Alimentation: Viande, %.2fkg/j\n"
               "=> Faim: %s\n"
               "=> Reproduction: %s\n"  // Reproduction
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
    } else if (getSexe() == 'F') {
        printf("----- %s ------\n"
               "=> Age: %s\n"
               "=> Alimentation: Viande, %.2fkg/j\n"
               "=> Faim: %s\n"
               "=> Reproduction: %s\n" // Reproduction
               "%s"
               "=> Esperance de vie: %s\n"
               "=> Ponte: %s\n"
               "=> Gestation: %s\n"
               "=> Mortalite infantile: %.2f%%\n"
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
    } else {
        printf("Aigle '%s'=> Error !", getName().c_str());
    }
}

void Aigle::resetDaysBeforeFed() { m_joursAvantFaim = 10; }


bool Aigle::fedAnimal(Aliment* food) {
    if (food->getFoodType() != FoodType::VIANDE) {
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

int Aigle::getMaturingTime() {
    return m_maturiteSexuelle;
}

void Aigle::setMaturingTime(int days) {
    m_maturiteSexuelle = days;
}

void Aigle::update(Aliment* food) {
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

FoodType Aigle::getFoodType() {
    return FoodType::VIANDE;
}

float Aigle::getFoodQuantity() {
    return m_AlimentationJour;
}

bool Aigle::getPortee() {
    return m_portee;
}

void Aigle::setPortee(bool portee) {
    m_portee = portee;
}

int Aigle::getGestation() {
    return m_gestation;
}

void Aigle::setGestation(int gestation) {
    m_gestation = gestation;
}

int Aigle::getEndMaturingTime() {
    return m_finDeReprod;
}

Aigle::~Aigle() {
    setDead(true);
}
