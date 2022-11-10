#include "Result.h"

void Result::print_cur_res() {
    for (int r: res) {
        std::cout << r << " ";
    }
    std::cout << '\n';
    // int ind = distance(res.begin(), std::max_element(res.begin(), res.end()));
    //std::cout << "\nStrategy " << ind + 1 << " win with score " << res[ind];
}

void Result::print_tot_res() {
    std::cout << "Total score: ";
    print_cur_res();
    int ind = distance(res.begin(), std::max_element(res.begin(), res.end()));
    std::cout << "Strategy " << ind + 1 << " win with score " << res[ind] << '\n';
}

void Result::create_res( Matrix matrix, const History &hist) {
    for (auto &h: hist.history) {
        for (int j = 0; j < MAX_VAR; j++) {
            if (matrix.act_matrix[j] == h) {
                for (int k = 0; k < STR_PLAY; k++)
                    res[k] += matrix.score_matrix[j][k];
                break;
            }
        }
    }
}

void Result::clear_res() {
    for (int i = 0; i < STR_PLAY; i++) {
        res[i] = 0;
    }
}

void Result::print_tot_tour_res(int frst,int scnd,int thrd) {
    std::cout << "Total score: ";
    print_cur_res();
    int ind = distance(res.begin(), std::max_element(res.begin(), res.end()));
    int winner;
    switch (ind) {
        case 0 : winner = frst; break;
        case 1 : winner = scnd; break;
        case 2 : winner = thrd; break;
        default: throw (std::invalid_argument("bad winner"));
    }
    std::cout << "Strategy " << winner << " win with score " << res[ind] << '\n';
}

void Result::incr_res(int round,History hist,Matrix matrix) {
    for (int j = 0; j < MAX_VAR; j++) {
        if (matrix.act_matrix[j] == hist.history[round]) {
            for (int k = 0; k < STR_PLAY; k++)
                res[k] += matrix.score_matrix[j][k];
            break;
        }
    }
}
