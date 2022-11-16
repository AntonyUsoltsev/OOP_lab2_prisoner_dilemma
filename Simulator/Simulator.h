#ifndef LAB2_PRISONER_DILEMMA_SIMULATOR_H
#define LAB2_PRISONER_DILEMMA_SIMULATOR_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "../Result/Result.h"
#include "../Matrix/Matrix.h"
#include "../Histrory/History.h"
#include "../Constants/Constants.h"
#include "../Strategies/Class_strategy/Class_str.h"
#include "../Strategies/Strategy_1_alw_coop/Strategy_1.h"
#include "../Strategies/Strategy_2_alw_def/Strategy_2.h"
#include "../Strategies/Strategy_3/Strategy_3.h"
#include "../Strategies/Strategy_4/Strategy_4.h"
#include "../Strategies/Strategy_5_alternation/Strategy_5.h"
#include "../Strategies/Strategy_6_rand/Strategy_6.h"
#include "../Factory/Factory.h"
#include "Help.h"

class Simulator {
public:
    std::vector<int> str_nums;
    int str_count;
    int rounds;
    std::string mode;
    std::vector<Strategies *> str_list;

    Simulator(const Matrix &matrix, History hist, Result result);

    ~Simulator() = default;

    void create_str();

    void detailed(const Matrix &matrix, History hist, Result result);

    void fast(const Matrix &matrix, History hist, Result result);

    void tournament(const Matrix &matrix, History hist, Result result);

    //void main_game(const Matrix& matrix, History hist, Result result);

    void input_str_nums(Help help);

    void str_moves(int round, History &hist);

//    void stoi(std::string data,std::vector<int> str_nums);

    void make_null();
};

#endif //LAB2_PRISONER_DILEMMA_SIMULATOR_H
