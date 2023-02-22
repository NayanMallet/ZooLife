//
// Created by Nayan Mallet on 22/02/2023.
//

#include <string>
#include <iostream>
#include <utility>
#include "Aliment.h"
#include <cmath>
using namespace std;

Aliment::Aliment(string nom, float prixKg): m_nom(std::move(nom)), m_prixKg(prixKg) {}

void Aliment::show() {
    printf("Nom: %s\nPrix: %.2f€/kg\n", m_nom.c_str(), m_prixKg);
}

string Aliment::getNom() { return m_nom; }

float Aliment::getPrixKg() const { return m_prixKg; }