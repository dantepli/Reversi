#include "../include/JoinGameCommand.h"
JoinGameCommand::JoinGameCommand() {}
void JoinGameCommand::execute(vector<string> args) {
  GameLobbies *lobbies = GameLobbies::getInstance();
  string lobbyName = args[0];
  int socket = atoi(args[1].c_str());
  GameLobby *lobby = lobbies->getLobby(lobbyName);
  lobby->setJoinedSocket(socket); // sets the the second player socket.
  // ########### NEED TO START THE GAME.............
}
JoinGameCommand::~JoinGameCommand() {

}
