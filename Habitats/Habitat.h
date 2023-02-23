#ifndef ZOOLIFE_HABITAT_H
#define ZOOLIFE_HABITAT_H
#include <string>
#include <vector>
#include "../Animaux/IAnimal.h"

using namespace std;

// TODO: 2 Créer une classe Habitat 🔴
// -> nom
// -> capacité
// -> type d’animal (ex: Tigre, Aigle, Coq, Poule)
// -> prix d’achat
// -> prix de vente
// -> Perte lié à la Surpopulation (50% de chance)
// -> Probabilité d'être malade
// => vector d'animal (ex: vector<typeAnimal*> nomHabitat(capacitéHabitat))

class Habitat {
public:
    Habitat(string nom, int capacite, string typeAnimal,
            double prixAchat, double prixVente, double perteSurPop, double probaMaladie);

    bool ajouterAnimal(IAnimal* animal);
private:
    string m_nom;
    int m_capacite;
    string m_typeAnimal;
    double m_prixAchat, m_prixVente;
    double m_perteSurPop, m_probaMaladie;
    vector<IAnimal*> Animaux;

    bool enleverAnimal(IAnimal *animal);

    bool estPlein() const;

    bool estVide() const;
}
//class Habitat {
//public:
//    Habitat(string nom, string typeAnimal) {};
//    void show();
//    void showAnimal(int i);
//    void addAnimal(Animal *animal);
//    void removeAnimal(int i);
//    void removeAnimal(Animal *animal);
//private:
//    string m_nom;
//
//};


#endif //ZOOLIFE_HABITAT_H
