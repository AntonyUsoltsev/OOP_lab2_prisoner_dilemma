
#include "Simulator/Simulator.h"


int main() {
    try {

        Matrix matrix;
        //matrix_constructor::create_matrix(matrix);
//        for (int i = 0; i < 8; ++i) {
//            for (int j = 0; j < 3; ++j) {
//                std::cout << matrix.matrix[i][j] << " ";
//            }
//            std::cout << std::endl;
//        }

        History hist;
        Result result;
        Simulator sim(matrix,hist,result);

       return 0;
    }

    catch (const std::invalid_argument &err) {
        std::cerr << err.what();
    }
}