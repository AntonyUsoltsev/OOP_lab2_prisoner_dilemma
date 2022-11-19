//
// Created by Antony on 18.11.2022.
//

#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_7_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_7_H

#include "D:/Antony/Programing_C++/OOP/lab2_prisoner_dilemma/Factory/Factory.h"
#include "../Class_strategy/Class_str.h"
#include "../Strategy_1_alw_coop/Strategy_1.h"
#include "../Strategy_2_alw_def/Strategy_2.h"
#include "../Strategy_3_def_if_def/Strategy_3.h"
#include "../Strategy_4_conf_file/Strategy_4.h"
#include "../Strategy_5_alternation/Strategy_5.h"
#include "../Strategy_6_rand/Strategy_6.h"

class Strategy_7 : public Strategies {
public:
    using Strategies::Strategies;

    std::vector<Strategies *> str_list;
    std::vector<int> str_nums;
    int str_count;

    void set_moves() {
        std::ifstream fin("../Strategies/Strategy_7_meta/config_str_7.txt");
        if (!fin.is_open())
            throw (std::invalid_argument("File didn't open"));
        int inp;
        fin >> inp;
        str_count = inp;

        if(fin.eof())
            throw (std::invalid_argument("File is empty"));

        if (str_count < 0 || str_count > STR_CNT)
            throw (std::invalid_argument("Count of strategies is incorrect"));
        int count = 0;

        while (!fin.eof()) {
            fin >> inp;
            if (str_count < 0 || str_count > STR_CNT-1)
                throw (std::invalid_argument("Number of strategy is incorrect"));
            str_nums.push_back(inp);
            count++;
            if (count == str_count)
                break;
        }
        if (count < str_count)
            throw (std::invalid_argument("Too few args"));
//
//        if (str_nums.empty())
//            throw (std::invalid_argument("No match "));
        fin.close();

    }

    int decision(int round, int pos, History &hist) override {
        if (round == 0) {
            set_moves();
            Strategies_Factory<int, Strategies> str_fact;
            str_fact.add<Strategy_1>(1);
            str_fact.add<Strategy_2>(2);
            str_fact.add<Strategy_3>(3);
            str_fact.add<Strategy_4>(4);
            str_fact.add<Strategy_5>(5);
            str_fact.add<Strategy_6>(6);

            for (int i: str_nums)
                str_list.push_back(str_fact.get(i)());
        }

        int step =0;
        for (int i = 0; i < str_count; i++) {
            step += str_list[i]->decision(round, i, hist);
        }
        return (step%2);
    }
};

#endif //LAB2_PRISONER_DILEMMA_STRATEGY_7_H
