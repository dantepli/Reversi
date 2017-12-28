#ifndef REVERSI_GAMELOBBIES_H
#define REVERSI_GAMELOBBIES_H

#include <map>
#include <vector>
#include "GameLobby.h"

#define NO_JOINABLE "No Joinable Games"
/**
 * Singleton object.
 */
class GameLobbies {
 public:
  /**
   * D'tor. deletes the game lobbies inside.
   */
  ~GameLobbies();
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
  /**
   *
   * @return - a vector of the names of the joinable lobbies,
   * if there are no joinable games, the vector will contain
   * "No Joinable Games".
   */
  vector<string> getJoinableLobbies();
 private:
  map<string, GameLobby*> lobbies;
  GameLobbies() {}
  static GameLobbies *instance;
};

#endif //REVERSI_GAMELOBBIES_H
