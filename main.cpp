#include <iostream>

using namespace std;

int main() {
    // Mettez en place un scénario type : 2 couples de tigre, 2 couples d’aigle, 1 coq, 10 poules sur 10 ans
    // TODO: 1. Créer une classe Aliment
        // -> nom
        // -> Prix / kg

    // TODO: 2 Créer une classe Habitat 🔴
        // -> nom
        // -> capacité
        // -> type d’animal (ex: Tigre, Aigle, Coq, Poule)
        // -> prix d’achat
        // -> prix de vente
        // -> Perte lié à la Surpopulation (50% de chance)
        // -> Probabilité d'être malade
            // => vector d'animal (ex: vector<typeAnimal*> nomHabitat(capacitéHabitat))

    // TODO: 3 Créer une classe Stat
        // Constructeur(*Tigre){
            // Alimentation(Viande)
            // Jours avant faim(2)
            // fin de reproduction(14 ans)
            // Espérance de vie(25 ans)
            // if FEMELLE
                // Alimentation par jour(10kg)
                // Maturité sexuelle (4 ans)
                // Ponte / portée(3 individus par portée / max 1 portée tous les 20 mois)
                // Gestation(3 mois)
                // Mortalité infantile(33%)
            // else MALE
                // Alimentation par jour(12kg)
                // Maturité sexuelle (6 mois)
        // }

        // Constructeur(*Aigle) {
            // Alimentation(Viande)
            // Jours avant faim(10)
            // fin de reproduction(14 ans)
            // Espérance de vie(25 ans)
            // Maturité sexuelle (4 ans)
                // if FEMELLE
                // Alimentation par jour(0.25kg)
                // Ponte / portée(2 oeuf en Mars)
                // Gestation(45 jours)
                // Mortalité infantile(50%)
            // else MALE
                // Alimentation par jour(0.30kg)
        // }

        // Constructeur(*Coq) {
            // Alimentation(Graines)
            // Alimentation par jour(0.18kg)
            // Jours avant faim(2)
            // Maturité sexuelle (6 mois)
            // fin de reproduction(8 ans)
            // Espérance de vie(15 ans)
        // }

        // Constructeur(*Poule) {
            // Alimentation(Graines)
            // Alimentation par jour(0.15kg)
            // Jours avant faim(1)
            // Ponte / portée(200 oeufs par an)
            // Maturité sexuelle (6 mois)
            // Gestation(6 semaines)
            // fin de reproduction(8 ans)
            // Espérance de vie(15 ans)
        // }



    // TODO: 4. Créer une classe Ianimal 🔴
        // -> Nom
        // -> Sexe
        // -> Age

        // TODO: 4.1 Créer une classe Tigre : public Ianimal
            // Tigre() -> param
            // => Stat(SexeAnimal, Age)

        // TODO: 4.2 Créer une classe Aigle : public Ianimal
            // Aigle() -> param
            // => Stat(SexeAnimal, Age)
            // Remarque : Fidéle

        // TODO: 4.3 Créer une classe Coq : public Ianimal
            // Coq() -> param
            // => Stat(SexeAnimal, Age)

        // TODO: 4.4 Créer une classe Poule : public Ianimal
            // Poule() -> param
            // => Stat(SexeAnimal, Age)





    // 2. Créer une classe Zoo
        //flemme
    // 3. Créer une classe Jour
        // 3.1 Créer une classe Nourriture
        // 3.2 Créer une classe Reproduction
        // 3.3 Créer une classe Mort
    // 4. Créer une classe Annee
        // 4.1 Créer une classe Mois
            // 4.1.1 Créer une classe Semaine
    vector<Tigre*> coupleTigre(2);
    coupleTigre.push_back(new Tigre("Tigre Male"));
    coupleTigre.push_back(new Tigre("Tigre Femelle"));
    vector<Aigle*> coupleAigle(2);
    cout << "Hello, World!" << endl;
    return 0;
}
