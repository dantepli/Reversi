#include "../include/StartCommand.h"
StartCommand::~StartCommand() {

}
StartCommand::StartCommand() {}
void StartCommand::execute(vector<string> args) {
  GameLobbies *lobbies = GameLobbies::getInstance();
  string name = args[0];
  int socket = atoi(args[1].c_str());
  string msg;
  const char *message;
  if (lobbies->addLobby(name, socket)) {
    // lobby addition succeeded
    //server->writeToSocket(START_SUCCESS, socket);
    msg = START_SUCCESS;
    message = msg.c_str();
  } else {
    // lobby addition failed
    //server->writeToSocket(START_FAILED, socket);
    msg = START_SUCCESS;
    message = msg.c_str();
  }
  int n = static_cast<int>(write(socket, &message, strlen(message)));
  if (n == -1) {
    cout << "Error writing to socket" << endl;
    throw "Error writing to socket";
  }
}
