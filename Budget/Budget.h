#ifndef ZOOLIFE_BUDGET_H
#define ZOOLIFE_BUDGET_H


class Budget {
public:
    Budget(int budget);

    void setBudget(int budget);
    int getBudget();
    void addBudget(int budget);
    void removeBudget(int budget);
private:
    int m_budget;

};


#endif //ZOOLIFE_BUDGET_H
