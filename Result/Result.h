#ifndef LAB2_PRISONER_DILEMMA_RESULT_H
#define LAB2_PRISONER_DILEMMA_RESULT_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "../Matrix/Matrix.h"
#include "../Histrory/History.h"
#include "../Constants/Constants.h"

class Result {
public:
    std::vector<int> res = {0, 0, 0};

    Result() = default;

    void create_res(Matrix matrix, const History &hist);

    ~Result() = default;

    void print_cur_res();

    void print_tot_res(int frst,int scnd,int thrd);

    void clear_res();

    void incr_res(int, History, Matrix matrix);

    //void print_tot_tour_res(int frst, int scnd, int thrd);

    static void print_abs_win( std::vector<int>,const std::vector<int>& );
};

#endif //LAB2_PRISONER_DILEMMA_RESULT_H
