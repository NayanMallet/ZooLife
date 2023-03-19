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
    virtual bool getPortee() = 0;
    virtual void setPortee(bool portee) = 0;
    virtual int getGestation() = 0;
    virtual void setGestation(int gestation) = 0;


    string getName();
    char getSexe() const;
    int getAge() const;
    AnimalType getTypeAnimal() const;
    float getPrix(char type) const;
    bool getReproduction() const;
    bool getFed() const;
    int getMaladie() const;
    bool getDead() const;

    void setReproduction(bool reproduction);
    void setFed(bool fed);
    void setAge(int age);
    void setMaladie(bool maladie);
    void setDead(bool dead);


private:
    string m_name;
    char m_sexe{};
    int m_age{}; // en jours
    AnimalType m_typeAnimal{};
    FoodType m_foodType{};
    bool m_fed{false}; // getFed -> True = Animal a faim / False = Animal n'as pas faim
    bool m_reproduction{false};
    int m_maladie{0};
    bool m_dead{false};

};


#endif //CORRECTION_TP_FEU_IANIMAL_H
