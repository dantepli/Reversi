//
// Dan Teplitski 312895147
//

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
   * C'tor.
   */
  Game ();
  /**
   * D'tor.
   */
  virtual ~Game ();
  /**
   * plays the game.
   */
  void play ();
 private:
  Board board;
  Logic *logic;
  Player *white;
  Player *black;
  Display *display;
  bool whiteMoves;
  bool blackMoves;
  /**
   * plays a turn.
   * @param player - a player.
   */
  void playTurn (const Player &player);
  /**
   * prints the high score.
   * @param player1 - a player.
   * @param player2 - a player.
   */
  void determineHighScore (const Player &player1, const Player &player2);
  /**
   * updates the available moves.
   * @param player - a player.
   */
  void updateMoves(const Player &player, bool hasMoves);
};

#endif //GAME_H
