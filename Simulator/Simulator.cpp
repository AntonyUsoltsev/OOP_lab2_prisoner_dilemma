#include "Simulator.h"

Simulator::Simulator(const Matrix &matrix, const History &hist, const Result &result) {
    std::cout << "Insert mode of game [detailed|fast|tournament] or [help] to call help\n";
    std::cin >> mode;

    if (mode == "help") {
        Help::call_mode_help();
        std::cout << "Insert mode of game[detailed|fast|tournament]\n";
        std::cin >> mode;
    }

    if (mode == "detailed") {
        input_str_nums();

        detailed(matrix, hist, result);

    } else if (mode == "fast") {
        input_str_nums();
        std::cout << "Insert count of rounds\n";
        std::cin >> rounds;
        if (rounds < 0)
            throw (std::invalid_argument("Count of numbers is incorrect"));

        fast(matrix, hist, result);

    } else if (mode == "tournament") {
        std::cout << "Insert count of strategies\n";
        std::cin >> str_count;
        if (str_count < 3)
            throw (std::invalid_argument("Count of strategies is incorrect"));
        std::cout << "Insert " << str_count << " numbers of strategies (from 1 to " << STR_CNT << ")\n";

        for (int i = 0; i < str_count; i++) {
            int num;
            std::cin >> num;
            if (num < 1 || num > STR_CNT)
                throw (std::invalid_argument("Strategy doesn't exist"));
            str_nums.push_back(num);
        }

        std::cout << "Insert count of rounds\n";
        std::cin >> rounds;
        if (rounds <= 0)
            throw (std::invalid_argument("Count of numbers is incorrect"));

        tournament(matrix, hist, result);

    } else
        throw (std::invalid_argument("Mode is incorrect"));
}

void Simulator::input_str_nums() {
    std::cout << "Insert three numbers of strategies (from 1 to " << STR_CNT << ") or [help] to call help\n";
    str_count = STR_PLAY;
    str_nums.resize(str_count);
    std::string data;
    std::cin >> data;
    if (data == "help") {
        Help::call_str_help();
        std::cout << "Insert three numbers of strategies (from 1 to " << STR_CNT << ")\n";
        std::cin >> str_nums[0] >> str_nums[1] >> str_nums[2];
    } else {
        int a = std::stoi(data);
        str_nums[0] = a;
        std::cin >> str_nums[1] >> str_nums[2];
    }
    for (int c: str_nums)
        if (c < 1 || c > STR_CNT)
            throw (std::invalid_argument("Strategy doesn't exist"));
}

void Simulator::create_str() {

    Strategies_Factory<int, Strategies> str_fact;
    str_fact.add<Strategy_1>(1);
    str_fact.add<Strategy_2>(2);
    str_fact.add<Strategy_3>(3);
    str_fact.add<Strategy_4>(4);
    str_fact.add<Strategy_5>(5);
    str_fact.add<Strategy_6>(6);

    for (int i: str_nums)
        str_list.push_back(str_fact.get(i)());
}

void Simulator::str_moves(int round, History &hist) {
    for (int i = 0; i < 3; i++) {
        int step = str_list[i]->decision(round, i, hist);
        hist.set_value(step, round);
        std::cout << static_cast<char>(step + 'c') << " ";
    }
}

void Simulator::detailed(const Matrix &matrix, History hist, Result result) {
    create_str();
    std::cout << "Press any button (to stop insert quit)\n";
    std::string insert;
    std::cin >> insert;
    int round = 0;
    while (insert != "quit") {
        hist.incr_history();

        std::cout << round + 1 << " round: ";
        str_moves(round, hist);

        result.incr_res(round, hist, matrix);
        std::cout << " Current score: ";
        result.print_cur_res();
        round++;
        std::cin >> insert;
    }
    result.print_tot_res(str_nums[0], str_nums[1], str_nums[2]);
    make_null();
}

void Simulator::fast(const Matrix &matrix, History hist, Result result) {
    create_str();
    hist.resize_history(rounds);
    for (int round = 0; round < rounds; round++) {
        std::cout << round + 1 << " round: ";
        str_moves(round, hist);
        std::cout << "\n";
    }
    result.create_res(matrix, hist);
    result.print_tot_res(str_nums[0], str_nums[1], str_nums[2]);
    make_null();
}


void Simulator::tournament(const Matrix &matrix, History hist, Result result) {
    create_str();
    std::vector<int> abs_win(STR_CNT);
    for (int i = 0; i < str_count - 2; i++) {
        for (int j = i + 1; j < str_count - 1; j++) {
            for (int k = j + 1; k < str_count; k++) {
                hist.clear_history();
                hist.resize_history(rounds);
                std::cout << "\nStrategies: " << str_nums[i] << " " << str_nums[j] << " " << str_nums[k] << '\n';
                for (int round = 0; round < rounds; round++) {

                    int step = str_list[i]->decision(round, 0, hist);
                    hist.set_value(step, round);
                    std::cout << static_cast<char>(step + 'c') << " ";

                    step = str_list[j]->decision(round, 1, hist);
                    hist.set_value(step, round);
                    std::cout << static_cast<char>(step + 'c') << " ";

                    step = str_list[k]->decision(round, 2, hist);
                    hist.set_value(step, round);
                    std::cout << static_cast<char>(step + 'c') << "\n";
                }
                result.create_res(matrix, hist);
                result.print_tot_res(str_nums[i], str_nums[j], str_nums[k]);
                abs_win[str_nums[i] - 1] += result.res[0];
                abs_win[str_nums[j] - 1] += result.res[1];
                abs_win[str_nums[k] - 1] += result.res[2];
                result.clear_res();
            }
        }
    }
    std::cout << "\n";
    Result::print_abs_win(abs_win, str_nums);
    make_null();
}

void Simulator::make_null() {
    for (auto &i: str_list)
        delete i;
}