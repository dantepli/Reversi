#include <cstring>
#include "../include/JoinGameCommand.h"
#include "../include/GameManager.h"

pthread_mutex_t join_lobbies_lock;

JoinGameCommand::JoinGameCommand() {}
void JoinGameCommand::execute(vector<string> args) {
  pthread_mutex_lock(&join_lobbies_lock);
  GameLobbies *lobbies = GameLobbies::getInstance();
  pthread_mutex_unlock(&join_lobbies_lock);
  string lobbyName = args[0];
  int socket = atoi(args[1].c_str());
  int n;
  GameLobby *lobby = lobbies->getLobby(lobbyName);
  if (lobby == NULL) {
    // invalid lobby name
    n = static_cast<int>(write(socket, "-1", 1));
    if (n == -1) {
      throw "Error writing message to client";
    }
    close(socket); // finished handling this command.
    return;
  }
  lobby->setJoinedSocket(socket); // sets the the second player socket.
  n = static_cast<int>(write(socket, "1", 1));
  if (n == -1) {
    throw "Error writing message to client";
  }
  sleep(0.5);
  GameManager manager(lobby);
  manager.play(); // starts the game.
}

JoinGameCommand::~JoinGameCommand() {

}
