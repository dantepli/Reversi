#ifndef REVERSI_BOARD_TEST_H_H
#define REVERSI_BOARD_TEST_H_H

#include <gtest/gtest.h>
#include "../include/Board.h"

class Board_test : public testing::Test {

  virtual void SetUp() {
    board;
  }

  virtual void TearDown() {

  }

 protected:
  Board board;
};
#endif //REVERSI_BOARD_TEST_H_H
