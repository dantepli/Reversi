#include "Server.h"

using namespace std;
#define MAX_CONNECTED_CLIENTS 2
#define MAX_LEN 10

Server::Server(int port) : port(port), serverSocket(0) {
  cout << "Server" << endl;
}

void Server::start() {
  bool clientOne = true, clientTwo = true;
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
    char msg[MAX_LEN] = {'1', '2'};
    int n = write(firstClient, &msg[0], 1);
    n = write(secondClient, &msg[1], 1);
    while (keepPlaying) {
      cout << "PLAYER 1" << endl;
      clientOne = handleClient(firstClient, secondClient);
      cout << "PLAYER 2" << endl;
      clientTwo = handleClient(secondClient, firstClient);
      if (!(clientOne) || !(clientTwo)) {
        keepPlaying = false;
        cout << "CLOSED" << endl;
      }
    }
    // Close communication with the client
    close(firstClient);
    close(secondClient);
    clientOne = true, clientTwo = true;
    keepPlaying = true;
  }
}

void Server::stop() {
  close(serverSocket);
}

bool Server::handleClient(int currentPlayer, int coPlayer) {
  char msg[MAX_LEN];
  int n = read(currentPlayer, &msg, sizeof(msg));
  cout << "SERVER READ: " << msg << endl;
  if (n == -1) {
    cout << "Error reading msg" << endl;
    return false;
  }
  if (n == 0) {
    cout << "Client disconnected" << endl;
    return false;
  }
  n = write(coPlayer, &msg, sizeof(msg));
  cout << "SERVER WROTE: " << msg << endl;
  if (n == -1) {
    cout << "Error writing to socket" << endl;
    return false;
  }
  if (!strcmp(reinterpret_cast<const char *>(&msg), "End")) {
    cout << "END MESSAGE" << endl;
    return false;
  }
  return true;
}

int Server::acceptClient(int &client) {
  struct sockaddr_in clientAddress;
  socklen_t clientAddressLen;
  client = accept(serverSocket,
                  (struct sockaddr *) &clientAddress,
                  &clientAddressLen);
  return client;
}

void Server::setUpServer() {
// Create a socket point
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    throw "Error opening socket";
  }
  // Assign a local address to the socket
  struct sockaddr_in serverAddress;
  bzero((void *) &serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(port);
  if (bind(serverSocket, (struct sockaddr *) &serverAddress,
           sizeof(serverAddress)) == -1) {
    throw "Error on binding";
  }
  // Start listening to incoming connections
  listen(serverSocket, MAX_CONNECTED_CLIENTS);
}

