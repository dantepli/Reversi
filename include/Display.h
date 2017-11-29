#ifndef DISPLAY_H
#define DISPLAY_H
#include "Board.h"
#include "Player.h"
class Display {
 public:
  /**
   * displays the board.
   * @param b - a board.
   */
  virtual void displayBoard(Board &board) const = 0;
  virtual void displayHumanPlayerChoiceMessage(const Player &player,
                                               const vector<Cell *> &moves) const = 0;
  virtual void displayNoMoves(const Player &player) const = 0;
  virtual void displayEndScreen(const Player &player1,
                                const Player &player2,
                                const Board &board,
                                int player1Score,
                                int player2Score) const = 0;
  virtual void displayAIChoice(const Player &player,
                               const Cell &cell) const = 0;
};
#endif //DISPLAY_H
