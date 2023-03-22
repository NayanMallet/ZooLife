#ifndef ZOOLIFE_BUDGET_H
#define ZOOLIFE_BUDGET_H
#include <string>

using namespace std;

class Budget {
public:
    Budget(float budget);

    void setBudget(float budget);
    float getBudget();
    void addBudget(float budget);
    void removeBudget(float budget);

private:
    float m_budget;

};


#endif //ZOOLIFE_BUDGET_H
