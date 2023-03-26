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
    printf("----- %s -----\n"
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

void Zoo::showResume() const {
    printf("--- %s ---\n"
           "=> Age: %s\n"
           "=> Stock: Graines: %.2fkg - Viande: %.2fkg\n"
           "=> Budget: %.2f$\n"
           "=> Nombre d'Enclos: %i\n"
           "-------------\n",
           m_name.c_str(),
           dateConverter(m_days).c_str(),
           m_stockAliment[0]->getQuantite(),
           m_stockAliment[1]->getQuantite(),
           m_budget->getBudget(),
           getNbrOfEnclos()
    );
}

// Action prochain tour ⭐️
void Zoo::nextMonth() {
    string month = m_months[m_month];
    if (month == "JANVIER") {
        for (auto& habitat : m_enclos) {
            habitat->MaladieAnnuelle();
        }
        subventionAnnual();
    }
    cout << "----- " << month << " ----" << endl;
    foodMonthlyUpdate(); // get food for the month
    volSpecimenMonthly(); // vol de spécimen
    incendieMonthly(); // incendie
    visiteurMonthly(month); // visiteurs
    for (auto& habitat : m_enclos) {
        if (habitat->getNbrOfAnimals() > habitat->getCapacite()) {
            habitat->PerteSurpopulation();
        }
        switch (habitat->getTypeAnimal()) {
            case AnimalType::TIGRE:
                habitat->update(month, m_stockAliment[1], m_enclosGestation[0]);
                break;
            case AnimalType::AIGLE:
                habitat->update(month, m_stockAliment[1], m_enclosGestation[1]);
                break;
            case AnimalType::POULE:
                habitat->update(month, m_stockAliment[0], m_enclosGestation[2]);
                break;
        }
    }

    for (auto& habitat : m_enclosGestation) {
        AnimalType type = habitat->getTypeAnimal();
       for (auto& animal : habitat->m_animaux) {
           string name = animal->getName();
           if (!animal->getPortee() && animal->getAge() >= 6 * 31) {
               bool isBebe = name.find("Bebe") != string::npos;
               if (isBebe) {
                   cout << "Le " << animal->getName() << " a grandit et peut aller dans le Zoo !" << endl << "Donnez un nom au bebe: ";
                   string bebeName;
                   getline(cin, bebeName);
                   animal->setNom(bebeName);
                   cout << endl << "Ou voulez-vous le placer ?" << endl;
               } else {
                   cout << "La mere " << animal->getName() << " peut revenir dans le Zoo !" << endl << "Ou voulez-vous la placer ?" << endl;
               }
               string choice;
               for (int i = 0; i < m_enclos.size(); i++) {
                   if (m_enclos[i]->getTypeAnimal() == type) {
                       cout << i << " - " << m_enclos[i]->getName() << endl;
                   }
               }
               getline(cin, choice);
               while (stoi(choice) >= m_enclos.size() || m_enclos[stoi(choice)]->getTypeAnimal() != type) {
                   cout << "Choix invalide, veuillez reessayer: ";
                   getline(cin, choice);
               }
               changeAnimalOfEnclos(habitat, m_enclos[stoi(choice)], animal);
           }
       }
    }
    cout << "-------------------" << endl;
    if (month == "DECMEMBRE") {
        m_month = 0;
    } else {
        m_month++;
    }
    m_days+=31;
}

void Zoo::nextYear() {
    for (int i = 0; i < 12; i++) {
        nextMonth();
    }
}


// Afficher le nom du Zoo ⭐️
void Zoo::showHabitats() const {
    printf(
            "---- Enclos ----\n"
            "%s"
            "----------------\n",
            listHabitats().c_str()
    );
}

// Retourne la liste des Habitats du Zoo ⭐️
string Zoo::listHabitats() const {
    string result;
    for (const auto& habitat : m_enclos) {
        result += ((!habitat->m_animaux.empty()) ? "-> " + habitat->getName() + "(" + animalTypeToString(habitat->getTypeAnimal()) + ") : " + to_string(habitat->getNbrOfAnimals()) + "/" + to_string(habitat->getCapacite()) + "\n" : "");
    }
    for (const auto& habitat : m_enclosGestation) {
        result += ((!habitat->m_animaux.empty()) ? "-> " + habitat->getName() + "(" + animalTypeToString(habitat->getTypeAnimal()) + ") : " + to_string(habitat->getNbrOfAnimals()) + "\n" : "");
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
    if (habitat->getTypeAnimal() == animal->getTypeAnimal()) {
        // Soustraire le prix de l'animal au budget
        m_budget->removeBudget(animal->getPrix('A'));
        // Ajouter l'animal dans l'habitat
        habitat->addAnimal(animal);
    } else {
        printf("L'habitat n'est pas du bon type !\n");
    }
}

// Verifier si l'habitat est dans le zoo ⭐️
bool Zoo::verifHabitat(Habitat *habitat) {
    return std::find(m_enclos.begin(), m_enclos.end(), habitat) != m_enclos.end();
}

// Verifier si l'habitat est dans le zoo ⭐️
bool Zoo::verifHabitatGestation(Habitat *habitat) {
    return std::find(m_enclosGestation.begin(), m_enclosGestation.end(), habitat) != m_enclosGestation.end();
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
        printf("L'aliment demande n'est pas disponible dans le Zoo !\n");
        return;
    }

    Aliment* aliment = m_stockAliment[alimentIndex];
    if (aliment->getQuantite() < quantite) {
        printf("Il n'y a pas assez d'aliments dans le Zoo !\n");
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
        printf("L'aliment demande n'est pas disponible dans le Zoo !\n");
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
        printf("L'habitat est deja dans le Zoo !\n");
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
    printf("Vous avez achete l'habitat %s pour %.2f$\n", nom.c_str(), prixTotal);
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

// Verifie s'il y a une avarie sur la viande ⭐️
void Zoo::viandeAvarieMonthly() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::bernoulli_distribution dist(0.1);

    if (!dist(gen)) {
        cout << "Pas de viande avariee !" << endl;
        return;
    }

    m_stockAliment[1]->subQuantite(m_stockAliment[1]->getQuantite() * 0.2f);
    cout << "Il y a eu une avarie sur la viande !" << endl;
}

// Verifie s'il y a des nuisibles sur les graines ⭐️
void Zoo::graineNuisibleMonthly() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::bernoulli_distribution dist(0.2);

    if (!dist(gen)) {
        cout << "Pas de nuisibles sur les graines !" << endl;
        return;
    }

    m_stockAliment[0]->subQuantite(m_stockAliment[0]->getQuantite() * 0.1f);
    cout << "Il y a eu des nuisibles sur les graines !" << endl;
}

// Verifie s'il y a un vol de spécimen dans le zoo ⭐️
void Zoo::volSpecimenMonthly() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::bernoulli_distribution dist(0.01);

    if (!dist(gen)) {
        printf("Pas de vol de specimen !\n");
        return;
    }

    auto habitatIndex = std::uniform_int_distribution<>(0, m_enclos.size() - 1)(gen);
    auto *habitat = m_enclos[habitatIndex];
    auto *animal = habitat->m_animaux[std::uniform_int_distribution<>(0, habitat->m_animaux.size() - 1)(gen)];
    printf("Il y a eu un vol de specimen sur un %s dans l'habitat '%s' !\n", animal->getName().c_str(), habitat->getName().c_str());
    habitat->removeAnimal(animal);
    animal->~IAnimal();
}

// Verifie si il y a un incendie dans le zoo ⭐️
void Zoo::incendieMonthly() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::bernoulli_distribution dist(0.01);

    if (!dist(gen)) {
        printf("Pas d'incendie !\n");
        return;
    }

    auto habitatIndex = std::uniform_int_distribution<>(0, m_enclos.size() - 1)(gen);
    auto *habitat = m_enclos[habitatIndex];
    auto habitatName = habitat->getName();
    printf("Il y a eu un incendie sur l'habitat '%s' !\n", habitatName.c_str());
    removeHabitat(habitat);
    habitat->~Habitat();
}

// Subvention annuelle du zoo ⭐️
void Zoo::subventionAnnual() {
    float sum = 0;
    for (auto &enclos : m_enclos) {
        AnimalType type = enclos->getTypeAnimal();
        for (auto &animal : enclos->m_animaux) {
            float EnclosSum = (type == AnimalType::TIGRE) ? 43800.0f : (type == AnimalType::AIGLE) ? 2190.0f : 0.0f;
            m_budget->addBudget(EnclosSum);
            sum += EnclosSum;
        }
    }
    printf("Cette annee, %s a recu une subvention de %.2f$ !\n", getName().c_str(), sum);
}

void Zoo::visiteurMonthly(string month) {
    float money = 0;
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distVariation(-0.2, 0.2);
    // Saison haute
    if (month == "MAI" || month == "JUILLET" || month == "AOUT" || month == "SEPTEMBRE") {
        for (auto &enclos: m_enclos) {
            // Enclos vide
            if (enclos->m_animaux.empty()) {
                continue;
            }
            AnimalType type = enclos->getTypeAnimal();
            for (auto &animal: enclos->m_animaux) {
                float variation = distVariation(gen);
                float visitors = (((type == AnimalType::TIGRE) ? 30.0f : (type == AnimalType::AIGLE) ? 15.0f : 0.0f) * (1.0f + variation));
                float sumVisitors = (((visitors / 2) * 17) + ((visitors / 2) * 13));
                m_budget->addBudget(sumVisitors);
                money += sumVisitors;
            }
        }
    } else {
        for (auto &enclos: m_enclos) {
            // Enclos vide
            if (enclos->m_animaux.empty()) {
                continue;
            }
            AnimalType type = enclos->getTypeAnimal();
            for (auto &animal: enclos->m_animaux) {
                float variation = distVariation(gen);
                float visitors = (((type == AnimalType::TIGRE) ? 5.0f : (type == AnimalType::AIGLE) ? 7.0f : 0.5f) * (1.0f + variation));
                float sumVisitors = (((visitors / 2) * 17) + ((visitors / 2) * 13));
                m_budget->addBudget(sumVisitors);
                money += sumVisitors;
            }
        }
    }
    printf("+ %.2f$ grace aux visiteurs !\n", money);
}


// Change l'animal d'un habitat à un autre
void Zoo::changeAnimalOfEnclos(Habitat *habitat, Habitat *newHabitat, IAnimal *animal) {
    if ((!verifHabitat(habitat) && !verifHabitatGestation(habitat)) || (!verifHabitat(newHabitat) && !verifHabitatGestation(newHabitat))) {
        printf("L'habitat n'est pas dans le Zoo !\n");
        return;
    }
    if (!habitat->verifAnimal(animal)) {
        printf("L'animal n'est pas dans l'habitat !\n");
        return;
    }
    if (habitat->getTypeAnimal() != newHabitat->getTypeAnimal()) {
        printf("Les habitats ne sont pas du meme type !\n");
        return;
    }
    habitat->removeAnimal(animal);
    newHabitat->addAnimal(animal);
    printf("Vous avez change l'animal %s de l'habitat %s a l'habitat %s\n", animal->getName().c_str(), habitat->getName().c_str(),
           newHabitat->getName().c_str());
}

float Zoo::getBudget() const {
    return m_budget->getBudget();
}

void Zoo::removeBudget(float budget) {
    m_budget->removeBudget(budget);
}
