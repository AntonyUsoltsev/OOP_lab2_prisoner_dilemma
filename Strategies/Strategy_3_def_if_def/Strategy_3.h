#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_3_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_3_H

#include "../Class_strategy/Class_str.h"

//If two other strategies chose defect on previous step, this strategy also choose defect.

class Strategy_3 : public Strategies {
public:
    using Strategies::Strategies;

    int decision(int round, int pos, History &hist) override {
        if (round == 0)
            return C;
        else
            switch (pos) {
                case (0) :return (hist.history[round - 1][1] || hist.history[round - 1][2]);
                case (1): return (hist.history[round - 1][0] || hist.history[round - 1][2]);
                case (2): return (hist.history[round - 1][0] || hist.history[round - 1][1]);
                default: return D;
            }
    }
};

#endif //LAB2_PRISONER_DILEMMA_STRATEGY_3_H
