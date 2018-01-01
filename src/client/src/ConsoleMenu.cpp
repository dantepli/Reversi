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

int ConsoleMenu::onlineChoices(Client *client) {
    funcInit();
    string input;
    string args;
    int j, color;
    char *command, *arg;
    cin.ignore();
    client->connectToServer();
    do {
      args = "";
      j = 0;
      cout << "Please choose one of the options: " << endl;
      cout << "1. Start a new game lobby. (start 'lobby name')" << endl;
      cout << "2. Join an existing game lobby. (join 'lobby name')" << endl;
      cout << "3. A list of game lobbies.  (list_games)" << endl;
      getline(cin, input);
      char *cstr = new char[input.length()];
      strcpy(cstr, input.c_str());
      command = strtok(cstr, " ");
      if(cstr[strlen(command) - 1] == '\0') {
        arg = strtok(NULL, "\n");
        args.append(arg);
      }
      int i = 0;
      for (i = 0; i < commands.size(); i++) {
        if (strcmp(command, commands.at(i).c_str()) == 0) {
          if (strcmp(command, "start") == 0) {
            color = startGame(client, input);
            if(color != FAILED) {
              return color;
            }
            client->connectToServer();
            j++;
          } else if (strcmp(command, "join") == 0) {
            color = joinGame(client, input);
            if(color == FAILED) {
              cout << "Wrong lobby name" << endl;
              client->connectToServer();
              j++;
            } else return color;
          } else if (strcmp(command, "list_games") == 0) {
            j++;
            listGames(client, input);
            client->connectToServer();
          }
        }
      }
      if (j == 0) {
        cout << "Unknown command please enter a new one." << endl;
      }
    }while(j != -1);
}

int ConsoleMenu::startGame(Client *client,string args) {
  string dummy;
  char *serverResponse = NULL;
  do {
    try {
      client->sendMsg(args.c_str());
    } catch (const char *msg) {
      cerr << msg << endl;
    }
    try {
      serverResponse = client->receiveMsg();
    } catch (const char *msg) {
      cerr << msg << endl;
    }
    cout << "SERVER WROTE " << serverResponse << endl;
    if (strcmp(serverResponse, "-1") == 0) {
      cout << "This game lobby is already registered" << endl;
      return FAILED;
    }
  } while (strcmp(serverResponse, "1") != 0);
  return BLACK_COLOR;
}

int ConsoleMenu::joinGame(Client *client, string args) {
  char *serverResponse = NULL;
  try {
    client->sendMsg(args.c_str());
  } catch (const char *msg) {
    cerr << msg << endl;
  }
  try {
    serverResponse = client->receiveMsg();
  } catch (const char *msg) {
    cerr << msg << endl;
  }
  cout << serverResponse << endl;
  if (strcmp(serverResponse, "-") == 0) {
    return FAILED;
  }
  return WHITE_COLOR;
}

void ConsoleMenu::listGames(Client *client, string args)  {
  char *serverResponse = NULL;
  try {
    client->sendMsg(args.c_str());
  } catch (const char *msg) {
    cerr << msg << endl;
  }
  cout << "Game rooms: " << endl;
  try {
    serverResponse = client->receiveMsg();
  } catch (const char *msg) {
    cerr << msg << endl;
  }
  cout << serverResponse << endl;
}
void ConsoleMenu::funcInit()  {
    commands.push_back("start");
    commands.push_back("join");
    commands.push_back("list_games");
}

