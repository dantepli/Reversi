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
  /**
   * displays the possible moves for the player.
   * @param player - a player.
   * @param moves - a vector of possible moves.
   */
  virtual void displayHumanPlayerChoiceMessage(const Player &player,
                                               const vector<Cell *> &moves) const = 0;
  /**
   * displays a no possible moves message for the player.
   * @param player - a player.
   */
  virtual void displayNoMoves(const Player &player) const = 0;
  /**
   * displays the end screen of the game.
   * @param player1 - a player.
   * @param player2 - a player.
   * @param board - a board.
   * @param player1Score - player 1 score.
   * @param player2Score - player 2 score.
   */
  virtual void displayEndScreen(const Player &player1,
                                const Player &player2,
                                const Board &board,
                                int player1Score,
                                int player2Score) const = 0;
  /**
   * displays the choice of the cell given.
   * @param player - a player.
   * @param cell - a cell.
   */
  virtual void displayAIChoice(const Player &player,
                               const Cell &cell) const = 0;
  /**
   * displays a waiting for player message.
   */
  virtual void displayWaitingForPlayer() const = 0;
};
#endif //DISPLAY_H
