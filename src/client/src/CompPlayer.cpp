#include "../include/CompPlayer.h"
#include "../include/HumanPlayer.h"
CompPlayer::CompPlayer(Display *display, Board *board, Logic *logic, char color)
    : display(display), board(board), logic(logic), color(color) {}
Cell CompPlayer::pickMove(vector<Cell *> &moves) const {
  if (moves.size() == 0) {
    return Cell();
  }
  int minScore = INT_MAX;
  Cell picked;
  for (int i = 0; i < moves.size(); i++) {
    // simulate a move.
    int currScore = simMove(*moves[i]);
    if (minScore > currScore) {
      // update min score of opponent.
      minScore = currScore;
      picked = *moves[i];
    }
  }
  display->displayAIChoice(*this, picked);
  return picked;
}
char CompPlayer::getColor() const {
  return color;
}
int CompPlayer::simMove(Cell &cell) const {
  int maxScore = INT_MIN;
  int row = cell.getRow();
  int col = cell.getCol();
  HumanPlayer opponent(display, opponentColor());
  Board sim(*board); // copy c'tor.
  logic->flip(*this, *sim.getCell(row, col), sim); // flip on the copied board.
  vector<Cell *> opponentMoves = logic->getPossibleMoves(opponent, sim);
  for (int i = 0; i < opponentMoves.size(); i++) {
    // simulate opponents' move.
    int currScore = simOpponent(sim, *opponentMoves[i], opponent);
    if (maxScore <= currScore) {
      // update max score of the opponent.
      maxScore = currScore;
    }
  }
  return maxScore;
}
int CompPlayer::simOpponent(Board &b, Cell &move, Player &opponent) const {
  Board simOpponent(b);
  logic->flip(opponent,
              *simOpponent.getCell(move.getRow(), move.getCol()),
              simOpponent);
  return detScore(simOpponent);
}
char CompPlayer::opponentColor() const {
  if (color == Globals::kBlacks) {
    return Globals::kWhites;
  } else {
    return Globals::kBlacks;
  }
}
int CompPlayer::detScore(Board &b) const {
  char opponentDisk = opponentColor();
  int myScore = 0, opponentScore = 0;
  int bSize = b.getSize();
  for (int i = 0; i < bSize; i++) {
    for (int j = 0; j < bSize; j++) {
      Cell *current = b.getCell(i, j);
      char disk = current->getDisk();
      if (disk == color) {
        myScore++;
      } else if (disk == opponentDisk) {
        opponentScore++;
      }
    }
  }
  return opponentScore - myScore;
}
void CompPlayer::endGame() const {

}
