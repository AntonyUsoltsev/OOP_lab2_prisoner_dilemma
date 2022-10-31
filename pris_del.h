#ifndef LAB2_PRISONER_DILEMMA_PRIS_DEL_H
#define LAB2_PRISONER_DILEMMA_PRIS_DEL_H

//#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_VAR 8
#define STR_CNT 5
#define STR_PLAY 3

class Matrix {
public:
    std::vector<std::vector<char>> act_matrix;
    std::vector<std::vector<int>> score_matrix;

    Matrix();
};


class History {
public:
    std::vector<std::vector<char>> history;

    void resize_history(int rounds) {
        history.resize(rounds);
    }

    void incr_history() {
        std::vector<char> tmp;
        history.push_back(tmp);
    }

    void set_value(char val, int round) {
        history[round].push_back(val);
    }
};

class Strategies {
public:
    virtual ~Strategies() = default;

    virtual char decision(int round, History &hist) = 0;
};

class strategy_1 : public Strategies {
public:
    char decision(int round, History &hist) override {
        // std::cout << "str1";
        return 'c';
    }
};

class strategy_2 : public Strategies {
public:
    char decision(int round, History &hist) override {
        //std::cout << "str2";
        return 'd';
    }
};

class strategy_3 : public Strategies {
public:
    char decision(int round, History &hist) override {
        //std::cout << "str3\n";
        if (round > 0 && hist.history[round - 1][0] == 'c') {
            return 'd';
        } else
            return 'c';
    }
};

class strategy_4 : public Strategies {
public:
    char decision(int round, History &hist) override {
        //std::cout << "str3\n";
        if (round > 0 && hist.history[round - 1][0] == 'c' && hist.history[round - 1][1] == 'd') {
            return 'd';
        } else if (round >= 3)
            return 'c';
        else {
            return 'd';
        }
    }
};

class strategy_5 : public Strategies {
public:
    char decision(int round, History &hist) override {
        if (round % 2 == 1)
            return 'd';
        return 'c';
    }
};

class factory {
public:
    virtual Strategies *create() = 0;
    //virtual ~factory() = default;
};

class str_1_factory : public factory {
public:
    Strategies *create() override {
        return new strategy_1;
    }
};

class str_2_factory : public factory {
public:
    Strategies *create() override {
        return new strategy_2;
    }
};

class str_3_factory : public factory {
public:
    Strategies *create() override {
        return new strategy_3;
    }
};

class str_4_factory : public factory {
public:
    Strategies *create() override {
        return new strategy_4;
    }
};

class str_5_factory : public factory {
public:
    Strategies *create() override {
        return new strategy_5;
    }
};

class Result {
public:
    std::vector<int> res = {0, 0, 0};

   // Result(const Matrix &matrix, const History &hist);
     void create_res( Matrix matrix, const History &hist);
    //~Result() = default;

    void print_cur_res();

    void print_tot_res();
    void empty_res();
};

class Simulator {
public:
    std::vector<int> str_nums;
    int str_count;
    int rounds;
    std::string mode;
    std::vector<Strategies *> str_list;

    Simulator();

    void create_str();

    void main_game(Matrix matrix, History hist);

    void input_str_nums();

    void str_moves(int round, History &hist);
};

#endif //LAB2_PRISONER_DILEMMA_PRIS_DEL_H