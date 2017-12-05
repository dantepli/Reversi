#ifndef REVERSI_SERVER_H
#define REVERSI_SERVER_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

class Server {
 public:
  Server(int port);
  void start();
  void stop();
 private:
  int port;
  int serverSocket; // the socket's file descriptor
  bool handleClient(int currentPlayer,int coPlayer);
  int acceptClient(int &client);
  void setUpServer();
};

#endif //REVERSI_SERVER_H
