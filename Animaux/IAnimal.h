#ifndef CORRECTION_TP_FEU_IANIMAL_H
#define CORRECTION_TP_FEU_IANIMAL_H

#include "../Aliments/Aliment.h"
#include <string>
#include <iostream>

using namespace std;

enum class AnimalType { TIGRE, AIGLE, POULE };

class IAnimal {
public:
    IAnimal(string name, char sexe, int age, AnimalType typeAnimal);

    virtual void show() = 0;
    virtual void fedAnimal(Aliment* food) = 0;
    virtual void resetDaysBeforeFed() = 0;

    string getName();
    char getSexe() const;
    int getAge() const;
    AnimalType getTypeAnimal() const;

private:
    string m_name;
    char m_sexe{};
    int m_age{}; // en jours
    AnimalType m_typeAnimal{};
    FoodType m_foodType{};
};


#endif //CORRECTION_TP_FEU_IANIMAL_H
