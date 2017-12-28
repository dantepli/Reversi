#include "../include/GameLobby.h"
GameLobby::GameLobby(const string &name, int initialSocket, int joinedSocket)
    : name(name), initialSocket(initialSocket), joinedSocket(joinedSocket) {}
void GameLobby::setJoinedSocket(int socket) {
  joinedSocket = socket;
}
bool GameLobby::isJoinable() {
  return initialSocket > NO_INIT && joinedSocket > NO_INIT;
}
string GameLobby::getLobbyName() {
  return name;
}
