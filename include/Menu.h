#ifndef REVERSI_MENU_H
#define REVERSI_MENU_H
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
   * D'tor.
   */
  virtual ~Menu() {};
};

#endif //REVERSI_MENU_H
