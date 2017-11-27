//
// Dan Teplitski 312895147
//

#include "StdLogic.h"
StdLogic::StdLogic() : kNumOfDirs(8) {
  // int dx[8] = {1,1,0,-1,-1,-1,0,1};
  // int dy[8] = {0,1,1,1,0,-1,-1,-1};
  // initialized below.
  dx = new int[8];
  dy = new int[8];
  dx[0] = dx[1] = dx[7] = 1;
  dx[2] = dx[6] = 0;
  dx[3] = dx[4] = dx[5] = -1;
  dy[0] = dy[4] = 0;
  dy[1] = dy[2] = dy[3] = 1;
  dy[5] = dy[6] = dy[7] = -1;
}
StdLogic::~StdLogic() {
  delete[] dx;
  delete[] dy;
}
vector<Cell *> StdLogic::getPossibleMoves(const Player &player, Board &board) {
  vector<Cell *> moves;
  int size = board.getSize();
  char opponentDisk = opponentCell(player.getColor());
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      Cell *current = board.getCell(i, j);
      if (current->getDisk() == Globals::kEmpty) {
        // a possible cell to place a disk.
        if (isPossibleMove(opponentDisk, *current, board)) {
          moves.push_back(current);
        }
      }
    }
  }
  return moves;
}
void StdLogic::flip(const Player &player, const Cell &cell, Board &board) {
  char opponentDisk = opponentCell(player.getColor());
  vector<Cell *> flips, temp;
  int row = 0, col = 0;
  for (int i = 0; i < kNumOfDirs; i++) {
    // iterate through the possible directions in the 2D plain.
    row = cell.getRow();
    col = cell.getCol();
    row += dx[i];
    col += dy[i];
    if (outOfBounds(row, col, board)) {
      // illegal direction.
      continue;
    }
    Cell *currentCheck = board.getCell(row, col);
    char disk = currentCheck->getDisk();
    if (disk == opponentDisk) {
      // we are not out of bounds, and there is an
      // opponent disk on the cell, continue checking.
      while (disk == opponentDisk) {
        // iterate through the opponents disks.
        temp.push_back(currentCheck);
        row += dx[i];
        col += dy[i];
        if (outOfBounds(row, col, board)) {
          // not between disks.
          break;
        }
        currentCheck = board.getCell(row, col);
        disk = currentCheck->getDisk();
      }
      if (outOfBounds(row, col, board)) {
        // didn't reach a valid place.
        temp.clear();
        continue;
      }
      if (board.getCell(row, col)->getDisk() == opponentCell(opponentDisk)) {
        // reached the original player cell from the opponent, means it's a valid move.
        for (int j = 0; j < temp.size(); j++) {
          flips.push_back(temp[j]);
        }
        temp.clear();
      }
      temp.clear();
    }
  }
  for (int i = 0; i < flips.size(); i++) {
    flips[i]->setDisk(player.getColor());
  }
}
bool StdLogic::isPossibleMove(char opponentDisk, const Cell &cell, Board &board) {
  int row = 0, col = 0;
  for (int i = 0; i < kNumOfDirs; i++) {
    // iterate through the possible directions in the 2D plain.
    row = cell.getRow();
    col = cell.getCol();
    row += dx[i];
    col += dy[i];
    if (outOfBounds(row, col, board)) {
      // illegal direction.
      continue;
    }
    Cell *currentCheck = board.getCell(row, col);
    char disk = currentCheck->getDisk();
    if (disk == opponentDisk) {
      // we are not out of bounds, and there is an
      // opponent disk on the cell, continue checking.
      if (!iterateOpponentDisks(dx[i], dy[i], &row, &col, opponentDisk, board)) {
        continue;
      }
      if (board.getCell(row, col)->getDisk() == opponentCell(opponentDisk)) {
        // reached the original player cell from the opponent, means it's a valid move.
        return true;
      }
    }
  }
  return false;
}
char StdLogic::opponentCell(char playerCell) {
  if (playerCell == Globals::kWhites) {
    return Globals::kBlacks;
  } else {
    return Globals::kWhites;
  }
}
bool StdLogic::outOfBounds(int row, int col, Board &board) {
  return row < 0 || row > (board.getSize() - 1) || col < 0 || col > (board.getSize() - 1);
}
bool StdLogic::iterateOpponentDisks(int dx, int dy, int *row, int *col, char opponentDisk, Board &board) {
  Cell *currentCheck = board.getCell(*row, *col);
  char disk = currentCheck->getDisk();
  while (disk == opponentDisk) {
    // iterate through the opponents disks.
    *row += dx;
    *col += dy;
    if (outOfBounds(*row, *col, board)) {
      // not between disks.
      return false;
    }
    currentCheck = board.getCell(*row, *col);
    disk = currentCheck->getDisk();
  }
  return true;
}
