#ifndef REVERSI_STARTCOMMAND_H
#define REVERSI_STARTCOMMAND_H
#include "Command.h"
#include "GameLobbies.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>
#define START_SUCCESS "1"
#define START_FAILED "-1"
using namespace std;
class StartCommand : public Command {
 public:
  /**
   * C'tor.
   */
  StartCommand();
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
};

#endif //REVERSI_STARTCOMMAND_H
