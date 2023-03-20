#ifndef CORRECTION_TP_FEU_POULE_H
#define CORRECTION_TP_FEU_POULE_H

#include "IAnimal.h"
#include <string>

using namespace  std;

class Poule : public IAnimal {
public:
    Poule(string name, int age);
    ~Poule() override = default;

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
            m_joursAvantFaim{1},
            m_finDeReprod{365 * 8}, // 8 ans
    m_esperanceDeVie{365 * 15}; // 15 ans
    float m_AlimentationJour{0.15}; // en kg
    int m_maturiteSexuelle{30 * 6}; // 6 mois
    bool m_portee{false};
    int m_gestation{0};
    float m_mortaliteInfantile{50};
};



#endif //CORRECTION_TP_FEU_POULE_H
