#include <fstream>
#include <iostream>
#include <cstdlib>
#include "../include/NetworkParser.h"
NetworkParser::NetworkParser(const string &fileName) : fileName(fileName) {
  parseFile();
}
string NetworkParser::getIP() {
  return ip;
}
int NetworkParser::getPort() {
  return port;
}
void NetworkParser::parseFile() {
  string ipDelim = "ip:";
  string portDelim = "port:";
  ifstream inFile;
  inFile.open(fileName.c_str());
  if (!inFile.is_open()) {
    cerr << "Error Opening File." << endl;
    return;
  }
  inFile >> ip;
  ip = ip.substr(ip.find(ipDelim) + ipDelim.size());
  string portStr;
  inFile >> portStr;
  portStr = portStr.substr(portStr.find(portDelim) + portDelim.size());
  port = atoi(portStr.c_str());
  inFile.close();
}
