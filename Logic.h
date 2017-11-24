//
// Dan Teplitski 312895147
//

#ifndef LOGIC_H
#define LOGIC_H

#include <vector>
#include "Board.h"
#include "Player.h"
class Logic {
 public:
  /**
   *
   * @param player - a player to find the possible moves for.
   * @return - a vector of the possible moves.
   */
  virtual vector<Cell*> getPossibleMoves(const Player &player)  = 0;
  /**
   *
   * @param player - a player to flip the pieces for.
   * @param cell - a cell to flip the cells around.
   */
  virtual void flip(const Player &player, const Cell &cell) = 0;
  /**
   * D'tor.
   */
  virtual ~Logic() {};
 private:
  virtual bool isPossibleMove(char opponentDisk, const Cell &cell) = 0;
};

#endif //LOGIC_H
