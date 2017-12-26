#ifndef REVERSI_GAMELOBBIES_H
#define REVERSI_GAMELOBBIES_H

#include <map>
#include "GameLobby.h"
/**
 * Singleton object.
 */
class GameLobbies {
 public:
  /**
   *
   * @return - the instance of the singleton.
   */
  static GameLobbies *getInstance();
  /**
   * adds a new lobby, if the lobby already exits, does nothing.
   * @param lobbyName - lobby name.
   * @param socket - a socket descriptor id for the opening of the lobby.
   * @return - true if the game was added.
   */
  bool addLobby(string lobbyName, int socket);
  /**
   * removes a lobby.
   * @param lobbyName - lobby name.
   * @return - true if the removal was successful.
   */
  bool removeLobby(string lobbyName);
  /**
   *
   * @param lobbyName - name of the lobby.
   * @return - the lobby of the game.
   */
  GameLobby *getLobby(string lobbyName);
 private:
  map<string, GameLobby*> lobbies;
  GameLobbies() {}
  static GameLobbies *instance;
};

#endif //REVERSI_GAMELOBBIES_H
