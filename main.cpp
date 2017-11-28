#include "src/Game.h"
#include "src/CompPlayer.h"
#include "src/ConsoleMenu.h"
int main() {
  Menu *menu = new ConsoleMenu();
  int input = menu->showMainMenu();
  if (input == 1) {
    Game g;
    g.play();
  } else if (input == 2) {
    Display *display = new ConsoleDisplay();
    Board *board = new Board(Globals::kSize);
    Logic *logic = new StdLogic();
    Player *black = new HumanPlayer(display, Globals::kBlacks);
    Player *white = new CompPlayer(display, board, logic, Globals::kWhites);
    Game g(display, board, logic, white, black);
    g.play();
  }
  delete menu;
  return 0;
}
