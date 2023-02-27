#include "Vendeur.h"

Vendeur::Vendeur(string nom) : m_nom(nom){}

Vendeur::~Vendeur() {
    for (auto &animal: m_animaux) {
        delete animal;
    }
    for (auto &habitat: m_habitats) {
        delete habitat;
    }
    for (auto &aliment: m_aliments) {
        delete aliment;
    }
}

void Vendeur::addAnimal(IAnimal *animal) {
    m_animaux.push_back(animal);
}

void Vendeur::addHabitat(Habitat *habitat) {
    m_habitats.push_back(habitat);
}

void Vendeur::addAliment(Aliment *aliment) {
    m_aliments.push_back(aliment);
}

const string &Vendeur::getName() const {
    return m_nom;
}

void Vendeur::removeAnimal(IAnimal *animal) {
    for (int i = 0; i < m_animaux.size(); i++) {
        if (m_animaux[i] == animal) {
            m_animaux.erase(m_animaux.begin() + i);
            return;
        }
    }
}

void Vendeur::removeHabitat(Habitat *habitat) {
    for (int i = 0; i < m_habitats.size(); i++) {
        if (m_habitats[i] == habitat) {
            m_habitats.erase(m_habitats.begin() + i);
            return;
        }
    }
}

void Vendeur::removeAliment(Aliment *aliment) {
    for (int i = 0; i < m_aliments.size(); i++) {
        if (m_aliments[i] == aliment) {
            m_aliments.erase(m_aliments.begin() + i);
            return;
        }
    }
}

