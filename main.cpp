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
            std::cout<<round+1<<" round ";
            for (int i:sim.str_nums) {
                char step = str_list[i-1]->decision(round, hist);
                hist.set_value(step, round);
                std::cout<<step<< " ";
            }
            std::cout<<"\n";
        }
        std::vector<int> res = {0, 0, 0};
        for (int i = 0; i < hist.history.size(); i++) {
            for (int j = 0; j < MAX_VAR; j++) {
                if (matrix.act_matrix[j] == hist.history[i]) {
                    res[0] += matrix.score_matrix[j][0];
                    res[1] += matrix.score_matrix[j][1];
                    res[2] += matrix.score_matrix[j][2];
                    break;
                }
            }
        }

        for (int i = 0; i < res.size(); i++) {
            std::cout << res[i] << " ";
        }
        int ind = distance(res.begin(),std::max_element(res.begin(),res.end()));
        std::cout << "\nStrategy "<<ind+1<<" win with score "<< res[ind];
//        strategies *sec = foo(ptr2);
//        for (int i = 1; i < 5; i++) {
//            main_str.do_decision(i);
//            str1.do_decision(i);
//            str2.do_decision(i);
//            str3.do_decision(i);
//        }

//        for (int i = 1; i < 5; ++i) {
//            for (int j = 0; j < 3; ++j) {
//                std::cout << main_str.history[i][j] << " ";
//            }
//            std::cout << std::endl;
//        }
        for (auto it = str_list.begin(); it != str_list.end(); it++)
            delete (*it);
    }

    catch (const std::invalid_argument &err) {
        std::cerr << err.what();
    }

}
