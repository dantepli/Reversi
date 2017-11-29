#include <gtest/gtest.h>
#include "../include/StdLogic.h"
#include "../include/Board.h"
#include "../include/HumanPlayer.h"
#include "../include/ConsoleDisplay.h"

#ifndef REVERSI_STDLOGIC_TEST_H
#define REVERSI_STDLOGIC_TEST_H

class StdLogic_test : public testing::Test {

  virtual void SetUp() {
    board = &bo;
    display = new ConsoleDisplay();
    blackPlayer = new HumanPlayer(display, Globals::kBlacks);
    whitePlayer = new HumanPlayer(display, Globals::kWhites);
    logic = new StdLogic();
  }

  virtual void TearDown() {
    delete display;
    delete blackPlayer;
    delete whitePlayer;
    delete logic;
  }

 protected:
  Cell *cell;
  Board *board;
  Board bo;
  Player *blackPlayer;
  Player *whitePlayer;
  Logic *logic;
  Display *display;
  vector<Cell *> moves;
};
#endif //REVERSI_STDLOGIC_TEST_H
