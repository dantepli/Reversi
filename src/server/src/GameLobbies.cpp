#include "../include/GameLobbies.h"

GameLobbies *GameLobbies::instance = NULL;

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
  size_t removed = lobbies.erase(lobbyName);
  return removed > 0; // if erase was successful removed value is 1.
}
GameLobby *GameLobbies::getLobby(string lobbyName) {
  map<string, GameLobby *>::iterator it = lobbies.find(lobbyName);
  if (it == lobbies.end()) {
    return NULL;
  }
  return it->second; // GameLobby*
}

