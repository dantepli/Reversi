#include <cstring>
#include "../include/JoinGameCommand.h"
#include "../include/GameManager.h"

struct playGameArgs {
  GameLobby *lobby;
};

void *playGame(void *lobby) {
  struct playGameArgs *args = (struct playGameArgs *)lobby;
  GameManager manager(args->lobby);
  manager.play();
  delete args;
}

JoinGameCommand::JoinGameCommand() {}
void JoinGameCommand::execute(vector<string> args) {
  GameLobbies *lobbies = GameLobbies::getInstance();
  string lobbyName = args[0];
  int socket = atoi(args[1].c_str());
  int n;
  char clientResponse[2];
  string msg;
  GameLobby *lobby = lobbies->getLobby(lobbyName);
  if (lobby == NULL) {
    // invalid lobby name
    msg = JOIN_ERROR;
    n = static_cast<int>(write(socket, msg.c_str(), msg.size()));
    n = static_cast<int>(read(socket, clientResponse, sizeof(clientResponse)));
    if (n == -1) {
      throw "Error writing message to client";
    }
    close(socket); // finished handling this command.
    return;
  }
  msg = JOIN_SUCCESS;
  lobby->setJoinedSocket(socket); // sets the the second player socket.
  n = static_cast<int>(write(socket, msg.c_str(), msg.size()));
  if (n == -1) {
    throw "Error writing message to client";
  }
  n = static_cast<int>(read(socket, clientResponse, sizeof(clientResponse)));
  // play game arguments.
  struct playGameArgs *playArgs = new struct playGameArgs();
  playArgs->lobby = lobby;
  pthread_t playThread;
  pthread_create(&playThread, NULL, playGame, (void *) playArgs);

  //manager.play(); // starts the game.
}



JoinGameCommand::~JoinGameCommand() {

}
