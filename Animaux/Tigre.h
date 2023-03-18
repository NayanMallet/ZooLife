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
    void fedAnimal(Aliment* food) override;
    void resetDaysBeforeFed() override;
private:
    int
            m_joursAvantFaim{2}, // 2 jours
    m_finDeReprod{365 * 14}, // 14 ans
    m_esperanceDeVie{365 * 25}; // 25 ans
    float m_AlimentationJour; // en kg
    int m_maturiteSexuelle;
    string m_portee;
    int m_gestation;
    float m_mortaliteInfantile;
};


#endif //CORRECTION_TP_FEU_TIGER_H
