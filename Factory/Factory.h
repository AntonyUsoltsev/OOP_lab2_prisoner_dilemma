#ifndef LAB2_PRISONER_DILEMMA_FACTORY_H
#define LAB2_PRISONER_DILEMMA_FACTORY_H

#include <map>

template <class ID, class Base_strategy> class Strategies_Factory {
private:
    typedef Base_strategy *(*fInstantiator)();

    std::map<ID, fInstantiator> classes;

    template <class Derived> static Base_strategy *instantiator() {
        return new Derived();
    }

public:
    Strategies_Factory() = default;

    template <class Derived> void add(ID id) {
        classes[id] = &instantiator<Derived>;
    }

    fInstantiator get(ID id) {
        return classes[id];
    }
};

#endif //LAB2_PRISONER_DILEMMA_FACTORY_H