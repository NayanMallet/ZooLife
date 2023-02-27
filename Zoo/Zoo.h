#ifndef CORRECTION_TP_FEU_ZOO_H
#define CORRECTION_TP_FEU_ZOO_H

#include <iostream>
#include <vector>
#include "../Habitats/Habitat.h"

using namespace std;

class Zoo {
public:
    vector<Habitat*> m_enclos;

    Zoo(string nom);
    ~Zoo();

    void show() const;
    void showHabitats() const;
    string listHabitats() const;

    const string & getName() const;
    int getNbrOfEnclos() const;

    void addHabitat(Habitat *habitat);

    void removeHabitat(Habitat *habitat);

    // TODO : Passing to the next year func
//    void nextYear();


private:
    string m_name;
    int m_days;
};


#endif //CORRECTION_TP_FEU_ZOO_H
