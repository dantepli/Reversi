#ifndef REVERSI_GAMELOBBY_H
#define REVERSI_GAMELOBBY_H
#include <string>
#define NO_INIT -1
using namespace std;
class GameLobby {
 public:
  /**
   * C'tor.
   * @param name - a name for the lobby.
   * @param initialSocket - initial socket that opened that lobby.
   * @param joinedSocket - a second socket that joined the lobby.
   * default value is -1, uninitialized.
   */
  GameLobby(const string &name, int initialSocket, int joinedSocket = NO_INIT);
  /**
   *
   * @return - name of the lobby.
   */
  string getLobbyName();
  /**
   *
   * @return - the initial socket that opened the lobby.
   */
  int getInitialSocket();
  /**
   *
   * @return - the socket that joined the lobby.
   */
  int getJoinedSocket();
  /**
   *
   * @param socket - a socket to set as the second player.
   */
  void setJoinedSocket(int socket);
  /**
   *
   * @return - true if the lobby is joinable (has only one socket).
   */
  bool isJoinable();
 private:
  string name;
  int initialSocket;
  int joinedSocket;
};

#endif //REVERSI_GAMELOBBY_H
