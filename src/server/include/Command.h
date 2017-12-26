#ifndef REVERSI_COMMAND_H
#define REVERSI_COMMAND_H
#include <vector>
#include <string>
using namespace std;
// Command interface
class Command {
 public:
  virtual void execute(vector<string> args) = 0;
  virtual ~Command() {}

};

#endif //REVERSI_COMMAND_H
