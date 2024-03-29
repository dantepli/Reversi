#include "../include/Client.h"
Client::Client(const char *serverIP, int serverPort)
    : serverIP(serverIP), serverPort(serverPort) {}
void Client::connectToServer() {
  // Create a socket point
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (clientSocket == -1) {
    throw "Error opening socket";
  }
  // Convert the ip string to a network address
  struct in_addr address;
  if (!inet_aton(serverIP, &address)) {
    throw "Can't parse IP address";
  }
  // Get a hostent structure for the given host address
  struct hostent *server;
  server = gethostbyaddr((const void *) &address, sizeof
      address, AF_INET);
  if (server == NULL) {
    throw "Host is unreachable";
  }
  // Create a structure for the server address
  struct sockaddr_in serverAddress;
  bzero((char *) &address, sizeof(address));
  serverAddress.sin_family = AF_INET;
  memcpy((char *) &serverAddress.sin_addr.s_addr,
         (char *) server->h_addr, server->h_length);
  // htons converts values between host and network byte
  // orders
  serverAddress.sin_port = htons(serverPort);
  // Establish a connection with the TCP server
  if (connect(clientSocket, (struct sockaddr *) &serverAddress,
              sizeof(serverAddress)) == -1) {
    throw "Error connecting to server";
  }
}
void Client::sendMsg(const char *msg) {
  // Write the message to the socket
  int n = write(clientSocket, msg, strlen(msg) + 1);
  if (n == -1) {
    throw "Error writing message to socket";
  }
}
char *Client::receiveMsg() {
  clearMessage();
  int n;
  n = read(clientSocket, &msg, sizeof(msg));
  if (n == -1) {
    throw "Error reading message from socket";
  }
  return msg;
}
void Client::clearMessage() {
  memset(msg, 0, sizeof(msg));
}
