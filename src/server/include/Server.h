#ifndef REVERSI_SERVER_H
#define REVERSI_SERVER_H
#include "ReversiHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <vector>
#define MAX_CONNECTED_CLIENTS 30
#define MAX_LEN 255
using namespace std;
class Server {
 public:
  /**
 * C'tor.
 * @param handler - a client handler.
 * @param port
 */
  Server(ReversiHandler *handler, int port);
  /**
 * start the server and handle the clients.
 */
  void start();
  /**
   * writes a message to the socket, throws exception if writing failed.
   * @param message - a given message.
   * @param socket - a given socket.
   */
  void writeToSocket(const char *message, int socket);
  /**
   *
   * @param socket - a given socket.
   * @return - the message read from the socket, NULL if read failed.
   */
  char *readFromSocket(int socket);
  void stop();
 private:
  int port;
  int serverSocket; // the socket's file descriptor
  char msg[MAX_LEN];
  vector<pthread_t> threads;
  ReversiHandler *handler;
  /**
 * handles the clients by sending and receiving their messages.
 * @param currentPlayer the client that send the message.
 * @param coPlayer  the client receiving the message.
 * @return a bool statement that let us know if to keep playing the game.
 */
//  bool handleClient(int currentPlayer, int coPlayer);
  /**
 * Accepting each client that connect to server.
 * @param client
 * @return
 */
  int acceptClient();
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
