// Dan Teplitski 312895147
// Or Lion 204025175

#ifndef REVERSI_COMPPLAYER_H
#define REVERSI_COMPPLAYER_H

#include <climits>
#include "Player.h"
#include "Logic.h"
#include "Board.h"
class CompPlayer : public Player {
 public:
  /**
   * C'tor.
   * @param board - a game board.
   * @param logic - logic for the game.
   * @param color - player color.
   */
  CompPlayer(Board *board, Logic *logic, char color);
  /**
   *
   * @param moves - a vector of possible moves.
   * @return - a picked cell to place the disk.
   */
  virtual Cell pickMove(vector<Cell *> &moves) const;
  virtual char getColor() const;
 private:
  Board *board;
  Logic *logic;
  char color;
  /**
   *
   * @param cell - a cell to perform the move on.
   * @return - score of the opponent after simulating the move.
   */
  int simMove(Cell &cell) const;
  /**
   *
   * @param b - a board.
   * @param move - a move to simulate the move.
   * @param opponent - an opponent.
   * @return - the max score the opponent can reach.
   */
  int simOpponent(Board &b, Cell &move, Player &opponent) const;
  /**
   *
   * @param b - a given board.
   * @return - the opponent's score (his disks - my disks).
   */
  int detScore(Board &b) const;
  /**
   *
   * @return - opponent's color.
   */
  char opponentColor() const;
};

#endif //REVERSI_COMPPLAYER_H
