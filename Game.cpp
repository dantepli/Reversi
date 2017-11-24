//
// Dan Teplitski 312895147
//

#include "Game.h"
Game::Game () : board(Globals::kSize), blackMoves(true), whiteMoves(true) {
  logic = new StdLogic(&board);
  white = new HumanPlayer(Globals::kWhites);
  black = new HumanPlayer(Globals::kBlacks);
  display = new ConsoleDisplay();
}
Game::~Game () {
  delete logic;
  delete white;
  delete black;
  delete display;
}
void Game::playTurn (const Player &player) {
  display->display(board);
  vector<Cell *> moves = logic->getPossibleMoves(player);
  if (moves.size() == 0) {
    updateMoves(player, false);
    cout << player.getColor() << ": You have no available moves, "
                                 "turn is passed to the other player." << endl;
    return;
  } else {
    updateMoves(player, true);
  }
  Cell cell = player.pickMove(moves);
  int row = cell.getRow();
  int col = cell.getCol();
  Cell *changedCell = board.getCell(row, col);
  changedCell->setDisk(player.getColor());
  logic->flip(player, *changedCell);
}
void Game::play () {
  while (blackMoves || whiteMoves) {
    playTurn(*black);
    playTurn(*white);
  }
  determineHighScore(*white, *black);
}
void Game::determineHighScore (const Player &player1, const Player &player2) {
  char player1Disk = player1.getColor();
  char player2Disk = player2.getColor();
  int player1Score = 0, player2Score = 0;
  int bSize = board.getSize();
  for (int i = 0; i < bSize; i++) {
    for (int j = 0; j < bSize; j++) {
      Cell *current = board.getCell(i, j);
      char disk = current->getDisk();
      if (disk == player1Disk) {
        player1Score++;
      } else if (disk == player2Disk) {
        player2Score++;
      }
    }
  }
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
void Game::updateMoves (const Player &player, bool hasMoves) {
  char disk = player.getColor();
  if (disk == Globals::kWhites) {
    whiteMoves = hasMoves;
  } else if (disk == Globals::kBlacks) {
    blackMoves = hasMoves;
  }
}
