#include "Aigle.h"

#include <utility>
#include "../Functions/functions.h"

Aigle::Aigle(string name, char sexe, int age): IAnimal(std::move(name), sexe, age, AnimalType::AIGLE){
    if (sexe == 'M') {
        m_AlimentationJour = 0.25;
    } else if (sexe == 'F') {
        m_AlimentationJour = 0.3;
        m_portee = "2 oeuf en Mars";
        m_gestation = (45); // 45 jours
        m_mortaliteInfantile = 50;
    } else {
        return;
    }
};

void Aigle::show() {
    if (getSexe() == 'M') {
        printf("----- %s (%c) -----\n"
               "=> Age: %s\n"
               "=> Alimentation: Viande, %.2fkg/j\n"
               "=> Jours avant faim: %s\n"
               "=> Fin de reproduction: %s\n"
               "=> Esperance de vie: %s\n"
               "=> Maturite sexuelle: %s\n"
               "=> Remarque: Fidele\n"
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
               "=> Esperance de vie: %s\n"
               "=> Maturite sexuelle: %s\n"
               "=> Ponte / portee: %s\n"
               "=> Gestation: %s\n"
               "=> Mortalité infantile: %.2f%%\n"
               "=> Remarque: Fidele\n"
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
        printf("Aigle '%s'=> Error !", getName().c_str());
    }
}

void Aigle::resetDaysBeforeFed() { m_joursAvantFaim = 10; }


bool Aigle::fedAnimal(Aliment* food) {
    if (food->getFoodType() != FoodType::VIANDE) {
        return true;
    }
    if (food->getQuantite() < m_AlimentationJour) {
        return true;
    }
    food->subQuantite(m_AlimentationJour);
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

    // update de la faim
    if (m_joursAvantFaim == 0) {
        setFed(fedAnimal(food));
    }

    // update de la reproduction
    if ((m_maturiteSexuelle <= getAge() <= m_finDeReprod) && !getMaladie() && getFed()) {
        setReproduction(true);
    } else {
        setReproduction(false);
    }

    if (getAge() == m_esperanceDeVie) {
        cout << getName() << " est mort de vieillesse !" << endl;
        Aigle::~Aigle();
        return;
    }
}

FoodType Aigle::getFoodType() {
    return FoodType::VIANDE;
}

float Aigle::getFoodQuantity() {
    return m_AlimentationJour;
}
