//
// Created by Nayan Mallet on 27/02/2023.
//

#include "Budget.h"
#include <iostream>

using namespace std;

Budget::Budget(int budget): m_budget(budget){}

void Budget::setBudget(int budget) {
    if (budget < 0) {
        cout << "Vous ne pouvez pas avoir un budget negatif !" << endl;
        return;
    }
    m_budget = budget;
}

int Budget::getBudget() { return m_budget; }

void Budget::addBudget(int budget) {
    if (budget < 0) {
        cout << "Vous ne pouvez pas ajouter une somme negative !" << endl;
        return;
    }
    m_budget = budget;
}

void Budget::removeBudget(int budget) {
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
