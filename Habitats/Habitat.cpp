#include "Habitat.h"
#include "../Animaux/IAnimal.h"
#include <string>
#include <utility>
#include <vector>
using namespace std;

Habitat::Habitat(string nom, int capacite, string typeAnimal, double prixAchat, double prixVente,
                 double perteSurPop, double probaMaladie):
                 m_nom(std::move(nom)), m_capacite(capacite), m_typeAnimal(std::move(typeAnimal)), m_prixAchat(prixAchat), m_prixVente(prixVente),
                 m_perteSurPop(perteSurPop), m_probaMaladie(probaMaladie) {
    // Initialiser le générateur aléatoire
    std::srand(std::time(nullptr));
    // Initialiser le vecteur d'animaux avec des pointeurs nuls
    Animaux = vector<IAnimal*>(capacite, nullptr);
}

// Ajouter un animal à l'habitat
bool Habitat::ajouterAnimal(IAnimal* animal) {
    // Vérifier si l'habitat est plein
    if (Animaux.size() >= m_capacite) {
        return false;
    }
    // Ajouter l'animal
    Animaux.push_back(animal);
    return true;
}

// Enlever un animal de l'habitat
bool Habitat::enleverAnimal(IAnimal* animal) {
    // Parcourir le vecteur d'animaux
    for (auto it = Animaux.begin(); it != Animaux.end(); ++it) {
        if (*it == animal) {
            // Supprimer l'animal
            delete *it;
            Animaux.erase(it);
            return true;
        }
    }
    return false;
}

// Vérifier si l'habitat est plein
bool Habitat::estPlein() const {
    return Animaux.size() >= m_capacite;
}

// Vérifier si l'habitat est vide
bool Habitat::estVide() const {
    return Animaux.empty();
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




//Habitat::Habitat(string nom, string type): m_nom(nom), m_probaMaladie(50){
//    if (type == "tigre") {
//        vector<*Tigre> nom(2);
//        m_prixAchat = 2000;
//        m_prixVente = 500;
//        m_perteSurPop = 1;
//    } else if (type == "aigle") {
//        vector<*Aigle> nom(2);
//        m_prixAchat = 2000;
//        m_prixVente = 500;
//        m_perteSurPop = 1;
//    } else if (type == "poules") {
//        vector<*Poules> nom(10);
//        m_prixAchat = 300;
//        m_prixVente = 50;
//        m_perteSurPop = 4;
//
//    }
//};
//
//void Habitat::show(){};
//void Habitat::showAnimal(int i){};
//void Habitat::addAnimal(Animal *animal){};
//void Habitat::removeAnimal(int i){};
//void Habitat::removeAnimal(Animal *animal){};