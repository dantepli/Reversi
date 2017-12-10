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
  /**
   * parses the given file to ip and port values. file has to be in proper
   * format.
   */
  void parseFile();
  string fileName;
  string ip;
  int port;
};

#endif //REVERSI_NETWORKPARSER_H
