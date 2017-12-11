#include <cstdlib>
#include "../include/LocalPlayer.h"
LocalPlayer::LocalPlayer(Player *player, Client *client)
    : player(player), client(client) {}
LocalPlayer::~LocalPlayer() {
  delete player;
}
Cell LocalPlayer::pickMove(vector<Cell *> &moves) const {
  Cell picked = player->pickMove(moves);
  if (moves.size() == 0) {
    // no moves.
    try {
      client->sendMsg("NoMove");
    } catch (const char *error) {
      cerr << error << endl;
      exit(1);
    }
    return Cell();
  }
  // parse the cell position.
  ostringstream messageParse;
  messageParse << picked.getRow();
  messageParse << SEPARATOR << picked.getCol();
  // send to server.
  client->sendMsg(messageParse.str().c_str());
  return picked;
}
char LocalPlayer::getColor() const {
  return player->getColor();
}
void LocalPlayer::endGame() const {
  client->sendMsg("End");
}
