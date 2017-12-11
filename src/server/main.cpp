#include "Server.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

int main() {
  int port;
  string portDelim = "port:";
  string portStr;
  string line;
  ifstream myfile ("../exe/server_config.txt");
  if (myfile.is_open()) {
    myfile >> portStr;
    portStr = portStr.substr(portStr.find(portDelim) + portDelim.size());
    port = atoi(portStr.c_str());
    myfile.close();
  }
  Server server(port);
  try {
    server.start();
  } catch (const char *msg) {
    cout << "Cannot start server. Reason: " << msg << endl;
    exit(-1);
  }
}