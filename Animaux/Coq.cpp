//
// Created by Nayan Mallet on 24/02/2023.
//

#include "Coq.h"
#include "../Functions/functions.h"

Coq::Coq(string name, int age): IAnimal(std::move(name), 'M', age, AnimalType::POULE){};

void Coq::show() {
    printf("----- %s (%c) -----\n"
           "=> Age: %s\n"
           "=> Alimentation: Graines, %.2fkg/j\n"
           "=> Jours avant faim: %s\n"
           "=> Fin de reproduction: %s\n"
           "=> Espérance de vie: %s\n"
           "=> Maturité sexuelle: %s\n"
           "---------------------\n",
           getName().c_str(), getSexe(),
           dateConverter(getAge()).c_str(),
           m_AlimentationJour,
           dateConverter(m_joursAvantFaim).c_str(),
           dateConverter(m_finDeReprod).c_str(),
           dateConverter(m_esperanceDeVie).c_str(),
           dateConverter(m_maturiteSexuelle).c_str()
    );
}

void Coq::resetDaysBeforeFed() { m_joursAvantFaim = 2; }

void Coq::fedAnimal(Aliment* food) {
    if (food->getFoodType() != FoodType::GRAINES) {
        cout << food->getNom() << " ne conviens pas a " << getName() << " !" << endl;
        return;
    }
    if (food->getQuantite() < m_AlimentationJour) {
        cout << "Pas assez d'aliment pour nourrir " << getName() << endl;
        return;
    }
    food->subQuantite(m_AlimentationJour);
    resetDaysBeforeFed();
    //
    cout << "L'animal " << getName() << " a été nourri avec succès !" << endl;
    //
}