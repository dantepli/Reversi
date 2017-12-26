#ifndef REVERSI_COMMANDMANAGER_H
#define REVERSI_COMMANDMANAGER_H
#include <map>
#include "Command.h"
#include "Server.h"
class CommandsManager {
 public:
  /**
   * Default c'tor, initializes a server and the map.
   */
  CommandsManager();
  /**
   *
   * @param server - a given server.
   */
  CommandsManager(Server *server);
  /**
   * D'tor.
   */
  ~CommandsManager();
  /**
   * gets a command and executes it.
   * @param command - a given command.
   * @param args - arguments for the command.
   */
  void executeCommand(string command,
                      vector<string> args);
 private:
  Server *server;
  map<string, Command *> commandsMap;
  /**
   * initializes the map with the commands that need to
   * be supported by the server.
   */
  void initMap();
};

#endif //REVERSI_COMMANDMANAGER_H
