#include "../include/Game.h"
Game::Game() : blackMoves(true), whiteMoves(true) {
  board = new Board(Globals::kSize);
  logic = new StdLogic();
  display = new ConsoleDisplay();
  white = new HumanPlayer(display, Globals::kWhites);
  black = new HumanPlayer(display, Globals::kBlacks);
}
Game::Game(Display *display,
           Board *board,
           Logic *logic,
           Player *white,
           Player *black)
    : display(display),
      board(board),
      logic(logic),
      white(white),
      black(black),
      blackMoves(true),
      whiteMoves(true) {};
Game::~Game() {
  delete board;
  delete logic;
  delete white;
  delete black;
  delete display;
}
void Game::playTurn(const Player &player) {
  display->displayBoard(*board);
  vector<Cell *> moves = logic->getPossibleMoves(player, *board);
  if (moves.size() == 0) {
    updateMoves(player, false);
    display->displayNoMoves(player);
    return;
  } else {
    updateMoves(player, true);
  }
  Cell cell = player.pickMove(moves);
  int row = cell.getRow();
  int col = cell.getCol();
  Cell *changedCell = board->getCell(row, col);
  changedCell->setDisk(player.getColor());
  logic->flip(player, *changedCell, *board);
}
void Game::play() {
  while (blackMoves || whiteMoves) {
    playTurn(*black);
    playTurn(*white);
  }
  determineHighScore(*white, *black);
}
void Game::determineHighScore(const Player &player1, const Player &player2) {
  char player1Disk = player1.getColor();
  char player2Disk = player2.getColor();
  int player1Score = 0, player2Score = 0;
  int bSize = board->getSize();
  for (int i = 0; i < bSize; i++) {
    for (int j = 0; j < bSize; j++) {
      Cell *current = board->getCell(i, j);
      char disk = current->getDisk();
      if (disk == player1Disk) {
        player1Score++;
      } else if (disk == player2Disk) {
        player2Score++;
      }
    }
  }
  display->displayEndScreen(*white, *black, *board, player1Score, player2Score);
}
void Game::updateMoves(const Player &player, bool hasMoves) {
  char disk = player.getColor();
  if (disk == Globals::kWhites) {
    whiteMoves = hasMoves;
  } else if (disk == Globals::kBlacks) {
    blackMoves = hasMoves;
  }
}
