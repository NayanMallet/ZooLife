#include <iostream>
#include <string>
#include "../Animaux/IAnimal.h"

using namespace std;

string dateConverter(int jours) {
    if (jours == 0) {
        return "0 jour";
    }

    int annees = jours / 365;
    int mois = (jours % 365) / 30;
    int joursRestants = (jours % 365) % 30;

    string resultat = "";

    if (annees == 1) {
        resultat += "1 an";
    }
    else if (annees > 1) {
        resultat += to_string(annees) + " ans";
    }

    if (mois == 1) {
        if (resultat != "") {
            resultat += ", ";
        }
        resultat += "1 mois";
    }
    else if (mois > 1) {
        if (resultat != "") {
            resultat += ", ";
        }
        resultat += to_string(mois) + " mois";
    }

    if (joursRestants == 1) {
        if (resultat != "") {
            resultat += ", ";
        }
        resultat += "1 jour";
    }
    else if (joursRestants > 1) {
        if (resultat != "") {
            resultat += ", ";
        }
        resultat += to_string(joursRestants) + " jours";
    }

    return resultat;
}

string animalTypeToString(AnimalType type) {
    switch (type) {
        case AnimalType::TIGRE:
            return "Tigre";
        case AnimalType::AIGLE:
            return "Aigle";
        case AnimalType::POULE:
            return "Poule";
        default:
            return "Inconnu";
    }
}