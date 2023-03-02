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

int main() {
    // Mettez en place un scénario type : 2 couples de tigre, 2 couples d’aigle, 1 coq, 10 poules sur 10 ans
//    auto *ble = new Graines("Graine");
//    auto *steak = new Viande("Viande");
//    ble->show();
//    steak->show();

    // Couples Tigres :)
    auto *TigreM1 = new Tigre("Tigrou", 'M', 0);
    auto *a = new Viande("Boeuf");
    a->addQuantite(24); // 24 kg d'aliment disponible
    TigreM1->fedAnimal(a); // nourrir le tigre avec l'aliment disponible

    auto *TigreM2 = new Tigre("Marck", 'M', 0);
    auto *TigreF1 = new Tigre("Jeanne", 'F', 0);
    auto *TigreF2 = new Tigre ("Elsa", 'F', 0);
//
//    // Couples Aigles :)
    auto *AigleM1 = new Aigle("Marckou", 'M', 0);
    auto *AigleM2 = new Aigle("Dalyll", 'M', 0);
    auto *AigleF1 = new Aigle("Leo", 'F', 0);
    auto *AigleF2 = new Aigle("Haagen", 'F', 0);
//
//    // Le Coq
    auto *Zizou = new Coq("Zizou", 0);
//
//    // Les Poules
    auto *Poule1 = new Poule("Poule1", 0);
    auto *Poule2 = new Poule("Poule2", 0);
    auto *Poule3 = new Poule("Poule3", 0);
    auto *Poule4 = new Poule("Poule4", 0);
    auto *Poule5 = new Poule("Poule5", 0);
    auto *Poule6 = new Poule("Poule6", 0);
    auto *Poule7 = new Poule("Poule7", 0);
    auto *Poule8 = new Poule("Poule8", 0);
    auto *Poule9 = new Poule("Poule9", 0);
    auto *Poule10 = new Poule("Poule10", 0);


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

    auto tigree = new Tigre("Tigrou", 'M', 190);
    auto jean = new Tigre("Jean", 'M', 190);
    auto jeanette = new Tigre("hors de l'habitat", 'F', 190);
    auto habitat34 = new Habitat("Dans le Zoo", AnimalType::TIGRE);
    auto habitat64 = new Habitat("Hors du Zoo", AnimalType::TIGRE);
    habitat34->addAnimal(jean);
    zooLife->addHabitat(habitat34);
    habitat64->addAnimal(jeanette);
//
//    zooLife->buyAnimal(habitat34, jeanette);
//    zooLife->show();
//    zooLife->sellAnimal(habitat34,jeanette);
//    zooLife->show();


    zooLife->buyAnimal(habitat34, jeanette);
    cout << "Buy animal not in habitat test ✅" << endl;
    zooLife->show();
    zooLife->sellAnimal(habitat34,jeanette);
    cout << "Sell animal not in habitat test ✅" << endl;
    zooLife->show();

//
    Vendeur *Bourebabab = new Vendeur("Bourebabab");
    Bourebabab->addAnimal(TigreM1);
    Bourebabab->addAnimal(AigleF1);
    Bourebabab->addAnimal(Poule1);
    Bourebabab->addHabitat(habitat);
    Bourebabab->addHabitat(habitat3);
    Bourebabab->addAliment(a);
//    Bourebabab->showAnimals();
//    Bourebabab->showHabitats();
//    Bourebabab->showAliments();

    return 0;
}

// Updates :)
// -> Aliment Class
// -> IAnimals Class
// -> Zoo Class

// ✅ => Complete
// ⭐️ => Optimised