#ifndef REVERSI_REVERSIHANDLER_H
#define REVERSI_REVERSIHANDLER_H

#include "CommandsManager.h"
#include <string>
#include <sstream>
#define COMMAND_DELIM " "
#define MAX_LEN 50
class ReversiHandler {
 public:
  ReversiHandler(CommandsManager *manager);
  /**
   * D'tor. deletes the commands manager.
   */
  virtual ~ReversiHandler();
  /**
   * handles the request by the socket according to the commands manager.
   * @param socket - a given socket to communicate with.
   */
  void handle(int socket);
 private:
  CommandsManager *manager;
};

#endif //REVERSI_REVERSIHANDLER_H
