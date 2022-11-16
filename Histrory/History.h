#ifndef LAB2_PRISONER_DILEMMA_HISTORY_H
#define LAB2_PRISONER_DILEMMA_HISTORY_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

class History {
public:
    std::vector<std::vector<int>> history;

    ~History() = default;

    void resize_history(int rounds) {
        history.resize(rounds);
    }

    void incr_history() {
        std::vector<int> tmp;
        history.push_back(tmp);
    }

    void set_value(int val, int round) {
        history[round].push_back(val);
    }

    void clear_history() {
        history.erase(history.begin(), history.end());
    }
};

#endif //LAB2_PRISONER_DILEMMA_HISTORY_H
