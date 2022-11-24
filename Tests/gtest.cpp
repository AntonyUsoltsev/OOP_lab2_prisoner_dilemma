#include <iostream>
#include "gtest/gtest.h"
#include "../Simulator/Simulator.h"

TEST(Factory, test_factory) {
    History hist;
    std::vector<Strategies *> str_list;
    Strategies_Factory<int, Strategies> str_fact;
    str_fact.add<Strategy_1>(1);
    str_fact.add<Strategy_2>(2);
    str_fact.add<Strategy_3>(3);
    str_fact.add<Strategy_4>(4);
    str_fact.add<Strategy_5>(5);
    str_fact.add<Strategy_6>(6);
    str_fact.add<Strategy_7>(7);

    for (int i = 1; i <= 7; i++)
        str_list.push_back(str_fact.get(i)());

    EXPECT_EQ(C, str_list[0]->decision(0, 1, hist));
    EXPECT_EQ(D, str_list[1]->decision(0, 1, hist));
    EXPECT_EQ(C, str_list[2]->decision(0, 1, hist));
    EXPECT_EQ(C, str_list[3]->decision(0, 1, hist));
    EXPECT_EQ(C, str_list[4]->decision(0, 1, hist));
    //EXPECT_EQ( , str_list[5]->decision(0,1,hist));
    EXPECT_EQ(D, str_list[6]->decision(0, 1, hist));

}

TEST (Matrix, read_matrix) {
    Matrix matr;

    std::vector<int> tmp = {7, 7, 7};
    EXPECT_EQ(tmp, matr.score_matrix[4*C+2*C+C]);

    tmp = {3, 3, 9};
    EXPECT_EQ(tmp, matr.score_matrix[4*C+2*C+D]);

    tmp = {3, 9, 3};
    EXPECT_EQ(tmp, matr.score_matrix[4*C+2*D+C]);

    tmp = {9, 3, 3};
    EXPECT_EQ(tmp, matr.score_matrix[4*D+2*C+C]);

    tmp = {0, 5, 5};
    EXPECT_EQ(tmp, matr.score_matrix[4*C+2*D+D]);

    tmp = {5, 0, 5};
    EXPECT_EQ(tmp, matr.score_matrix[4*D+2*C+D]);

    tmp = {5, 5, 0};
    EXPECT_EQ(tmp, matr.score_matrix[4*D+2*D+C]);

    tmp = {1, 1, 1};
    EXPECT_EQ(tmp, matr.score_matrix[4*D+2*D+D]);
}


GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}