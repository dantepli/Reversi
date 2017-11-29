#ifndef REVERSI_COMPPLAYER_TEST_H
#define REVERSI_COMPPLAYER_TEST_H

#include <gtest/gtest.h>
#include "../include/Display.h"
#include "../include/Logic.h"
#include "../include/ConsoleDisplay.h"
#include "../include/CompPlayer.h"
#include "../include/StdLogic.h"
class CompPlayer_test : public testing::Test {
  virtual void SetUp() {
    board = &bo;
    display = new ConsoleDisplay();
    logic = new StdLogic();
    CompWhitePlayer = new CompPlayer(display, board, logic, Globals::kWhites);
  }

  virtual void TearDown() {
    delete display;
    delete CompWhitePlayer;
    delete logic;
  }

 protected:
  Cell chosenCell;
  vector<Cell *> moves;
  Player *CompWhitePlayer;
  Logic *logic;
  Display *display;
  Board *board;
  Board bo;
};

#endif //REVERSI_COMPPLAYER_TEST_H
