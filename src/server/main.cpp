#include "include/Server.h"
#include "include/GameLobbies.h"
#include <stdlib.h>
using namespace std;
#include <fstream>

int main() {
  int port;
  string portDelim = "port:";
  string portStr;
  string line;
  //ifstream myfile("../exe/server_config.txt"); // CLION RUN
  ifstream myfile("server_config.txt"); // CMD RUN
  if (myfile.is_open()) {
    myfile >> portStr;
    portStr = portStr.substr(portStr.find(portDelim) + portDelim.size());
    port = atoi(portStr.c_str());
    myfile.close();
  }
  cout << "PORT: " << port << endl;
  CommandsManager *manager = new CommandsManager();
  ReversiHandler *handler = new ReversiHandler(manager);
  Server server(handler, port);
  try {
    server.start();
  } catch (const char *msg) {
    cout << "Cannot start server. Reason: " << msg << endl;
    exit(-1);
  }
  delete manager;
  delete handler;
  GameLobbies *lobby = GameLobbies::getInstance();
  delete lobby;
}
