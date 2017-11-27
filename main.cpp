// Dan Teplitski 312895147
// Or Lion 204025175

#include "src/Game.h"
#include "src/CompPlayer.h"
int main() {
//  Game g;
//  g.play();
  Board *board = new Board(Globals::kSize);
  Logic *logic = new StdLogic();
  Player *black = new HumanPlayer(Globals::kBlacks);
  Player *white = new CompPlayer(board, logic, Globals::kWhites);
  Game g(board, logic, white, black);
  g.play();
}
