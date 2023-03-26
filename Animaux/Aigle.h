#ifndef CORRECTION_TP_FEU_AIGLE_H
#define CORRECTION_TP_FEU_AIGLE_H

#include "IAnimal.h"
#include <string>
#include <iostream>

using namespace  std;

class Aigle : public IAnimal {
public:
    Aigle(string name, char sexe, int age);
    ~Aigle() override;

    void show() override;
    bool fedAnimal(Aliment* food) override;
    void resetDaysBeforeFed() override;
    void update(Aliment* food) override;
    int getMaturingTime() override;
    int getEndMaturingTime() override;
    FoodType getFoodType() override;
    float getFoodQuantity() override;
    bool getPortee() override;
    void setPortee(bool portee) override;
    int getGestation() override;
    void setGestation(int gestation) override;

    void setMaturingTime(int days) override;

private:
    int
            m_joursAvantFaim{10}, // 10 jours
    m_finDeReprod{365 * 14}, // 14 ans
    m_esperanceDeVie{365 * 25}; // 25 ans
    float m_AlimentationJour; // en kg
    int m_maturiteSexuelle{365 * 4}; // 4 ans
    bool m_portee{false};
    int m_gestation{0};
    float m_mortaliteInfantile;
    string m_remarque{"Fidéle"};
};



#endif //CORRECTION_TP_FEU_AIGLE_H
