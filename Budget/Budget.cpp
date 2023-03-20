#include "Budget.h"
#include <iostream>

using namespace std;

Budget::Budget(float budget): m_budget(budget){}

void Budget::setBudget(float budget) {
    if (budget < 0) {
        cout << "Vous ne pouvez pas avoir un budget negatif !" << endl;
        return;
    }
    m_budget = budget;
}

float Budget::getBudget() { return m_budget; }

void Budget::addBudget(float budget) {
    if (budget < 0) {
        cout << "Vous ne pouvez pas ajouter une somme negative !" << endl;
        return;
    }
    m_budget += budget;
}

void Budget::removeBudget(float budget) {
    if (budget > m_budget) {
        cout << "Vous ne pouvez pas depenser plus que votre budget !" << endl;
        return;
    }
    if (budget < 0) {
        cout << "Vous ne pouvez pas retirer une somme negative !" << endl;
        return;
    }
    m_budget -= budget;
}


//void Budget::subventionAnnual(Zoo zooLife) {
//    // The Aigle give 2190€ per year and The Tigre give 43800€ per year
//    // create a loop who takes all the tiger
//    // and add 43800€ to the budget
//    //get name of the zoo and add the budget
//    int money;
//    for (auto &h : zooLife.m_enclos) {
//        for (auto &animal : h->m_animaux) {
//            if (animal->getTypeAnimal() == AnimalType::TIGRE) {
//                m_budget += 43800;
//                money += 43800;
//            } else if (animal->getTypeAnimal() == AnimalType::AIGLE) {
//                m_budget += 2190;
//                money += 2190;
//            }
//        }
//    }
//    cout << "Cette année, le zoo " << zooLife.getName() << " a reçu une subvention de " << money << "€" << endl;
//}
//
//int Budget::Variation(double visitors, float percentage_range) {
//    // (+/-) 20% of the base value
//
//    // calculer la plage de variation
//    float variation_range = visitors * percentage_range;
//    float min_value = visitors - variation_range;
//    float max_value = visitors + variation_range;
//
//    // initialiser le générateur de nombres aléatoires
//    srand(time(NULL));
//
//    // générer un nombre aléatoire dans la plage de variation
//    float random_number = ((float)rand() / RAND_MAX) * (max_value - min_value) + min_value;
//
//    int integer_number = (int)random_number;
//
//    return integer_number;
//}
//
//void Budget::visiteurMonthly(Zoo zooLife, string month) {
//    int money;
//    if (month == "JANVIER" || month == "FEVRIER" || month == "MARS" || month == "AVRIL" || month == "OCTOBRE" ||
//        month == "NOVEMBRE" || month == "DECEMBRE") {
//        for (auto &h: zooLife.m_enclos) {
//            for (auto &animal: h->m_animaux) {
//                if (animal->getTypeAnimal() == AnimalType::TIGRE) {
//                    int visitors = Variation(30, 0.2);
//                    m_budget += (visitors / 2) * 17;
//                    m_budget += (visitors / 2) * 13;
//                    money += (visitors / 2) * 17;
//                    money += (visitors / 2) * 13;
//                } else if (animal->getTypeAnimal() == AnimalType::AIGLE) {
//                    int visitors = Variation(15, 0.2);
//                    m_budget += (visitors / 2) * 17;
//                    m_budget += (visitors / 2) * 13;
//                    money += (visitors / 2) * 17;
//                    money += (visitors / 2) * 13;
//                } else if (animal->getTypeAnimal() == AnimalType::POULE) {
//                    int visitors = Variation(2, 0.2);
//                    m_budget += (visitors / 2) * 17;
//                    m_budget += (visitors / 2) * 13;
//                    money += (visitors / 2) * 17;
//                    money += (visitors / 2) * 13;
//                }
//            }
//        }
//    } else if (month == "MAI" || month == "JUILLET" || month == "AOUT" || month == "SEPTEMBRE") {
//        for (auto &h: zooLife.m_enclos) {
//            for (auto &animal: h->m_animaux) {
//                if (animal->getTypeAnimal() == AnimalType::TIGRE) {
//                    int visitors = Variation(5, 0.2);
//                    m_budget += (visitors / 2) * 17;
//                    m_budget += (visitors / 2) * 13;
//                    money += (visitors / 2) * 17;
//                    money += (visitors / 2) * 13;
//                } else if (animal->getTypeAnimal() == AnimalType::AIGLE) {
//                    int visitors = Variation(7, 0.2);
//                    m_budget += (visitors / 2) * 17;
//                    m_budget += (visitors / 2) * 13;
//                    money += (visitors / 2) * 17;
//                    money += (visitors / 2) * 13;
//                } else if (animal->getTypeAnimal() == AnimalType::POULE) {
//                    int visitors = Variation(0.5, 0.2);
//                    m_budget += (visitors / 2) * 17;
//                    m_budget += (visitors / 2) * 13;
//                    money += (visitors / 2) * 17;
//                    money += (visitors / 2) * 13;
//                }
//            }
//        }
//    }
//    cout << "Vous avez gagne " << money << "euros ce mois-ci grâce aux visiteurs" << endl;
//}