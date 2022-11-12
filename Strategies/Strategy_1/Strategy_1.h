#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_1_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_1_H
#include "../Class_strategy/Class_str.h"

class Strategy_1 : public Strategies {
public:
    using Strategies::Strategies;

    char decision(int round, History &hist) override {
        // std::cout << "str1";
        return 'c';
    }
};
#endif //LAB2_PRISONER_DILEMMA_STRATEGY_1_H
