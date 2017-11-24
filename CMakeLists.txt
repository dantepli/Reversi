cmake_minimum_required(VERSION 3.8)
project(Ex1)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES
        Board.cpp
        Board.h
        main.cpp Cell.cpp Cell.h Globals.h Player.h HumanPlayer.cpp HumanPlayer.h Logic.h StdLogic.cpp StdLogic.h Game.cpp Game.h Display.h ConsoleDisplay.cpp ConsoleDisplay.h)

add_executable(Ex1 ${SOURCE_FILES})