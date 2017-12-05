#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Cell.h"
/**
 * pure abstract class (interface).
 */
class Player {
 public:
  /**
   *
   * @param moves - a vector of possible moves.
   * @return - a picked cell to place the disk.
   */
  virtual Cell pickMove(vector<Cell *> &moves) const = 0;
  /**
   *
   * @return - color of the player.
   */
  virtual char getColor() const = 0;
  /**
   * Destructor.
   */
  virtual ~Player() {};
};

#endif //PLAYER_H
