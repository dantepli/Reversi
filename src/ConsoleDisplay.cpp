#include "ConsoleDisplay.h"
void ConsoleDisplay::displayBoard(Board &board) const {
  cout << endl;
  string row;
  int size = board.getSize();
  row.append((size * 4) + 2, ROW_SEP);
  cout << Globals::kEmpty << COL_SEP << Globals::kEmpty;
  for (int x = 1; x <= size; x++) {
    // prints the column number indicator.
    cout << x << Globals::kEmpty << COL_SEP << Globals::kEmpty;
  }
  cout << endl << row << endl;
  for (int j = 0; j < size; j++) {
    for (int i = -1; i < size; i++) {
      if (i == -1) {
        // prints the row number indicator.
        cout << j + 1 << COL_SEP << Globals::kEmpty;
        continue;
      }
      cout << *board.getCell(j, i) << Globals::kEmpty << COL_SEP
           << Globals::kEmpty;
    }
    cout << endl << row << endl;
  }
}
void ConsoleDisplay::displayHumanPlayerChoiceMessage(const Player &player,
                                                     const vector<Cell *> &moves) const {
  cout << player.getColor() << ": " << "Your Turn." << endl;
  cout << "Your possible moves are: ";
  for (int i = 0; i < moves.size(); i++) {
    cout << moves[i]->toCoordinate() + " ";
  }
  cout << endl << "Please enter your move. "
       << "Expected input for (x,y) is x y" << endl;
}
void ConsoleDisplay::displayNoMoves(const Player &player) const {
  cout << player.getColor() << ": You have no available moves, "
      "turn is passed to the other player." << endl;
}
void ConsoleDisplay::displayEndScreen(const Player &player1,
                                      const Player &player2,
                                      const Board &board,
                                      int player1Score,
                                      int player2Score) const {
  if (player1Score + player2Score == board.getSize() * board.getSize()) {
    // board is full.
    cout << "No more possible moves." << endl;
  }
  if (player1Score > player2Score) {
    cout << player1.getColor() << ": " << "You Won!" << endl;
  } else {
    cout << player2.getColor() << ": " << "You Won!" << endl;
  }
}
void ConsoleDisplay::displayAIChoice(const Player &player,
                                     const Cell &cell) const {
  cout << endl;
  cout << player.getColor() << " picked: " << cell.toCoordinate() << endl;
}

