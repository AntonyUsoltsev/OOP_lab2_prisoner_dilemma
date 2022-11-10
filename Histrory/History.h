#ifndef LAB2_PRISONER_DILEMMA_HISTORY_H
#define LAB2_PRISONER_DILEMMA_HISTORY_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

class History {
public:
    std::vector<std::vector<char>> history;

    ~History() = default;

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

    void clear_history() {
        history.erase(history.begin(), history.end());
    }
};

#endif //LAB2_PRISONER_DILEMMA_HISTORY_H
