//
// Dan Teplitski 312895147
//

#ifndef CELL_H
#define CELL_H
using namespace std;
#include <iostream>
#include <sstream>
#include <string>
#include "Globals.h"
class Cell {
 public:
  /**
   * Default Constructor.
   * @param row - row value for the cell in the grid (Board)
   * @param col - column value for the cell in the grid (Board).
   * @param disk - X or O for the player disks.
   */
  Cell(int row = 0, int col = 0, char disk = Globals::kEmpty);
  /**
   * Copy Constructor.
   * @param oldCell - Cell instance to copy.
   */
  Cell(const Cell &oldCell);
  /**
   *
   * @return - row value.
   */
  int getRow() const;
  /**
   *
   * @return - column value.
   */
  int getCol() const;
  /**
   *
   * @return - disk value.
   */
  char getDisk() const;
  /**
   *
   * @param disk - sets the current disk.
   */
  void setDisk(char disk);
  /**
   *
   * @param other - a cell.
   * @return - itself, with values from other assigned.
   */
  Cell &operator=(const Cell &other);
  /**
   *
   * @param other - a cell to compare with.
   * @return - true if equal (by coordinates).
   */
  bool operator==(const Cell &other);
  /**
   *
   * @param out - an output stream operator.
   * @param cell - a cell reference.
   * @return - an output stream representation of the cell (disk value).
   */
  friend ostream &operator<<(ostream &out, const Cell &cell);
  /**
   *
   * @return - a string representation of the location of the cell in the grid.
   */
  string toCoordinate() const;
 private:
  int row;
  int col;
  char disk;
};

#endif //CELL_H
