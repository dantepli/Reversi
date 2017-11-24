//
// Dan Teplitski 312895147
//

#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include "Display.h"
class ConsoleDisplay: public Display {
 public:
  virtual void display(Board &board) const;
};

#endif //CONSOLEDISPLAY_H
