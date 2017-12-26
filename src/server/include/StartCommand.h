#ifndef REVERSI_STARTCOMMAND_H
#define REVERSI_STARTCOMMAND_H
#include "Command.h"
#include "Server.h"

class StartCommand: public Command {
 public:
  /**
   * C'tor.
   * @param server - a given server.
   */
  StartCommand(Server *server);
  /**
   * starts a game lobby with the name given in the arguments,
   * if the game exits it will not open a new game lobby.
   * @param args - arguments for the command.
   */
  virtual void execute(vector<string> args);
  /**
   * D'tor.
   */
  virtual ~StartCommand();
 private:
  Server *server;
};

#endif //REVERSI_STARTCOMMAND_H
