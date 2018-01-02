#include "../include/GameManager.h"
GameManager::GameManager(GameLobby *lobby) : lobby(lobby) {}
void GameManager::play() {
  try {
    setUpGame();
  } catch (const char *error) {
    // failed creating game.
    closeGame();
  }
  gameFlow();
  closeGame();
}
void GameManager::setUpGame() {
  int n;
  int firstClient = lobby->getInitialSocket();
  int secondClient = lobby->getJoinedSocket();
  char msg[2] = {'1', '2'};
  n = static_cast<int>(write(firstClient, &msg[0], 1));
  if (n == -1) {
    throw "Error writing to player";
  }
  n = static_cast<int>(write(secondClient, &msg[1], 1));
  if (n == -1) {
    throw "Error writing to player";
  }
}
void GameManager::gameFlow() {
  // GameFlow
  int firstClient = lobby->getInitialSocket();
  int secondClient = lobby->getJoinedSocket();
  bool keepPlaying = true;
  while (keepPlaying) {
    keepPlaying = playTurn(firstClient, secondClient);
    if (!(keepPlaying)) {
      keepPlaying = false;
      continue;
    }
    keepPlaying = playTurn(secondClient, firstClient);
    if (!(keepPlaying)) {
      keepPlaying = false;
    }
  }
}
bool GameManager::playTurn(int currPlayer, int coPlayer) {
  int n;
  char msg[REVERSI_MAX_LEN];
  n = static_cast<int>(read(currPlayer, &msg, sizeof(msg)));
  if (n == -1) {
    cout << "Error reading msg" << endl;
    return false;
  }
  if (n == 0) {
    cout << "Client disconnected" << endl;
    return false;
  }
  n = static_cast<int>(write(coPlayer, &msg, strlen(msg) + 1));
  if (n == -1) {
    cout << "Error writing to socket" << endl;
    return false;
  }
  return strcmp(reinterpret_cast<const char *>(&msg), "End") != 0;
}
void GameManager::closeGame() {
  GameLobbies *lobbies = GameLobbies::getInstance();
  // close sockets and remove the lobby after the game is done
  close(lobby->getInitialSocket());
  close(lobby->getJoinedSocket());
  lobbies->removeLobby(lobby->getLobbyName());
}
