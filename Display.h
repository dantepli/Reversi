//
// Dan Teplitski 312895147
//

#ifndef DISPLAY_H
#define DISPLAY_H
#include "Board.h"
class Display {
 public:
  /**
   * displays the board.
   * @param b - a board.
   */
  virtual void display(Board &board) const = 0;
};
#endif //DISPLAY_H
