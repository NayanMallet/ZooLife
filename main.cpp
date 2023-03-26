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
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int chooseEnclosFromZoo(Zoo *zooLife) {
    cout << "Choisis un enclos :" << endl;
    for (int i = 0; i < zooLife->m_enclos.size(); i++) {
        cout << "[" << i << "] " << zooLife->m_enclos[i]->getName()<< endl;
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

int chooseAnimalFromEnclos(Habitat *habitat) {
    cout << "Choisis un animal :" << endl;
    for (int i = 0; i < habitat->m_animaux.size(); i++) {
        cout << "[" << i << "] " << habitat->m_animaux[i]->getName()<< endl;
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
    auto *TigreM1 = new Tigre("TigreM1", 'M', 0);
    auto *TigreM2 = new Tigre("TigreM2", 'M', 0);
    auto *TigreF1 = new Tigre("TigreF1", 'F', 0);
    auto *TigreF2 = new Tigre("TigreF2", 'F', 0);

    // Couples Aigles :)
    auto *AigleM1 = new Aigle("AigleM1", 'M', 0);
    auto *AigleM2 = new Aigle("AigleM2", 'M', 0);
    auto *AigleF1 = new Aigle("AigleF1", 'F', 0);
    auto *AigleF2 = new Aigle("AigleF2", 'F', 0);

    // Le Coq
    auto *Coq1 = new Coq("Coq1", 0);

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
    /*habitat->addAnimal(TigreM1);
    habitat->addAnimal(TigreF1);*/
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
    /*habitat5->addAnimal(Poule7);
    habitat5->addAnimal(Poule8);
    habitat5->addAnimal(Poule9);
    habitat5->addAnimal(Poule10);*/

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
        printf("Que souhaitez-vous faire ?\n\t[1] Voir mon Zoo\n\t[2] Aller au vendeur\n\t[3] Passer au prochain mois\n\n\t-> Stop (tapez 'exit')\n");
        getline(cin, Rep);
        if (Rep == "1")
        {
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
                        printf("L'animal est malade ! Il vous en coutera %d$ pour le soigner.\nVoulez-vous le soigner ? [1] Oui - [2] Non\n", Cout);
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
                    for (int i = 0; i < zooLife->m_enclos.size(); i++) {
                        if (zooLife->m_enclos[i]->getTypeAnimal() == zooLife->m_enclos[chooseEnclos]->m_animaux[chooseAnimal]->getTypeAnimal()) {
                            printf("[%d] %s\n", i, zooLife->m_enclos[i]->getName().c_str());
                        }
                    }
                    cout << endl << "<- Exit (tapez 'exit')" << endl;

                    int chooseEnclos2;
                    cin >> chooseEnclos2;
                    cin.ignore();

                    while (true) {
                        printf("Choisissez un enclos : ");
                        getline(cin, RepAction2);
                        if (chooseEnclos2 < 0 || chooseEnclos2 >= zooLife->m_enclos.size()) {
                            printf("Choix invalide !\n");
                            continue;
                        }
                        if (zooLife->m_enclos[chooseEnclos2]->getTypeAnimal() != zooLife->m_enclos[chooseEnclos]->m_animaux[chooseAnimal]->getTypeAnimal()) {
                            printf("L'enclos choisi n'est pas compatible avec l'animal !\n");
                            continue;
                        }
                        break;
                    }

                    zooLife->changeAnimalOfEnclos(zooLife->m_enclos[chooseEnclos], zooLife->m_enclos[chooseEnclos2], zooLife->m_enclos[chooseEnclos]->m_animaux[chooseAnimal]);
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
                printf("Bonjour! Que souhaitez-vous faire ?\n\t-> Acheter/Vendre un animal (1)\n\t-> Acheter/Vendre un habitat (2)\n\t-> Acheter/Vendre de la nourriture (3)\n\t-> Sortir (4)\n");
                getline(cin, VendRep);
                if (VendRep == "1") {
                    string AnimalRep;
                    while (AnimalRep != "3") {
                        cout << "----- Animaux -----" << endl;
                        printf("Que souhaitez-vous faire ?\n\t- Acheter un animal (1)\n\t- Vendre un animal (2)\n\t- Exit (3)\n");
                        getline(cin, AnimalRep);
                        if (AnimalRep == "1") {
                            cout << "--- Acheter un animal ---" << endl;
                            for (int i = 0; i < vendeur->m_animaux.size(); i++) {
                                printf("- %s (%i): %.2f$\n", vendeur->m_animaux[i]->getName().c_str(), i,
                                       vendeur->m_animaux[i]->getPrix('A'));
                            }
                            printf("Entrer le numero de l'animal que vous voulez acheter ou Entree pour revenir en arriere: \n");
                            string v1;
                            getline(cin, v1);
                            while (v1.empty() || stoi(v1) >= vendeur->m_animaux.size() || stoi(v1) < 0) {
                                printf("Entrer le numero de l'animal que vous voulez acheter ou Entree pour revenir en arriere: \n");
                                getline(cin, v1);
                            }
                            if (!v1.empty()) {
                                if (zooLife->getBudget() < vendeur->m_animaux[stoi(v1)]->getPrix('A')) {
                                    cout << "Vous n'avez pas assez d'argent pour acheter cet animal!" << endl;
                                } else {
                                    printf("Choisissez un enclos pour l'animal: \n");
                                    for (int i = 0; i < zooLife->m_enclos.size(); i++) {
                                        printf("- Enclos %s (%i)\n", zooLife->m_enclos[i]->getName().c_str(), i);
                                    }
                                    printf("Entrer le numero de l'enclos ou Entree pour revenir en arriere: \n");
                                    string v2;
                                    getline(cin, v2);
                                    while (stoi(v2) >= zooLife->m_enclos.size() || stoi(v2) < 0) {
                                        printf("Entrer le numero de l'enclos ou Entree pour revenir en arriere: \n");
                                        getline(cin, v2);
                                    }
                                    if (!v2.empty()) {
                                        if (stoi(v2) < zooLife->m_enclos.size() && stoi(v2) >= 0) {
                                            zooLife->buyAnimal(zooLife->m_enclos[stoi(v2)],
                                                               vendeur->m_animaux[stoi(v1)]);
                                            if (zooLife->getBudget() < vendeur->m_animaux[stoi(v1)]->getPrix('A')) {
                                                cout << "Vous n'avez pas assez d'argent pour acheter cet animal!" << endl;
                                                continue;
                                            } else if (zooLife->m_enclos[stoi(v2)]->getTypeAnimal() !=
                                                       vendeur->m_animaux[stoi(v1)]->getTypeAnimal()) {
                                                cout << "Enclos incompatible!" << endl;
                                                continue;
                                            } else if (zooLife->m_enclos[stoi(v2)]->m_animaux.size() >=
                                                       zooLife->m_enclos[stoi(v2)]->getCapacite()) {
                                                cout << "Enclos plein!" << endl;
                                                continue;
                                            } else {
                                                vendeur->m_animaux.erase(vendeur->m_animaux.begin() + stoi(v1));
                                                cout << "Animal achete!" << endl;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if (AnimalRep == "2") {
                            cout << "--- Vendre un animal ---" << endl;
                            printf("Choisissez un enclos: \n");
                            for (int i = 0; i < zooLife->m_enclos.size(); i++) {
                                printf("- Enclos %s (%i)\n", zooLife->m_enclos[i]->getName().c_str(), i);
                            }
                            printf("Entrer le numero de l'enclos ou Entree pour revenir en arriere: \n");
                            string numEnclos;
                            getline(cin, numEnclos);
                            while (stoi(numEnclos) >= zooLife->m_enclos.size() || stoi(numEnclos) < 0) {
                                printf("Entrer le numero de l'enclos ou Entree pour revenir en arriere: \n");
                                getline(cin, numEnclos);
                            }
                            if (!numEnclos.empty()) {
                                for (int j = 0; j < zooLife->m_enclos[stoi(numEnclos)]->m_animaux.size(); j++) {
                                    printf("- %s (%i): %.2f$\n",
                                           zooLife->m_enclos[stoi(numEnclos)]->m_animaux[j]->getName().c_str(), j,
                                           zooLife->m_enclos[stoi(numEnclos)]->m_animaux[j]->getPrix('V'));
                                }
                                printf("Entrer le numero de l'animal que vous voulez vendre ou Entree pour revenir en arriere: \n");
                                string numAnimal;
                                getline(cin, numAnimal);
                                while (stoi(numAnimal) >= zooLife->m_enclos[stoi(numEnclos)]->m_animaux.size() || stoi(numAnimal) < 0) {
                                    printf("Entrer le numero de l'animal que vous voulez vendre ou Entree pour revenir en arriere: \n");
                                }
                                if (!numAnimal.empty()) {
                                    zooLife->sellAnimal(zooLife->m_enclos[stoi(numEnclos)],
                                                        zooLife->m_enclos[stoi(numEnclos)]->m_animaux[stoi(numAnimal)]);
                                    vendeur->m_animaux.push_back(zooLife->m_enclos[stoi(numEnclos)]->m_animaux[stoi(numAnimal)]);
                                    // print nom de l'animal vendu pour Prix de vente
                                    printf("%s vendu pour %.2f$\n",
                                           zooLife->m_enclos[stoi(numEnclos)]->m_animaux[stoi(numAnimal)]->getName().c_str(),
                                           zooLife->m_enclos[stoi(numEnclos)]->m_animaux[stoi(numAnimal)]->getPrix('V'));
                                }
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
                            for (int i = 0; i < vendeur->m_habitats.size(); i++) {
                                printf("- Enclos %s (%i): %.2f$\n", vendeur->m_habitats[i]->getName().c_str(), i,
                                       vendeur->m_habitats[i]->getPrix('A'));
                            }
                            printf("Entrer le numero de l'enclos ou Entree pour revenir en arriere: \n");
                            string numEnclos;
                            getline(cin, numEnclos);
                            while (stoi(numEnclos) >= vendeur->m_habitats.size() || stoi(numEnclos) < 0) {
                                printf("Entrer le numero de l'enclos ou Entree pour revenir en arriere: \n");
                                getline(cin, numEnclos);
                            }
                            if (!numEnclos.empty()) {
                                if (zooLife->getBudget() < vendeur->m_habitats[stoi(numEnclos)]->getPrix('A')) {
                                    cout << "Vous n'avez pas assez d'argent pour acheter cet enclos!" << endl;
                                    continue;
                                } else {
                                    zooLife->buyHabitat(vendeur->m_habitats[stoi(numEnclos)]->getName(), vendeur->m_habitats[stoi(numEnclos)]->getTypeAnimal());
                                    vendeur->m_habitats.erase(vendeur->m_habitats.begin() + stoi(numEnclos));
                                    printf("Enclos %s achete pour %.2f$",
                                           vendeur->m_habitats[stoi(numEnclos)]->getName().c_str(),
                                           vendeur->m_habitats[stoi(numEnclos)]->getPrix('A'));
                                }
                            } else {
                                continue;
                            }

                        } else if (HabitatRep == "2") {
                            cout << "Vendre un habitat" << endl;
                            for (int i = 0; i < zooLife->m_enclos.size(); i++) {
                                printf("- Enclos %s (%i)\n", zooLife->m_enclos[i]->getName().c_str(), i);
                            }
                            printf("Entrer le numero de l'enclos ou Entree pour revenir en arriere: \n");
                            string numEnclos;
                            getline(cin, numEnclos);
                            while (stoi(numEnclos) >= zooLife->m_enclos.size() || stoi(numEnclos) < 0) {
                                printf("Entrer le numero de l'enclos ou Entree pour revenir en arriere: \n");
                                getline(cin, numEnclos);
                            }
                            if (!numEnclos.empty()) {
                                if (zooLife->m_enclos[stoi(numEnclos)]->m_animaux.size() > 0) {
                                    cout << "Vous ne pouvez pas vendre un enclos avec des animaux dedans!" << endl;
                                    continue;
                                } else {
                                    printf("%s vendu pour %.2f$\n", zooLife->m_enclos[stoi(numEnclos)]->getName().c_str(),
                                           zooLife->m_enclos[stoi(numEnclos)]->getPrix('V'));
                                    zooLife->sellHabitat(zooLife->m_enclos[stoi(numEnclos)]);
                                    vendeur->m_habitats.push_back(zooLife->m_enclos[stoi(numEnclos)]);
                                }
                            } else {
                                continue;
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
                            for (int i = 0; i < vendeur->m_aliments.size(); i++) {
                                printf("- %s (%i): %.2f$/Kg\n", vendeur->m_aliments[i]->getNom().c_str(), i,
                                       vendeur->m_aliments[i]->getPrixKg());
                            }
                            printf("Entrer le numero de l'aliment ou Entree pour revenir en arriere: \n");
                            string numAliment;
                            getline(cin, numAliment);
                            while (stoi(numAliment) >= vendeur->m_aliments.size() || stoi(numAliment) < 0) {
                                printf("Entrer le numero de l'aliment ou Entree pour revenir en arriere: \n");
                                getline(cin, numAliment);
                            }
                            if (!numAliment.empty()) {
                                printf("Combien de kg voulez-vous acheter ?\n");
                                string kg;
                                getline(cin, kg);
                                while (stoi(kg) < 0) {
                                    printf("Combien de kg voulez-vous acheter ?\n");
                                    getline(cin, kg);
                                }
                                if (zooLife->getBudget() < vendeur->m_aliments[stoi(numAliment)]->getPrixKg() * stoi(kg)) {
                                    cout << "Vous n'avez pas assez d'argent pour acheter cet aliment!" << endl;
                                    continue;
                                } else {
                                    zooLife->buyAliment(vendeur->m_aliments[stoi(numAliment)]->getFoodType(), stoi(kg));
                                    printf("%s achete pour %.2f$\n", vendeur->m_aliments[stoi(numAliment)]->getNom().c_str(),
                                           vendeur->m_aliments[stoi(numAliment)]->getPrixKg() * stoi(kg));
                                }
                            } else {
                                continue;
                            }
                        } else if (NourritureRep == "2") {
                            cout << "Vendre de la nourriture" << endl;
                            for (int i = 0; i < zooLife->m_stockAliment.size(); i++) {
                                printf("-[%i] %s (%.2f/Kg): %.2f$/Kg\n", i, zooLife->m_stockAliment[i]->getNom().c_str(), zooLife->m_stockAliment[i]->getQuantite(), zooLife->m_stockAliment[i]->getPrixKg());
                            }
                            printf("Entrer le numero de l'aliment ou Entree pour revenir en arriere: \n");
                            string numAliment;
                            getline(cin, numAliment);
                            while (stoi(numAliment) >= zooLife->m_stockAliment.size() || stoi(numAliment) < 0) {
                                printf("Entrer le numero de l'aliment ou Entree pour revenir en arriere: \n");
                                getline(cin, numAliment);
                            }
                            if (!numAliment.empty()) {
                                printf("Combien de kg voulez-vous vendre ?\n");
                                string kg;
                                getline(cin, kg);
                                while (stoi(kg) < 0) {
                                    printf("Combien de kg voulez-vous vendre ?\n");
                                    getline(cin, kg);
                                }
                                if (zooLife->m_stockAliment[stoi(numAliment)]->getQuantite() < stoi(kg)) {
                                    cout << "Vous n'avez pas assez de nourriture pour vendre cet aliment!" << endl;
                                    continue;
                                } else {
                                    zooLife->sellAliment(zooLife->m_stockAliment[stoi(numAliment)]->getFoodType(), stoi(kg));
                                    printf("%s vendu pour %.2f$\n", zooLife->m_stockAliment[stoi(numAliment)]->getNom().c_str(),
                                           zooLife->m_stockAliment[stoi(numAliment)]->getPrixKg() * stoi(kg));
                                }
                            } else {
                                continue;
                            }
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

//
//
//
//
//            if (a < zooLife->m_enclos[e]->m_animaux.size() && a >= 0) {
//                zooLife->m_enclos[e]->m_animaux[a]->show();
//                printf("Appuyez sur Entree pour continuer...");
//                cin.get();
//                cout << endl;
//                printf("Souhaitez-vous interagir avec cet animal ? (O/N)\n");
//                string an1;
//                getline(cin, an1);
//                if (an1 == "O" || an1 == "o") {
//                    string an2;
//                    while (an2 != "4") {
//                        printf("Que souhaitez-vous faire ?\n\t-> Renommer l'animal (1)\n\t-> Le changer d'enclos (2)\n\t-> Le soigner (3)\n\t-> Sortir (4)\n");
//                        getline(cin, an2);
//                        if (an2 == "1") {
//                            printf("Entrer le nouveau nom de l'animal: \n");
//                            string an3;
//                            getline(cin, an3);
//                            zooLife->m_enclos[e]->m_animaux[a]->setNom(an3);
//                            printf("Le nom de l'animal a ete change en %s\n",
//                                   zooLife->m_enclos[e]->m_animaux[a]->getName().c_str());
//                            printf("Appuyez sur Entree pour continuer...");
//                            cin.get();
//                            cout << endl;
//                        } else if (an2 == "2") {
//                            printf("---- Enclos ----\n");
//                            for (int i = 0; i < zooLife->m_enclos.size(); i++) {
//                                printf("- Enclos %s (%i)\n", zooLife->m_enclos[i]->getName().c_str(), i);
//                            }
//                            printf("Entrer le numero de l'enclos ou vous voulez le mettre: \n");
//                            string an3;
//                            getline(cin, an3);
//                            while (stoi(an3) >= zooLife->m_enclos.size() || stoi(an3) < 0) {
//                                printf("Entrer le numero de l'enclos ou vous voulez le mettre: \n");
//                                getline(cin, an3);
//                            }
//                            if (!an3.empty()) {
//                                int an4 = stoi(an3);
//                                if (an4 < zooLife->m_enclos.size() && an4 >= 0) {
//                                    zooLife->m_enclos[an4]->addAnimal(zooLife->m_enclos[e]->m_animaux[a]);
//                                    zooLife->m_enclos[e]->m_animaux.erase(
//                                            zooLife->m_enclos[e]->m_animaux.begin() + a);
//                                }
//                            }
//                            printf("Appuyez sur Entree pour continuer...");
//                            cin.get();
//                            cout << endl;
//                        } else if (an2 == "3") {
//                            if (zooLife->m_enclos[e]->m_animaux[a]->getMaladie() > 0) {
//                                if (zooLife->getBudget() >
//                                    float(zooLife->m_enclos[e]->m_animaux[a]->getMaladie()) * 1000) {
//                                    printf("Soigner l'animal pour %i$ ? (O/N)\n",
//                                           zooLife->m_enclos[e]->m_animaux[a]->getMaladie() * 1000);
//                                    string s1;
//                                    getline(cin, s1);
//                                    if (s1 == "O" || s1 == "o") {
//                                        zooLife->removeBudget(
//                                                float(zooLife->m_enclos[e]->m_animaux[a]->getMaladie()) *
//                                                1000);
//                                        zooLife->m_enclos[e]->m_animaux[a]->setMaladie(0);
//                                        printf("L'animal a ete soigne !\n");
//                                        printf("Appuyez sur Entree pour continuer...");
//                                        cin.get();
//                                        cout << endl;
//                                    } else {
//                                        printf("L'animal n'a pas ete soigne !\n");
//                                        printf("Appuyez sur Entree pour continuer...");
//                                        cin.get();
//                                        cout << endl;
//                                    }
//                                } else {
//                                    printf("Vous n'avez pas assez d'argent pour soigner l'animal !\n");
//                                    printf("Appuyez sur Entree pour continuer...");
//                                    cin.get();
//                                    cout << endl;
//                                }
//                            } else {
//                                printf("L'animal n'est pas malade !\n");
//                                printf("Appuyez sur Entree pour continuer...");
//                                cin.get();
//                                cout << endl;
//                            }
//                        }
//                    }
//                } else {
//                    printf("Appuyez sur Entree pour continuer...");
//                    cin.get();
//                    cout << endl;
//                }
//            }
//        }
//    } else {
//}

//void showMyZoo(Zoo *zooLife) {
//    zooLife->show();
//    etapePause();
//    printf("---- Enclos ----\n");
//    for (int i = 0; i < zooLife->m_enclos.size(); i++) {
//        printf("- Enclos %s (%i)\n", zooLife->m_enclos[i]->getName().c_str(), i);
//    }
//    printf("Numero de l'enclos que vous voulez voir ('Entree' pour sortir): \n");
//    string rep1;
//    getline(cin, rep1);
//    if (rep1.empty() || rep1 == " ") {
//        return;
//    }
//    int numEnclos = stoi(rep1);
//    if (numEnclos >= zooLife->m_enclos.size() || numEnclos < 0) {
//        printf("'%i' n'est pas un numero d'enclos valide.\n", numEnclos);
//        return;
//    }
//    while (numEnclos >= zooLife->m_enclos.size() || numEnclos < 0 || numEnclos) {
//        printf("Entrer le numero de l'enclos que vous voulez voir ou Entree pour revenir en arriere: \n");
//        getline(cin, rep1);
//    }
//
//        int e = stoi(rep1);
//        if (e < zooLife->m_enclos.size() && e >= 0) {
//            zooLife->m_enclos[e]->show();
//            printf("Appuyez sur Entree pour continuer...");
//            cin.get();
//            for (int i = 0; i < zooLife->m_enclos[e]->m_animaux.size(); i++) {
//                printf("- %s (%i)\n", zooLife->m_enclos[e]->m_animaux[i]->getName().c_str(), i);
//            }
//            printf("Entrer le numero de l'animal que vous voulez voir ou Entree pour revenir en arriere: \n");
//            string a1;
//            getline(cin, a1);
//            if (!a1.empty()) {
//                while (stoi(a1) >= zooLife->m_enclos[e]->m_animaux.size() || stoi(a1) < 0) {
//                    printf("Entrer le numero de l'animal que vous voulez voir ou Entree pour revenir en arriere: \n");
//                    getline(cin, a1);
//                }
//                int a = stoi(a1);
//                if (a < zooLife->m_enclos[e]->m_animaux.size() && a >= 0) {
//                    zooLife->m_enclos[e]->m_animaux[a]->show();
//                    printf("Appuyez sur Entree pour continuer...");
//                    cin.get();
//                    cout << endl;
//                    printf("Souhaitez-vous interagir avec cet animal ? (O/N)\n");
//                    string an1;
//                    getline(cin, an1);
//                    if (an1 == "O" || an1 == "o") {
//                        string an2;
//                        while (an2 != "4") {
//                            printf("Que souhaitez-vous faire ?\n\t-> Renommer l'animal (1)\n\t-> Le changer d'enclos (2)\n\t-> Le soigner (3)\n\t-> Sortir (4)\n");
//                            getline(cin, an2);
//                            if (an2 == "1") {
//                                printf("Entrer le nouveau nom de l'animal: \n");
//                                string an3;
//                                getline(cin, an3);
//                                zooLife->m_enclos[e]->m_animaux[a]->setNom(an3);
//                                printf("Le nom de l'animal a ete change en %s\n",
//                                       zooLife->m_enclos[e]->m_animaux[a]->getName().c_str());
//                                printf("Appuyez sur Entree pour continuer...");
//                                cin.get();
//                                cout << endl;
//                            } else if (an2 == "2") {
//                                printf("---- Enclos ----\n");
//                                for (int i = 0; i < zooLife->m_enclos.size(); i++) {
//                                    printf("- Enclos %s (%i)\n", zooLife->m_enclos[i]->getName().c_str(), i);
//                                }
//                                printf("Entrer le numero de l'enclos ou vous voulez le mettre: \n");
//                                string an3;
//                                getline(cin, an3);
//                                while (stoi(an3) >= zooLife->m_enclos.size() || stoi(an3) < 0) {
//                                    printf("Entrer le numero de l'enclos ou vous voulez le mettre: \n");
//                                    getline(cin, an3);
//                                }
//                                if (!an3.empty()) {
//                                    int an4 = stoi(an3);
//                                    if (an4 < zooLife->m_enclos.size() && an4 >= 0) {
//                                        zooLife->m_enclos[an4]->addAnimal(zooLife->m_enclos[e]->m_animaux[a]);
//                                        zooLife->m_enclos[e]->m_animaux.erase(
//                                                zooLife->m_enclos[e]->m_animaux.begin() + a);
//                                    }
//                                }
//                                printf("Appuyez sur Entree pour continuer...");
//                                cin.get();
//                                cout << endl;
//                            } else if (an2 == "3") {
//                                if (zooLife->m_enclos[e]->m_animaux[a]->getMaladie() > 0) {
//                                    if (zooLife->getBudget() >
//                                        float(zooLife->m_enclos[e]->m_animaux[a]->getMaladie()) * 1000) {
//                                        printf("Soigner l'animal pour %i$ ? (O/N)\n",
//                                               zooLife->m_enclos[e]->m_animaux[a]->getMaladie() * 1000);
//                                        string s1;
//                                        getline(cin, s1);
//                                        if (s1 == "O" || s1 == "o") {
//                                            zooLife->removeBudget(
//                                                    float(zooLife->m_enclos[e]->m_animaux[a]->getMaladie()) *
//                                                    1000);
//                                            zooLife->m_enclos[e]->m_animaux[a]->setMaladie(0);
//                                            printf("L'animal a ete soigne !\n");
//                                            printf("Appuyez sur Entree pour continuer...");
//                                            cin.get();
//                                            cout << endl;
//                                        } else {
//                                            printf("L'animal n'a pas ete soigne !\n");
//                                            printf("Appuyez sur Entree pour continuer...");
//                                            cin.get();
//                                            cout << endl;
//                                        }
//                                    } else {
//                                        printf("Vous n'avez pas assez d'argent pour soigner l'animal !\n");
//                                        printf("Appuyez sur Entree pour continuer...");
//                                        cin.get();
//                                        cout << endl;
//                                    }
//                                } else {
//                                    printf("L'animal n'est pas malade !\n");
//                                    printf("Appuyez sur Entree pour continuer...");
//                                    cin.get();
//                                    cout << endl;
//                                }
//                            }
//                        }
//                    } else {
//                        printf("Appuyez sur Entree pour continuer...");
//                        cin.get();
//                        cout << endl;
//                    }
//                }
//            }
//        } else {
//            printf("Erreur: Numero d'enclos invalide !\n");
//        }
//    }





int main() {
    scenario();
    return 0;
}

// TODO: Maladie => 1ans
// TODO:

// ✅ => Complete
// ⭐️ => Optimised