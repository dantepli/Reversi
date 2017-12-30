#include <cstring>
#include "../include/JoinGameCommand.h"
#include "../include/GameManager.h"
JoinGameCommand::JoinGameCommand() {}
void JoinGameCommand::execute(vector<string> args) {
  GameLobbies *lobbies = GameLobbies::getInstance();
  string lobbyName = args[0];
  int socket = atoi(args[1].c_str());
  GameLobby *lobby = lobbies->getLobby(lobbyName);
  lobby->setJoinedSocket(socket); // sets the the second player socket.
  // ########### NEED TO START THE GAME.............
  int n = static_cast<int>(write(socket, "1", 1));
  sleep(1); // #######################
  GameManager manager(lobby);
  manager.play();
}

JoinGameCommand::~JoinGameCommand() {

}
