#include "Matrix.h"

Matrix::Matrix() {
    //FILE *fin = fopen("matrix.txt", "r");
    std::ifstream fin("../Matrix/matrix.txt");
    if (!fin.is_open()) {
        throw (std::invalid_argument("file didn't open"));
        //throw(const std::ios_base::failure);
    }
    score_matrix.resize(MAX_VAR);
    //act_matrix.resize(MAX_VAR);
    std::vector<int> hash(3);
    for (int i = 0; i < MAX_VAR; ++i) {
        for (int j = 0; j < 3; ++j) {
            char a;
            fin >> a;
            if (a != 'c' && a != 'd')
                throw (std::invalid_argument("Incorrect matrix"));
            //act_matrix[i].push_back(a);
            hash[j] = a - 'c';
        }

        int hash_ind = hash[0] * 4 + hash[1] * 2 + hash[2];

        for (int j = 3; j < 6; ++j) {
            int a;
            fin >> a;
            score_matrix[hash_ind].push_back(a);
        }
    }
}
