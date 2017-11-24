//
// Dan Teplitski 312895147
//

#ifndef STDLOGIC_H
#define STDLOGIC_H
#include "Logic.h"
#include "Player.h"
// Standard logic rule set for the Reversi game.
class StdLogic: public Logic {
 public:
  /**
   * C'tor.
   * @param board - a game board.
   */
  StdLogic(Board *board);
  /**
   * D'tor.
   */
  virtual ~StdLogic();
  /**
   *
   * @param player - a player to get the moves for.
   * @return - a vector of possible moves.
   */
  virtual vector<Cell*> getPossibleMoves(const Player &player);
  /**
   * flips the cells between the placed cell to the player's cell. assuming validity of cell.
   * @param player - a player to flip for.
   * @param cell - a chosen cell to flip from.
   */
  virtual void flip(const Player &player, const Cell &cell);
 private:
  Board* board;
  // directions in the 2D plain, creating all 8 = kNumOfDirs possible moves on the grid:
  // (1,0), (1,1) (0,1), (-1,1), (-1,0), (-1,-1), (0,-1), (1,-1).
  int *dx;
  int *dy;
  const int kNumOfDirs;
  /**
   *
   * @param opponentDisk - disk color for the opponent.
   * @param cell - a given cell to check for.
   * @return - true if possible to place player's disk.
   */
  bool isPossibleMove(char opponentDisk, const Cell &cell);
  /**
   *
   * @param row - row value.
   * @param col - column value.
   * @return - true if out of the bounds of the board.
   */
  bool outOfBounds(int row, int col);
  /**
   *
   * @param dx - x direction.
   * @param dy - y direction.
   * @param row - current row.
   * @param col - current column.
   * @param opponentDisk - opponents disk.
   * @return - true if we iterated through the opponents disks without reaching
   * the end of the board.
   */
  bool iterateOpponentDisks(int dx, int dy, int *row, int *col, char opponentDisk);
  /**
   *
   * @param playerCell - a current player cell disk.
   * @return - the opponent's player cell disk.
   */
  char opponentCell (char playerCell);
};

#endif //STDLOGIC_H
