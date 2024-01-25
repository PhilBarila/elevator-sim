cmake_minimum_required(VERSION 3.27)
project(elevator_sim)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(elevator_sim main.cpp
        Elevator.cpp
        Elevator.h
        Controller.cpp
        Controller.h
        ArgParser.cpp
        ArgParser.h)

add_executable(elevator_sim_tests
        elevator_tests.cpp
        controller_tests.cpp
        argparser_tests.cpp
        arg_parser_tests.cpp
        Elevator.cpp
        Elevator.h
        Controller.cpp
        Controller.h
        ArgParser.cpp
        ArgParser.h)

target_link_libraries(elevator_sim_tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(elevator_sim_tests)