#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_3_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_2_H

#include "../Class_strategy/Class_str.h"

class strategy_2 : public Strategies {
public:
    char decision(int round, History &hist) override {
        //std::cout << "str2";
        return 'd';
    }
};
#endif //LAB2_PRISONER_DILEMMA_STRATEGY_3_H
