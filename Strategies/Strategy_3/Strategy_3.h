#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_3_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_3_H

#include "../Class_strategy/Class_str.h"

class Strategy_3 : public Strategies {
public:
    using Strategies::Strategies;
    char decision(int round, History &hist) override {
        //std::cout << "str3\n";
        if (round > 0 && hist.history[round - 1][0] == 'c') {
            return 'd';
        } else
            return 'c';
    }
};
#endif //LAB2_PRISONER_DILEMMA_STRATEGY_3_H
