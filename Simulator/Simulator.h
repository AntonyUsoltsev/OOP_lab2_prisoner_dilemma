#ifndef LAB2_PRISONER_DILEMMA_SIMULATOR_H
#define LAB2_PRISONER_DILEMMA_SIMULATOR_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Help.h"
#include "../Constants/Constants.h"
#include "../Factory/Factory.h"
#include "../History/History.h"
#include "../Matrix/Matrix.h"
#include "../Result/Result.h"
#include "../Strategies/Class_strategy/Class_str.h"
#include "../Strategies/Strategy_1_alw_coop/Strategy_1.h"
#include "../Strategies/Strategy_2_alw_def/Strategy_2.h"
#include "../Strategies/Strategy_3_def_if_def/Strategy_3.h"
#include "../Strategies/Strategy_4_conf_file/Strategy_4.h"
#include "../Strategies/Strategy_5_alternation/Strategy_5.h"
#include "../Strategies/Strategy_6_rand/Strategy_6.h"
#include "../Strategies/Strategy_7_meta/Strategy_7.h"

class Simulator {
public:
    std::vector<int> str_nums;
    int str_count;
    int rounds;
    std::string mode;
    std::vector<Strategies *> str_list;

    Simulator(const Matrix &matrix, const History& hist, const Result& result);

    ~Simulator() = default;

    void create_str();

    void detailed(const Matrix &matrix, History hist, Result result);

    void fast(const Matrix &matrix, History hist, Result result);

    void tournament(const Matrix &matrix, History hist, Result result);

    void input_str_nums(int);

    void str_moves(int round, const std::vector<int>&, History &hist);

    void make_null();
};

#endif //LAB2_PRISONER_DILEMMA_SIMULATOR_H
