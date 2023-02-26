#ifndef ZOOLIFE_HABITAT_H
#define ZOOLIFE_HABITAT_H

#include <string>
#include <vector>
#include "../Animaux/IAnimal.h"

using namespace std;

class Habitat {
public:
    vector<IAnimal*> m_animaux;

    Habitat(const string& nom, const string& typeAnimal);
    ~Habitat();

    void show() const;
    void showAnimals() const;
    string listAnimals() const;

    const string & getName() const;
    int getCapacite() const;
    int getNbrOfAnimals() const;
    const string & getTypeAnimal() const;

    void addAnimal(IAnimal* animal);

    void removeAnimal(IAnimal* animal);
private:
    string m_nom;
    int m_capacite;
    string m_typeAnimal;
    int m_prixAchat, m_prixVente;
    int m_perteSurPop;
    float m_probaMaladie;

    static bool isValidType(const string& typeAnimal);
};

#endif //ZOOLIFE_HABITAT_H
