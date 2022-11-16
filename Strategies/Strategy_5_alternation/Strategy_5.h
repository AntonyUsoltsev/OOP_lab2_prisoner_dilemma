//
// Created by Antony on 10.11.2022.
//

#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_5_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_5_H

#include "../Class_strategy/Class_str.h"

//This strategy choose alternation variants .

class Strategy_5 : public Strategies {
public:
    using Strategies::Strategies;

    int decision(int round, int pos, History &hist) override {
        if (round % 2 == 1)
            return D;
        return C;
    }
};

#endif //LAB2_PRISONER_DILEMMA_STRATEGY_5_H
