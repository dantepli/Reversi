//
// Created by or on 26/11/17.
//
#include "Board_test.h"

TEST_F(Board_test, StartingPosition) {
  int mid = (board.getSize() / 2) - 1;
  int roofMid = (board.getSize() / 2);
  EXPECT_EQ(8 , board.getSize());
  EXPECT_TRUE(board.getCell(-1, 1) == NULL);
  for(int i=0;i < board.getSize(); i++) {
    for(int j=0;j < board.getSize(); j++) {
      EXPECT_TRUE(board.getCell(i,j) != NULL);
    }
  }
  EXPECT_EQ('O', board.getCell(mid,mid)->getDisk());
  EXPECT_EQ('O', board.getCell(roofMid,roofMid)->getDisk());
  EXPECT_EQ('X', board.getCell(roofMid,mid)->getDisk());
  EXPECT_EQ('X', board.getCell(mid,roofMid)->getDisk());

}

TEST_F(Board_test, DeepCopyTest) {
  board.getCell(1,1)->setDisk(Globals::kWhites);
  Board copyBoard(board);
  EXPECT_EQ('O', copyBoard.getCell(1,1)->getDisk());
  EXPECT_NE(&copyBoard, &board);
}

