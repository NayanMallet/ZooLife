#include <string>
#include <utility>
#include <stdexcept>
#include "Aliment.h"

using namespace std;

Aliment::Aliment(string nom, float prixKg, FoodType foodType): m_nom(nom), m_prixKg(prixKg), m_foodType(foodType){};

void Aliment::show() {
    // TODO: ADD FOODTYPE
    printf("----- %s ------\n=> Prix: %.2f€/kg\n=> Quantite: %.2fkg\n\n", m_nom.c_str(), m_prixKg, m_quantite);
}

string Aliment::getNom() { return m_nom; }

float Aliment::getPrixKg() const { return m_prixKg; }

float Aliment::getQuantite() { return m_quantite; }

FoodType Aliment::getFoodType() { return m_foodType; }

void Aliment::subQuantite(float qt) {
    if (qt > m_quantite) {
        throw invalid_argument("Quantité insuffisante !");
    }
    m_quantite -= qt;
};

void Aliment::addQuantite(float qt) {
    m_quantite += qt;
};