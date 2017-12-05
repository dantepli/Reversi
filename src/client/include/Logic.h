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
   * @param board - a board.
   * @return - a vector of the possible moves.
   */
  virtual vector<Cell *> getPossibleMoves(const Player &player,
                                          Board &board)  = 0;
  /**
   *
   * @param player - a player to flip the pieces for.
   * @param cell - a cell to flip the cells around.
   * @param board - a board.
   */
  virtual void flip(const Player &player, const Cell &cell, Board &board) = 0;
  /**
   * D'tor.
   */
  virtual ~Logic() {};
 private:
  virtual bool isPossibleMove(char opponentDisk,
                              const Cell &cell,
                              Board &board) = 0;
};

#endif //LOGIC_H
