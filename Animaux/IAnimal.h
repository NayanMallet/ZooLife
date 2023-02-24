//
// Created by theos on 1/23/2023.
//

#ifndef CORRECTION_TP_FEU_IANIMAL_H
#define CORRECTION_TP_FEU_IANIMAL_H

#include <string>
#include <iostream>

using namespace std;

class IAnimal {
public:
    IAnimal(string name, char sexe, int age, string typeAnimal);

    virtual void show() = 0;

    string getName();
    char getSexe() const;
    int getAge() const;
    string getTypeAnimal() const;

private:
    string m_name;
    char m_sexe{};
    int m_age; // en jours
    string m_typeAnimal;
};


#endif //CORRECTION_TP_FEU_IANIMAL_H
