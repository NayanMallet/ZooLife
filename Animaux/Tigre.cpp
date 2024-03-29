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
        m_mortaliteInfantile = 33.33;
    } else {
        return;
    }
};

void Tigre::show() {
    if (getSexe() == 'M') {
        printf("----- %s -----\n"
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
    } else if (getSexe() == 'F') {
        printf("----- %s -----\n"
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

void Tigre::resetDaysBeforeFed() { m_joursAvantFaim = 2; }


bool Tigre::fedAnimal(Aliment* food) {
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

int Tigre::getMaturingTime() {
    return m_maturiteSexuelle;
}

void Tigre::setMaturingTime(int days) {
    m_maturiteSexuelle = days;
}

void Tigre::update(Aliment* food) {
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

FoodType Tigre::getFoodType() {
    return FoodType::VIANDE;
}

float Tigre::getFoodQuantity() {
    return m_AlimentationJour;
}

bool Tigre::getPortee() {
    return m_portee;
}

void Tigre::setPortee(bool portee) {
    m_portee = portee;
}

int Tigre::getGestation() {
    return m_gestation;
}

void Tigre::setGestation(int gestation) {
    m_gestation = gestation;

}

int Tigre::getEndMaturingTime() {
    return m_finDeReprod;
}

Tigre::~Tigre() {
    setDead(true);
}
