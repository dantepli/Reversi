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
  virtual int onlineChoices(Client *client);
 private:
  vector<std::string> commands;
  int getOpponentChoice();
  /**
   * shows the start game option, and gets the user lobby name.
   * @param client - id of the user.
   * @return - the color of the user.
   */
  int startGame(Client *client, string args);
  /**
   * shows the join game option, and gets the user lobby name.
   * @param client - id of the user.
   * @return - the color of id
   */
  int joinGame(Client *client, string args);
  /**
   * prints all the game lobbies that are joinable.
   * @param client - id of the user.
   */
  void listGames(Client *client, string args);
  void funcInit();
};

#endif //REVERSI_CONSOLEMENU_H
