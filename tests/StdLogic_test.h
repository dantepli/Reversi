//
// Created by or on 28/11/17.
//

#include <gtest/gtest.h>
#include "../src/StdLogic.h"
#include "../src/Board.h"
#include "../src/HumanPlayer.h"
#include "../src/ConsoleDisplay.h"

#ifndef REVERSI_STDLOGIC_TEST_H
#define REVERSI_STDLOGIC_TEST_H

struct StdLogic_test : testing::Test {
  Board board;
  Player* blackPlayer;
  Player* whitePlayer;
  Logic* logic;
  Display* display;
  StdLogic_test() {
    display = new ConsoleDisplay();
    blackPlayer = new HumanPlayer(display,Globals::kBlacks);
    whitePlayer = new HumanPlayer(display, Globals::kWhites);
    logic = new StdLogic();
  }
};
#endif //REVERSI_STDLOGIC_TEST_H
