#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"
#include "StdLogic.h"
#include "HumanPlayer.h"
#include "Display.h"
#include "ConsoleDisplay.h"
class Game {
 public:
  /**
   * Default C'tor. Creates the game with 2 Human players and a board size 8.
   */
  Game();
  Game(Display *display,
       Board *board,
       Logic *logic,
       Player *white,
       Player *black);
  /**
   * D'tor. Deletes all the members given.
   */
  virtual ~Game();
  /**
   * plays the game.
   */
  void play();
 private:
  Display *display;
  Board *board;
  Logic *logic;
  Player *white;
  Player *black;
  bool whiteMoves;
  bool blackMoves;
  /**
   * plays a turn.
   * @param player - a player.
   */
  void playTurn(const Player &player);
  /**
   * prints the high score.
   * @param player1 - a player.
   * @param player2 - a player.
   */
  void determineHighScore(const Player &player1, const Player &player2);
  /**
   * updates the available moves.
   * @param player - a player.
   */
  void updateMoves(const Player &player, bool hasMoves);
};

#endif //GAME_H
