//
// Created by Nayan Mallet on 22/02/2023.
//

#ifndef ZOOLIFE_ALIMENT_H
#define ZOOLIFE_ALIMENT_H
#include <string>

using namespace std;

enum class FoodType { VIANDE, GRAINES };

class Aliment {
public:
    Aliment(string nom, float prixKg, FoodType foodType);
    void show();
    string getNom();
    float getPrixKg() const;
    float getQuantite();
    void subQuantite(float qt);
    void addQuantite(float qt);
    FoodType getFoodType();
private:
    string m_nom;
    float m_prixKg;
    float m_quantite;
    FoodType m_foodType;
};


#endif //ZOOLIFE_ALIMENT_H
