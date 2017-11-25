//
// Dan Teplitski 312895147
//

#include "Cell.h"
Cell::Cell(int row, int col, char disk) : row(row), col(col), disk(disk) {}
Cell::Cell(const Cell &oldCell) {
  row = oldCell.row;
  col = oldCell.col;
  disk = oldCell.disk;
}
int Cell::getRow() const {
  return row;
}
int Cell::getCol() const {
  return col;
}
char Cell::getDisk() const {
  return disk;
}
void Cell::setDisk(char disk) {
  Cell::disk = disk;
}
string Cell::toCoordinate() const {
  ostringstream rowStr, colStr;
  rowStr << row + 1;
  colStr << col + 1;
  return '(' + rowStr.str() + ',' + colStr.str() + ')';
}
bool Cell::operator==(const Cell &other) {
  return row == other.row && col == other.col;
}
ostream &operator<<(ostream &out, const Cell &cell) {
  out << cell.disk;
  return out;
}
Cell &Cell::operator=(const Cell &other) {
  if (this != &other) {
    row = other.row;
    col = other.col;
    disk = other.disk;
  }
  return *this;
}
