#include "../include/GameLobbies.h"
GameLobbies *GameLobbies::getInstance() {
  if (instance != NULL) {
    // already initialized.
    return instance;
  }
  // first time creation
  instance = new GameLobbies();
  return instance;
}
bool GameLobbies::addLobby(string lobbyName, int socket) {
  if (lobbies.count(lobbyName) == 1) {
    // same lobby exists in the map, no duplicate lobby can be created
    return false;
  }
  lobbies[lobbyName] = new GameLobby(lobbyName, socket);
  return true;
}
bool GameLobbies::removeLobby(string lobbyName) {
  return false;
}
GameLobby *GameLobbies::getLobby(string lobbyName) {
  return NULL;
}

GameLobbies::GameLobbies() {}
