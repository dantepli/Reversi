#ifndef REVERSI_LOCALPLAYER_H
#define REVERSI_LOCALPLAYER_H

#include "Player.h"
#include "Client.h"
#define SEPARATOR ", "
class LocalPlayer: public Player {
 public:
  /**
   * C'tor. Supports player-serverClient integration.
   * @param player - a player.
   * @param client - a client.
   */
  LocalPlayer(Player *player, Client *client);
  /**
   * D'tor. NOTE: DOES NOT DELETE THE CLIENT.
   * DELETES THE PLAYER.
   */
  virtual ~LocalPlayer();
  /**
   * calls the player to pick the cell, sends the picked cell
   * to the server via the client.
   * @param moves - vector of moves.
   * @return - a picked cell.
   */
  virtual Cell pickMove(vector<Cell *> &moves) const;
  virtual char getColor() const;
 private:
  Player *player;
  Client *client;
};

#endif //REVERSI_LOCALPLAYER_H
