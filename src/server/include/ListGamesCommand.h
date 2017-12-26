#ifndef REVERSI_LISTGAMESCOMMAND_H
#define REVERSI_LISTGAMESCOMMAND_H
#include "Command.h"
#include "Server.h"
class ListGamesCommand: public Command {
 public:
  /**
   *
   * @param server - a given server.
   */
  ListGamesCommand(Server *server);
  /**
   * retrieves a list of game lobbies currently available to join.
   * @param args - arguments for the command.
   */
  virtual void execute(vector<string> args);
  /**
   * D'tor.
   */
  virtual ~ListGamesCommand();
 private:
  Server *server;
};

#endif //REVERSI_LISTGAMESCOMMAND_H
