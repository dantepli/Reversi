#ifndef REVERSI_CONSOLEMENU_H
#define REVERSI_CONSOLEMENU_H

#include <iostream>
#include <limits>
#include "Menu.h"
using namespace std;
class ConsoleMenu : public Menu {
 public:
  virtual int showMainMenu() const;
 private:
  int getOpponentChoice() const;
};

#endif //REVERSI_CONSOLEMENU_H
