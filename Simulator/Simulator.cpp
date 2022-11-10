#include "Simulator.h"

void Simulator::input_str_nums() {
    std::cout << "Insert three numbers of strategies (from 1 to " << STR_CNT << ")\n"; //TODO: more 3 arg
    str_nums.resize(STR_PLAY);
    //  std::vector<int> buff;
    str_count = STR_PLAY;
//    for(int i = 0; i<STR_PLAY;i++){
//        int a;
//        std::cin>>a;
//        buff.push_back(a);
//    }
    std::cin >> str_nums[0] >> str_nums[1] >> str_nums[2];
    for (int c: str_nums) {
        if (c < 1 || c > STR_CNT)
            throw (std::invalid_argument("Strategy doesn't exist"));
    }
}

Simulator::Simulator() {
    std::cout << "Insert mode of game[detailed|fast|tournament]\n";
    std::cin >> mode;
    if (mode == "detailed") {
        input_str_nums();
    } else if (mode == "fast") {
        input_str_nums();
        std::cout << "Insert count of rounds\n";
        std::cin >> rounds;
        if (rounds < 0) {
            throw (std::invalid_argument("Count of numbers is incorrect"));
        }
    } else if (mode == "tournament") {
        std::cout << "Insert count of strategies\n";
        std::cin >> str_count;
        std::cout << "Insert numbers of strategies (from 1 to " << STR_CNT << ")\n";
        for (int i = 0; i < str_count; i++) {
            int num;
            std::cin >> num;
            if (num < 1 || num > STR_CNT)
                throw (std::invalid_argument("Strategy doesn't exist"));
            str_nums.push_back(num);
        }
        std::cout << "Insert count of rounds\n";
        std::cin >> rounds;
        if (rounds < 0) {
            throw (std::invalid_argument("Count of numbers is incorrect"));
        }

    } else
        throw (std::invalid_argument("Mode is incorrect"));

}

void Simulator::create_str() {
    auto *str1_cr = new str_1_factory;
    auto *str2_cr = new str_2_factory;
    auto *str3_cr = new str_3_factory;
    auto *str4_cr = new str_4_factory;
    auto *str5_cr = new str_5_factory;
    str_list.push_back(str1_cr->create());
    str_list.push_back(str2_cr->create());
    str_list.push_back(str3_cr->create());
    str_list.push_back(str4_cr->create());
    str_list.push_back(str5_cr->create());
}

void Simulator::str_moves(int round, History &hist) {
    for (int i: str_nums) {
        char step = str_list[i - 1]->decision(round, hist);
        hist.set_value(step, round);
        std::cout << step << " ";
    }
}


void Simulator::main_game(const Matrix& matrix, History hist, Result result) {
    create_str();

    if (mode == "detailed") {
        std::cout << "Press any button (to stop insert quit)\n";
        std::string insert;
        std::cin >> insert;
        int round = 0;
        while (insert != "quit") {
            hist.incr_history();

            std::cout << round + 1 << " round: ";
            str_moves(round, hist);
            std::cout << " Current score: ";
           // result.incr_res(round,hist, matrix);
            result.clear_res();
            result.create_res(matrix, hist);
            result.print_cur_res();   //done too many times
            round++;
            std::cin >> insert;
        }

        result.print_tot_res();

    } else if (mode == "fast") {
        hist.resize_history(rounds);
        for (int round = 0; round < rounds; round++) {
            std::cout << round + 1 << " round ";
            str_moves(round, hist);
            std::cout << "\n";
        }
        result.create_res(matrix, hist);
        result.print_tot_res();

    } else if (mode == "tournament") {
        for (int i = 0; i < str_count - 2; i++) {
            for (int j = i + 1; j < str_count - 1; j++) {
                for (int k = j + 1; k < str_count; k++) {
                    hist.clear_history();
                    hist.resize_history(rounds);
                    std::cout << "\nStrategies: " << str_nums[i] << " " << str_nums[j] << " " << str_nums[k] << '\n';
                    for (int round = 0; round < rounds; round++) {
                        char step = str_list[str_nums[i] - 1]->decision(round, hist);
                        hist.set_value(step, round);
                        std::cout << step << " ";
                        step = str_list[str_nums[j] - 1]->decision(round, hist);
                        hist.set_value(step, round);
                        std::cout << step << " ";
                        step = str_list[str_nums[k] - 1]->decision(round, hist);
                        hist.set_value(step, round);
                        std::cout << step << "\n";
                    }
                    result.create_res(matrix, hist);
                    //result.print_tot_res();
                    result.print_tot_tour_res(str_nums[i], str_nums[j], str_nums[k]);
                    result.clear_res();
                    // TODO:absolut winner
                }
            }
        }
    }
    make_null();
}

void Simulator::make_null() {
    for (auto &i: str_list)
        delete i;
}
