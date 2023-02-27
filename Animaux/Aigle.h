//
// Created by theos on 1/23/2023.
//

#ifndef CORRECTION_TP_FEU_AIGLE_H
#define CORRECTION_TP_FEU_AIGLE_H

#include "IAnimal.h"
#include <string>
#include <iostream>

using namespace  std;

class Aigle : public IAnimal {
public:
    Aigle(string name, char sexe, int age);

    void show() override;
    void fedAnimal(Aliment* food) override;
    void resetDaysBeforeFed() override;
private:
    int
    m_joursAvantFaim{10}, // 10 jours
    m_finDeReprod{365 * 14}, // 14 ans
    m_esperanceDeVie{365 * 25}; // 25 ans
    float m_AlimentationJour; // en kg
    int m_maturiteSexuelle{365 * 4}; // 4 ans
    string m_portee;
    int m_gestation;
    float m_mortaliteInfantile;
    string m_remarque{"Fidéle"};
};



#endif //CORRECTION_TP_FEU_AIGLE_H
