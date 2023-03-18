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
