#ifndef REVERSI_NETWORKPLAYER_H
#define REVERSI_NETWORKPLAYER_H

#include "Player.h"
#include "Client.h"
#include "Display.h"
#include <cstdlib>
#define SEPARATOR ", "
class NetworkPlayer : public Player {
 public:
  /**
   * C'tor.
   * @param display - a display.
   * @param client - a client.
   * @param color - player's color.
   */
  NetworkPlayer(Display *display, Client *client, char color);
  /**
   *
   * @param moves - vector of moves.
   * @return - picked cell from the server.
   */
  virtual Cell pickMove(vector<Cell *> &moves) const;
  virtual char getColor() const;
  /**
   * D'tor. NOTE: DOES NOT DELETE THE DISPLAY AND CLIENT.
   */
  virtual ~NetworkPlayer();
 private:
  Display *display;
  Client *client;
  char color;
};

#endif //REVERSI_NETWORKPLAYER_H
