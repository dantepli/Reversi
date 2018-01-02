#ifndef REVERSI_GAMEMANAGER_H
#define REVERSI_GAMEMANAGER_H

#include <cstring>
#include <unistd.h>
#include <iostream>
#include "GameLobbies.h"
#include "GameLobby.h"

#define REVERSI_MAX_LEN 255
using namespace std;
class GameManager {
 public:
  GameManager(GameLobby *lobby);
  /**
   * plays the game.
   */
  void play();
 private:
  GameLobby *lobby;
  /**
   * sets up the game, sends colors to players.
   */
  void setUpGame();
  /**
   * runs the game, reads and writes the moves of players.
   */
  void gameFlow();
  /**
   *
   * @param currPlayer - sender socket.
   * @param coPlayer - receiver socket.
   * @return - true if the game can continue.
   */
  bool playTurn(int currPlayer, int coPlayer);
  /**
   * removes the game lobby and closes the sockets.
   */
  void closeGame();
};

#endif //REVERSI_GAMEMANAGER_H
