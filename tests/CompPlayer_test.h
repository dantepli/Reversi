//

#ifndef REVERSI_COMPPLAYER_TEST_H
#define REVERSI_COMPPLAYER_TEST_H

#include <gtest/gtest.h>
#include "../src/Display.h"
#include "../src/Logic.h"
#include "../src/ConsoleDisplay.h"
#include "../src/CompPlayer.h"
#include "../src/StdLogic.h"
struct CompPlayer_test {
  Player* CompWhitePlayer;
  Logic* logic;
  Display* display;
  Board* board;
  Board bo;
  CompPlayer_test() {
    board = &bo;
    display = new ConsoleDisplay();
    CompWhitePlayer = new CompPlayer(display, board , logic, Globals::kWhites);
    logic = new StdLogic();
  }
};

#endif //REVERSI_COMPPLAYER_TEST_H
