#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_2_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_2_H

#include "../Class_strategy/Class_str.h"

//This strategy always choose to defect.

class Strategy_2 : public Strategies {
public:
    using Strategies::Strategies;

    int decision(int round, int pos, History &hist) override {
        return D;
    }
};

#endif //LAB2_PRISONER_DILEMMA_STRATEGY_2_H
