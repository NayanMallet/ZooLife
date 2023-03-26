#include <unordered_set>
#include "Habitat.h"
#include <algorithm>
#include <random>
#include "../Functions/functions.h"
#include "../Animaux/Tigre.h"
#include "../Animaux/Aigle.h"
#include "../Animaux/Poule.h"
#include "../Animaux/Coq.h"

using namespace std;

Habitat::Habitat(string nom, AnimalType typeAnimal) : m_nom(nom), m_typeAnimal(typeAnimal) {
    switch (typeAnimal) {
        case AnimalType::TIGRE:
            m_capacite = 2;
            m_prixAchat = 2000;
            m_prixVente = 500;
            m_probaMaladie = 20;
            break;
        case AnimalType::AIGLE:
            m_capacite = 4;
            m_prixAchat = 2000;
            m_prixVente = 500;
            m_probaMaladie = 10;
            break;
        case AnimalType::POULE:
            m_capacite = 10;
            m_prixAchat = 300;
            m_prixVente = 50;
            m_probaMaladie = 5;
            break;
        default:
            break;
    }
}

// Destructeur de la classe Habitat ⭐️
Habitat::~Habitat() {
    for (auto animal : m_animaux) {
        delete animal;
    }
    m_animaux.clear();
}

// Afficher les informations de l'habitat ⭐️
void Habitat::show() const {
    printf("----- %s -----\n"
           "=> Capacite: %d\n"
           "=> Prix d'achat: %i$\n"
           "=> Prix de vente: %i$\n"
           "=> Perte liee a la surpopulation (50%% de chance): %s\n"
           "=> Probabilite d'etre malade: %.2f%%\n"
           "=> Animaux: %zu/%d\n"
           "Liste des animaux:\n%s"
           "------------------------------\n",
           m_nom.c_str(),
           m_capacite,
           m_prixAchat, m_prixVente,
           m_perteSurPop ? "Oui" : "Non",
           m_probaMaladie,
           m_animaux.size(), m_capacite,
           listAnimals().c_str()
    );
}

// Retourne la liste les animaux de l'habitat ⭐️
string Habitat::listAnimals() const {
    string result;
    for (const auto& animal : m_animaux) {
        result += (animal ? "-> " + (*animal).getName() + " (" + dateConverter((*animal).getAge()) + ")" + (animal->getMaladie() > 0 ? "Malade" : "") + "\n" : "-> Vide\n");
    }
    return result;
}

// Afficher les animaux de l'habitat ⭐️
void Habitat::showAnimals() const {
    printf(
            "----- Habitat %s (%s) -----\n"
            "%s"
            "------------------------------\n",
            m_nom.c_str(), animalTypeToString(m_typeAnimal).c_str(),
            listAnimals().c_str()
    );
}

// Getters class Habitat ⭐️
const string& Habitat::getName() const { return m_nom; }
int Habitat::getCapacite() const { return m_capacite; }
int Habitat::getNbrOfAnimals() const { return m_animaux.size(); }
AnimalType Habitat::getTypeAnimal() const { return m_typeAnimal; }

// Ajouter un animal à l'habitat ⭐️
void Habitat::addAnimal(IAnimal* animal) {
    // Vérifier si l'animal est du mauvais type
    if (animal->getTypeAnimal() != m_typeAnimal) {
        printf("Impossible d'ajouter l'animal a l'habitat !\n");
        return;
    }

    // Vérifier si la capacité est atteinte
    if (m_animaux.size() >= m_capacite) {
        printf("Capacite depassee, des risques de surpopulation sont presents !\n");
        m_perteSurPop = true;
    }

    // Les animaux ne se reproduisent pas avant 1 mois
    if (animal->getAge() >= animal->getMaturingTime()) {
        animal->setMaturingTime(animal->getAge() + 31);
    } else {
        animal->setMaturingTime(animal->getMaturingTime() + 31);
    }

    // Ajouter l'animal
    m_animaux.push_back(animal);
}

// Enlever un animal de l'habitat ⭐️
void Habitat::removeAnimal(IAnimal* animal) {
// Vérifier si l'habitat est vide ou si l'animal est du mauvais type
    if (m_animaux.empty() || (animal->getTypeAnimal() != m_typeAnimal)) {
        printf("Impossible d'enlever l'animal de l'habitat !\n");
        return;
    }

    // Vérifier si la capacité est atteinte
    if (m_animaux.size() <= m_capacite) {
        m_perteSurPop = false;
    }

// Enlever l'animal
    m_animaux.erase(std::remove(m_animaux.begin(), m_animaux.end(), animal), m_animaux.end());
}

// Verifier si l'animal est dans l'habitat ⭐️
bool Habitat::verifAnimal(IAnimal* animal) {
    return std::find(m_animaux.begin(), m_animaux.end(), animal) != m_animaux.end();
}

// Retourne le prix d'achat d'un habitat ⭐️
float Habitat::getPrix(char type) const {
    float prix = 0;
    switch (m_typeAnimal) {
        case AnimalType::TIGRE:
        case AnimalType::AIGLE:
            prix = (type == 'A') ? 2000 : 500;
            break;
        case AnimalType::POULE:
            prix = (type == 'A') ? 300 : 50;
            break;
        default:
            break;
    }
    return prix;
}

// Gestion de la surpopulation ⭐️
void Habitat::PerteSurpopulation() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::bernoulli_distribution dist(0.5);

    if (!dist(gen)) {
        printf("Pas de perte surpopulation !\n");
        return;
    }

    // Stocker le type d'animal dans une variable locale pour éviter de l'appeler plusieurs fois
    AnimalType type = Habitat::getTypeAnimal();

    switch (type) {
        case AnimalType::TIGRE:
        case AnimalType::AIGLE:
            if (m_animaux.empty()) {
                return;
            }
            m_animaux.erase(m_animaux.begin() + rand() % m_animaux.size());
            printf("Un %s est mort de surpopulation !\n", (type == AnimalType::TIGRE ? "tigre" : "aigle"));
            break;

        case AnimalType::POULE:
            if (m_animaux.size() < 4) {
                m_animaux.clear();
                printf("Toutes les poules sont mortes de surpopulation !\n");
            } else {
                for (int i = 0; i < 4; i++) {
                    m_animaux.erase(m_animaux.begin() + rand() % m_animaux.size());
                }
                printf("Quatre poules sont mortes de surpopulation !\n");
            }
            break;

        default:
            return;
    }

    // Vérifier si la capacité est atteinte
    if (m_animaux.size() <= m_capacite) {
        m_perteSurPop = false;
    }
}

// Update de l'habitat ⭐️
void Habitat::update(const string& month, Aliment *food, Habitat *habitat) {
    // update Portee
    AnimalType type = Habitat::getTypeAnimal();
    bool hasMale = false;
    for (auto& animal : m_animaux) {
        if (animal->getSexe() == 'M' && animal->getReproduction()) {
            hasMale = true;
            break;
        }
    }

    if (hasMale) {
        switch (type) {
            case AnimalType::TIGRE:
                // 3 individus tout les 620 jours = 20 mois
                for (auto& animal : m_animaux) {
                    if (animal->getSexe() == 'F' && animal->getReproduction()) {
                        animal->setPortee(true);
                        animal->setReproduction(false);
                        animal->setGestation(93); // 3 mois
                        animal->setMaturingTime(animal->getAge() + 93 + 620); // ne peut plus se reproduire avant 20 mois
                        auto mere = animal;
                        removeAnimal(mere);
                        habitat->addAnimal(mere);
                        cout << "Un tigre est enceinte pour 45 jours !" << endl
                             << "Il est place en gestation pour accueillir la portee." << endl;
                    }
                }
                break;
            case AnimalType::AIGLE:
                // 2 oeufs
                if (month == "MARS") {
                    for (auto& animal : m_animaux) {
                        if (animal->getSexe() == 'F' && animal->getReproduction()) {
                            animal->setPortee(true);
                            animal->setReproduction(false);
                            animal->setGestation(45); // 45 jours
                            auto mere = animal;
                            removeAnimal(mere);
                            habitat->addAnimal(mere);
                            cout << "Un aigle est enceinte pour 45 jours !" << endl
                                << "Il est place en gestation pour accueillir la portee." << endl;
                        }
                    }
                }
                break;
            case AnimalType::POULE:
                // 25 œufs / 6 semaines (1ans = 8*6semaines)
                for (auto& animal : m_animaux) {
                    if (animal->getSexe() == 'F' && animal->getReproduction()) {
                        static std::random_device rd;
                        static std::mt19937 gen(rd());
                        int m = int(0.5);
                        static std::bernoulli_distribution distS(m);
                        if (distS(gen)) {
                            animal->setPortee(true);
                            animal->setReproduction(false);
                            animal->setGestation(42); // 6 semaines
                            auto mere = animal;
                            removeAnimal(mere);
                            habitat->addAnimal(mere);
                            cout << "Une poule est enceinte pour 6 semaines !" << endl
                                 << "Il est place en gestation pour accueillir la portee." << endl;
                        }
                    }
                }
                break;
            default:
                break;
        }
    }


    for (int i = 0; i < 31; i++) {
        // Vérifier si l'habitat est vide
        if (m_animaux.empty()) {
            return;
        }
        for (auto &animal: m_animaux) {
            // Vérifier si l'animal est mort
            if (animal->getDead()) {
                m_animaux.erase(std::remove(m_animaux.begin(), m_animaux.end(), animal), m_animaux.end());
                continue;
            }

            animal->update(food);

            // update de la reproduction
            if (animal->getAge() <= animal->getMaturingTime() || animal->getAge() >= animal->getEndMaturingTime() || animal->getMaladie() > 0 || getNbrOfAnimals() > m_capacite ) {
                animal->setReproduction(false);
            } else {
                if (animal->getFed()) {
                    cout << animal->getName() << " ne peut pas se reproduire car il a faim !" << endl;
                    return;
                }
                animal->setReproduction(true);
            }

        }

        for (auto &animal : habitat->m_animaux) {
            // Vérifier si l'animal est mort
            if (animal->getDead()) {
                m_animaux.erase(std::remove(m_animaux.begin(), m_animaux.end(), animal), m_animaux.end());
                continue;
            }

            animal->update(food);

            // Update Gestation
            if (animal->getGestation() > 0) {
                animal->setGestation(animal->getGestation() - 1);
            } else if (animal->getGestation() == 0 && animal->getPortee()) {
                // Naissance
                cout << "----- Naissances -----" << endl;
                animal->setPortee(false);
                static std::random_device rd;
                static std::mt19937 gen(rd());
                static std::bernoulli_distribution distS(0.5);
                static std::bernoulli_distribution distT(0.33);
                static std::bernoulli_distribution distAP(0.5);
                switch (type) {
                    case AnimalType::TIGRE:
                        // 3 individus
                        for (int j = 1; j <= 3; j++) {
                            if (distT(gen)) {
                                printf("Un bebe tigre n'as pas survecu a l'accouchement !\n");
                            } else {
                                char genre = distS(gen) ? 'M' : 'F';
                                habitat->addAnimal(new Tigre("Bebe tigre", genre, 0));
                                printf("Un bebe tigre (%c) est nee !\n", genre);
                            }
                        }
                        break;
                    case AnimalType::AIGLE:
                        // 2 oeufs
                        for (int j = 1; j <= 2; j++) {
                            if (distAP(gen)) {
                                printf("Un bebe aigle n'as pas survecu a l'accouchement !\n");
                            } else {
                                char genre = distS(gen) ? 'M' : 'F';
                                habitat->addAnimal(new Aigle("Bebe aigle", genre, 0));
                                printf("Un bebe aigle (%c) est nee !\n", genre);
                            }
                        }
                        break;
                    case AnimalType::POULE:
                        // 25 oeufs
                        for (int j = 1; j <= 25; j++) {
                            if (distAP(gen)) {
                                printf("Un poussin n'as pas survecu a l'accouchement !\n");
                            } else {
                                char genre = distS(gen) ? 'M' : 'F';
                                if (genre == 'M') {
                                    habitat->addAnimal(new Coq("Bebe coq", 0));
                                    printf("Un poussin (M) est nee !\n");
                                } else {
                                    habitat->addAnimal(new Poule("Bebe poule", 0));
                                    printf("Un poussin (F) est nee !\n");
                                }
                            }
                        }
                        break;
                    default:
                        break;
                }
                cout << "----------------------" << endl;
            }
        }
    }
}


// Maladie annuelle ⭐️
void Habitat::MaladieAnnuelle() {
    if (m_animaux.empty()) {
        return;
    }
    // Stocker le type d'animal dans une variable locale pour éviter de l'appeler plusieurs fois
    AnimalType type = Habitat::getTypeAnimal();
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::bernoulli_distribution dist_mort(0.1); // Probabilité que l'animal meure dès le début
    static std::bernoulli_distribution dist_maladie((type == AnimalType::TIGRE) ? 0.3 : (type == AnimalType::AIGLE) ? 0.1 : 0.05); // Probabilité de contracter la maladie
    int choixAnimal = rand() % m_animaux.size();
    if (dist_mort(gen)) {
        // Un animal est mort dès le début de l'année
        cout << m_animaux[choixAnimal]->getName() << " de l'habitat " << getName() << " est mort dès le début de l'année !" << endl;
        m_animaux[choixAnimal]->setDead(true);
        return;
    }

    if (!dist_maladie(gen)) {
        // Pas de maladie annuelle
        cout << "Pas de maladie annuelle dans l'habitat " << getName() << " !" << endl;
        return;
    }

    // Durée de la maladies en fonctions du type d'animal
    int  duree = (type == AnimalType::TIGRE) ? 15 : (type == AnimalType::AIGLE) ? 30 : 5;
    // Calcul de la variation de durée
    std::uniform_real_distribution<float> distVariation(-0.2, 0.2);
    float variation = distVariation(gen);
    duree = int(duree * (1.0 + variation));

    // Passe la maladie à un animal au hasard de l'habitat
    cout << m_animaux[choixAnimal]->getName() << " de l'habitat " << getName() << " est tombé malade pour une durée de " << duree << " jours !" << endl;
    m_animaux[choixAnimal]->setMaladie(duree);
}

void Habitat::setName(const string &name) {
    m_nom = name;
}
