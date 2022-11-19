cmake_minimum_required(VERSION 3.20)
project(lab2_prisoner_dilemma)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2_prisoner_dilemma main.cpp Result/Result.cpp Result/Result.h Matrix/Matrix.cpp
        Matrix/Matrix.h History/History.cpp History/History.h Strategies/Strategy_1_alw_coop/Strategy_1.cpp
        Strategies/Strategy_1_alw_coop/Strategy_1.h Simulator/Simulator.cpp Simulator/Simulator.h Constants/Constants.h
        Strategies/Class_strategy/Class_str.h Strategies/Strategy_2_alw_def/Strategy_2.cpp Strategies/Strategy_2_alw_def/Strategy_2.h
        Strategies/Strategy_3_def_if_def/Strategy_3.cpp Strategies/Strategy_3_def_if_def/Strategy_3.h Strategies/Strategy_4_conf_file/Strategy_4.cpp
        Strategies/Strategy_4_conf_file/Strategy_4.h Strategies/Strategy_5_alternation/Strategy_5.cpp Strategies/Strategy_5_alternation/Strategy_5.h
        Factory/Factory.cpp Factory/Factory.h Strategies/Strategy_6_rand/Strategy_6.cpp Strategies/Strategy_6_rand/Strategy_6.h
        Simulator/Help.cpp Simulator/Help.h Strategies/Strategy_7_meta/Strategy_7.cpp Strategies/Strategy_7_meta/Strategy_7.h)

#find_package(GTest)
#target_link_libraries(big_int {GTEST_LIBRARY})
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
target_link_libraries(lab2_prisoner_dilemma gtest_main)
add_test(NAME example_test COMMAND example)