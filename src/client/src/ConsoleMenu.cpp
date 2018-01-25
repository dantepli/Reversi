#include "../include/ConsoleMenu.h"

int ConsoleMenu::showMainMenu() {
  return getOpponentChoice();
}
int ConsoleMenu::getOpponentChoice() {
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

bool ConsoleMenu::onlineChoices(Client *client) {
  game = true;
  string input;
  string args;
  cin.ignore();
  do {
    try {
      client->connectToServer();
    } catch (const char *error) {
      cerr << error << endl;
      return false;
    }
    cout << "Please choose one of the options: " << endl;
    cout << "start 'lobby name' --- (Start a new game lobby)" << endl;
    cout << "join  'lobby name' --- (Join an existing game lobby)" << endl;
    cout << "list_games         --- (A list of game lobbies)" << endl;
    // getting a input from the user and divide it to command
    getline(cin, input);
    istringstream iss(input);
    string command;
    string arg;
    iss >> command; // command part
    iss >> arg;
    if (command == "start") {
      if (arg == "") {
        continue;
      }
      check = startGame(client, input);
      if (!(game)) {
        return false; // if we can't write or read from the server we exit from the game.
      }
      if (check) {
        return check;
      }
      continue;
    } else if (command == "join") {
      if (arg == "") {
        continue;
      }
      check = joinGame(client, input);
      if (!(game)) {
        return false; // if we can't write or read from the server we exit from the game.
      }
      if (!check) {
        cout << "Wrong lobby name" << endl;
        continue;
      } else return check;
    } else if (command == "list_games") {
      listGames(client, input);
      continue;
    }
    cout << "Unknown command please enter a new one." << endl;
  } while (game);
}

bool ConsoleMenu::startGame(Client *client, string args) {
  string dummy;
  char *serverResponse = NULL;
  do {
    try {
      client->sendMsg(args.c_str());
    } catch (const char *msg) {
      cerr << msg << endl;
      game = false;
      return game;
    }
    try {
      serverResponse = client->receiveMsg();
    } catch (const char *msg) {
      cerr << msg << endl;
      game = false;
      return game;
    }
    if (strcmp(serverResponse, "-1") == 0) {
      cout << "This game lobby is already registered" << endl;
      return false;
    }
  } while (strcmp(serverResponse, "1") != 0);
  return true;
}

bool ConsoleMenu::joinGame(Client *client, string args) {
  char *serverResponse = NULL;
  try {
    client->sendMsg(args.c_str());
  } catch (const char *msg) {
    cerr << msg << endl;
    game = false;
    return game;
  }
  try {
    serverResponse = client->receiveMsg();
  } catch (const char *msg) {
    cerr << msg << endl;
    game = false;
    return game;
  }
  client->sendMsg(serverResponse);
  return strcmp(serverResponse, "-1") != 0;
}

void ConsoleMenu::listGames(Client *client, string args) {
  char *serverResponse = NULL;
  try {
    client->sendMsg(args.c_str());
  } catch (const char *msg) {
    cerr << msg << endl;
    game = false;
    return;
  }
  try {
    serverResponse = client->receiveMsg();
  } catch (const char *msg) {
    cerr << msg << endl;
    game = false;
    return;
  }
  cout << "Game rooms: " << endl;
  cout << serverResponse << endl;
}

