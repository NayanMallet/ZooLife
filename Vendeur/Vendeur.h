#ifndef ZOOLIFE_VENDEUR_H
#define ZOOLIFE_VENDEUR_H
#include <string>
#include <vector>
#include "../Animaux/IAnimal.h"
#include "../Habitats/Habitat.h"
#include "../Aliments/Viande.h"
#include "../Aliments/Graines.h"
#include "../Habitats/Habitat.h"
#include "../Animaux/Tigre.h"
#include "../Animaux/Poule.h"
#include "../Animaux/IAnimal.h"
#include "../Animaux/Coq.h"
#include "../Animaux/Aigle.h"

using namespace std;

class Vendeur {
public:
    vector<IAnimal*> m_animaux{
            new Tigre("Tigre(F)", 'F', 31*6), // 6 mois
            new Tigre("Tigre(M)", 'M', 365*4), // 4 ans
            new Tigre("Tigre(M)", 'M', 365*14), // 14 ans
            new Poule("Poule", 31*6), // 6 mois
            new Coq("Coq", 31*6), // 6 mois
            new Aigle("Aigle(F)", 'F', 31*6), // 6 mois
            new Aigle("Aigle(M)", 'M', 365*4), // 4 ans
            new Aigle("Aigle(M)", 'M', 365*14), // 14 ans
    };

    vector<Habitat*> m_habitats{
        new Habitat("Habitat pour Tigre", AnimalType::TIGRE), // 6 mois
        new Habitat("Habitat pour Aigle", AnimalType::AIGLE), // 6 mois
        new Habitat("Habitat pour Poules", AnimalType::POULE) // 6 mois
    };
    vector<Aliment*> m_aliments{
        new Viande("Viande"),
        new Graines("Graine"),
    };

    Vendeur(string nom);
    ~Vendeur();

//    void show() const;
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
