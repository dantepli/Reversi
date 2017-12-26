#ifndef REVERSI_JOINGAMECOMMAND_H
#define REVERSI_JOINGAMECOMMAND_H

#include "Server.h"
#include "Command.h"
class JoinGameCommand: public Command {
 public:
  /**
   *
   * @param server - a given server.
   */
  JoinGameCommand(Server *server);
  /**
   * joins a game lobby with the given name, and starts the game.
   * @param args - arguments for the command.
   */
  virtual void execute(vector<string> args);
  /**
   * D'tor.
   */
  virtual ~JoinGameCommand();
 private:
  Server *server;
};

#endif //REVERSI_JOINGAMECOMMAND_H
