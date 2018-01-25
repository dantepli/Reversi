#include "include/Server.h"
using namespace std;
#include <fstream>
#define THREAD_NUM 5
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
  CommandsManager *manager = new CommandsManager();
  ReversiHandler *handler = new ReversiHandler(manager);
  ThreadPool *pool = new ThreadPool(THREAD_NUM);
  Server server(handler, pool, port);
  try {
    server.start();
  } catch (const char *msg) {
    cout << "Cannot start server. Reason: " << msg << endl;
  }
  delete manager;
  delete handler;
  delete pool;
  GameLobbies::deleteInstance();
}
