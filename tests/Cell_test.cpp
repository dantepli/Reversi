//
// Created by or on 27/11/17.
//


#include <gtest/gtest.h>
#include "../src/Cell.h"

TEST(CellTest, HandLegalNums) {
  Cell defaultCell;
  EXPECT_EQ(0, defaultCell.getRow());
  EXPECT_EQ(0, defaultCell.getCol());
  EXPECT_EQ(' ', defaultCell.getDisk());
  int row = 1, col =1;
  char disk = Globals::kBlacks;
  Cell cell(row,col,disk);
  EXPECT_EQ(1, cell.getRow());
  EXPECT_EQ(1, cell.getCol());
  EXPECT_EQ('X', cell.getDisk());
  cell.setDisk(Globals::kWhites);
  EXPECT_EQ('O', cell.getDisk());
}