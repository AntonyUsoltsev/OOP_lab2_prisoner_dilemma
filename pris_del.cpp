#include "pris_del.h"
#include "cassert"

matrix_constructor::matrix_constructor() {
    //FILE *fin = fopen("matrix.txt", "r");
    std::ifstream fin("matrix.txt");
    if (!fin.is_open()) {
        throw (std::invalid_argument("file didn't open"));
        //throw(const std::ios_base::failure);
    }
    score_matrix.resize(8);
    act_matrix.resize(8);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            char a;
            fin >> a;
            act_matrix[i].push_back(a);
        }
        for (int j = 3; j < 6; ++j) {
            int a;
            fin >> a;
            score_matrix[i].push_back(a);
        }
    }
}

simulator::simulator() {
    std::cout << "Insert three numbers of strategies (from 1 to " << STR_CNT << ")\n";
    str_nums.resize(3);
    std::cin >> str_nums[0] >> str_nums[1] >> str_nums[2];
    for (int c: str_nums) {
        if (c < 1 || c > STR_CNT)
            throw (std::invalid_argument("Strategy doesn't exist"));
    }
    std::cout << "Insert count of rounds\n";
    std::cin >> rounds;
    if (rounds < 0) {
        throw (std::invalid_argument("Count of numbers is incorrect"));
    }
}
