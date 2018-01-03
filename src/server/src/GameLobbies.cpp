#include "../include/GameLobbies.h"

GameLobbies *GameLobbies::instance = NULL;
pthread_mutex_t GameLobbies::lock;

GameLobbies *GameLobbies::getInstance() {
  if (instance == NULL) {
    pthread_mutex_lock(&lock);
    if (instance == NULL) {
      instance = new GameLobbies();
    }
    pthread_mutex_unlock(&lock);
  }
  return instance;
}
GameLobbies::~GameLobbies() {
  map<string, GameLobby *>::iterator it;
  for (it = lobbies.begin(); it != lobbies.end(); it++) {
    delete it->second;
  }
}
bool GameLobbies::addLobby(string lobbyName, int socket) {
  pthread_mutex_lock(&lock);
  unsigned long count = lobbies.count(lobbyName);
  pthread_mutex_unlock(&lock);
  if (count == 1) {
    // same lobby exists in the map, no duplicate lobby can be created
    return false;
  }
  pthread_mutex_lock(&lock);
  lobbies[lobbyName] = new GameLobby(lobbyName, socket);
  pthread_mutex_unlock(&lock);
  return true;
}
bool GameLobbies::removeLobby(string lobbyName) {
  pthread_mutex_lock(&lock);
  map<string, GameLobby *>::iterator it = lobbies.find(lobbyName);
  pthread_mutex_unlock(&lock);
  if (it == lobbies.end()) {
    // no such lobby
    return false;
  }
  pthread_mutex_lock(&lock);
  delete it->second; // deletes the game lobby
  lobbies.erase(it); // removes entry from the map
  pthread_mutex_unlock(&lock);
  return true;
}
GameLobby *GameLobbies::getLobby(string lobbyName) {
  pthread_mutex_lock(&lock);
  map<string, GameLobby *>::iterator it = lobbies.find(lobbyName);
  pthread_mutex_unlock(&lock);
  if (it == lobbies.end() || !it->second->isJoinable()) {
    // lobby not found OR lobby is not joinable
    return NULL;
  }
  return it->second; // GameLobby*
}
vector<string> GameLobbies::getJoinableLobbies() {
  vector<string> joinable;
  map<string, GameLobby *>::iterator it;
  pthread_mutex_lock(&lock);
  for (it = lobbies.begin(); it != lobbies.end(); it++) {
    GameLobby *lobby = it->second;
    if (lobby->isJoinable()) {
      joinable.push_back(lobby->getLobbyName());
    }
  }
  pthread_mutex_unlock(&lock);
  if (joinable.empty()) {
    // no joinable games
    joinable.push_back(NO_JOINABLE);
  }
  return joinable;
}
void GameLobbies::deleteInstance() {
  if (instance == NULL) {
    return;
  }
  delete instance;
}
