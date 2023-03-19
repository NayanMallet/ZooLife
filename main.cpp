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
    auto *Poule8 = new Poule("Poule8", 0);
    auto *Poule9 = new Poule("Poule9", 0);
    auto *Poule10 = new Poule("Poule10", 0);

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
    habitat5->addAnimal(Poule4);
    habitat5->addAnimal(Poule5);
    habitat5->addAnimal(Poule6);
    habitat5->addAnimal(Poule7);
    habitat5->addAnimal(Poule8);
    habitat5->addAnimal(Poule9);
    habitat5->addAnimal(Poule10);

    Zoo *zooLife = new Zoo("ZooLife");
    zooLife->addHabitat(habitat);
    zooLife->addHabitat(habitat2);
    zooLife->addHabitat(habitat3);
    zooLife->addHabitat(habitat4);
    zooLife->addHabitat(habitat5);
    zooLife->show();
    string Rep;
    while (Rep != "3") {
        printf("Que souhaitez-vous faire ?\n\t1 - Voir mon Zoo\n\t2 - Passer au prochain mois\n\t3 - Exit\n");
        getline(cin, Rep);
        if (Rep == "1") {
            zooLife->show();
        } else if (Rep == "2") {
            zooLife->nextMonth();
        }
    }
}

int main() {
    // Couples Tigres :)
    auto *TigreM = new Tigre("Tigrou", 'M', 365*6);
    auto *TigreF = new Tigre("Jeanne", 'F', 365*6);

    // Couples Aigles :)
    auto *AigleM = new Aigle("Jules", 'M', 365*4);
    auto *AigleF = new Aigle("Leo", 'F', 365*4);

    // Le Coq
    auto *Coq1 = new Coq("Zizou", 31*6);

    // Les Poules
    auto *Poule1 = new Poule("Poule1", 31*6);


    // Les Habitats
    auto *hTigres = new Habitat("Couple de Tigre", AnimalType::TIGRE);
    hTigres->addAnimal(TigreM);
    hTigres->addAnimal(TigreF);
    auto *hAigles = new Habitat("Couple d'Aigle", AnimalType::AIGLE);
    hAigles->addAnimal(AigleM);
    hAigles->addAnimal(AigleF);
    auto *hPoules = new Habitat("KFC", AnimalType::POULE);
    hPoules->addAnimal(Coq1);
    hPoules->addAnimal(Poule1);

    Zoo *zooLife = new Zoo("ZooLife");
    zooLife->addHabitat(hTigres);
    zooLife->addHabitat(hAigles);
    zooLife->addHabitat(hPoules);

    string Rep;

    while (Rep != "3") {
        printf("Que souhaitez-vous faire ?\n\t1 - Voir mes enclos\n\t2 - Passer au prochain mois\n\t3 - Exit\n");
        getline(cin, Rep);
        if (Rep == "1") {

        } else if (Rep == "2") {
            zooLife->nextMonth();
        }
    }

    return 0;
}

// TODO: Maladie => 1ans
// TODO:

// ✅ => Complete
// ⭐️ => Optimised