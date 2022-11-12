#ifndef LAB2_PRISONER_DILEMMA_FACTORY_H
#define LAB2_PRISONER_DILEMMA_FACTORY_H

#include "../Strategies/Class_strategy/Class_str.h"
#include "../Strategies/Strategy_1/Strategy_1.h"
#include "../Strategies/Strategy_2/Strategy_2.h"
#include "../Strategies/Strategy_3/Strategy_3.h"
#include "../Strategies/Strategy_4/Strategy_4.h"
#include "../Strategies/Strategy_5/Strategy_5.h"
#include "../Strategies/Strategy_6/Strategy_6.h"

//class factory {
//public:
//    virtual Strategies *create() = 0;
//
//    virtual ~factory() = default;
//};
//
//class str_1_factory : public factory {
//public:
//    Strategies *create() override {
//        return new strategy_1;
//    }
//};
//
//class str_2_factory : public factory {
//public:
//    Strategies *create() override {
//        return new strategy_2;
//    }
//};
//
//class str_3_factory : public factory {
//public:
//    Strategies *create() override {
//        return new strategy_3;
//    }
//};
//
//class str_4_factory : public factory {
//public:
//    Strategies *create() override {
//        return new strategy_4;
//    }
//};
//
//class str_5_factory : public factory {
//public:
//    Strategies *create() override {
//        return new strategy_5;
//    }
//};
//
//class str_6_factory : public factory {
//public:
//
//    Strategies *create() override {
//        return new strategy_6;
//    }
//};

#include <iostream>
#include <string>
#include <map>

using namespace std;


template<class ID, class Base_strategies>
class Strategies_Factory {
private:
    typedef Base_strategies *(*fInstantiator)();

    std::map<ID, fInstantiator> classes;

    template<class Derived>
    static Base_strategies *instantiator() {
        return new Derived();
    }

public:
    Strategies_Factory() = default;

    template<class Derived>
    void add(ID id) {
        classes[id] = &instantiator<Derived>;
    }

    fInstantiator get(ID id) {
        return classes[id];
    }

};

#endif //LAB2_PRISONER_DILEMMA_FACTORY_H
