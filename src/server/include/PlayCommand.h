#ifndef REVERSI_PLAYCOMMAND_H
#define REVERSI_PLAYCOMMAND_H

#include "Command.h"
class PlayCommand: public Command {
 public:
  /**
   * C'tor.
   * @param server - a given server.
   */
  PlayCommand();
  /**
   * sends the given play to the other play.
   * @param args - arguments for the command.
   */
  virtual void execute(vector<string> args);
  /**
   * D'tor.
   */
  virtual ~PlayCommand();
 private:
};

#endif //REVERSI_PLAYCOMMAND_H
