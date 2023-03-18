#include "Zoo.h"
#include <string>
#include <algorithm>
#include "../Functions/functions.h"

using namespace std;


// Constructeur de la classe Zoo ⭐️
Zoo::Zoo(string nom):m_name(nom) {}

// Destructeur de la classe Zoo ⭐️
Zoo::~Zoo() {
    for (auto& habitat : m_enclos) {
        delete habitat;
    }
    m_enclos.clear();
}


void Zoo::show() const {
    printf("----- Zoo %s -----\n"
           "=> Age: %s\n"
           "=> Stock Aliment:\n"
           "   -> Graines: %.2f\n"
           "   -> Viande: %.2f\n"
           "=> Budget: %.2f$\n"
           "=> Nombre d'Enclos: %i\n"
           "=> Liste des Enclos:\n%s"
           "---------------------------\n",
           m_name.c_str(),
           dateConverter(m_days).c_str(),
           m_stockAliment[0]->getQuantite(),
           m_stockAliment[1]->getQuantite(),
           m_budget->getBudget(),
           getNbrOfEnclos(),
           listHabitats().c_str()
    );
}

// Afficher le nom du Zoo ⭐️
void Zoo::showHabitats() const {
    printf(
            "----- Zoo %s -----\n"
            "%s"
            "---------------------------\n",
            m_name.c_str(),
            listHabitats().c_str()
    );
}

// Retourne la liste des Habitats du Zoo ⭐️
string Zoo::listHabitats() const {
    string result;
    for (const auto& habitat : m_enclos) {
        result += ((!m_enclos.empty()) ? "-> " + habitat->getName() + "(" + animalTypeToString(habitat->getTypeAnimal()) + ") : " + to_string(habitat->getNbrOfAnimals()) + "/" + to_string(habitat->getCapacite()) + "\n" : "-> Vide\n");
    }
    return result;
}

// Getters de la classe Zoo ⭐️
const string & Zoo::getName() const { return m_name; }
int Zoo::getNbrOfEnclos() const { return m_enclos.size(); }

// Ajouter un habitat au Zoo ⭐️
void Zoo::addHabitat(Habitat *habitat) {
    m_enclos.push_back(habitat);
}

// Enlever un habitat du Zoo ⭐
void Zoo::removeHabitat(Habitat *habitat) {
// Chercher l'indice de l'habitat dans le vecteur
    auto it = find(m_enclos.begin(), m_enclos.end(), habitat);

    // Si l'habitat est dans le Zoo, le supprimer
    if (it != m_enclos.end()) {
        m_enclos.erase(it);
    } else {
        printf("L'habitat n'est pas dans le Zoo !\n");
    }
}

// Vendre Animal dans le Zoo ⭐️
void Zoo::sellAnimal(Habitat *habitat, IAnimal *animal) {
    if (verifHabitat(habitat) && habitat->verifAnimal(animal)){
        m_budget->addBudget(animal->getPrix('V'));
        habitat->removeAnimal(animal);
    } else {
        printf("L'habitat n'est pas dans le Zoo ou l'animal n'est pas dans l'habitat !\n");
    }
}

// Achat Animal dans le Zoo ⭐️
void Zoo::buyAnimal(Habitat* habitat, IAnimal* animal) {
    // Vérifier si l'habitat est dans le zoo et si l'animal est dans l'habitat
    if (!verifHabitat(habitat)) {
        printf("L'habitat n'est pas dans le Zoo !\n");
        return;
    }

    // Vérifier s'il y a de la place et que l'animal est du bon type
    if (habitat->getCapacite() > habitat->getNbrOfAnimals() && habitat->getTypeAnimal() == animal->getTypeAnimal()) {
        // Soustraire le prix de l'animal au budget
        m_budget->removeBudget(animal->getPrix('A'));
        // Ajouter l'animal dans l'habitat
        habitat->addAnimal(animal);
    } else {
        printf("L'habitat est plein ou n'est pas du bon type !\n");
    }
}

// Verifier si l'habitat est dans le zoo ⭐️
bool Zoo::verifHabitat(Habitat *habitat) {
    return std::find(m_enclos.begin(), m_enclos.end(), habitat) != m_enclos.end();
}

// Vendre Aliment dans le Zoo ⭐️
void Zoo::sellAliment(FoodType alimentType, float quantite) {
    int alimentIndex = -1;
    for (int i = 0; i < m_stockAliment.size(); i++) {
        if (m_stockAliment[i]->getFoodType() == alimentType) {
            alimentIndex = i;
            break;
        }
    }
    if (alimentIndex == -1) {
        printf("L'aliment demandé n'est pas disponible dans le Zoo !\n");
        return;
    }

    Aliment* aliment = m_stockAliment[alimentIndex];
    if (aliment->getQuantite() < quantite) {
        printf("Il n'y a pas assez d'aliment dans le Zoo !\n");
        return;
    }

    aliment->subQuantite(quantite);
    m_budget->addBudget(aliment->getPrixKg() * quantite);
    printf("Vous avez vendu %.2fkg de %s pour %.2f$\n", quantite, aliment->getNom().c_str(), aliment->getPrixKg() * quantite);
}

// Achat Aliment dans le Zoo ⭐️
void Zoo::buyAliment(FoodType alimentType, float quantite) {
    int alimentIndex = -1;
    for (int i = 0; i < m_stockAliment.size(); i++) {
        if (m_stockAliment[i]->getFoodType() == alimentType) {
            alimentIndex = i;
            break;
        }
    }
    if (alimentIndex == -1) {
        printf("L'aliment demandé n'est pas disponible dans le Zoo !\n");
        return;
    }

    Aliment* aliment = m_stockAliment[alimentIndex];
    float prixTotal = aliment->getPrixKg() * quantite;
    if (m_budget->getBudget() < prixTotal) {
        printf("Il n'y a pas assez d'argent dans le Zoo !\n");
        return;
    }

    aliment->addQuantite(quantite);
    m_budget->removeBudget(prixTotal);
    printf("Vous avez acheté %.2fkg de %s pour %.2f$\n", quantite, aliment->getNom().c_str(), prixTotal);
}

