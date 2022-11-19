//
// Created by Antony on 10.11.2022.
//

#ifndef LAB2_PRISONER_DILEMMA_STRATEGY_4_H
#define LAB2_PRISONER_DILEMMA_STRATEGY_4_H

#include "../Class_strategy/Class_str.h"

//This strategy do moves like in config file.

class Strategy_4 : public Strategies {
public:
    using Strategies::Strategies;

    std::vector<int> moves;

    void set_moves() {
        std::ifstream fin("../Strategies/Strategy_4_conf_file/config_str_4.txt");
        if (!fin.is_open())
            throw (std::invalid_argument("File didn't open"));
        char inp;
        fin >> inp;
        while (!fin.eof()) {
            if (inp != 'c' && inp != 'd')
                throw (std::invalid_argument("Incorrect move"));
            moves.push_back(static_cast<int> (inp - 'c'));
            fin >> inp;
        }
        fin.close();
        if (moves.empty())
            throw (std::invalid_argument("File is empty"));
    }

    int decision(int round, int pos, History &hist) override {
        if (round == 0)
            set_moves();
        return (moves[round % moves.size()]);
    }
};

#endif //LAB2_PRISONER_DILEMMA_STRATEGY_4_H
