#ifndef CORRECTION_TP_FEU_ZOO_H
#define CORRECTION_TP_FEU_ZOO_H

#include <iostream>
#include <vector>
#include "../Budget/Budget.h"
#include "../Habitats/Habitat.h"
#include "../Aliments/Aliment.h"
#include "../Aliments/Graines.h"
#include "../Aliments/Viande.h"

using namespace std;

class Zoo {
public:
    vector<Habitat*> m_enclos;

    Zoo(string nom);
    ~Zoo();

    void show() const;
    void showHabitats() const;
    string listHabitats() const;

    const string & getName() const;
    int getNbrOfEnclos() const;

    void addHabitat(Habitat *habitat);
    void removeHabitat(Habitat *habitat);

    // TODO : Passing to the next year func
//    void nextYear();

    void sellAnimal(Habitat *habitat, IAnimal *animal);
    void buyAnimal(Habitat *habitat, IAnimal *animal);
    bool verifHabitat(Habitat *habitat);

//void sellHabitat(Habitat *habitat);
//void buyHabitat(Habitat *habitat);

void sellAliment(Aliment *aliment);
void buyAliment(Aliment *aliment);

private:
    string m_name;
    int m_days{0};
    Budget *m_budget{ new Budget(80000)};
    vector<Aliment*> m_stockAliment{ new Graines("Graines"), new Viande("Viande")}
};


#endif //CORRECTION_TP_FEU_ZOO_H
