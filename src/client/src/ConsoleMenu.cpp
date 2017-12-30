#include "../include/ConsoleMenu.h"

int ConsoleMenu::showMainMenu() const {
  return getOpponentChoice();
}
int ConsoleMenu::getOpponentChoice() const {
  int input;
  cout << "Please choose your opponent: " << endl;
  cout << "1. Press 1 to play against a Local Human Player." << endl;
  cout << "2. Press 2 to play against an AI Player." << endl;
  cout << "3. Press 3 to play against a Remote Player." << endl;
  cin >> input;
  while (input != 1 && input != 2 && input != 3) {
    if (cin.fail()) {
      // clear the input.
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Please enter a valid option." << endl;
    cout << "Please choose your opponent: " << endl;
    cout << "1. Press 1 to play against a Local Human Player." << endl;
    cout << "2. Press 2 to play against an AI Player." << endl;
    cout << "3. Press 3 to play against a Remote Player." << endl;
    cin >> input;
  }
  return input;
}

int ConsoleMenu::onlineChoices(Client *client) const {
  int input;
  do {
    client->connectToServer();
    cout << "Please choose one of the options: " << endl;
    cout << "1. Start a new game lobby." << endl;
    cout << "2. Join an existing game lobby." << endl;
    cout << "3. A list of game lobbies." << endl;
    cin >> input;
    switch (input) {
      case 1: {
        int color = startGame(client);
        if (color != FAILED) {
          cout << "Waiting for other player to join..." << endl;
          return color;
        }
        break;
      }
      case 2: {
        int color = joinGame(client);
        if (color != FAILED) {
          return color;
        }
        break;
      }
      case 3: {
        listGames(client);
        break;
      }
      default:cout << "Invalid choice." << endl;
        break;
    }
  } while (input != FAILED);
}

int ConsoleMenu::startGame(Client *client) const {
  string sInput;
  string dummy;
  char *serverResponse;
  cout << "Please enter a new lobby name" << endl;
  cin >> sInput;
  do {
    string startCommand = "start ";
    startCommand.append(sInput);
    client->sendMsg(startCommand.c_str());
    serverResponse = client->receiveMsg();
    cout << "SERVER WROTE " << serverResponse << endl;
    if (strcmp(serverResponse, "-1") == 0) {
      cout << "This game lobby is already registered" << endl;
      cout << "Please enter a new lobby name (return to the last menu with 'back')" << endl;
      cin >> sInput;
      if (strcmp(sInput.c_str(), "back") == 0) {
        return FAILED;
      }
      client->connectToServer();
    }
  } while (strcmp(serverResponse, "1") != 0);
  return BLACK_COLOR;
}

int ConsoleMenu::joinGame(Client *client) const {
  string sInput;
  char *serverResponse;
  cout << "Please enter a lobby name" << endl;
  cin >> sInput;
  string joinCommand = "join ";
  joinCommand.append(sInput);
  client->sendMsg(joinCommand.c_str());
  serverResponse = client->receiveMsg();
  cout << serverResponse << endl;
  if (strcmp(serverResponse, "-1") == 0) {
    cout << "Failed to join game lobby" << endl;
    return FAILED;
  }
  return WHITE_COLOR;
}

void ConsoleMenu::listGames(Client *client) const {
  char *serverResponse;
  string listGames = "list_games";
  client->sendMsg(listGames.c_str());
  cout << "Game rooms: " << endl;
  serverResponse = client->receiveMsg();
  cout << serverResponse << endl;
}
