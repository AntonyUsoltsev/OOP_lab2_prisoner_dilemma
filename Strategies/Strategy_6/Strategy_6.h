//
// Created by Antony on 11.11.2022.
//

#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_6_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_6_H

#include "../Class_strategy/Class_str.h"
#include <cstdlib>
#include <ctime>

class Strategy_6 : public Strategies {
public:
    using Strategies::Strategies;
    std::vector<int> rand_vect={static_cast<int>((unsigned) time(nullptr))};
    char decision(int round, History &hist) override {
        srand(rand_vect[round]);
        int random = rand();
        rand_vect.push_back(random);
        if (random % 2 == 0)
            return 'd';
        else
            return 'c';
    }
};

#endif //LAB2_PRISONER_DILEMMA_STRATEGY_6_H
