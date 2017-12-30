#include "../include/Server.h"

struct handleArgs {
  int clientSocket;
  ReversiHandler *handler;
};

struct acceptArgs {
  int serverSocket;
  ReversiHandler *handler;
};

void *handleClient(void *handleArgs) {
  struct handleArgs *args = (struct handleArgs *) handleArgs;
  try {
    args->handler->handle(args->clientSocket);
  } catch (const char *msg) {
    cerr << msg << endl;
  }
}

void *acceptClients(void *acceptArgs) {
  struct acceptArgs *args = (struct acceptArgs *) acceptArgs;
  struct sockaddr_in clientAddress = {};
  socklen_t clientAddressLen;
  int clientSocket;
  vector<pthread_t> threads;
  cout << args->serverSocket << endl;
  while (true) {
    cout << "Waiting for client connections..." << endl;
    clientSocket = accept(args->serverSocket,
                          (struct sockaddr *) &clientAddress,
                          &clientAddressLen);
    if (clientSocket == -1) {
      throw "Error on accept";
    }
    struct handleArgs handleArgs;
    handleArgs.clientSocket = clientSocket;
    handleArgs.handler = args->handler;
    cout << "CLIENT SOCKET " << clientSocket << endl;
    pthread_t handleThread;
    int rc =
        pthread_create(&handleThread, NULL, handleClient, (void *) &handleArgs);
    threads.push_back(handleThread);
  }
  for (int i = 0; i < threads.size(); i++) {
    cout << "WAITING ON THREADS" << endl;
    pthread_join(threads[i], NULL);
  }
}

// constructor.
Server::Server(ReversiHandler *handler, int port)
    : handler(handler), port(port), serverSocket(0) {
  cout << "Server" << endl;
}
// starts the server.
void Server::start() {
  bool keepPlaying = true;
  int firstClient, secondClient;
  this->setUpServer();
  // Define the client socket's structures
  pthread_t acceptThread;
  struct acceptArgs args;
  cout << serverSocket << "SERVER SOCKET" << endl;
  args.serverSocket = serverSocket;
  args.handler = handler;
  int rc = pthread_create(&acceptThread, NULL, acceptClients, (void *) &args);
  pthread_join(acceptThread, NULL);
  pthread_exit(NULL);
//  while (true) {
//    cout << "Waiting for client connections..." << endl;
//    // Accept a new client connection
//    /*
//     * GameManager || THIS IS THE FLOW OF THE GAME AFTER JOIN
//     * ######################################################
//     */
//    firstClient = acceptClient();
//    if (firstClient == -1) {
//      throw "Error accept";
//    }
//    cout << "Player 1 connected" << endl;
//    secondClient = acceptClient();
//    if (secondClient == -1) {
//      throw "Error accept";
//    }
//    cout << "Player 2 connected" << endl;
//    this->setUpClients(firstClient, secondClient);
//    while (keepPlaying) {
//      keepPlaying = handleClient(firstClient, secondClient);
//      if (!(keepPlaying)) {
//        keepPlaying = false;
//        continue;
//      }
//      keepPlaying = handleClient(secondClient, firstClient);
//      if (!(keepPlaying)) {
//        keepPlaying = false;
//      }
//    }
//    /*
//     * ######################################################
//     */
//    // Close communication with the client
//    close(firstClient);
//    close(secondClient);
//    keepPlaying = true;
}
// stops the server.
void Server::stop() {
  close(serverSocket);
}

//bool Server::handleClient(int currentPlayer, int coPlayer) {
//  int n;
//  char msg[MAX_LEN];
//  n = static_cast<int>(read(currentPlayer, &msg, sizeof(msg)));
//  if (n == -1) {
//    cout << "Error reading msg" << endl;
//    return false;
//  }
//  if (n == 0) {
//    cout << "Client disconnected" << endl;
//    return false;
//  }
//  n = static_cast<int>(write(coPlayer, &msg, sizeof(msg)));
//  if (n == -1) {
//    cout << "Error writing to socket" << endl;
//    return false;
//  }
//  return strcmp(reinterpret_cast<const char *>(&msg), "End") != 0;
//}
// accept each connections of the client.
int Server::acceptClient() {
  struct sockaddr_in clientAddress = {};
  socklen_t clientAddressLen;
  int client = accept(serverSocket,
                      (struct sockaddr *) &clientAddress,
                      &clientAddressLen);
  return client;
}
// setting up the server.
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
// give each client is number.
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

void Server::writeToSocket(const char *message, int socket) {
  int n = static_cast<int>(write(socket, &message, strlen(message)));
  if (n == -1) {
    cout << "Error writing to socket" << endl;
    throw "Error writing to socket";
  }
}
char *Server::readFromSocket(int socket) {
  int n = static_cast<int>(read(socket, &msg, sizeof(msg)));
  if (n == -1) {
    cout << "Error reading msg" << endl;
    return NULL;
  }
  if (n == 0) {
    cout << "Client disconnected" << endl;
    return NULL;
  }
  return msg;
}

