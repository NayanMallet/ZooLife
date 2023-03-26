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
#include "Budget/Budget.h"
#include "Functions/functions.h"

#include <vector>

using namespace std;

void etapePause() {
    printf("Appuyez sur Entree pour continuer...");
    cin.get();
    cout << endl;
}

bool isNumber(string input) {
    for (char c: input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int chooseEnclosFromZoo(Zoo *zooLife) {
    cout << "Choisis un enclos :" << endl;
    for (int i = 0; i < zooLife->m_enclos.size(); i++) {
        cout << "[" << i << "] " << zooLife->m_enclos[i]->getName() << endl;
    }
    cout << endl << "<- Sortir (tapez 'exit')" << endl << "Numero de l'enclos que vous souhaitez voir : ";
    string rep1;
    getline(cin, rep1);
    int choix = -1;
    while (true) {
        if (rep1 == "exit") {
            clearScreen();
            return -1;
        }

        if (rep1 == "" || !isNumber(rep1)) {
            cout << "Numero de l'enclos que vous souhaitez voir : ";
            getline(cin, rep1);
            continue;
        } else {
            choix = stoi(rep1);
            if (choix >= 0 && choix < zooLife->m_enclos.size()) {
                break;
            }
        }
        cout << "Numero de l'enclos que vous souhaitez voir : ";
        getline(cin, rep1);
    }
    clearScreen();
    return choix;
}

int chooseEnclosFromZooSpe(Zoo *zooLife, AnimalType type) {
    cout << "Choisis un enclos :" << endl;
    for (int i = 0; i < zooLife->m_enclos.size(); i++) {
        if (zooLife->m_enclos[i]->getTypeAnimal() == type) {
            cout << "[" << i << "] " << zooLife->m_enclos[i]->getName() << endl;
        }
    }
    cout << endl << "<- Sortir (tapez 'exit')" << endl << "Numero de l'enclos que vous souhaitez voir : ";
    string rep1;
    getline(cin, rep1);
    int choix = -1;
    while (true) {
        if (rep1 == "exit") {
            clearScreen();
            return -1;
        }

        if (rep1 == "" || !isNumber(rep1)) {
            cout << "Numero de l'enclos que vous souhaitez voir : ";
            getline(cin, rep1);
            continue;
        } else {
            choix = stoi(rep1);
            if (choix >= 0 && choix < zooLife->m_enclos.size() && zooLife->m_enclos[choix]->getTypeAnimal() == type) {
                break;
            }
        }
        cout << "Numero de l'enclos que vous souhaitez voir : ";
        getline(cin, rep1);
    }
    clearScreen();
    return choix;
}

int chooseAnimalFromEnclos(Habitat *habitat) {
    cout << "Choisis un animal :" << endl;
    for (int i = 0; i < habitat->m_animaux.size(); i++) {
        cout << "[" << i << "] " << habitat->m_animaux[i]->getName() << endl;
    }
    cout << endl << "<- Sortir (tapez 'exit')" << endl << "Numero de l'animal que vous souhaitez voir : ";
    string rep1;
    getline(cin, rep1);
    int choix = -1;
    while (true) {
        if (rep1 == "exit") {
            clearScreen();
            return -1;
        }

        if (rep1 == "" || !isNumber(rep1)) {
            cout << "Numero de l'animal que vous souhaitez voir : ";
            getline(cin, rep1);
            continue;
        } else {
            choix = stoi(rep1);
            if (choix >= 0 && choix < habitat->m_animaux.size()) {
                break;
            }
        }
        cout << "Numero de l'animal que vous souhaitez voir : ";
        getline(cin, rep1);
    }
    clearScreen();
    return choix;
}

int chooseAnimalFromBS(vector<IAnimal*> inventaire, char type) {
    cout << "Choisis un animal :" << endl;
    for (int i = 0; i < inventaire.size(); i++) {
        cout << "[" << i << "] " << inventaire[i]->getName() << " -> " << inventaire[i]->getPrix(type)  << "$" << endl;
    }
    cout << endl << "<- Sortir (tapez 'exit')" << endl << "Numero de l'animal que vous souhaitez " << (type == 'A' ? "acheter" : "vendre") << ": ";
    string rep1;
    getline(cin, rep1);
    int choix = -1;
    while (true) {
        if (rep1 == "exit") {
            clearScreen();
            return -1;
        }

        if (rep1 == "" || !isNumber(rep1)) {
            cout << "Numero de l'animal que vous souhaitez " << (type == 'A' ? "acheter" : "vendre") << ": ";
            getline(cin, rep1);
            continue;
        } else {
            choix = stoi(rep1);
            if (choix >= 0 && choix < inventaire.size()) {
                break;
            }
        }
        cout << "Numero de l'animal que vous souhaitez " << (type == 'A' ? "acheter" : "vendre") << ": ";
        getline(cin, rep1);
    }
    clearScreen();
    return choix;
}

int chooseEnclosFromBS(vector<Habitat*> habitat, char type) {
    cout << "Choisis un habitat :" << endl;
    for (int i = 0; i < habitat.size(); i++) {
        cout << "[" << i << "] " << habitat[i]->getName() << " -> " << habitat[i]->getPrix(type)  << "$" << endl;
    }
    cout << endl << "<- Sortir (tapez 'exit')" << endl << "Numero de l'habitat que vous souhaitez " << (type == 'A' ? "acheter" : "vendre") << ": ";
    string rep1;
    getline(cin, rep1);
    int choix = -1;
    while (true) {
        if (rep1 == "exit") {
            clearScreen();
            return -1;
        }

        if (rep1 == "" || !isNumber(rep1)) {
            cout << "Numero de l'habitat que vous souhaitez " << (type == 'A' ? "acheter" : "vendre") << ": ";
            getline(cin, rep1);
            continue;
        } else {
            choix = stoi(rep1);
            if (choix >= 0 && choix < habitat.size()) {
                break;
            }
        }
        cout << "Numero de l'habitat que vous souhaitez " << (type == 'A' ? "acheter" : "vendre") << ": ";
        getline(cin, rep1);
    }
    clearScreen();
    return choix;
}

int chooseFoodFromBS(vector<Aliment*> nourriture, char type) {
    cout << "Choisis une nourriture :" << endl;
    for (int i = 0; i < nourriture.size(); i++) {
        (type == 'A' ? cout << "[" << i << "] " << nourriture[i]->getNom() << ": " << nourriture[i]->getPrixKg()  << "$/Kg" << endl : cout << "[" << i << "] " << nourriture[i]->getNom() << ": " << nourriture[i]->getQuantite()  << "Kg" << endl);
    }

    cout << endl << "<- Sortir (tapez 'exit')" << endl << "Numero de la nourriture que vous souhaitez " << (type == 'A' ? "acheter" : "vendre") << ": ";
    string rep1;
    getline(cin, rep1);
    int choix = -1;
    while (true) {
        if (rep1 == "exit") {
            clearScreen();
            return -1;
        }

        if (rep1 == "" || !isNumber(rep1)) {
            cout << "Numero de la nourriture que vous souhaitez " << (type == 'A' ? "acheter" : "vendre") << ": ";
            getline(cin, rep1);
            continue;
        } else {
            choix = stoi(rep1);
            if (choix >= 0 && choix < nourriture.size()) {
                break;
            }
        }
        cout << "Numero de la nourriture que vous souhaitez " << (type == 'A' ? "acheter" : "vendre") << ": ";
        getline(cin, rep1);
    }
    clearScreen();
    return choix;
}

void scenario() {
    // Mettez en place un scénario type : 2 couples de tigre, 2 couples d’aigle, 1 coq, 10 poules sur 10 ans
    cout << "----- ZooLife -----" << endl;
    printf("\tBienvenue dans le simulateur de Zoo !\n\tGerez votre zoo en achetant et vendant des animaux, de la nourriture et des habitats.\n\tLes visiteurs generent de l'argent, mais attention a ne pas surcharger vos enclos ou vos animaux peuvent tomber malades et mourir.\n\tLe jeu dure 10 ans, soyez prudent avec votre argent et gerez votre zoo au mieux de vos capacites.\n\tBonne chance !\n");
    printf("\nCommencez par donner un nom a votre zoo : ");
    string nomZoo;
    getline(cin, nomZoo);
    auto *zooLife = new Zoo(nomZoo);
    printf("\nBienvenue dans votre zoo %s !\nVoici vos stats : \n", nomZoo.c_str());
    zooLife->show();
    etapePause();
    printf("\nVous avez 10 ans pour gerer votre zoo, bonne chance !\n");
    // Couples Tigres :)
    auto *TigreM1 = new Tigre("TigreM1", 'M', 4*365);
    auto *TigreM2 = new Tigre("TigreM2", 'M', 4*365);
    auto *TigreF1 = new Tigre("TigreF1", 'F', 4*365);
    auto *TigreF2 = new Tigre("TigreF2", 'F', 4*365);

    // Couples Aigles :)
    auto *AigleM1 = new Aigle("AigleM1", 'M', 4*365);
    auto *AigleM2 = new Aigle("AigleM2", 'M', 4*365);
    auto *AigleF1 = new Aigle("AigleF1", 'F', 4*365);
    auto *AigleF2 = new Aigle("AigleF2", 'F', 4*365);

    // Le Coq
    auto *Coq1 = new Coq("Coq1", 6*31);

    // Les Poules
    auto *Poule1 = new Poule("Poule1", 6*31);
    auto *Poule2 = new Poule("Poule2", 0);
    auto *Poule3 = new Poule("Poule3", 6*31);
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
    habitat5->addAnimal(Coq1);
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

    zooLife->addHabitat(habitat);
    zooLife->addHabitat(habitat2);
    zooLife->addHabitat(habitat3);
    zooLife->addHabitat(habitat4);
    zooLife->addHabitat(habitat5);
    auto *vendeur = new Vendeur("Vendeur");

    string Rep;
    while (Rep != "exit") {
        clearScreen();
        zooLife->showResume();
        printf("Que souhaitez-vous faire ?\n\t[1] Voir mon Zoo\n\t[2] Aller au vendeur\n\t[3] Passer au prochain mois\n\n\t<- Exit (tapez 'exit')\n");
        getline(cin, Rep);
        if (Rep == "1") {
            zooLife->show();
            etapePause();
            string RepEnclos;
            while (RepEnclos != "1" && RepEnclos != "2") {
                printf("Voulez-vous voir un enclos en particulier ? [1] Oui - [2] Non\n");
                getline(cin, RepEnclos);
            }
            if (RepEnclos == "2") {
                continue;
            }

            int chooseEnclos = chooseEnclosFromZoo(zooLife);
            if (chooseEnclos == -1) {
                continue;
            }
            zooLife->m_enclos[chooseEnclos]->show();
            etapePause();

            string RepAnimal;
            while (RepAnimal != "1" && RepAnimal != "2") {
                printf("Voulez-vous voir un animal en particulier ? [1] Oui - [2] Non\n");
                getline(cin, RepAnimal);
            }
            if (RepAnimal == "2") {
                continue;
            }
            int chooseAnimal = chooseAnimalFromEnclos(zooLife->m_enclos[chooseEnclos]);
            if (chooseAnimal == -1) {
                continue;
            }
            zooLife->m_enclos[chooseEnclos]->m_animaux[chooseAnimal]->show();
            etapePause();

            string RepAction;
            while (RepAction != "1" && RepAction != "2") {
                printf("Voulez-vous faire une action sur cet animal ? [1] Oui - [2] Non\n");
                getline(cin, RepAction);
            }
            if (RepAction == "2") {
                continue;
            }
            string RepAction2;
            while (RepAction2 != "4") {
                printf("Que voulez-vous faire ?\n\t[1] Renommer l'animal\n\t[2] Soigner l'animal\n\t[3] Changer d'enclos\n\t[4] Exit\n");
                getline(cin, RepAction2);

                if (RepAction2 == "1") {
                    string newName;
                    printf("Entrez le nouveau nom de l'animal : ");
                    getline(cin, newName);
                    zooLife->m_enclos[chooseEnclos]->m_animaux[chooseAnimal]->setNom(newName);
                    printf("Le nom de l'animal a bien été changé !\n");
                    etapePause();
                } else if (RepAction2 == "2") {
                    int Maladie = zooLife->m_enclos[chooseEnclos]->m_animaux[chooseAnimal]->getMaladie();
                    if (Maladie == 0) {
                        printf("L'animal n'est pas malade !\n");
                        etapePause();
                        continue;
                    }
                    int Cout = Maladie * 1000;
                    if (zooLife->getBudget() < Cout) {
                        printf("Vous n'avez pas assez d'argent pour soigner l'animal !\n");
                        etapePause();
                        continue;
                    }

                    string RepSoigner;
                    while (RepSoigner != "1" && RepSoigner != "2") {
                        printf("L'animal est malade ! Il vous en coutera %d$ pour le soigner.\nVoulez-vous le soigner ? [1] Oui - [2] Non\n",
                               Cout);
                        getline(cin, RepSoigner);
                    }
                    if (RepSoigner == "2") {
                        continue;
                    }

                    zooLife->m_enclos[chooseEnclos]->m_animaux[chooseAnimal]->setMaladie(0);
                    zooLife->removeBudget(Cout);
                    printf("L'animal a bien été soigné !\n");
                    etapePause();

                } else if (RepAction2 == "3") {
                    cout << "Choisissez l'enclos dans lequel vous voulez mettre l'animal." << endl;
                    int chooseEnclos2 = chooseEnclosFromZooSpe(zooLife, zooLife->m_enclos[chooseEnclos]->m_animaux[chooseAnimal]->getTypeAnimal());
                    if (chooseEnclos2 == -1) {
                        continue;
                    }
                    zooLife->changeAnimalOfEnclos(zooLife->m_enclos[chooseEnclos], zooLife->m_enclos[chooseEnclos2],
                                                  zooLife->m_enclos[chooseEnclos]->m_animaux[chooseAnimal]);
                    printf("L'animal a bien été changé d'enclos !\n");
                    etapePause();
                    continue;
                } else if (RepAction2 == "4") {
                    continue;
                }
            }
        } else if (Rep == "2") {
            cout << "----- " << vendeur->getName() << " -----" << endl;
            string VendRep;
            while (VendRep != "4") {
                clearScreen();
                cout << "----- " << vendeur->getName() << " -----" << endl;

                printf("Bonjour! Que souhaitez-vous faire ?\n\t[1] Acheter/Vendre un animal\n\t[2] Acheter/Vendre un habitat\n\t[3] Acheter/Vendre de la nourriture \n\t-> Sortir (4)\n");
                getline(cin, VendRep);
                if (VendRep == "1") {
                    string AnimalRep;
                    while (AnimalRep != "3") {
                        cout << "----- Animaux -----" << endl;
                        printf("Que souhaitez-vous faire ?\n\t[1] Acheter un animal \n\t[2] Vendre un animal \n\t[3] Exit\n");
                        getline(cin, AnimalRep);
                        if (AnimalRep == "1") {
                            cout << "--- Acheter un animal ---" << endl;
                            int chooseAnimal = chooseAnimalFromBS(vendeur->m_animaux, 'A');
                            if (chooseAnimal == -1) {
                                continue;
                            }
                            if (zooLife->getBudget() < vendeur->m_animaux[chooseAnimal]->getPrix('A')) {
                                cout << "Vous n'avez pas assez d'argent pour acheter cet animal!" << endl;
                                etapePause();
                                continue;
                            }

                            cout << "Choisissez l'enclos dans lequel vous voulez mettre l'animal." << endl;
                            int chooseEnclos = chooseEnclosFromZooSpe(zooLife,
                                                                      vendeur->m_animaux[chooseAnimal]->getTypeAnimal());
                            if (chooseEnclos == -1) {
                                continue;
                            }

                            zooLife->buyAnimal(zooLife->m_enclos[chooseEnclos], vendeur->m_animaux[chooseAnimal]);
                            vendeur->removeAnimal(vendeur->m_animaux[chooseAnimal]);
                            cout << "L'animal a bien été acheté !" << endl;
                            etapePause();

                        } else if (AnimalRep == "2") {
                            cout << "--- Vendre un animal ---" << endl;
                            cout << "Choissisez l'enclot dans lequel se trouve l'animal que vous voulez vendre."
                                 << endl;
                            int chooseEnclos = chooseEnclosFromZoo(zooLife);
                            if (chooseEnclos == -1) {
                                continue;
                            }
                            cout << "Choisissez l'animal que vous voulez vendre." << endl;
                            int chooseAnimal = chooseAnimalFromBS(zooLife->m_enclos[chooseEnclos]->m_animaux, 'V');
                            if (chooseAnimal == -1) {
                                continue;
                            }

                            vendeur->addAnimal(zooLife->m_enclos[chooseEnclos]->m_animaux[chooseAnimal]);
                            zooLife->sellAnimal(zooLife->m_enclos[chooseEnclos],
                                                zooLife->m_enclos[chooseEnclos]->m_animaux[chooseAnimal]);

                            cout << "L'animal a bien été vendu !" << endl;
                            etapePause();
                        } else if (AnimalRep == "3") {
                            continue;
                        }
                    }
                } else if (VendRep == "2") {
                    string HabitatRep;
                    while (HabitatRep != "3") {
                        cout << "----- Habitats -----" << endl;
                        printf("Que souhaitez-vous faire ?\n\t[1] Acheter un habitat\n\t[2] Vendre un habitat\n\t[3] Exit\n");
                        getline(cin, HabitatRep);
                        if (HabitatRep == "1") {
                            cout << "--- Acheter un habitat ---" << endl;
                            cout << "Choissisez l'enclot dans lequel se trouve l'animal que vous voulez vendre." << endl;

                            int chooseEnclos = chooseEnclosFromBS(vendeur->m_habitats, 'A');

                            if (chooseEnclos == -1) {
                                continue;
                            }

                            if (zooLife->getBudget() < vendeur->m_habitats[chooseEnclos]->getPrix('A')) {
                                cout << "Vous n'avez pas assez d'argent pour acheter cet enclos!" << endl;
                                etapePause();
                                continue;
                            }

                            string nameForHabitat;
                            cout << "Entrez le nom de l'enclos: " << endl;
                            getline(cin, nameForHabitat);
                            zooLife->buyHabitat(nameForHabitat, vendeur->m_habitats[chooseEnclos]->getTypeAnimal());
                            cout << "L'enclos << " << nameForHabitat << " >> a bien été acheté !" << endl;
                            etapePause();
                        } else if (HabitatRep == "2") {
                            cout << "--- Vendre un habitat ---" << endl;
                            cout << "Choissisez l'enclot que vous voulez vendre." << endl;

                            int chooseEnclos = chooseEnclosFromBS(zooLife->m_enclos, 'V');
                            if (chooseEnclos == -1) {
                                continue;
                            }

                            if (zooLife->m_enclos[chooseEnclos]->m_animaux.size() != 0) {
                                cout << "Vous ne pouvez pas vendre un enclos qui contient des animaux!" << endl;
                                etapePause();
                                continue;
                            }

                            zooLife->sellHabitat(zooLife->m_enclos[chooseEnclos]);
                            cout << "L'enclos a bien été vendu !" << endl;
                            etapePause();
                        } else if (HabitatRep == "3") {
                            continue;
                        }
                    }
                } else if (VendRep == "3") {
                    string NourritureRep;
                    while (NourritureRep != "3") {
                        cout << "----- Nourriture -----" << endl;
                        printf("Que souhaitez-vous faire ?\n\t[1] Acheter de la nourriture\n\t[2] Vendre de la nourriture\n\t[3] Exit\n");
                        getline(cin, NourritureRep);
                        if (NourritureRep == "1") {
                            cout << "--- Acheter de la nourriture ---" << endl;
                            printf("Voici la liste des aliments disponibles: \n");
                            int chooseAliment = chooseFoodFromBS(vendeur->m_aliments, 'A');
                            if (chooseAliment == -1) {
                                continue;
                            }

                            if (zooLife->getBudget() < vendeur->m_aliments[chooseAliment]->getPrixKg()) {
                                cout << "Vous n'avez pas assez d'argent pour acheter cet aliment!" << endl;
                                etapePause();
                                continue;
                            }

                            printf("Combien de kg voulez-vous acheter ?\n");
                            float kg;
                            cin >> kg;
                            while (kg < 0) {
                                printf("Combien de kg voulez-vous acheter ?\n");
                                cin >> kg;
                            }
                            zooLife->buyAliment(vendeur->m_aliments[chooseAliment]->getFoodType(), kg);
                            cin.ignore();

                            cout << "Vous avez bien acheté " << kg << " kg de "
                                 << (vendeur->m_aliments[chooseAliment]->getFoodType() == FoodType::GRAINES ? "Graines"
                                                                                                            : "Viande")
                                 << " !" << endl;
                            etapePause();
                        } else if (NourritureRep == "2") {
                            cout << "--- Vendre de la nourriture ---" << endl;
                            printf("Voici la liste des aliments disponibles: \n");
                            int chooseAliment = chooseFoodFromBS(zooLife->m_stockAliment, 'V');
                            if (chooseAliment == -1) {
                                continue;
                            }

                            printf("Combien de kg voulez-vous vendre ?\n");
                            float kg;
                            cin >> kg;
                            while (kg < 0) {
                                printf("Combien de kg voulez-vous vendre ?\n");
                                cin >> kg;
                            }

                            if (zooLife->m_stockAliment[chooseAliment]->getQuantite() < kg) {
                                cout << "Vous n'avez pas assez de nourriture pour vendre " << kg << " kg !" << endl;
                                etapePause();
                                continue;
                            }

                            zooLife->sellAliment(zooLife->m_stockAliment[chooseAliment]->getFoodType(), kg);
                            cin.ignore();

                            cout << "Vous avez bien vendu " << kg << " kg de "
                                 << (zooLife->m_stockAliment[chooseAliment]->getFoodType() == FoodType::GRAINES ? "Graines"
                                                                                                              : "Viande")
                                 << " !" << endl;
                            etapePause();
                        } else if (NourritureRep == "3") {
                            continue;
                        }
                    }
                }
            }
        } else if (Rep == "3") {
            zooLife->nextMonth();
            etapePause();
        } else {
            printf("'%s' n'est pas une option valide.\n", Rep.c_str());
        }
    }
}





int main() {
    scenario();
    return 0;
}

// TODO: Maladie => 1ans
// TODO:

// ✅ => Complete
// ⭐️ => Optimised