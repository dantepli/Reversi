#include <gtest/gtest.h>
#include "../include/Cell.h"

TEST(CellTest, HandLegalNums) {
  Cell defaultCell;
  // checks if no arguments were entered to the cell.
  EXPECT_EQ(0, defaultCell.getRow());
  EXPECT_EQ(0, defaultCell.getCol());
  EXPECT_EQ(' ', defaultCell.getDisk());
  int row = 1, col = 1;
  char disk = Globals::kBlacks;
  Cell cell(row, col, disk);
  EXPECT_EQ(1, cell.getRow());
  EXPECT_EQ(1, cell.getCol());
  EXPECT_EQ('X', cell.getDisk());
  cell.setDisk(Globals::kWhites);
  // checks setDisk method.
  EXPECT_EQ('O', cell.getDisk());
}