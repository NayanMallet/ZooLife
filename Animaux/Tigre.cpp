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
        printf("----- %s (%c) -----\n"
               "=> Age: %s\n"
               "=> Alimentation: Viande, %.2fkg/j\n"
               "=> Jours avant faim: %s\n"
               "=> Reproduction: %s\n" // Reproduction
               "=> Esperance de vie: %s\n"
               "=> Remarque: Fidele\n"
               "---------------------\n",
               getName().c_str(), getSexe(),
               dateConverter(getAge()).c_str(),
               m_AlimentationJour,
               dateConverter(m_joursAvantFaim).c_str(),
               (getReproduction() ? "Oui" : "Non"),
               dateConverter(m_esperanceDeVie).c_str()
        );
    } else if (getSexe() == 'F') {
        printf("----- %s (%c) -----\n"
               "=> Age: %s\n"
               "=> Alimentation: Viande, %.2fkg/j\n"
               "=> Jours avant faim: %s\n"
               "=> Reproduction: %s\n" // Reproduction
               "=> Esperance de vie: %s\n"
               "=> Ponte: %s\n"
               "=> Gestation: %s\n"
               "=> Mortalité infantile: %.2f%%\n"
               "=> Remarque: Fidele\n"
               "---------------------\n",
               getName().c_str(), getSexe(),
               dateConverter(getAge()).c_str(),
               m_AlimentationJour,
               dateConverter(m_joursAvantFaim).c_str(),
               (getReproduction() ? "Oui" : "Non"),
               dateConverter(m_esperanceDeVie).c_str(),
               (m_portee ? "Oui" : "Non"),
               dateConverter(m_gestation).c_str(),
               m_mortaliteInfantile
        );
    } else {
        printf("Aigle '%s'=> Error !", getName().c_str());
    }
}

//void Tigre::show() {
//    if (getSexe() == 'M') {
//        printf("----- %s (%c) -----\n"
//               "=> Age: %s\n"
//               "=> Alimentation: Viande, %.2fkg/j\n"
//               "=> Jours avant faim: %s\n"
//               "=> Fin de reproduction: %s\n"
//               "=> Esperance de vie: %s\n"
//               "=> Maturité sexuelle: %s\n"
//               "---------------------\n",
//               getName().c_str(), getSexe(),
//               dateConverter(getAge()).c_str(),
//               m_AlimentationJour,
//               dateConverter(m_joursAvantFaim).c_str(),
//               dateConverter(m_finDeReprod).c_str(),
//               dateConverter(m_esperanceDeVie).c_str(),
//               dateConverter(m_maturiteSexuelle).c_str()
//        );
//    } else if (getSexe() == 'F') {
//        printf("----- %s (%c) -----\n"
//               "=> Age: %s\n"
//               "=> Alimentation: Viande, %.2fkg/j\n"
//               "=> Jours avant faim: %s\n"
//               "=> Fin de reproduction: %s\n"
//               "=> Esperance de vie: %s\n"
//               "=> Maturité sexuelle: %s\n"
//               "=> Ponte / portée: %s\n"
//               "=> Gestation: %s\n"
//               "=> Mortalité infantile: %.2f%%\n"
//               "---------------------\n",
//               getName().c_str(), getSexe(),
//               dateConverter(getAge()).c_str(),
//               m_AlimentationJour,
//               dateConverter(m_joursAvantFaim).c_str(),
//               dateConverter(m_finDeReprod).c_str(),
//               dateConverter(m_esperanceDeVie).c_str(),
//               dateConverter(m_maturiteSexuelle).c_str(),
//               (m_portee ? "Oui" : "Non"),
//               dateConverter(m_gestation).c_str(),
//               m_mortaliteInfantile
//        );
//    } else {
//        printf("Tigre '%s'=> Error !", getName().c_str());
//    }
//}

void Tigre::resetDaysBeforeFed() { m_joursAvantFaim = 2; }


bool Tigre::fedAnimal(Aliment* food) {
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
        setFed(fedAnimal(food));
    }

//    if (getAge() == m_esperanceDeVie || m_joursAvantFaim < 0) {
    if (getAge() == m_esperanceDeVie) {
        cout << getName() << " est mort !" << endl;
        Tigre::~Tigre();
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
