#include "pris_del.h"


int main() {
    try {
        matrix_constructor matrix;
        //matrix_constructor::create_matrix(matrix);
//        for (int i = 0; i < 8; ++i) {
//            for (int j = 0; j < 3; ++j) {
//                std::cout << matrix.matrix[i][j] << " ";
//            }
//            std::cout << std::endl;
//        }
        simulator sim;
        //strategies main_str;
        auto *str1_cr = new str_1_factory;
        auto *str2_cr = new str_2_factory;;
        auto *str3_cr = new str_3_factory;
        auto *str4_cr = new str_4_factory;
//        strategies str1 = main_str.create_strategy(sim.s1);
//        strategies str2 = main_str.create_strategy(sim.s2);
//        strategies str3 = main_str.create_strategy(sim.s3);
        //factory *str1 = &str1_cr;
//        factory *str2 = &str2_cr;
//        factory *str3 = &str3_cr;
        std::vector<strategies *> str_list;
        history hist;
        str_list.push_back(str1_cr->create());
        str_list.push_back(str2_cr->create());
        str_list.push_back(str3_cr->create());
        str_list.push_back(str4_cr->create());
        hist.incr_history(sim.rounds);
        for (int round = 0; round < sim.rounds; round++) {
            std::cout << round + 1 << " round ";
            for (int i: sim.str_nums) {
                char step = str_list[i - 1]->decision(round, hist);
                hist.set_value(step, round);
                std::cout << step << " ";
            }
            std::cout << "\n";
        }
        Result result(matrix,hist);
        result.print_res();
        for (auto it = str_list.begin(); it != str_list.end(); it++)
            delete (*it);
    }

    catch (const std::invalid_argument &err) {
        std::cerr << err.what();
    }

}
