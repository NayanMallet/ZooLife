#ifndef CORRECTION_TP_FEU_TIGER_H
#define CORRECTION_TP_FEU_TIGER_H

#include "IAnimal.h"
#include "../Aliments/Aliment.h"
#include <string>

using namespace  std;

class Tigre : public IAnimal {
public:
    Tigre(string name, char sexe, int age);
    ~Tigre() override = default;

    void show() override;
    bool fedAnimal(Aliment* food) override;
    void resetDaysBeforeFed() override;
    void update(Aliment* food) override;
    int getMaturingTime() override;
    FoodType getFoodType() override;
    float getFoodQuantity() override;
    bool getPortee();
    void setPortee(bool portee);

    void setMaturingTime(int days) override;

private:
    int
            m_joursAvantFaim{2}, // 2 jours
    m_finDeReprod{365 * 14}, // 14 ans
    m_esperanceDeVie{365 * 25}; // 25 ans
    float m_AlimentationJour; // en kg
    int m_maturiteSexuelle;
    bool m_portee{false};
    int m_gestation;
    float m_mortaliteInfantile;
};


#endif //CORRECTION_TP_FEU_TIGER_H
