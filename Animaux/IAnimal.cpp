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
    switch (type) {
        case 'A':
            switch (m_typeAnimal) {
                case AnimalType::TIGRE:
                    if (m_age > 365 * 14) {
                        // 14 ans
                        return 60000;
                    } else if (m_age > 365 * 4) {
                        // 4 ans
                        return 120000;
                    } else if (m_age > 180) {
                        // 6 mois
                        return 3000;
                    }
                case AnimalType::AIGLE:
                    if (m_age > 365 * 14) {
                        // 14 ans
                        return 2000;
                    } else if (m_age > 365 * 4) {
                        // 4 ans
                        return 4000;
                    } else if (m_age > 180) {
                        // 6 mois
                        return 1000;
                    }
                case AnimalType::POULE:
                    switch (getSexe()) {
                        case 'M':
                            // Coq
                            if (m_age > 180) {
                                // 6 mois
                                return 100;
                            }
                        case 'F':
                            // Poule
                            if (m_age > 180) {
                                // 6 mois
                                return 20;
                            }
                        default:
                            return 0;
                    }

                default:
                    return 0;
            }
        case 'V':
            switch (m_typeAnimal) {
                case AnimalType::TIGRE:
                    if (m_age > 365 * 14) {
                        // 14 ans
                        return 10000;
                    } else if (m_age > 365 * 4) {
                        // 4 ans
                        return 60000;
                    } else if (m_age > 180) {
                        // 6 mois
                        return 1500;
                    }
                case AnimalType::AIGLE:
                    if (m_age > 365 * 14) {
                        // 14 ans
                        return 400;
                    } else if (m_age > 365 * 4) {
                        // 4 ans
                        return 2000;
                    } else if (m_age > 180) {
                        // 6 mois
                        return 500;
                    }
                case AnimalType::POULE:
                    switch (getSexe()) {
                        case 'M':
                            // Coq
                            if (m_age > 180) {
                                // 6 mois
                                return 20;
                            }
                        case 'F':
                            // Poule
                            if (m_age > 180) {
                                // 6 mois
                                return 10;
                            }
                        default:
                            return 0;
                    }

                default:
                    return 0;
            }
        default:
            return 0;
    }
}
