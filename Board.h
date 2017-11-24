//
// Dan Teplitski 312895147
//

#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include "Globals.h"
#include "Cell.h"
#define COL_SEP '|'
#define ROW_SEP '-'
using namespace std;
class Board {
 public:
  /**
   * Constructor. Initializes the board with starting values.
   * @param size - a value for the board size. Default size is 8x8.
   */
  Board(int size = Globals::kSize);
  /**
   * Clears the board to empty cells.
   */
  void clearBoard();
  /**
   *
   * @return - size of the board.
   */
  int getSize() const;
  /**
   *
   * @param row - row index.
   * @param col - column index.
   * @return - a cell in the corresponding location, NULL if out of bounds.
   */
  Cell* getCell(int row, int col);
  /**
   * Destructor.
   */
  virtual ~Board();
 private:
  Cell **board;
  int size;
};

#endif //BOARD_H
