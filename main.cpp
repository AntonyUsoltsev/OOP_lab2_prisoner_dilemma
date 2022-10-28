#include <iostream>
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
        strategies main_str;
        strategies str1 = main_str.create_strategy(sim.s1);
        strategies str2 = main_str.create_strategy(sim.s2);
        strategies str3 = main_str.create_strategy(sim.s3);
        for (int i = 1; i < 5; i++) {
            main_str.do_decision(i);
            str1.do_decision(i);
            str2.do_decision(i);
            str3.do_decision(i);
        }

        for (int i = 1; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << main_str.history[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    catch (const std::ios_base::failure &err) {
        std::cerr << err.what();
    }

}
