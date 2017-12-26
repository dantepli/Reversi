#ifndef REVERSI_REVERSIHANDLER_H
#define REVERSI_REVERSIHANDLER_H

#include "CommandsManager.h"
#include "GameLobby.h"
class ReversiHandler {
 public:
  ReversiHandler();
 private:
  CommandsManager manager;
  vector<GameLobby> lobbies;
};

#endif //REVERSI_REVERSIHANDLER_H
