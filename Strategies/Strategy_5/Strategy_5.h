//
// Created by Antony on 10.11.2022.
//

#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_5_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_5_H

#include "../Class_strategy/Class_str.h"

class strategy_5 : public Strategies {
public:
    char decision(int round, History &hist) override {
        if (round % 2 == 1)
            return 'd';
        return 'c';
    }
};

#endif //LAB2_PRISONER_DILEMMA_STRATEGY_5_H