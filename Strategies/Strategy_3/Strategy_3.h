#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_3_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_3_H

#include "../Class_strategy/Class_str.h"

class Strategy_3 : public Strategies {
public:
    using Strategies::Strategies;
    char decision(int round, int pos, History &hist) override {

        if (round == 0) {
            return 'c';
        } else
            return 'c';
    }
};
#endif //LAB2_PRISONER_DILEMMA_STRATEGY_3_H
