cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -pthread")
add_subdirectory(src/client/lib/googletest-release-1.8.0)
include_directories(src/client/lib/googletest-release-1.8.0/googletest/include)
include_directories(src/client/lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES
        src/client/src/Board.cpp
        src/client/include/Board.h
        src/client/src/Cell.cpp src/client/include/Cell.h src/client/include/Globals.h src/client/include/Player.h src/client/src/HumanPlayer.cpp src/client/include/HumanPlayer.h src/client/include/Logic.h src/client/src/StdLogic.cpp src/client/include/StdLogic.h src/client/src/Game.cpp src/client/include/Game.h src/client/include/Display.h src/client/src/ConsoleDisplay.cpp src/client/include/ConsoleDisplay.h src/client/src/CompPlayer.cpp src/client/include/CompPlayer.h src/client/include/Menu.h src/client/src/ConsoleMenu.cpp src/client/include/ConsoleMenu.h src/client/src/Client.cpp src/client/include/Client.h src/client/src/LocalPlayer.cpp src/client/include/LocalPlayer.h src/client/src/NetworkPlayer.cpp src/client/include/NetworkPlayer.h src/client/src/NetworkParser.cpp src/client/include/NetworkParser.h)
set(TEST_FILES
        src/client/tests/main_test.cpp src/client/tests/Board_test.cpp src/client/src/Board.cpp src/client/include/Board.h src/client/src/Cell.cpp src/client/include/Cell.h src/client/include/Globals.h src/client/include/Player.h src/client/src/HumanPlayer.cpp src/client/include/HumanPlayer.h src/client/include/Logic.h src/client/src/StdLogic.cpp src/client/include/StdLogic.h src/client/src/Game.cpp src/client/include/Game.h src/client/include/Display.h src/client/src/ConsoleDisplay.cpp src/client/include/ConsoleDisplay.h src/client/src/CompPlayer.cpp src/client/include/CompPlayer.h src/client/tests/Cell_test.cpp src/client/tests/StdLogic_test.cpp src/client/tests/Board_test.h src/client/include/Menu.h src/client/src/ConsoleMenu.cpp src/client/include/ConsoleMenu.h src/client/tests/StdLogic_test.h src/client/tests/CompPlayer_test.cpp src/client/tests/CompPlayer_test.h src/client/tests/Board_test.h src/client/src/Client.cpp src/client/include/Client.h src/client/src/LocalPlayer.cpp src/client/include/LocalPlayer.h src/client/src/NetworkPlayer.cpp src/client/include/NetworkPlayer.h src/client/src/NetworkParser.cpp src/client/include/NetworkParser.h)
set(SERVER_FILES
        src/server/src/Server.cpp src/server/include/Server.h src/server/src/CommandsManager.cpp src/server/include/CommandsManager.h src/server/include/Command.h src/server/src/StartCommand.cpp src/server/include/StartCommand.h src/server/src/ListGamesCommand.cpp src/server/include/ListGamesCommand.h src/server/src/JoinGameCommand.cpp src/server/include/JoinGameCommand.h src/server/src/GameLobby.cpp src/server/include/GameLobby.h src/server/src/ReversiHandler.cpp src/server/include/ReversiHandler.h src/server/src/GameLobbies.cpp src/server/include/GameLobbies.h src/server/src/GameManager.cpp src/server/include/GameManager.h src/server/include/Task.h src/server/src/ThreadPool.cpp src/server/include/ThreadPool.h)

add_executable(Reversi ${SOURCE_FILES} src/client/main.cpp)
add_executable(ReversiTest ${TEST_FILES} ${SOURCE_FILES})
add_executable(Server ${SERVER_FILES} src/server/main.cpp)
target_link_libraries(ReversiTest gtest gtest_main)