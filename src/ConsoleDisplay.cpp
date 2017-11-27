//
// Dan Teplitski 312895147
//

#include "ConsoleDisplay.h"
void ConsoleDisplay::display(Board &board) const {
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
      cout << *board.getCell(j, i) << Globals::kEmpty << COL_SEP << Globals::kEmpty;
    }
    cout << endl << row << endl;
  }
}
