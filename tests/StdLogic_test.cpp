#include "StdLogic_test.h"

TEST_F(StdLogic_test, StartingPositionOfPossibleMovesHuman) {
  moves = logic->getPossibleMoves(*blackPlayer, bo);
  // checking that the moves is not empty and have 4 moves.
  EXPECT_FALSE(moves.empty());
  EXPECT_EQ(4, moves.size());
  // checks the possible moves of black player
  EXPECT_EQ(moves[0]->toCoordinate(), "(3,4)");
  EXPECT_EQ(moves[1]->toCoordinate(), "(4,3)");
  EXPECT_EQ(moves[2]->toCoordinate(), "(5,6)");
  EXPECT_EQ(moves[3]->toCoordinate(), "(6,5)");
  moves = logic->getPossibleMoves(*whitePlayer, bo);
  // checking that the moves is not empty and have 4 moves.
  EXPECT_FALSE(moves.empty());
  EXPECT_EQ(4, moves.size());
  // checks the possible moves of white player.
  EXPECT_EQ(moves[0]->toCoordinate(), "(3,5)");
  EXPECT_EQ(moves[1]->toCoordinate(), "(4,6)");
  EXPECT_EQ(moves[2]->toCoordinate(), "(5,3)");
  EXPECT_EQ(moves[3]->toCoordinate(), "(6,4)");
}

TEST_F(StdLogic_test, MidGameCheck) {
  // sets mid game board.
  bo.getCell(4, 4)->setDisk('X');
  bo.getCell(4, 5)->setDisk('X');
  bo.getCell(5, 4)->setDisk('X');
  bo.getCell(5, 6)->setDisk('X');
  bo.getCell(5, 5)->setDisk('O');
  bo.getCell(6, 6)->setDisk('O');
  moves = logic->getPossibleMoves(*blackPlayer, bo);
  // checks the possible moves of black player.
  EXPECT_EQ(moves[0]->toCoordinate(), "(3,3)");
  EXPECT_EQ(moves[1]->toCoordinate(), "(3,4)");
  EXPECT_EQ(moves[2]->toCoordinate(), "(4,3)");
  EXPECT_EQ(moves[3]->toCoordinate(), "(7,6)");
  EXPECT_EQ(moves[4]->toCoordinate(), "(8,7)");
  moves = logic->getPossibleMoves(*whitePlayer, bo);
  // checks the possible moves of white player.
  EXPECT_EQ(moves[0]->toCoordinate(), "(4,6)");
  EXPECT_EQ(moves[1]->toCoordinate(), "(5,7)");
  EXPECT_EQ(moves[2]->toCoordinate(), "(6,4)");
  EXPECT_EQ(moves[3]->toCoordinate(), "(6,8)");
  bo.getCell(3, 5)->setDisk('O');
  cell = bo.getCell(3, 5);
  logic->flip(*whitePlayer, *cell, bo);
  // checks the flip method.
  EXPECT_EQ('O', bo.getCell(3, 4)->getDisk());
  EXPECT_EQ('O', bo.getCell(4, 5)->getDisk());
}

TEST_F(StdLogic_test, NoMoves) {
  // put ' ' in the board.
  bo.clearBoard();
  // check that there are no possible moves to the players.
  moves = logic->getPossibleMoves(*blackPlayer, bo);
  EXPECT_TRUE(moves.empty());
  moves = logic->getPossibleMoves(*whitePlayer, bo);
  EXPECT_TRUE(moves.empty());

}

TEST_F(StdLogic_test, FullBoard) {
  for (int i = 0; i < bo.getSize(); i++) {
    for (int j = 0; j < bo.getSize(); j++) {
      bo.getCell(i, j)->setDisk(Globals::kWhites);
    }
  }
  moves = logic->getPossibleMoves(*blackPlayer, bo);
  EXPECT_TRUE(moves.empty());
  moves = logic->getPossibleMoves(*whitePlayer, bo);
  EXPECT_TRUE(moves.empty());
}