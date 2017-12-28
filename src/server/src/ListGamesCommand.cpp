#include "../include/ListGamesCommand.h"
ListGamesCommand::ListGamesCommand() {}
void ListGamesCommand::execute(vector<string> args) {
  int socket = atoi(args[0].c_str());
  GameLobbies *lobbies = GameLobbies::getInstance();
  vector<string> joinable = lobbies->getJoinableLobbies();
  const char *message;
  for (int i = 0; i < joinable.size(); i++) {
    // iterates through the names of the lobbies and writes
    // to the client.
    //server->writeToSocket(joinable[i].c_str(), socket);
    message = joinable[i].c_str();
    int n = static_cast<int>(write(socket, &message, strlen(message)));
    if (n == -1) {
      cout << "Error writing to socket" << endl;
      throw "Error writing to socket";
    }
  }
  //server->writeToSocket("LIST_END", socket);
  string end = "LIST_END";
  message = end.c_str();
  int n = static_cast<int>(write(socket, &message, strlen(message)));
  if (n == -1) {
    cout << "Error writing to socket" << endl;
    throw "Error writing to socket";
  }
}
ListGamesCommand::~ListGamesCommand() {

}
