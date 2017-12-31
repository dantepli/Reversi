#include <sstream>
#include "../include/StartCommand.h"

pthread_mutex_t start_lobbies_lock;

StartCommand::~StartCommand() {}
StartCommand::StartCommand() {}
void StartCommand::execute(vector<string> args) {
  pthread_mutex_lock(&start_lobbies_lock);
  GameLobbies *lobbies = GameLobbies::getInstance();
  pthread_mutex_unlock(&start_lobbies_lock);
  string name = args[0];
  int socket;
  int n;
  //int socket = atoi(args[1].c_str());
  stringstream ss(args[1]);
  ss >> socket;
  string msg;
  if (lobbies->addLobby(name, socket)) {
    // lobby addition succeeded
    cout << "ADDED LOBBY " << name << endl;
    msg = START_SUCCESS;
  } else {
    // lobby addition failed
    msg = START_FAILED;
    n = static_cast<int>(write(socket, msg.c_str(), msg.size()));
    if (n == -1) {
      cout << "Error writing to socket" << endl;
      throw "Error writing to socket";
    }
    close(socket); // close the socket.
    return;
  }
  n = static_cast<int>(write(socket, msg.c_str(), msg.size()));
  if (n == -1) {
    cout << "Error writing to socket" << endl;
    throw "Error writing to socket";
  }
}
