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
GameLobbies::~GameLobbies() {
  map<string, GameLobby *>::iterator it;
  for (it = lobbies.begin(); it != lobbies.end(); it++) {
    delete it->second;
  }
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
  map<string, GameLobby *>::iterator it = lobbies.find(lobbyName);
  if (it == lobbies.end()) {
    // no such lobby
    return false;
  }
  delete it->second; // deletes the game lobby
  lobbies.erase(it); // removes entry from the map
  return true;
}
GameLobby *GameLobbies::getLobby(string lobbyName) {
  map<string, GameLobby *>::iterator it = lobbies.find(lobbyName);
  if (it == lobbies.end()) {
    return NULL;
  }
  return it->second; // GameLobby*
}
vector<string> GameLobbies::getJoinableLobbies() {
  vector<string> joinable;
  map<string, GameLobby *>::iterator it;
  for (it = lobbies.begin(); it != lobbies.end(); it++) {
    GameLobby *lobby = it->second;
    if (lobby->isJoinable()) {
      joinable.push_back(lobby->getLobbyName());
    }
  }
  if (joinable.empty()) {
    // no joinable games
    joinable.push_back(NO_JOINABLE);
  }
  return joinable;
}

