#include <iostream>
#include "Aliments/Aliment.h"
#include "Animaux/Tigre.h"
#include "Animaux/Poule.h"
#include "Animaux/Aigle.h"
#include "Animaux/Coq.h"
#include "Habitats/Habitat.h"
#include "Aliments/Graines.h"
#include "Aliments/Viande.h"
#include "Functions/functions.h"

#include <vector>

using namespace std;

int main() {
    // Mettez en place un scénario type : 2 couples de tigre, 2 couples d’aigle, 1 coq, 10 poules sur 10 ans
//    auto *ble = new Graines("Graine");
//    auto *steak = new Viande("Viande");
//    ble->show();
//    steak->show();

    // TODO: 3 Créer une classe Stat




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
    // Couples Tigres :)
    Tigre *TigreM1 = new Tigre("Tigrou", 'M', 0);
    Tigre *TigreM2 = new Tigre("Marck", 'M', 0);
    Tigre *TigreF1 = new Tigre("Jeanne", 'F', 0);
    Tigre *TigreF2 = new Tigre ("Elsa", 'F', 0);

    // Couples Aigles :)
    Aigle *AigleM1 = new Aigle("Marckou", 'M', 0);
    Aigle *AigleM2 = new Aigle("Dalyll", 'M', 0);
    Aigle *AigleF1 = new Aigle("Leo", 'F', 0);
    Aigle *AigleF2 = new Aigle("Haagen", 'F', 0);

    // Le Coq
    Coq *Zizou = new Coq("Zizou", 0);

    // Les Poules
    Poule *Poule1 = new Poule("Poule1", 0);
    Poule *Poule2 = new Poule("Poule2", 0);
    Poule *Poule3 = new Poule("Poule3", 0);
    Poule *Poule4 = new Poule("Poule4", 0);
    Poule *Poule5 = new Poule("Poule5", 0);
    Poule *Poule6 = new Poule("Poule6", 0);
    Poule *Poule7 = new Poule("Poule7", 0);
    Poule *Poule8 = new Poule("Poule8", 0);
    Poule *Poule9 = new Poule("Poule9", 0);
    Poule *Poule10 = new Poule("Poule10", 0);

//    cout << "Couple Tigre 1 ✅" << endl;
//    TigreM1->show();
//    TigreF1->show();
//    cout << "Couple Tigre 2 ✅" << endl;
//    TigreM2->show();
//    TigreF2->show();
//    cout << "Couple Aigle 1 ✅" << endl;
//    AigleM1->show();
//    AigleF1->show();
//    cout << "Couple Aigle 2 ✅" << endl;
//    AigleM2->show();
//    AigleF2->show();
//    cout << "Le Coq ✅" << endl;
//    Zizou->show();
//    cout << "Les Poules ✅" << endl;
//    Poule1->show();
//    Poule2->show();
//    Poule3->show();
//    Poule4->show();
//    Poule5->show();
//    Poule6->show();
//    Poule7->show();
//    Poule8->show();
//    Poule9->show();
//    Poule10->show();
    Habitat *habitat = new Habitat("Couple de Tigre 1", "tigre");
    habitat->ajouterAnimal(TigreM1);
    habitat->ajouterAnimal(TigreF1);
    Habitat *habitat2 = new Habitat("Couple de Tigre 2", "tigre");
    habitat2->ajouterAnimal(TigreM2);
    habitat2->ajouterAnimal(TigreF2);
    Habitat *habitat3 = new Habitat("Couple Aigle 1", "aigle");
    habitat3->ajouterAnimal(AigleM1);
    habitat3->ajouterAnimal(AigleF1);
    Habitat *habitat4 = new Habitat("Couple Aigle 2", "aigle");
    habitat4->ajouterAnimal(AigleM2);
    habitat4->ajouterAnimal(AigleF2);
    Habitat *habitat5 = new Habitat("KFC", "poule");
    habitat5->ajouterAnimal(Zizou);
    habitat5->ajouterAnimal(Poule1);
    habitat5->ajouterAnimal(Poule2);
    habitat5->ajouterAnimal(Poule3);

    habitat->show();
    habitat2->show();
    habitat3->show();
    habitat4->show();
    habitat5->show();
    return 0;
}

// Updates :)
// -> Aliment Class Working
// -> IAnimal && theses animals class created
//      -> TODO: adding params to every animals class