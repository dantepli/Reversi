#ifndef REVERSI_JOINGAMECOMMAND_H
#define REVERSI_JOINGAMECOMMAND_H

#include <cstdlib>
#include "Command.h"
#include "GameLobbies.h"
class JoinGameCommand: public Command {
 public:
  /**
   *
   */
  JoinGameCommand();
  /**
   * joins a game lobby with the given name, and starts the game.
   * @param args - arguments for the command.
   */
  virtual void execute(vector<string> args);
  /**
   * D'tor.
   */
  virtual ~JoinGameCommand();
};

#endif //REVERSI_JOINGAMECOMMAND_H
