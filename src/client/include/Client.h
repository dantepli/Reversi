#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
using namespace std;
#define REVERSI_MAX_LEN 255
class Client {
 public:
  /**
   * C'tor.
   * @param serverIP - the server's IP.
   * @param serverPort - the server's Port.
   */
  Client(const char *serverIP, int serverPort);
  /**
   * connects to the server.
   */
  void connectToServer();
  /**
   * sends the message to the server.
   * @param msg - a message to be sent.
   */
  void sendMsg(const char *msg);
  /**
   * receive a message from the server.
   * @return - a message from the server.
   */
  char *receiveMsg();
 private:
  const char *serverIP;
  char msg[REVERSI_MAX_LEN];
  int serverPort;
  int clientSocket;
  /**
   * clears the previous message leftover.
   */
  void clearMessage();
};

#endif //REVERSI_CLIENT_H
