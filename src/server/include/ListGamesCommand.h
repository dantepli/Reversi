#ifndef REVERSI_LISTGAMESCOMMAND_H
#define REVERSI_LISTGAMESCOMMAND_H
#include "Command.h"
#include "GameLobbies.h"
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <cstring>
#include <iostream>
class ListGamesCommand : public Command {
 public:
  /**
   *
   */
  ListGamesCommand();
  /**
   * retrieves a list of game lobbies currently available to join.
   * @param args - arguments for the command.
   */
  virtual void execute(vector<string> args);
  /**
   * D'tor.
   */
  virtual ~ListGamesCommand();
};

#endif //REVERSI_LISTGAMESCOMMAND_H
