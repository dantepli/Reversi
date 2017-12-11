#include "Server.h"

using namespace std;
#define MAX_CONNECTED_CLIENTS 2
#define MAX_LEN 10
/**
 * C'tor.
 * @param port
 */
Server::Server(int port) : port(port), serverSocket(0) {
  cout << "Server" << endl;
}
/**
 * start the server and handle the clients.
 */
void Server::start() {
  bool keepPlaying = true;
  int firstClient, secondClient;
  this->setUpServer();
  // Define the client socket's structures
  while (true) {
    cout << "Waiting for client connections..." << endl;
    // Accept a new client connection
    firstClient = acceptClient(firstClient);
    if (firstClient == -1) {
      throw "Error accept";
    }
    cout << "Player 1 connected" << endl;
    secondClient = acceptClient(secondClient);
    if (secondClient == -1) {
      throw "Error accept";
    }
    cout << "Player 2 connected" << endl;
    this->setUpClients(firstClient,secondClient);
    while (keepPlaying) {
      keepPlaying = handleClient(firstClient, secondClient);
      if (!(keepPlaying)) {
        keepPlaying = false;
        continue;
      }
      keepPlaying = handleClient(secondClient, firstClient);
      if (!(keepPlaying)) {
        keepPlaying = false;
      }
    }
    // Close communication with the client
    close(firstClient);
    close(secondClient);
    keepPlaying = true;
  }
}

void Server::stop() {
  close(serverSocket);
}
/**
 * handles the clients by sending and receiving their messages.
 * @param currentPlayer the client that send the message.
 * @param coPlayer  the client receiving the message.
 * @return a bool statement that let us know if to keep playing the game.
 */
bool Server::handleClient(int currentPlayer, int coPlayer) {
  int n;
  char msg[MAX_LEN];
  n = static_cast<int>(read(currentPlayer, &msg, sizeof(msg)));
  if (n == -1) {
    cout << "Error reading msg" << endl;
    return false;
  }
  if (n == 0) {
    cout << "Client disconnected" << endl;
    return false;
  }
  n = static_cast<int>(write(coPlayer, &msg, sizeof(msg)));
  if (n == -1) {
    cout << "Error writing to socket" << endl;
    return false;
  }
  return strcmp(reinterpret_cast<const char *>(&msg), "End") != 0;
}
/**
 * Accepting each client that connect to server.
 * @param client 
 * @return 
 */
int Server::acceptClient(int &client) {
  struct sockaddr_in clientAddress = {};
  socklen_t clientAddressLen;
  client = accept(serverSocket,
                  (struct sockaddr *) &clientAddress,
                  &clientAddressLen);
  return client;
}
/**
 * Setting up the server.
 */
void Server::setUpServer() {
// Create a socket point
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    throw "Error opening socket";
  }
  // Assign a local address to the socket
  struct sockaddr_in serverAddress = {};
  bzero((void *) &serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(static_cast<uint16_t>(port));
  if (bind(serverSocket, (struct sockaddr *) &serverAddress,
           sizeof(serverAddress)) == -1) {
    throw "Error on binding";
  }
  // Start listening to incoming connections
  listen(serverSocket, MAX_CONNECTED_CLIENTS);
}
/**
 * Give the clients their numbers(who is first to play).
 * @param firstClient the first player.
 * @param secondClient the second player.
 */
void Server::setUpClients(int firstClient, int secondClient) {
  int n;
  char msg[MAX_LEN] = {'1', '2'};
  n = static_cast<int>(write(firstClient, &msg[0], 1));
  if (n == -1) {
    cout << "Error writing to player" << endl;
  }
  n = static_cast<int>(write(secondClient, &msg[1], 1));
  if (n == -1) {
    cout << "Error writing to player" << endl;
  }
}

