#include "include/Game.h"
#include "include/CompPlayer.h"
#include "include/ConsoleMenu.h"
#include "include/Client.h"
#include "include/NetworkPlayer.h"
#include "include/LocalPlayer.h"
#include "include/NetworkParser.h"
void startNetworkGame();
int main() {
  Menu *menu = new ConsoleMenu();
  int input = menu->showMainMenu();
  switch (input) {
    case 1: {
      Game g;
      g.play();
      break;
    }
    case 2: {
      Display *display = new ConsoleDisplay();
      Board *board = new Board(Globals::kSize);
      Logic *logic = new StdLogic();
      Player *black = new HumanPlayer(display, Globals::kBlacks);
      Player *white = new CompPlayer(display, board, logic, Globals::kWhites);
      Game g(display, board, logic, white, black);
      g.play();
      break;
    }
    case 3:startNetworkGame();
      break;
    default:break;

  }
  delete menu;
  return 0;
}

void startNetworkGame() {
  Display *display = new ConsoleDisplay();
  Board *board = new Board(Globals::kSize);
  Logic *logic = new StdLogic();
  NetworkParser parser("net_config.txt"); // CLION RUN
  //NetworkParser parser("../exe/net_config.txt"); // CMD RUN
  Client *client = new Client(parser.getIP().c_str(), parser.getPort());
  try {
    client->connectToServer();
  } catch (const char *error) {
    cerr << "Error Occurred: " << error << endl;
    delete display;
    delete board;
    delete logic;
    delete client;
    exit(1);
  }
  display->displayWaitingForPlayer();
  char *initialColor = client->receiveMsg();
  if (strcmp(initialColor, "1") == 0) {
    // local player color is black.
    Player *human = new HumanPlayer(display, Globals::kBlacks);
    Player *local = new LocalPlayer(human, client);
    Player *network = new NetworkPlayer(display, client, Globals::kWhites);
    Game g(display, board, logic, network, local);
    g.play();
  } else {
    // local player color is white.
    Player *human = new HumanPlayer(display, Globals::kWhites);
    Player *local = new LocalPlayer(human, client);
    Player *network = new NetworkPlayer(display, client, Globals::kBlacks);
    Game g(display, board, logic, local, network);
    g.play();
  }
  delete client;
}
