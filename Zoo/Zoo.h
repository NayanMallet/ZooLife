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
    vector<Habitat*> m_enclosGestation{
        new Habitat("Gestation Tigres", AnimalType::TIGRE),
        new Habitat("Gestation Aigles", AnimalType::AIGLE),
        new Habitat("Gestation Poules", AnimalType::POULE)
    };
    vector<Aliment*> m_stockAliment{
        new Graines("Graines"),
        new Viande("Viande")
    };

    Zoo(string nom);
    ~Zoo();

    void show() const;
    void showResume() const;
    void showHabitats() const;
    string listHabitats() const;

    void foodMonthlyUpdate();
    void graineNuisibleMonthly();
    void viandeAvarieMonthly();

    const string & getName() const;
    int getNbrOfEnclos() const;

    void addHabitat(Habitat *habitat);
    void removeHabitat(Habitat *habitat);

    // TODO : Passing to the next year func
    void nextYear();
    void nextMonth();

    float getBudget() const;
    void removeBudget(float budget);

    void sellAnimal(Habitat *habitat, IAnimal *animal);
    void buyAnimal(Habitat *habitat, IAnimal *animal);
    bool verifHabitat(Habitat *habitat);

    void sellAliment(FoodType alimentType, float quantite);
    void buyAliment(FoodType alimentType, float quantite);

    void sellHabitat(Habitat *habitat);
    void buyHabitat(string nom, AnimalType typeAnimal);

    void volSpecimenMonthly();
    void incendieMonthly();
    void subventionAnnual();
    void visiteurMonthly(string month);

    void changeAnimalOfEnclos(Habitat *habitat, Habitat *newHabitat, IAnimal *animal);


private:
    string m_name;
    int m_days{0};
    const vector<string> m_months{"JANVIER", "FEVRIER", "MARS", "AVRIL", "MAI", "JUIN", "JUILLET", "AOUT", "SEPTEMBRE", "OCTOBRE", "NOVEMBRE", "DECMEMBRE"};
    int m_month = {0};
    Budget *m_budget{ new Budget(80000)};

    bool verifHabitatGestation(Habitat *habitat);
};


#endif //CORRECTION_TP_FEU_ZOO_H
