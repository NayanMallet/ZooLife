#ifndef ZOOLIFE_VENDEUR_H
#define ZOOLIFE_VENDEUR_H
#include <string>
#include <vector>
#include "../Animaux/IAnimal.h"
#include "../Habitats/Habitat.h"

using namespace std;

class Vendeur {
public:
    vector<IAnimal*> m_animaux;
    vector<Habitat*> m_habitats;
    vector<Aliment*> m_aliments;

    Vendeur(string nom, int argent);
    ~Vendeur();

    void show() const;
    void showAnimals() const;
    void showHabitats() const;
    void showAliments() const;

    const string & getName() const;

    void addAnimal(IAnimal* animal);
    void addHabitat(Habitat* habitat);
    void addAliment(Aliment* aliment);

    void removeAnimal(IAnimal* animal);
    void removeHabitat(Habitat* habitat);
    void removeAliment(Aliment* aliment);
private:
    string m_nom;

};


#endif //ZOOLIFE_VENDEUR_H
