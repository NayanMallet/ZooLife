//
// Created by Nayan Mallet on 22/02/2023.
//

#ifndef ZOOLIFE_ALIMENT_H
#define ZOOLIFE_ALIMENT_H
#include <string>

using namespace std;


class Aliment {
public:
    Aliment(string nom, float prixKg);
    void show();
    string getNom();
    float getPrixKg() const;
private:
    string m_nom;
    float m_prixKg;
};


#endif //ZOOLIFE_ALIMENT_H
