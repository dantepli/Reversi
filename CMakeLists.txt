cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 98)

add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES
        src/Board.cpp
        include/Board.h
        src/Cell.cpp include/Cell.h include/Globals.h include/Player.h src/HumanPlayer.cpp include/HumanPlayer.h include/Logic.h src/StdLogic.cpp include/StdLogic.h src/Game.cpp include/Game.h include/Display.h src/ConsoleDisplay.cpp include/ConsoleDisplay.h src/CompPlayer.cpp include/CompPlayer.h include/Menu.h src/ConsoleMenu.cpp include/ConsoleMenu.h)
set(TEST_FILES
        tests/main_test.cpp tests/Board_test.cpp src/Board.cpp include/Board.h src/Cell.cpp include/Cell.h include/Globals.h include/Player.h src/HumanPlayer.cpp include/HumanPlayer.h include/Logic.h src/StdLogic.cpp include/StdLogic.h src/Game.cpp include/Game.h include/Display.h src/ConsoleDisplay.cpp include/ConsoleDisplay.h src/CompPlayer.cpp include/CompPlayer.h tests/Cell_test.cpp tests/StdLogic_test.cpp tests/Board_test.h include/Menu.h src/ConsoleMenu.cpp include/ConsoleMenu.h tests/StdLogic_test.h tests/CompPlayer_test.cpp tests/CompPlayer_test.h tests/Board_test.h)

add_executable(Reversi ${SOURCE_FILES} main.cpp)
add_executable(ReversiTest ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(ReversiTest gtest gtest_main)