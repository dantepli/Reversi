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
  vector<string> args;
  istringstream iss(msg);
  string command;
  string arg;
  iss >> command; // command part
  iss >> ws; // ignore whitespaces until arg
  while (iss) {
    getline(iss, arg);
  }
  if (arg.size() > 0) {
    args.push_back(arg);
  }
  // parse socket to arguments
  ostringstream ss;
  ss << socket;
  args.push_back(ss.str());
  for (int i = 0; i < args.size(); i++) {
    cout << args[i] << " ARGUMENTS OF COMMAND" << endl;
  }
  manager->executeCommand(command, args);
}
ReversiHandler::ReversiHandler(CommandsManager *manager) : manager(manager) {}
