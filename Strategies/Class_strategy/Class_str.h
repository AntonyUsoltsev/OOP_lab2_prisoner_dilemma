#ifndef LAB2_PRISONER_DILEMMA_CLASS_STR_H
#define LAB2_PRISONER_DILEMMA_CLASS_STR_H

#include "../../Histrory/History.h"

class Strategies {
public:
    virtual ~Strategies() = default;

    virtual char decision(int round, History &hist) = 0;
};
#endif //LAB2_PRISONER_DILEMMA_CLASS_STR_H
