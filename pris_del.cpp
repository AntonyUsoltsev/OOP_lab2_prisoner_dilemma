#include "pris_del.h"
#include "cassert"

matrix_constructor::matrix_constructor() {
    //FILE *fin = fopen("matrix.txt", "r");
    std::ifstream fin("matrix.txt");
    if (!fin.is_open()) {
        throw (std::ifstream::failbit);
        //throw(const std::ios_base::failure);
    }
    matrix.resize(8);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            int a;
            fin >> a;
            matrix[i].push_back(a);
        }
    }
}

strategies strategies::create_strategy(int id)  {
    strategies *p = nullptr;
    switch (id) {
        case 1:
            p = new strategy_1();
            break;
        case 2:
            p = new strategy_2();
            break;
        case 3:
            p = new strategy_3();
            break;
        default:
            assert(false);
    }
    return *p;
}
