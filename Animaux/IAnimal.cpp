#include "IAnimal.h"
#include <utility>

IAnimal::IAnimal(string name, char sexe, int age, const string& typeAnimal)
: m_name(name), m_sexe(sexe), m_age(age), m_typeAnimal(typeAnimal) {
    if (sexe != 'M' && sexe != 'F') {
        throw invalid_argument("Le sexe doit être M ou F");
    }
    if (age < 0) {
        throw invalid_argument("L'age doit être positif");
    }
    if (typeAnimal != "tigre" && typeAnimal != "aigle" && typeAnimal != "poule" && typeAnimal != "coq") {
        throw invalid_argument("Le type d'animal doit être tigre, aigle, poule ou coq");
    }
}

string IAnimal::getName() { return m_name; };

char IAnimal::getSexe() const { return m_sexe; };

int IAnimal::getAge() const { return m_age; };

const string& IAnimal::getTypeAnimal() const { return m_typeAnimal; };