#ifndef LAB2_PRISONER_DILEMMA_PRIS_DEL_H
#define LAB2_PRISONER_DILEMMA_PRIS_DEL_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_VAR 8
#define STR_CNT 4

class matrix_constructor {
public:
    std::vector<std::vector<char>> act_matrix;
    std::vector<std::vector<int>> score_matrix;

    matrix_constructor();
};

class simulator {
public:
    std::vector<int> str_nums;
    int rounds;
    std::string reg;

    simulator();
};

class history {
public:
    std::vector<std::vector<char>> history;

    void incr_history(int rounds) {
        history.resize(rounds);
    }

    void set_value(char val, int round) {
        history[round].push_back(val);
    }
};

class strategies {
public:
    // virtual ~strategies()= default;
    virtual char decision(int round, history hist) = 0;
};

class strategy_1 : public strategies {
public:
    char decision(int round, history hist) override {
        // std::cout << "str1";
        return 'c';
    }
};

class strategy_2 : public strategies {
public:
    char decision(int round, history hist) override {
        //std::cout << "str2";
        return 'd';
    }
};

class strategy_3 : public strategies {
public:
    char decision(int round, history hist) override {
        //std::cout << "str3\n";
        if (round > 0 && hist.history[round - 1][0] == 'c') {
            return 'd';
        } else
            return 'c';
    }
};

class strategy_4 : public strategies {
public:
    char decision(int round, history hist) override {
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

class factory {
public:
    virtual strategies *create() = 0;
    //virtual ~factory() = default;
};

class str_1_factory : public factory {
public:
    strategies *create() override {
        return new strategy_1;
    }
};

class str_2_factory : public factory {
public:
    strategies *create() override {
        return new strategy_2;
    }
};

class str_3_factory : public factory {
public:
    strategies *create() override {
        return new strategy_3;
    }
};

class str_4_factory : public factory {
public:
    strategies *create() override {
        return new strategy_4;
    }
};

class Result {
public:
    std::vector<int> res = {0, 0, 0};

    Result(matrix_constructor matrix, const history &hist) {
        for (auto &h: hist.history) {
            for (int j = 0; j < MAX_VAR; j++) {
                if (matrix.act_matrix[j] == h) {
                    for (int k = 0; k < STR_CNT; k++)
                        res[k] += matrix.score_matrix[j][k];
                    break;
                }
            }
        }
    }
    void print_res() {
        for (int i = 0; i < res.size(); i++) {
            std::cout << res[i] << " ";
        }
        int ind = distance(res.begin(), std::max_element(res.begin(), res.end()));
        std::cout << "\nStrategy " << ind + 1 << " win with score " << res[ind];
    }
};

#endif //LAB2_PRISONER_DILEMMA_PRIS_DEL_H


