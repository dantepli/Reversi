#ifndef REVERSI_SERVER_H
#define REVERSI_SERVER_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

class Server {
 public:
  Server(int port); // constructor.
  void start(); // starts the server.
  void stop(); // stops the server.
 private:
  int port;
  int serverSocket; // the socket's file descriptor
  bool handleClient(int currentPlayer,int coPlayer); // run each client.
  int acceptClient(int &client); // accept each connections of the client.
  void setUpServer(); // setting up the server.
  void setUpClients(int firstClient, int secondClient); // give each client is number.
};

#endif //REVERSI_SERVER_H
