#include <unordered_set>
#include "Habitat.h"
#include "../Functions/functions.h"

using namespace std;

Habitat::Habitat(const string& nom, const string& typeAnimal) : m_nom(nom), m_typeAnimal(typeAnimal) {
    if (!isValidType(m_typeAnimal)) {
        throw invalid_argument("Le type d'animal doit être tigre, aigle, poule ou coq");
    }
    if (m_typeAnimal == "tigre") {
        m_prixAchat = 2000;
        m_prixVente = 500;
        m_capacite = 2;
        m_perteSurPop = 1;
        m_probaMaladie = 20;
    } else if (m_typeAnimal == "aigle") {
        m_prixAchat = 2000;
        m_prixVente = 500;
        m_capacite = 4;
        m_perteSurPop = 1;
        m_probaMaladie = 10;
    } else if (m_typeAnimal == "poule" || m_typeAnimal == "coq") {
        m_prixAchat = 300;
        m_prixVente = 50;
        m_capacite = 10;
        m_perteSurPop = 4;
        m_probaMaladie = 5;
        m_typeAnimal = "poule";
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
           "=> Perte liée à la surpopulation (50%% de chance): %i/mois\n"
           "=> Probabilité d'être malade: %.2f%%\n"
           "=> Animaux: %zu/%d\n"
           "Liste des animaux:\n%s"
           "---------------------------\n",
           m_nom.c_str(), m_typeAnimal.c_str(),
           m_capacite,
           m_prixAchat, m_prixVente,
           m_perteSurPop,
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
            m_nom.c_str(), m_typeAnimal.c_str(),
            listAnimals().c_str()
    );
}

// Getters class Habitat ⭐️
const string& Habitat::getName() const { return m_nom; }
int Habitat::getCapacite() const { return m_capacite; }
int Habitat::getNbrOfAnimals() const { return m_animaux.size(); }
const string& Habitat::getTypeAnimal() const { return m_typeAnimal; }

// Ajouter un animal à l'habitat ⭐️
void Habitat::addAnimal(IAnimal* animal) {
    // Vérifier si l'habitat est plein ou si l'animal est du mauvais type
    if (m_animaux.size() == m_capacite || (animal->getTypeAnimal() != m_typeAnimal && !(animal->getTypeAnimal() == "coq" && m_typeAnimal == "poule"))) {
        printf("Impossible d'ajouter l'animal à l'habitat !\n");
        return;
    }
    // Ajouter l'animal
    m_animaux.push_back(animal);
}

// Enlever un animal de l'habitat ⭐️
void Habitat::removeAnimal(IAnimal* animal) {
// Vérifier si l'habitat est vide ou si l'animal est du mauvais type
    if (m_animaux.empty() || (animal->getTypeAnimal() != m_typeAnimal && !(animal->getTypeAnimal() == "coq" && m_typeAnimal == "poule"))) {
        printf("Impossible d'enlever l'animal de l'habitat !\n");
        return;
    }
// Enlever l'animal
    m_animaux.erase(std::remove(m_animaux.begin(), m_animaux.end(), animal), m_animaux.end());
}

// Méthode privée pour vérifier si le type d'animal est valide ⭐️
bool Habitat::isValidType(const string& typeAnimal) {
    static const unordered_set<string> validTypes = {"tigre", "aigle", "poule", "coq"};
    return validTypes.count(typeAnimal);
}
// -> conteneur unordered_set pour stocker les types valides d'animaux, ce qui est une structure
// de données efficace pour rechercher rapidement si un élément est présent dans le conteneur.


//// Calculer la perte liée à la surpopulation
//double Habitat::calculerPerteSurpopulation() const {
//    // Générer un nombre aléatoire entre 0 et 1
//    double rand_num = (double)std::rand() / RAND_MAX;
//    // Si le nombre est inférieur à la probabilité de perte liée à la surpopulation,
//    // retourner la moitié du prix d'achat de tous les animaux dans l'habitat
//    if (rand_num < m_perteSurPop) {
//        double perte = 0;
//        for (const auto& animal : Animaux) {
//            perte += animal->getPrix() / 2.0;
//        }
//        return perte;
//    }
//    return 0;
//}