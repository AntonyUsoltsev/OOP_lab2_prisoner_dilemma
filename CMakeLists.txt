cmake_minimum_required(VERSION 3.20)
project(lab2_prisoner_dilemma)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2_prisoner_dilemma main.cpp Result/Result.cpp Result/Result.h Matrix/Matrix.cpp Matrix/Matrix.h Histrory/History.cpp Histrory/History.h Strategies/Strategy_1/Strategy_1.cpp Strategies/Strategy_1/Strategy_1.h Simulator/Simulator.cpp Simulator/Simulator.h Constants/Constants.h Strategies/Class_strategy/Class_str.h Strategies/Strategy_2/Strategy_2.cpp Strategies/Strategy_2/Strategy_2.h Strategies/Strategy_3/Strategy_3.cpp Strategies/Strategy_3/Strategy_3.h Strategies/Strategy_4/Strategy_4.cpp Strategies/Strategy_4/Strategy_4.h Strategies/Strategy_5/Strategy_5.cpp Strategies/Strategy_5/Strategy_5.h Factory/Factory.cpp Factory/Factory.h)
