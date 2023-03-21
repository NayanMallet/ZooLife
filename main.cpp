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
        printf("Que souhaitez-vous faire ?\n\t1 - Voir mes enclos\n\t2 - Passer au prochain mois\n\t3 - Exit\n");
        getline(cin, Rep);
        if (Rep == "1") {
            cout << "----- Habitats -----" << endl;
            for (auto& h : zooLife->m_enclos) {
                h->show();
            }
            cout << "-------------------" << endl;
        } else if (Rep == "2") {
            zooLife->nextMonth();
        }
    }
}

int test() {
    // Couples Tigres :)
    auto *TigreM = new Tigre("Tigrou", 'M', 365*6);
    auto *TigreF = new Tigre("Jeanne", 'F', 365*6);

    // Les Habitats
    auto *hTigres = new Habitat("Couple de Tigre", AnimalType::TIGRE);
    hTigres->addAnimal(TigreM);
    hTigres->addAnimal(TigreF);

    Zoo *zooLife = new Zoo("ZooLife");
    zooLife->addHabitat(hTigres);
    Vendeur *vendeur = new Vendeur("Moha");
    string Rep;

    while (Rep != "4") {
        printf("Que souhaitez-vous faire ?\n\t1 - Voir mes enclos\n\t2 - Passer au prochain mois\n\t3 - Parler au vendeur\n\t4 - Exit\n");
        getline(cin, Rep);
        if (Rep == "1") {
            cout << "----- Habitats -----" << endl;
            zooLife->showHabitats();
            cout << "-------------------" << endl;
        } else if (Rep == "2") {
            zooLife->nextMonth();
        } else if (Rep == "3") {
            cout << "----- " << vendeur->getName() << " -----" << endl;
            string VendRep;
            while (VendRep != "4") {
                printf("Bonjour! Que souhaitez-vous faire ?\n\t1 - Acheter/Vendre un animal\n\t2 - Acheter/Vendre un habitat\n\t3 - Acheter/Vendre de la nourriture\n\t4 - Exit\n");
                getline(cin, VendRep);
                if (VendRep == "1") {
                    string AnimalRep;
                    while (AnimalRep != "3") {
                        cout << "----- Animaux -----" << endl;
                        printf("Que souhaitez-vous faire ?\n\t1 - Acheter un animal\n\t2 - Vendre un animal\n\t3 - Exit\n");
                        getline(cin, AnimalRep);
                        if (AnimalRep == "1") {
                            cout << "Acheter un animal" << endl;
                            vendeur->showAnimals();
                        } else if (AnimalRep == "2") {
                            cout << "Vendre un animal" << endl;
                            for (auto& h : zooLife->m_enclos) {
                                h->showAnimals();
                            }
                        }
                    }
                } else if (VendRep == "2") {
                    string HabitatRep;
                    while (HabitatRep != "3") {
                        cout << "----- Habitats -----" << endl;
                        printf("Que souhaitez-vous faire ?\n\t1 - Acheter un habitat\n\t2 - Vendre un habitat\n\t3 - Exit\n");
                        getline(cin, HabitatRep);
                        if (HabitatRep == "1") {
                            cout << "Acheter un habitat" << endl;
                            vendeur->showHabitats();
                        } else if (HabitatRep == "2") {
                            cout << "Vendre un habitat" << endl;
                            for (auto& h : zooLife->m_enclos) {
                                h->show();
                            }
                        }
                    }
                } else if (VendRep == "3") {
                    string NourritureRep;
                    while (NourritureRep != "3") {
                        cout << "----- Nourriture -----" << endl;
                        printf("Que souhaitez-vous faire ?\n\t1 - Acheter de la nourriture\n\t2 - Vendre de la nourriture\n\t3 - Exit\n");
                        getline(cin, NourritureRep);
                        if (NourritureRep == "1") {
                            cout << "Acheter de la nourriture" << endl;
                            vendeur->showAliments();
                        } else if (NourritureRep == "2") {
                            cout << "Vendre de la nourriture" << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int main() {
    test();
    return 0;
}

// TODO: Maladie => 1ans
// TODO:

// ✅ => Complete
// ⭐️ => Optimised