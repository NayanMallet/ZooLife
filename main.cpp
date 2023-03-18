#include <iostream>
#include "Aliments/Graines.h"
#include "Aliments/Viande.h"
#include "Animaux/Tigre.h"
#include "Animaux/Poule.h"
#include "Animaux/Aigle.h"
#include "Animaux/Coq.h"
#include "Habitats/Habitat.h"
#include "Functions/functions.h"
#include "Zoo/Zoo.h"
#include "Vendeur/Vendeur.h"

#include <vector>

using namespace std;

void scenario() {
    // Mettez en place un scénario type : 2 couples de tigre, 2 couples d’aigle, 1 coq, 10 poules sur 10 ans

    // Couples Tigres :)
    auto *TigreM1 = new Tigre("Tigrou", 'M', 0);
    auto *TigreM2 = new Tigre("Marck", 'M', 0);
    auto *TigreF1 = new Tigre("Jeanne", 'F', 0);
    auto *TigreF2 = new Tigre ("Elsa", 'F', 0);

    // Couples Aigles :)
    auto *AigleM1 = new Aigle("Marckou", 'M', 0);
    auto *AigleM2 = new Aigle("Dalyll", 'M', 0);
    auto *AigleF1 = new Aigle("Leo", 'F', 0);
    auto *AigleF2 = new Aigle("Haagen", 'F', 0);

    // Le Coq
    auto *Zizou = new Coq("Zizou", 0);

    // Les Poules
    auto *Poule1 = new Poule("Poule1", 0);
    auto *Poule2 = new Poule("Poule2", 0);
    auto *Poule3 = new Poule("Poule3", 0);
    auto *Poule4 = new Poule("Poule4", 0);
    auto *Poule5 = new Poule("Poule5", 0);
    auto *Poule6 = new Poule("Poule6", 0);
    auto *Poule7 = new Poule("Poule7", 0);

    // Les Habitats
    auto *habitat = new Habitat("Couple de Tigre 1", AnimalType::TIGRE);
    habitat->addAnimal(TigreM1);
    habitat->addAnimal(TigreF1);
    auto *habitat2 = new Habitat("Couple de Tigre 2", AnimalType::TIGRE);
    habitat2->addAnimal(TigreM2);
    habitat2->addAnimal(TigreF2);
    auto *habitat3 = new Habitat("Couple Aigle 1", AnimalType::AIGLE);
    habitat3->addAnimal(AigleM1);
    habitat3->addAnimal(AigleF1);
    auto *habitat4 = new Habitat("Couple Aigle 2", AnimalType::AIGLE);
    habitat4->addAnimal(AigleM2);
    habitat4->addAnimal(AigleF2);
    auto *habitat5 = new Habitat("KFC", AnimalType::POULE);
    habitat5->addAnimal(Zizou);
    habitat5->addAnimal(Poule1);
    habitat5->addAnimal(Poule2);
    habitat5->addAnimal(Poule3);

    Zoo *zooLife = new Zoo("ZooLife");
    zooLife->addHabitat(habitat);
    zooLife->addHabitat(habitat2);
    zooLife->addHabitat(habitat3);
    zooLife->addHabitat(habitat4);
    zooLife->addHabitat(habitat5);
    zooLife->show();
}

int main() {
    Zoo *zooLife = new Zoo("ZooLife");
    auto *AigleM1 = new Aigle("Marckou", 'M', 0);
    auto *AigleM2 = new Aigle("Dalyll", 'M', 0);
    auto *AigleM3= new Aigle("Dalyll", 'M', 0);
    auto *AigleM4 = new Aigle("Dalyll", 'M', 0);
    auto *AigleM5 = new Aigle("Dalyll", 'M', 0);
    auto *AigleM6 = new Aigle("Dalyll", 'M', 0);
    auto *AigleM7 = new Aigle("Dalyll", 'M', 0);
    auto *AigleM8 = new Aigle("Dalyll", 'M', 0);
    auto *AigleF1 = new Aigle("Leo", 'F', 0);
    auto *AigleF2 = new Aigle("Haagen", 'F', 0);
    auto *AigleF3 = new Aigle("Haagen", 'F', 0);

    auto *habitat3 = new Habitat("Couple Aigle 1", AnimalType::AIGLE);
    habitat3->addAnimal(AigleM1);
    habitat3->addAnimal(AigleM2);
    habitat3->addAnimal(AigleF1);
    habitat3->addAnimal(AigleF2);
    habitat3->addAnimal(AigleM3);
    habitat3->addAnimal(AigleM4);
    habitat3->addAnimal(AigleF3);
    habitat3->addAnimal(AigleM5);
    habitat3->addAnimal(AigleM6);
    habitat3->addAnimal(AigleM7);
    habitat3->addAnimal(AigleM8);
    zooLife->addHabitat(habitat3);
    zooLife->m_enclos[0]->show();
    zooLife->m_enclos[0]->PerteSurpopulation();
    zooLife->m_enclos[0]->show();

    return 0;
}

// Updates :)
// -> Aliment Class
// -> IAnimals Class
// -> Zoo Class

// ✅ => Complete
// ⭐️ => Optimised