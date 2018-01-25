#ifndef REVERSI_CONSOLEMENU_H
#define REVERSI_CONSOLEMENU_H

#include <iostream>
#include <limits>
#include <map>
#include "Menu.h"
#include "Client.h"
#include "../include/ConsoleDisplay.h"
#define BLACK_COLOR 1
#define WHITE_COLOR 2
#define FAILED (-1)

using namespace std;
class ConsoleMenu : public Menu {
 public:
  virtual int showMainMenu();
  virtual bool onlineChoices(Client *client);
 private:
  bool check,
      game; // helps us check if there was error in connection with the server and keeping the online lobby.
  int getOpponentChoice();
  /**
   * shows the start game option, and gets the user lobby name.
   * @param client - id of the user.
   * @param args - input from the user.
   * @return - true if the server started a new lobby and false if we failed writing or reading to the server.
   */
  bool startGame(Client *client, string args);
  /**
   * shows the join game option, and gets the user lobby name.
   * @param client - id of the user.
   * @param args - input from the user.
   * @return - true if the server started a new lobby and false if we failed writing or reading to the server.
   */
  bool joinGame(Client *client, string args);
  /**
   * prints all the game lobbies that are joinable.
   * @param args - input from the user.
   * @param client - id of the user.
   */
  void listGames(Client *client, string args);
};

#endif //REVERSI_CONSOLEMENU_H
