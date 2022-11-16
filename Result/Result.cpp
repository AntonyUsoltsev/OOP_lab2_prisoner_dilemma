#include "Result.h"

void Result::create_res(Matrix matrix, const History &hist) {
    for (auto &h: hist.history) {
        int hash_ind = 4*(h[0]-'c')+2*(h[1]-'c')+(h[2]-'c');
//        for (int j = 0; j < MAX_VAR; j++) {
//            if (matrix.act_matrix[j] == h) {
                for (int k = 0; k < STR_PLAY; k++)
                    res[k] += matrix.score_matrix[hash_ind][k];
               // break;
//            }
//        }
    }
}

void Result::clear_res() {
    for (int i = 0; i < STR_PLAY; i++) {
        res[i] = 0;
    }
}

void Result::print_cur_res() {
    for (int r: res) {
        std::cout << r << " ";
    }
    std::cout << '\n';
}

void Result::print_tot_res(int frst, int scnd, int thrd) {
    std::cout << "Total score: ";
    print_cur_res();
    int ind = distance(res.begin(), std::max_element(res.begin(), res.end()));
    int winner;
    switch (ind) {
        case 0 :
            winner = frst;
            break;
        case 1 :
            winner = scnd;
            break;
        case 2 :
            winner = thrd;
            break;
        default:
            throw (std::invalid_argument("bad winner"));
    }
    std::cout << "Strategy " << winner << " win with score " << res[ind] << '\n';
}

void Result::print_abs_win(std::vector<int> abs_win, const std::vector<int>& str_nums) {
    std::cout << "Total score of tournament: ";
    for (int r: str_nums) {
        std::cout << r << ":" << abs_win[r - 1] << " ";
    }
    std::cout << '\n';
    int ind = distance(abs_win.begin(), std::max_element(abs_win.begin(), abs_win.end()));
    std::cout << "Strategy " << ind + 1 << " win with score " << abs_win[ind] << '\n';
}

void Result::incr_res(int round, History hist, Matrix matrix) {
    int hash_ind = 4*(hist.history[round][0]-'c')+2*(hist.history[round][1]-'c')+(hist.history[round][2]-'c');
//    for (int j = 0; j < MAX_VAR; j++) {
//        if (matrix.act_matrix[j] == hist.history[round]) {
            for (int k = 0; k < STR_PLAY; k++)
                res[k] += matrix.score_matrix[hash_ind][k];
//            break;
//        }
//    }
}


