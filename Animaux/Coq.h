#ifndef ZOOLIFE_COQ_H
#define ZOOLIFE_COQ_H
#include "IAnimal.h"


class Coq: public IAnimal {
public:
    Coq(string name, int age);
    ~Coq() override = default;

    void show() override;
    void fedAnimal(Aliment* food) override;
    void resetDaysBeforeFed() override;
private:
    int
            m_joursAvantFaim{2}, // 2 jours
    m_finDeReprod{365 * 8}, // 8 ans
    m_esperanceDeVie{365 * 15}; // 15 ans
    float m_AlimentationJour{0.18}; // en kg
    int m_maturiteSexuelle{30 * 6}; // 6 mois
};


#endif //ZOOLIFE_COQ_H
