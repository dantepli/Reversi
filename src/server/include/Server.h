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
   * stop the server.
   */
  void stop();
 private:
  int port;
  int serverSocket; // the socket's file descriptor
  char msg[REVERSI_MAX_LEN];
  ReversiHandler *handler;
  /**
 * Setting up the server.
 */
  void setUpServer();
};

#endif //REVERSI_SERVER_H
