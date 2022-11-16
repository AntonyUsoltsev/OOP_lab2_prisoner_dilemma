#ifndef LAB2_PRISONER_DILEMMA_MATRIX_H
#define LAB2_PRISONER_DILEMMA_MATRIX_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "../Constants/Constants.h"

class Matrix {
public:
    std::vector<std::vector<int>> score_matrix;

    Matrix();

    ~Matrix() = default;
};

#endif //LAB2_PRISONER_DILEMMA_MATRIX_H
