#ifndef REVERSI_MENU_H
#define REVERSI_MENU_H
#include "Client.h"
/**
 * pure abstract class (interface).
 */
class Menu {
 public:
  /**
   * shows the main menu, and gets the user's choice.
   * @return - the user's choice.
   */
  virtual int showMainMenu() const = 0;
  /**
   * shows the online choices to the player and gets the user's choice. 
   * @param client - id of the user.
   * @return - the color of the user in the game.
   */
  virtual int onlineChoices(Client *client) const = 0;
  /**
   * D'tor.
   */
  virtual ~Menu() {};
};

#endif //REVERSI_MENU_H
