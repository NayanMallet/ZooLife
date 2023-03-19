#ifndef ZOOLIFE_HABITAT_H
#define ZOOLIFE_HABITAT_H

#include <string>
#include <vector>
#include "../Animaux/IAnimal.h"

using namespace std;

class Habitat {
public:
    vector<IAnimal*> m_animaux;

    Habitat(string nom, AnimalType typeAnimal);
    ~Habitat();

    void show() const;
    void showAnimals() const;
    string listAnimals() const;

    const string & getName() const;
    int getCapacite() const;
    int getNbrOfAnimals() const;
    AnimalType getTypeAnimal() const;
    float getPrix(char type) const;

    void addAnimal(IAnimal* animal);

    void removeAnimal(IAnimal* animal);

    bool verifAnimal(IAnimal* animal);

    void PerteSurpopulation();

    void MaladieAnnuelle();

    void foetus(IAnimal* animal);

    void update(string month, Aliment *food);
private:
    string m_nom;
    int m_capacite;
    AnimalType m_typeAnimal;
    int m_prixAchat, m_prixVente;
    bool m_perteSurPop{false};
    float m_probaMaladie;

};

#endif //ZOOLIFE_HABITAT_H
