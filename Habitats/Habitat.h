#ifndef ZOOLIFE_HABITAT_H
#define ZOOLIFE_HABITAT_H
#include <string>
#include <vector>
#include "../Animaux/Poule.h"
#include "../Animaux/Tigre.h"
#include "../Animaux/Aigle.h"
using namespace std;

class Habitat {
public:
    vector<IAnimal*> m_animaux;

    Habitat(string nom, string typeAnimal);

    void show();
    void showAnimals() const;
    string listAnimals() const;

    string getName() const;
    int getCapacite() const;
    int getNbrOfAnimals() const;
    string getTypeAnimal() const;

    void ajouterAnimal(IAnimal *animal);

    void enleverAnimal(IAnimal *animal);
private:
    string m_nom;
    int m_capacite;
    string m_typeAnimal;
    int m_prixAchat, m_prixVente;
    int m_perteSurPop;
    float m_probaMaladie;
};

#endif //ZOOLIFE_HABITAT_H
