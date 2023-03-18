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
    virtual ~IAnimal() = default;

    virtual void show() = 0;
    virtual bool fedAnimal(Aliment* food) = 0;
    virtual void resetDaysBeforeFed() = 0;
    virtual void update(Aliment* food) = 0;
    virtual int getMaturingTime() = 0;
    virtual FoodType getFoodType() = 0;
    virtual float getFoodQuantity() = 0;
    virtual void setMaturingTime(int days) = 0;


    string getName();
    char getSexe() const;
    int getAge() const;
    AnimalType getTypeAnimal() const;
    float getPrix(char type) const;
    bool getReproduction() const;
    bool getFed() const;
    bool getMaladie() const;

    void setReproduction(bool reproduction);
    void setFed(bool fed);
    void setAge(int age);
    void setMaladie(bool maladie);


private:
    string m_name;
    char m_sexe{};
    int m_age{}; // en jours
    AnimalType m_typeAnimal{};
    FoodType m_foodType{};
    bool m_fed{false};
    bool m_reproduction{false};
    bool m_maladie{false};

};


#endif //CORRECTION_TP_FEU_IANIMAL_H
