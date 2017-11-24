//
// Dan Teplitski 3128952147
//
#include "Board.h"

Board::Board(int size) : size(size) {
  // board table init
  this->board = new Cell *[size];
  for (int i = 0; i < size; i++) {
    this->board[i] = new Cell[size];
    for (int j = 0; j < size; j++) {
      this->board[i][j] = Cell(i,j);
    }
  }
  // player disks init
  int mid = (size / 2) - 1;
  int roofMid = (size / 2);
  this->board[mid][mid].setDisk(Globals::kWhites);
  this->board[roofMid][roofMid].setDisk(Globals::kWhites);
  this->board[mid][roofMid].setDisk(Globals::kBlacks);
  this->board[roofMid][mid].setDisk(Globals::kBlacks);
}
Board::~Board() {
  for(int i = 0 ; i < size ; i++) {
    // deleting allocated rows.
    delete[] this->board[i];
  }
  // deleting the board.
  delete[] this->board;
}
void Board::clearBoard() {
  for(int i = 0 ; i < size ; i++) {
    for(int j = 0 ; j < size ; j++) {
      this->board[i][j].setDisk(Globals::kEmpty);
    }
  }
}
int Board::getSize() const {
  return size;
}
Cell* Board::getCell(int row, int col) {
  if(row > size || col > size) {
    return NULL;
  }
  return &board[row][col];
}

