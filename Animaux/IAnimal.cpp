//
// Created by theos on 1/23/2023.
//

#include "IAnimal.h"
#include "../Functions/functions.h"

#include <utility>

IAnimal::IAnimal(string name, char sexe, int age): m_name(std::move(name)), m_age(age) {
    assert((sexe == 'M' || sexe == 'F') && "Le sexe ne peut être que Male(M) ou Femelle(M)");
    m_sexe = sexe;
}
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

//void IAnimal::show() {
//    switch (m_sexe) {
//        case 'M':
//            printf("----- %s (%c) -----\n"
//                   "=> Age: %s\n"
//                   "=> Alimentation: %s, %.2fkg/j \n"
//                   "=> Jours avant faim: %s\n"
//                   "=> Fin de reproduction: %s\n"
//                   "=> Espérance de vie: %s\n"
//                   "=> Maturité sexuelle: %s\n",
//                   getName().c_str(), getSexe(),
//                   dateConverter(getAge()).c_str(),
//                   "Viande", 1.5,// to change
//                   dateConverter(2).c_str(),// to change
//                   dateConverter(344).c_str(),// to change
//                   dateConverter(1440).c_str(),// to change
//                   dateConverter(245).c_str()// to change
//                    );
//        case 'F':
//            printf("----- %s (%c) -----\n"
//                   "=> Age: %s\n"
//                   "=> Alimentation: %s, %.2fkg/j \n"
//                   "=> Jours avant faim: %s\n"
//                   "=> Fin de reproduction: %s\n"
//                   "=> Espérance de vie: %s\n"
//                   "=> Maturité sexuelle: %s\n",
//                   getName().c_str(), getSexe(),
//                   dateConverter(getAge()).c_str(),
//                   "Viande", 1.5,// to change
//                   dateConverter(2).c_str(),// to change
//                   dateConverter(344).c_str(),// to change
//                   dateConverter(1440).c_str(),// to change
//                   dateConverter(245).c_str()// to change
//                   );
//
//        default:
//            printf("Tigre '%s'=> Error !", getName().c_str());
//        };
//    };

string IAnimal::getName() { return m_name; };

char IAnimal::getSexe() const { return m_sexe; };

int IAnimal::getAge() const { return m_age; };