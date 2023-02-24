#include "Habitat.h"
#include "../Animaux/IAnimal.h"
#include "../Functions/functions.h"
#include <string>
#include <utility>
#include <vector>
using namespace std;


Habitat::Habitat(string nom, string typeAnimal): m_nom(std::move(nom)) {
    if (typeAnimal != "tigre" && typeAnimal != "aigle" && typeAnimal != "poule" && typeAnimal != "coq") {
        throw invalid_argument("Le type d'animal doit être tigre, aigle, poule ou coq");
    }
    if (typeAnimal == "tigre") {
        m_prixAchat = 2000;
        m_prixVente = 500;
        m_capacite = 2;
        m_perteSurPop = 1;
        m_probaMaladie = 20;
        m_typeAnimal = std::move(typeAnimal);
    } else if (typeAnimal == "aigle") {
        m_prixAchat = 2000;
        m_prixVente = 500;
        m_capacite = 4;
        m_perteSurPop = 1;
        m_probaMaladie = 10;
        m_typeAnimal = std::move(typeAnimal);
    } else if (typeAnimal == "poule" || typeAnimal == "coq") {
        m_prixAchat = 300;
        m_prixVente = 50;
        m_capacite = 10;
        m_perteSurPop = 4;
        m_probaMaladie = 5;
        m_typeAnimal = "poule";
    }
}

// Afficher les informations de l'habitat
void Habitat::show() {
    printf("----- Habitat %s (%s) -----\n"
           "=> Capacité: %d\n"
           "=> Prix d'achat: %i€\n"
           "=> Prix de vente: %i€\n"
           "=> Perte lié à la Surpopulation (50%% de chance): %i/mois\n"
           "=> Probabilité d'être malade: %.2f%%\n"
           "=> Animaux: \n",
           m_nom.c_str(), m_typeAnimal.c_str(),
           m_capacite,
           m_prixAchat,m_prixVente,
           m_perteSurPop,
           m_probaMaladie);
    Habitat::showAnimals();
    cout << "---------------------------" << endl;
}

// Ajouter un animal à l'habitat
void Habitat::ajouterAnimal(IAnimal *animal) {
    // Vérifier si l'habitat n'est pas plein
    if (m_animaux.size() < m_capacite) {
        // Vérifier si l'animal est du bon type
        if (animal->getTypeAnimal() == "coq" && m_typeAnimal == "poule") {
            // Ajouter l'animal
            m_animaux.push_back(animal);
        } else if (animal->getTypeAnimal() == m_typeAnimal) {
            // Ajouter l'animal
            m_animaux.push_back(animal);
        } else {
            printf("L'animal n'est pas du bon type !\n");
        }
    } else {
        printf("L'habitat est plein !\n");
    }

}

// Enlever un animal de l'habitat
void Habitat::enleverAnimal(IAnimal *animal) {
    // Vérifier si l'animal est dans l'habitat
    for (int i = 0; i < m_animaux.size(); i++) {
        if (m_animaux[i] == animal) {
            // Enlever l'animal
            m_animaux.erase(m_animaux.begin() + i);
            return;
        }
    }
    throw invalid_argument("L'animal n'est pas dans l'habitat !");
}

void Habitat::showAnimals() {
    for (auto & i : m_animaux) {
        if (i != nullptr) {
            printf("-> %s (%s)\n", i->getName().c_str(), dateConverter(i->getAge()).c_str());
        } else {
            printf("-> Vide\n");
        }
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