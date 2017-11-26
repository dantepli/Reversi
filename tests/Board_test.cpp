//
// Created by or on 26/11/17.
//
#include <gtest/gtest.h>
#include "../src/Board.h"

TEST(BoardTest, HandleLegalNums) {
  Board board(6);
  EXPECT_EQ(6, board.getSize());
  for(int i=0;i < board.getSize(); i++) {
    for(int j=0;j < board.getSize(); j++) {
      EXPECT_TRUE(board.getCell(i,j));
    }
  }
}
