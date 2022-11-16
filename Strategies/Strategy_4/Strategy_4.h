//
// Created by Antony on 10.11.2022.
//

#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_4_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_4_H

#include "../Class_strategy/Class_str.h"

class Strategy_4 : public Strategies {
public:
    using Strategies::Strategies;
    char decision(int round,int pos, History &hist) override {
        //std::cout << "str3\n";
        if (round > 0 && hist.history[round - 1][0] == 'c' && hist.history[round - 1][1] == 'd') {
            return 'd';
        } else if (round >= 3)
            return 'c';
        else {
            return 'd';
        }
    }
};
#endif //LAB2_PRISONER_DILEMMA_STRATEGY_4_H
