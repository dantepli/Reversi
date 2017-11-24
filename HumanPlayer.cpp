//
// Dan Teplitski 312895147
//
#include "HumanPlayer.h"
HumanPlayer::HumanPlayer (char color) : color(color) {}
HumanPlayer::~HumanPlayer () {}
Cell HumanPlayer::pickMove (vector<Cell *> &moves) const {
  printMessage(moves);
  int row = 0, col = 0;
  cin >> row >> col;
  if (cin.fail()) {
    // clear the input.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  Cell picked(row - 1, col - 1);
  while (!cellValidity(picked, moves)) {
    cout << "Please enter a valid move." << endl;
    cin >> row >> col;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    picked = Cell(row - 1, col - 1);
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return picked;
}
char HumanPlayer::getColor () const {
  return color;
}
void HumanPlayer::printMessage (vector<Cell *> &moves) const {
  cout << color << ": " << "Your Turn." << endl;
  cout << "Your possible moves are: ";
  for (int i = 0; i < moves.size(); i++) {
    cout << moves[i]->toCoordinate() + " ";
  }
  cout << endl << "Please enter your move. "
       << "Expected input for (x,y) is x y" << endl;
}
bool HumanPlayer::cellValidity (Cell &cell, vector<Cell *> &moves) const {
  for (int i = 0; i < moves.size(); i++) {
    if (cell == *moves[i]) {
      return true;
    }
  }
  return false;
}
