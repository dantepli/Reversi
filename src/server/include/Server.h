#ifndef REVERSI_SERVER_H
#define REVERSI_SERVER_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

class Server {
 public:
  /**
 * C'tor.
 * @param port
 */
  Server(int port);
  /**
 * start the server and handle the clients.
 */
  void start();

  void stop();
 private:
  int port;
  int serverSocket; // the socket's file descriptor
  /**
 * handles the clients by sending and receiving their messages.
 * @param currentPlayer the client that send the message.
 * @param coPlayer  the client receiving the message.
 * @return a bool statement that let us know if to keep playing the game.
 */
  bool handleClient(int currentPlayer, int coPlayer);
  /**
 * Accepting each client that connect to server.
 * @param client
 * @return
 */
  int acceptClient(int &client);
  /**
 * Setting up the server.
 */
  void setUpServer();
  /**
 * Give the clients their numbers(who is first to play).
 * @param firstClient the first player.
 * @param secondClient the second player.
 */
  void setUpClients(int firstClient, int secondClient);
};

#endif //REVERSI_SERVER_H
