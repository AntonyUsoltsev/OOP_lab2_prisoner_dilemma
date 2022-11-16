//
// Created by Antony on 11.11.2022.
//

#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_6_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_6_H

#include "../Class_strategy/Class_str.h"
#include <cstdlib>
#include <ctime>

//This strategy choose random variant.

class Strategy_6 : public Strategies {
public:
    using Strategies::Strategies;

    std::vector<int> rand_vect = {static_cast<int>((unsigned) time(nullptr))};

    int decision(int round, int pos, History &hist) override {
        srand(rand_vect[round]);
        int random = rand();
        rand_vect.push_back(random);
        if (random % 2 == 0)
            return D;
        else
            return C;
    }
};

#endif //LAB2_PRISONER_DILEMMA_STRATEGY_6_H
