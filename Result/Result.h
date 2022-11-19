#ifndef LAB2_PRISONER_DILEMMA_RESULT_H
#define LAB2_PRISONER_DILEMMA_RESULT_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "../Matrix/Matrix.h"
#include "../History/History.h"
#include "../Constants/Constants.h"

class Result {
public:
    std::vector<int> res = {0, 0, 0};

    Result() = default;

    void create_res(Matrix, const History &);

    ~Result() = default;

    void print_cur_res(const std::string&);

    void print_tot_res(int, int, int);

    void clear_res();

    void incr_res(int, History, Matrix);

    static void print_abs_win(std::vector<int>, const std::vector<int> &);
};

#endif //LAB2_PRISONER_DILEMMA_RESULT_H
