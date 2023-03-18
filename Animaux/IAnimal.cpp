#include "IAnimal.h"
#include <utility>

IAnimal::IAnimal(string name, char sexe, int age, AnimalType typeAnimal)
        : m_name(name), m_sexe(sexe), m_age(age), m_typeAnimal(typeAnimal) {
    if (sexe != 'M' && sexe != 'F') {
        throw invalid_argument("Le sexe doit être M ou F");
    }
    if (age < 0) {
        throw invalid_argument("L'age doit etre positif");
    }
}



string IAnimal::getName() { return m_name; }

char IAnimal::getSexe() const { return m_sexe; }

int IAnimal::getAge() const { return m_age; }

AnimalType IAnimal::getTypeAnimal() const { return m_typeAnimal; }

float IAnimal::getPrix(char type) const {
    if (m_age <= 180) { // Si l'animal a moins de 6 mois, le prix est toujours 0
        return 0;
    }
    switch (type) {
        case 'A':
            switch (m_typeAnimal) {
                case AnimalType::TIGRE:
                    return (m_age > 365 * 14) ? 60000 : float(((m_age > 365 * 4) ? 120000 : 3000));
                case AnimalType::AIGLE:
                    return (m_age > 365 * 14) ? 2000 : float(((m_age > 365 * 4) ? 4000 : 1000));
                case AnimalType::POULE:
                    if (getSexe() == 'M') { // Coq
                        return (m_age > 180) ? 100 : 0;
                    } else if (getSexe() == 'F') { // Poule
                        return (m_age > 180) ? 20 : 0;
                    } else { // Autre
                        return 0;
                    }
                default:
                    return 0;
            }
        case 'V':
            switch (m_typeAnimal) {
                case AnimalType::TIGRE:
                    return (m_age > 365 * 14) ? 10000 : float(((m_age > 365 * 4) ? 60000 : 1500));
                case AnimalType::AIGLE:
                    return (m_age > 365 * 14) ? 400 : float(((m_age > 365 * 4) ? 2000 : 500));
                case AnimalType::POULE:
                    if (getSexe() == 'M') { // Coq
                        return (m_age > 180) ? 20 : 0;
                    } else if (getSexe() == 'F') { // Poule
                        return (m_age > 180) ? 10 : 0;
                    } else { // Autre
                        return 0;
                    }
                default:
                    return 0;
            }
        default:
            return 0;
    }
}

bool IAnimal::getReproduction() const {
    return m_reproduction;
}

bool IAnimal::getFed() const {
    return m_fed;
}

int IAnimal::getMaladie() const {
    return m_maladie;
}

void IAnimal::setReproduction(bool reproduction) {
    m_reproduction = reproduction;
}

void IAnimal::setFed(bool fed) {
    m_fed = fed;
}

void IAnimal::setAge(int age) {
    m_age = age;
}

void IAnimal::setMaladie(bool maladie) {
    m_maladie = maladie;

}

