//#include <iostream>
//#include "gtest/gtest.h"
//#include "../Simulator/Simulator.h"
//
//TEST(Game,fast) {
//    Matrix matrix;
//    History hist;
//    Result result;
//    Simulator sim(matrix, hist, result);
//}
////
//TEST(bigint_test_costructor, str_constructor) {
//    EXPECT_EQ("0", (std::string) BigInt("0"));
//    EXPECT_EQ("0", (std::string) BigInt("-0"));
//    EXPECT_EQ("1234567899876543210", (std::string) BigInt("1234567899876543210"));
//    EXPECT_EQ("123456789", (std::string) BigInt("000000000123456789"));
//    EXPECT_EQ("-1239876545151515", (std::string) BigInt("-1239876545151515"));
//}
//
//TEST(bigint_test_costructor, copy_constructor) {
//    BigInt val1 = BigInt(123456789);
//    const BigInt &val2 = val1;
//    EXPECT_EQ("123456789", (std::string) val2);
//}
//
//
//TEST(bigint_test_operator, compare_test) {
//    EXPECT_TRUE(BigInt("0") == BigInt("-0"));
//    EXPECT_TRUE(BigInt("123456789987") == BigInt("123456789987"));
//
//    EXPECT_TRUE(BigInt("123456789987") != BigInt("984984295"));
//    EXPECT_TRUE(BigInt("123456789987") != BigInt("-123456789987"));
//
//    EXPECT_TRUE(BigInt("147149498419419") > BigInt("5"));
//    EXPECT_TRUE(BigInt("4294967296") > BigInt("-94984984984894"));
//    EXPECT_TRUE(BigInt("-49848494") > BigInt("-49848496"));
//
//    EXPECT_TRUE(BigInt("1") < BigInt("429499849484"));
//    EXPECT_TRUE(BigInt("-1949232149") < BigInt("135"));
//    EXPECT_TRUE(BigInt("-1984984156") < BigInt("-1984984152"));
//
//    EXPECT_TRUE(BigInt("16516165") <= BigInt("16516165"));
//    EXPECT_TRUE(BigInt("16516165") >= BigInt("16516165"));
//}
//
//
//GTEST_API_ int main(int argc, char **argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}