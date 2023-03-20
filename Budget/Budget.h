#ifndef ZOOLIFE_BUDGET_H
#define ZOOLIFE_BUDGET_H
#include <string>

using namespace std;
//#include "../Zoo/Zoo.h"

class Budget {
public:
    Budget(float budget);

    void setBudget(float budget);
    float getBudget();
    void addBudget(float budget);
    void removeBudget(float budget);
    int Variation(double visitors, float percentage_range);
//    void subventionAnnual(Zoo zooLife);
//    void visiteurMonthly(Zoo zooLife, string month);

private:
    float m_budget;

};


#endif //ZOOLIFE_BUDGET_H
