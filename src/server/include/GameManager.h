#ifndef REVERSI_GAMEMANAGER_H
#define REVERSI_GAMEMANAGER_H

#include <cstring>
#include <unistd.h>
#include <iostream>
#include "GameLobbies.h"
#include "GameLobby.h"

#define MAX_LEN 255
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
  void setUpGame();
  void gameFlow();
  bool playTurn(int currPlayer, int coPlayer);
  void closeGame();
};

#endif //REVERSI_GAMEMANAGER_H
