#include "../include/ListGamesCommand.h"


ListGamesCommand::ListGamesCommand() {}
void ListGamesCommand::execute(vector<string> args) {
  int socket = atoi(args[0].c_str());
  GameLobbies *lobbies = GameLobbies::getInstance();
  vector<string> joinable = lobbies->getJoinableLobbies();
  string message;
  for (int i = 0; i < joinable.size() - 1; i++) {
    // iterates through the names of the lobbies and writes
    // to the client.
    message.append(joinable[i]);
    message.append(", ");
  }
  message.append(joinable[joinable.size() - 1]);
  int n = static_cast<int>(write(socket, message.c_str(), message.size()));
  if (n == -1) {
    cout << "Error writing to socket" << endl;
    throw "Error writing to socket";
  }
  close(socket);
}
ListGamesCommand::~ListGamesCommand() {

}
