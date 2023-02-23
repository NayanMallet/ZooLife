//
// Created by Nayan Mallet on 22/02/2023.
//

#include <string>
#include <iostream>
#include <utility>
#include "Aliment.h"
#include <cmath>
using namespace std;

Aliment::Aliment(string nom, float prixKg): m_nom(std::move(nom)), m_prixKg(prixKg){};

void Aliment::show() {
    printf("----- %s ------\n=> Prix: %.2f€/kg\n=> Quantite: %.2fkg\n\n", m_nom.c_str(), m_prixKg, m_quantite);
}

string Aliment::getNom() { return m_nom; }

float Aliment::getPrixKg() const { return m_prixKg; }

float Aliment::getQuantite() { return m_quantite; };

void Aliment::subQuantite(float qt) {
    assert((qt <= m_quantite) && "Vide !");
    m_quantite -= qt;
};