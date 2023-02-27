#include <iostream>
#include "Aliments/Aliment.h"
#include "Animaux/Tigre.h"
#include "Animaux/Poule.h"
#include "Animaux/Aigle.h"
#include "Animaux/Coq.h"
#include "Habitats/Habitat.h"
#include "Aliments/Graines.h"
#include "Aliments/Viande.h"
#include "Functions/functions.h"
#include "Zoo/Zoo.h"

#include <vector>

using namespace std;

int main() {
    // Mettez en place un scénario type : 2 couples de tigre, 2 couples d’aigle, 1 coq, 10 poules sur 10 ans
//    auto *ble = new Graines("Graine");
//    auto *steak = new Viande("Viande");
//    ble->show();
//    steak->show();

    // Couples Tigres :)
    Tigre *TigreM1 = new Tigre("Tigrou", 'M', 0);
//    Graines *a = new Graines("Boeuf");
//    a->addQuantite(100); // 24 kg d'aliment disponible
//    TigreM1->fedAnimal(a); // nourrir le tigre avec l'aliment disponible

    Tigre *TigreM2 = new Tigre("Marck", 'M', 0);
    Tigre *TigreF1 = new Tigre("Jeanne", 'F', 0);
    Tigre *TigreF2 = new Tigre ("Elsa", 'F', 0);
//
//    // Couples Aigles :)
    Aigle *AigleM1 = new Aigle("Marckou", 'M', 0);
    Aigle *AigleM2 = new Aigle("Dalyll", 'M', 0);
    Aigle *AigleF1 = new Aigle("Leo", 'F', 0);
    Aigle *AigleF2 = new Aigle("Haagen", 'F', 0);
//
//    // Le Coq
    Coq *Zizou = new Coq("Zizou", 0);
//
//    // Les Poules
    Poule *Poule1 = new Poule("Poule1", 0);
    Poule *Poule2 = new Poule("Poule2", 0);
    Poule *Poule3 = new Poule("Poule3", 0);
    Poule *Poule4 = new Poule("Poule4", 0);
    Poule *Poule5 = new Poule("Poule5", 0);
    Poule *Poule6 = new Poule("Poule6", 0);
    Poule *Poule7 = new Poule("Poule7", 0);
    Poule *Poule8 = new Poule("Poule8", 0);
    Poule *Poule9 = new Poule("Poule9", 0);
    Poule *Poule10 = new Poule("Poule10", 0);


    Habitat *habitat = new Habitat("Couple de Tigre 1", AnimalType::TIGRE);
    habitat->addAnimal(TigreM1);
    habitat->addAnimal(TigreF1);
    Habitat *habitat2 = new Habitat("Couple de Tigre 2", AnimalType::TIGRE);
    habitat2->addAnimal(TigreM2);
    habitat2->addAnimal(TigreF2);
    Habitat *habitat3 = new Habitat("Couple Aigle 1", AnimalType::AIGLE);
    habitat3->addAnimal(AigleM1);
    habitat3->addAnimal(AigleF1);
    Habitat *habitat4 = new Habitat("Couple Aigle 2", AnimalType::AIGLE);
    habitat4->addAnimal(AigleM2);
    habitat4->addAnimal(AigleF2);
    Habitat *habitat5 = new Habitat("KFC", AnimalType::POULE);
    habitat5->addAnimal(Zizou);
    habitat5->addAnimal(Poule1);
    habitat5->addAnimal(Poule2);
    habitat5->addAnimal(Poule3);


//
//
//
//
    Zoo *zooLife = new Zoo("ZooLife");
    zooLife->addHabitat(habitat);
    zooLife->addHabitat(habitat2);
    zooLife->addHabitat(habitat3);
    zooLife->addHabitat(habitat4);
    zooLife->addHabitat(habitat5);
    zooLife->show();
    return 0;
}

// Updates :)
// -> Aliment Class
// -> IAnimals Class
// -> Zoo Class

// ✅ => Complete
// ⭐️ => Optimised