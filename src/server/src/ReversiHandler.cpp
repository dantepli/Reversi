#include "../include/ReversiHandler.h"

ReversiHandler::~ReversiHandler() {
}
void ReversiHandler::handle(int socket) {
  // ########### THREAD?
  //char *msg = server->readFromSocket(socket);
  char msg[MAX_LEN];
  int n;
  n = static_cast<int>(read(socket, &msg, sizeof(msg)));
  cout << "READ::::::::::::" << msg << endl;
  if (n == -1) {
    throw "Error reading msg\n";
  }
  if (n == 0) {
    throw "Client disconnected\n";
  }
  string command = strtok(msg, COMMAND_DELIM); // command part of message
  cout << command << endl;
  string arg = strtok(NULL, COMMAND_DELIM); // arg part
  cout << arg << endl;
  vector<string> args;
  args.push_back(arg);
  manager->executeCommand(command, args);
}
ReversiHandler::ReversiHandler(CommandsManager *manager) : manager(manager) {}
