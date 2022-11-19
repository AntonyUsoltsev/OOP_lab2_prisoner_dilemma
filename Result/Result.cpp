#include "Result.h"

void Result::create_res(Matrix matrix, const History &hist) {
    for (auto &h: hist.history) {
        int hash_ind = 4 * h[0] + 2 * h[1] + h[2];
        for (int k = 0; k < STR_PLAY; k++)
            res[k] += matrix.score_matrix[hash_ind][k];
    }
}

void Result::clear_res() {
    for (int i = 0; i < STR_PLAY; i++)
        res[i] = 0;
}

void Result::print_cur_res(const std::string &str) {
    std::cout << str;
    for (int r: res)
        std::cout << r << " ";
    std::cout << '\n';
}

void Result::print_tot_res(int frst, int scnd, int thrd) {
    //  std::cout << "Total score: ";
    print_cur_res("Total score: ");
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

void Result::print_abs_win(std::vector<int> abs_win, const std::vector<int> &str_nums) {
    std::cout << "\nTotal score of tournament: ";
    for (int r: str_nums)
        std::cout << r << ":" << abs_win[r - 1] << " ";
    int ind = distance(abs_win.begin(), std::max_element(abs_win.begin(), abs_win.end()));
    std::cout << "\nStrategy " << ind + 1 << " win with score " << abs_win[ind] << '\n';
}

void Result::incr_res(int round, History hist, Matrix matrix) {
    auto h = hist.history[round];
    int hash_ind = 4 * h[0] + 2 * h[1] + h[2];
    for (int k = 0; k < STR_PLAY; k++)
        res[k] += matrix.score_matrix[hash_ind][k];
}