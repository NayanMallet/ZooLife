#include <unordered_set>
#include "Habitat.h"
#include <algorithm>
#include <random>
#include "../Functions/functions.h"

using namespace std;

Habitat::Habitat(string nom, AnimalType typeAnimal) : m_nom(nom), m_typeAnimal(typeAnimal) {
    switch (typeAnimal) {
        case AnimalType::TIGRE:
            m_capacite = 2;
            m_prixAchat = 2000;
            m_prixVente = 500;
            m_probaMaladie = 20;
        case AnimalType::AIGLE:
            m_capacite = 4;
            m_prixAchat = 2000;
            m_prixVente = 500;
            m_probaMaladie = 10;
        case AnimalType::POULE:
            m_capacite = 10;
            m_prixAchat = 300;
            m_prixVente = 50;
            m_probaMaladie = 5;
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
    printf("----- Habitat %s (%s) -----\n"
           "=> Capacité: %d\n"
           "=> Prix d'achat: %i€\n"
           "=> Prix de vente: %i€\n"
           "=> Perte liée à la surpopulation (50%% de chance): %s\n"
           "=> Probabilité d'être malade: %.2f%%\n"
           "=> Animaux: %zu/%d\n"
           "Liste des animaux:\n%s"
           "---------------------------\n",
           m_nom.c_str(), animalTypeToString(m_typeAnimal).c_str(),
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
        result += (animal ? "-> " + (*animal).getName() + " (" + dateConverter((*animal).getAge()) + ")\n" : "-> Vide\n");
    }
    return result;
}

// Afficher les animaux de l'habitat ⭐️
void Habitat::showAnimals() const {
    printf(
            "----- Habitat %s (%s) -----\n"
            "%s"
            "---------------------------\n",
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
        printf("Impossible d'ajouter l'animal à l'habitat !\n");
        return;
    }

    // Vérifier si la capacité est atteinte
    if (m_animaux.size() >= m_capacite) {
        printf("Capacité dépassée, des risques de surpopulation sont présents !\n");
        m_perteSurPop = true;
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