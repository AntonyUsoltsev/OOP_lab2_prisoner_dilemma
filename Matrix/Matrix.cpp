#include "Matrix.h"

Matrix::Matrix() {
    std::ifstream fin("..//Matrix/matrix.txt");
    if (!fin.is_open())
        throw (std::invalid_argument("File didn't open"));
    score_matrix.resize(MAX_VAR);

    std::vector<int> hash(3);

    for (int i = 0; i < MAX_VAR; ++i) {
        for (int j = 0; j < 3; ++j) {
            char inp;
            fin >> inp;
            if (inp != 'c' && inp != 'd')
                throw (std::invalid_argument("Incorrect matrix"));
            hash[j] = inp - 'c';
        }

        int hash_ind = hash[0] * 4 + hash[1] * 2 + hash[2];

        for (int j = 3; j < 6; ++j) {
            int inp;
            fin >> inp;
            score_matrix[hash_ind].push_back(inp);
        }
    }
    fin.close();
}
