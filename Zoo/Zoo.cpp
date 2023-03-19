#include "Zoo.h"
#include <string>
#include <algorithm>
#include <unordered_set>
#include <random>
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
           "   -> Graines: %.2fkg\n"
           "   -> Viande: %.2fkg\n"
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

void Zoo::nextMonth() {
    string month = m_months[m_month];
    if (month == "JANVIER") {
        // Maladie Annuelle
        for (auto& habitat : m_enclos) {
            habitat->MaladieAnnuelle();
        }
    }
    cout << "----- " << month << " -----" << endl;
    foodMonthlyUpdate(); // get food for the month
    for (auto& habitat : m_enclos) {
        if (habitat->getNbrOfAnimals() > habitat->getCapacite()) {
            habitat->PerteSurpopulation();
        }
        switch (habitat->getTypeAnimal()) {
            case AnimalType::TIGRE:
            case AnimalType::AIGLE:
                habitat->update(month, m_stockAliment[1]);
                break;
            case AnimalType::POULE:
                habitat->update(month, m_stockAliment[0]);
                break;
        }
    }
    cout << "--------------------" << endl;
    if (month == "DECMEMBRE") {
        m_month = 0;
    } else {
        m_month++;
    }
    m_days+=31;
}

void Zoo::nextYear() {
    // update monthly
    for (auto& habitat : m_enclos) {
        habitat->MaladieAnnuelle();
    }

    for (auto& month : {"JANVIER", "FEVRIER", "MARS", "AVRIL", "MAI", "JUIN", "JUILLET", "AOUT", "SEPTEMBRE", "OCTOBRE", "NOVEMBRE", "DECMEMBRE"}) {
        cout << "----- " << month << " -----" << endl;
        foodMonthlyUpdate();
        for (auto& habitat : m_enclos) {
            if (habitat->getNbrOfAnimals() > habitat->getCapacite()) {
                habitat->PerteSurpopulation();
            }
            switch (habitat->getTypeAnimal()) {
                case AnimalType::TIGRE:
                case AnimalType::AIGLE:
                    habitat->update(month, m_stockAliment[1]);
                    break;
                case AnimalType::POULE:
                    habitat->update(month, m_stockAliment[0]);
                    break;
            }
        }
        cout << "--------------------" << endl;
    }
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
}


// Vente d'habitat dans le Zoo ⭐️
void Zoo::sellHabitat(Habitat *habitat) {
    if (!verifHabitat(habitat)) {
        printf("L'habitat n'est pas dans le Zoo !\n");
        return;
    }
    if (habitat->getNbrOfAnimals() > 0) {
        printf("Il y a encore des animaux dans l'habitat !\n");
        return;
    }
    m_budget->addBudget(habitat->getPrix('V'));
    removeHabitat(habitat);
    printf("Vous avez vendu l'habitat %s pour %.2f$\n", habitat->getName().c_str(), habitat->getPrix('V'));
}

// Vérifier si l'habitat est déjà dans le zoo en utilisant un unordered_set pour une recherche plus rapide
void Zoo::buyHabitat(string nom, AnimalType typeAnimal) {
    unordered_set<string> habitatNames;
    for (const auto &habitat: m_enclos) {
        habitatNames.insert(habitat->getName());
    }
    if (habitatNames.find(nom) != habitatNames.end()) {
        printf("L'habitat est déjà dans le Zoo !\n");
        return;
    }

    // Créer l'habitat
    Habitat *habitat = new Habitat(nom, typeAnimal);
    float prixTotal = habitat->getPrix('A');

    // Vérifier si le budget est suffisant
    if (m_budget->getBudget() < prixTotal) {
        printf("Il n'y a pas assez d'argent dans le Zoo !\n");
        delete habitat;
        return;
    }

    // Ajouter l'habitat au zoo
    addHabitat(habitat);
    m_budget->removeBudget(prixTotal);
    printf("Vous avez acheté l'habitat %s pour %.2f$\n", nom.c_str(), prixTotal);
}

void Zoo::foodMonthlyUpdate() {
    viandeAvarieMonthly();
    graineNuisibleMonthly();
    for (const auto &habitat: m_enclos) {
        for (const auto &animal: habitat->m_animaux) {
            buyAliment(animal->getFoodType(), animal->getFoodQuantity());
            }
        }
    }

void Zoo::viandeAvarieMonthly() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::bernoulli_distribution dist(0.1);

    if (!dist(gen)) {
        printf("Pas de viande avarié !\n");
        return;
    }

    m_stockAliment[1]->subQuantite(float(m_stockAliment[1]->getQuantite() * 0.2));
    printf("Il y a eu une avarie sur la viande !\n");
}

void Zoo::graineNuisibleMonthly() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::bernoulli_distribution dist(0.2);

    if (!dist(gen)) {
        printf("Pas de nuisibles sur les graines !\n");
        return;
    }

    m_stockAliment[0]->subQuantite(float(m_stockAliment[0]->getQuantite() * 0.1));
    printf("Il y a eu des nuisibles sur les graines !\n");
}


void Zoo::volSpecimenMonthly() {

}

void Zoo::incendieMonthly() {

}
