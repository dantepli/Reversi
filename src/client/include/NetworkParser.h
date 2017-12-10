#ifndef REVERSI_NETWORKPARSER_H
#define REVERSI_NETWORKPARSER_H
#include <string>
using namespace std;
class NetworkParser {
 public:
  NetworkParser(const string &fileName = "net_config.txt");
  string getIP();
  int getPort();
 private:
  string fileName;
};

#endif //REVERSI_NETWORKPARSER_H
