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
  cout << "Waiting for client connections..." << endl;
  vector<pthread_t> threads;
  while (true) {
    clientSocket = accept(args->serverSocket,
                          (struct sockaddr *) &clientAddress,
                          &clientAddressLen);
    if (clientSocket == -1) {
      throw "Error on accept";
    }
    struct handleArgs handleArgs;
    handleArgs.clientSocket = clientSocket;
    handleArgs.handler = args->handler;
    pthread_t handleThread;
    pthread_create(&handleThread, NULL, handleClient, (void *) &handleArgs);
    threads.push_back(handleThread);
  }
  for (int i = 0; i < threads.size(); i++) {
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
  this->setUpServer();
  // Define the client socket's structures
  pthread_t acceptThread;
  struct acceptArgs args;
  cout << serverSocket << "SERVER SOCKET" << endl;
  args.serverSocket = serverSocket;
  args.handler = handler;
  pthread_create(&acceptThread, NULL, acceptClients, (void *) &args);
  string exitInput;
  do {
    cin >> exitInput;
  } while(exitInput == "exit");
  if (exitInput == "exit") {
    pthread_cancel(acceptThread);
    pthread_join(acceptThread, NULL);
    stop();
    return;
  }
  pthread_join(acceptThread, NULL);
  pthread_exit(NULL);
}
// stops the server.
void Server::stop() {
  close(serverSocket);
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
