#include "ConsoleMenu.h"
int ConsoleMenu::showMainMenu() const {
  int input = getOpponentChoice();
}
int ConsoleMenu::getOpponentChoice() const {
  int input;
  cout << "Please choose your opponent: " << endl;
  cout << "1. Press 1 to play against a Local Human Player." << endl;
  cout << "2. Press 2 to play against an AI Player." << endl;
  cin >> input;
  while (input != 1 && input != 2) {
    if (cin.fail()) {
      // clear the input.
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Please enter a valid option." << endl;
    cout << "Please choose your opponent: " << endl;
    cout << "1. Press 1 to play against a Local Human Player." << endl;
    cout << "2. Press 2 to play against an AI Player." << endl;
    cin >> input;
  }
  return input;
}
