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
