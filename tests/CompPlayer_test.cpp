#include "CompPlayer_test.h"

TEST_F(CompPlayer_test, StartingPosition) {
  moves = logic->getPossibleMoves(*CompWhitePlayer, bo);
  chosenCell = CompWhitePlayer->pickMove(moves);
  EXPECT_EQ(chosenCell.toCoordinate(), "(3,5)");
}

TEST_F(CompPlayer_test, RegularAIMove) {
  for (int i = 2; i < 8; i++) {
    bo.getCell(i, i)->setDisk(Globals::kWhites);
  }
  for (int i = 2; i < 7; i++) {
    bo.getCell(i, i + 1)->setDisk(Globals::kBlacks);
  }
  bo.getCell(4, 3)->setDisk(Globals::kBlacks);
  bo.getCell(4, 4)->setDisk(Globals::kBlacks);
  bo.getCell(4, 5)->setDisk(Globals::kBlacks);
  bo.getCell(5, 4)->setDisk(Globals::kBlacks);
  bo.getCell(5, 6)->setDisk(Globals::kBlacks);
  bo.getCell(7, 6)->setDisk(Globals::kBlacks);
  moves = logic->getPossibleMoves(*CompWhitePlayer, bo);
  chosenCell = CompWhitePlayer->pickMove(moves);
  EXPECT_EQ(chosenCell.toCoordinate(), "(4,6)");
}

TEST_F(CompPlayer_test, OneMoveFromWin) {
  for (int j = 0; j < 5; j++) {
    bo.getCell(0, j)->setDisk(Globals::kWhites);
    bo.getCell(1, j)->setDisk(Globals::kWhites);
    bo.getCell(2, j)->setDisk(Globals::kWhites);
    bo.getCell(3, j)->setDisk(Globals::kWhites);
  }
  bo.getCell(1, 4)->setDisk(Globals::kEmpty);
  bo.getCell(2, 4)->setDisk(Globals::kEmpty);
  bo.getCell(2, 3)->setDisk(Globals::kBlacks);
  bo.getCell(3, 3)->setDisk(Globals::kBlacks);
  for (int j = 2; j < 6; j++) {
    bo.getCell(4, j)->setDisk(Globals::kWhites);
  }
  bo.getCell(4, 3)->setDisk(Globals::kBlacks);
  bo.getCell(5, 3)->setDisk(Globals::kBlacks);
  bo.getCell(5, 5)->setDisk(Globals::kWhites);
  bo.getCell(6, 6)->setDisk(Globals::kWhites);
  moves = logic->getPossibleMoves(*CompWhitePlayer, bo);
  chosenCell = CompWhitePlayer->pickMove(moves);
  EXPECT_EQ(chosenCell.toCoordinate(), "(7,4)");
}