#include <sstream>
#include "../include/StartCommand.h"
StartCommand::~StartCommand() {

}
StartCommand::StartCommand() {}
void StartCommand::execute(vector<string> args) {
  GameLobbies *lobbies = GameLobbies::getInstance();
  string name = args[0];
  int socket;
  //int socket = atoi(args[1].c_str());
  stringstream ss(args[1]);
  ss >> socket;
  string msg;
  if (lobbies->addLobby(name, socket)) {
    // lobby addition succeeded
    //server->writeToSocket(START_SUCCESS, socket);
    cout << "ADDED LOBBY " << name << endl;
    msg = START_SUCCESS;
  } else {
    // lobby addition failed
    //server->writeToSocket(START_FAILED, socket);
    msg = START_FAILED;
  }
  int n = static_cast<int>(write(socket, msg.c_str(), msg.size()));
  cout << "SIZE SENT " << msg.size() + 1 << endl;
  cout << "WROTE ON START " << msg.c_str() << endl;
  if (n == -1) {
    cout << "Error writing to socket" << endl;
    throw "Error writing to socket";
  }
}
