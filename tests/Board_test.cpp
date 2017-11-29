#include "Board_test.h"

TEST_F(Board_test, StartingPosition) {
  int mid = (board.getSize() / 2) - 1;
  int roofMid = (board.getSize() / 2);
  EXPECT_EQ(8, board.getSize());
  // no access to cells that are not in the board.
  EXPECT_TRUE(board.getCell(-1, 1) == NULL);
  // checks that we can access all the cells in the boards.
  for (int i = 0; i < board.getSize(); i++) {
    for (int j = 0; j < board.getSize(); j++) {
      EXPECT_TRUE(board.getCell(i, j) != NULL);
    }
  }
  // checking the starting position.
  EXPECT_EQ('O', board.getCell(mid, mid)->getDisk());
  EXPECT_EQ('O', board.getCell(roofMid, roofMid)->getDisk());
  EXPECT_EQ('X', board.getCell(roofMid, mid)->getDisk());
  EXPECT_EQ('X', board.getCell(mid, roofMid)->getDisk());

}

TEST_F(Board_test, DeepCopyTest) {
  board.getCell(1, 1)->setDisk(Globals::kWhites); // a test cell
  Board eqBoard(6);
  eqBoard = board;
  // checks that board of different size cannot be equal.
  EXPECT_NE('O', eqBoard.getCell(1, 1)->getDisk());
  Board copyBoard(board);
  // checks that deep copy is working (copy the board and has different address in the memory)
  EXPECT_EQ('O', copyBoard.getCell(1, 1)->getDisk());
  EXPECT_NE(&copyBoard, &board);
  // checks that every cell in the board has different address in the memory compare to the copy.
  for (int i = 0; i < board.getSize(); i++) {
    for (int j = 0; j < board.getSize(); j++) {
      EXPECT_NE(board.getCell(i, j), copyBoard.getCell(i,j));
    }
  }
}

