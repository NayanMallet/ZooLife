#include "Habitat.h"
#include "../Animaux/IAnimal.h"
#include "../Functions/functions.h"
#include <string>
#include <utility>
#include <vector>
using namespace std;

// Constructeur Habitat ⭐️
Habitat::Habitat(string nom, string typeAnimal): m_nom(std::move(nom)) {
    if (typeAnimal != "tigre" && typeAnimal != "aigle" && typeAnimal != "poule" && typeAnimal != "coq") {
        throw invalid_argument("Le type d'animal doit être tigre, aigle, poule ou coq");
    }
    m_typeAnimal = std::move(typeAnimal);
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

// Afficher les informations de l'habitat ⭐️
void Habitat::show() {
    printf("----- Habitat %s (%s) -----\n"
           "=> Capacité: %d\n"
           "=> Prix d'achat: %i€\n"
           "=> Prix de vente: %i€\n"
           "=> Perte lié à la Surpopulation (50%% de chance): %i/mois\n"
           "=> Probabilité d'être malade: %.2f%%\n"
           "=> Animaux: %zu/%d\n"
           "Liste des animaux:\n%s"
           "---------------------------\n",
           m_nom.c_str(), m_typeAnimal.c_str(),
           m_capacite,
           m_prixAchat,m_prixVente,
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
        result += (animal ? "-> " + animal->getName() + "(" + dateConverter(animal->getAge()) + ")\n" : "-> Vide\n");
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
            Habitat::listAnimals().c_str()
    );
}

// Ajouter un animal à l'habitat ⭐️
void Habitat::ajouterAnimal(IAnimal* animal) {
    // Vérifier si l'habitat est plein ou si l'animal n'est pas du bon type
    if (m_animaux.size() == m_capacite || (animal->getTypeAnimal() != m_typeAnimal && !(animal->getTypeAnimal() == "coq" && m_typeAnimal == "poule"))) {
        printf("Impossible d'ajouter l'animal à l'habitat !\n");
        return;
    }

    // Ajouter l'animal
    m_animaux.push_back(animal);
}

// Enlever un animal de l'habitat ⭐️
void Habitat::enleverAnimal(IAnimal* animal) {
    // Chercher l'indice de l'animal dans le vecteur
    auto it = find(m_animaux.begin(), m_animaux.end(), animal);

    // Si l'animal est dans l'habitat, le supprimer
    if (it != m_animaux.end()) {
        m_animaux.erase(it);
    } else {
        printf("L'animal n'est pas dans l'habitat !\n");
    }
}




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