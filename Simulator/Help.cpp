//
// Created by Antony on 12.11.2022.
//

#include "Help.h"

void Help::call_mode_help() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Mode help: 1) detailed - Cоревнование с детализацией. \n"
                 "\t\tНа каждом шаге программа ожидает нажатия клавиши от пользователя,после которого делает один шаг.\n "
                 "\t\tПодробное состояние симуляции выводится после каждого шага\n"
                 "\t   2) fast - Соревнование без детализации.\n"
                 "\t\tПрограмма вычисляет заданное количество ходов и выводит результат.\n"
                 "\t   3) tournament - Турнир. Программа перебирает все возможные тройки указанных стратегий и\n"
                 "\t\tпо общему результату выявляет победителя по сумме баллов за все игры.\n";
}