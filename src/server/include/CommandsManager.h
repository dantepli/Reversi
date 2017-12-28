#ifndef REVERSI_COMMANDMANAGER_H
#define REVERSI_COMMANDMANAGER_H
#include <map>
#include "Command.h"
#include "GameLobby.h"
#include "StartCommand.h"
#include "JoinGameCommand.h"
#include "ListGamesCommand.h"
class CommandsManager {
 public:
  /**
   * C'tor.
   */
  CommandsManager();
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
  map<string, Command *> commandsMap;
};

#endif //REVERSI_COMMANDMANAGER_H
