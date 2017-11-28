//
// Created by or on 28/11/17.
//

#include <gtest/gtest.h>
#include "../src/StdLogic.h"
#include "../src/Board.h"
#include "../src/HumanPlayer.h"
#include "../src/ConsoleDisplay.h"
#include "../src/CompPlayer.h"

#ifndef REVERSI_STDLOGIC_TEST_H
#define REVERSI_STDLOGIC_TEST_H

struct StdLogic_test : testing::Test {
  Cell* cell;
  Board* board;
  Board bo;
  Player* blackPlayer;
  Player* whitePlayer;
  Player* CompWhitePlayer;
  Logic* logic;
  Display* display;
  vector<Cell *> moves;
  StdLogic_test() {
      board = &bo;

    display = new ConsoleDisplay();
    CompWhitePlayer = new CompPlayer(display, board , logic, Globals::kWhites);
    blackPlayer = new HumanPlayer(display,Globals::kBlacks);
    whitePlayer = new HumanPlayer(display, Globals::kWhites);
    logic = new StdLogic();
  }
};
#endif //REVERSI_STDLOGIC_TEST_H
