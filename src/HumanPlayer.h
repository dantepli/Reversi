//
// Dan Teplitski 312895147
//

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"
#include <limits>
class HumanPlayer: public Player {
 public:
  /**
   * C'tor.
   * @param color - player's color.
   */
  HumanPlayer (char color);
  /**
   *
   * @param moves - a vector of possible moves.
   * @return - a chosen cell to place the disk.
   */
  virtual Cell pickMove(vector<Cell*> &moves) const;
  /**
   *
   * @return - player's color.
   */
  virtual char getColor () const;
  /**
   * D'tor.
   */
  virtual ~HumanPlayer();
 private:
  char color;
  /**
   * prints the message for the user.
   * @param moves - a vector of possible moves.
   */
  void printMessage(vector<Cell*> &moves) const;
  /**
   *
   * @param cell - a chosen cell.
   * @param moves - a vector of possible moves.
   * @return - true if the chosen cell is a valid move.
   */
  bool cellValidity (Cell &cell, vector<Cell *> &moves) const;
};

#endif //HUMANPLAYER_H
