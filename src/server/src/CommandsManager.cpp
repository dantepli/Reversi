#include "../include/CommandsManager.h"
CommandsManager::CommandsManager() {
  commandsMap["start"] = new StartCommand();
  commandsMap["join"] = new JoinGameCommand();
  commandsMap["list_games"] = new ListGamesCommand();
}

CommandsManager::~CommandsManager() {
  map<string, Command *>::iterator it;
  for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
    delete it->second;
  }
}

void CommandsManager::executeCommand(string command, vector<string> args) {
  Command *commandObj = commandsMap[command];
  commandObj->execute(args);
}
