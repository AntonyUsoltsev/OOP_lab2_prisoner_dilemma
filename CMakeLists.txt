cmake_minimum_required(VERSION 3.20)
project(lab2_prisoner_dilemma)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2_prisoner_dilemma main.cpp Result/Result.cpp Result/Result.h Matrix/Matrix.cpp
        Matrix/Matrix.h Histrory/History.cpp Histrory/History.h Strategies/Strategy_1_alw_coop/Strategy_1.cpp
        Strategies/Strategy_1_alw_coop/Strategy_1.h Simulator/Simulator.cpp Simulator/Simulator.h Constants/Constants.h
        Strategies/Class_strategy/Class_str.h Strategies/Strategy_2_alw_def/Strategy_2.cpp Strategies/Strategy_2_alw_def/Strategy_2.h
        Strategies/Strategy_3_def_if_def/Strategy_3.cpp Strategies/Strategy_3_def_if_def/Strategy_3.h Strategies/Strategy_4_conf_file/Strategy_4.cpp
        Strategies/Strategy_4_conf_file/Strategy_4.h Strategies/Strategy_5_alternation/Strategy_5.cpp Strategies/Strategy_5_alternation/Strategy_5.h
        Factory/Factory.cpp Factory/Factory.h Strategies/Strategy_6_rand/Strategy_6.cpp Strategies/Strategy_6_rand/Strategy_6.h Simulator/Help.cpp Simulator/Help.h)
