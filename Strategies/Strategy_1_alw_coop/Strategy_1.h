#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_1_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_1_H

#include "../Class_strategy/Class_str.h"

// This strategy always choose to cooperate.

class Strategy_1 : public Strategies {
public:
    using Strategies::Strategies;

    int decision(int round, int pos, History &hist) override {
        return C;
    }
};

#endif //LAB2_PRISONER_DILEMMA_STRATEGY_1_H
