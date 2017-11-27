cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 98)

add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES
        src/Board.cpp
        src/Board.h
        src/Cell.cpp src/Cell.h src/Globals.h src/Player.h src/HumanPlayer.cpp src/HumanPlayer.h src/Logic.h src/StdLogic.cpp src/StdLogic.h src/Game.cpp src/Game.h src/Display.h src/ConsoleDisplay.cpp src/ConsoleDisplay.h src/CompPlayer.cpp src/CompPlayer.h)
set(TEST_FILES
        tests/main_test.cpp tests/Board_test.cpp src/Board.cpp src/Board.h src/Cell.cpp src/Cell.h src/Globals.h src/Player.h src/HumanPlayer.cpp src/HumanPlayer.h src/Logic.h src/StdLogic.cpp src/StdLogic.h src/Game.cpp src/Game.h src/Display.h src/ConsoleDisplay.cpp src/ConsoleDisplay.h src/CompPlayer.cpp src/CompPlayer.h)
add_executable(Reversi ${SOURCE_FILES} main.cpp)
add_executable(ReversiTest ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(ReversiTest gtest gtest_main)