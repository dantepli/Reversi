#include "../include/NetworkPlayer.h"
NetworkPlayer::NetworkPlayer(Display *display, Client *client, char color)
    : display(display), client(client), color(color) {}
NetworkPlayer::~NetworkPlayer() {}
Cell NetworkPlayer::pickMove(vector<Cell *> &moves) const {
  int row = 0, col = 0;
  char *msg;
  display->displayWaitingForChoice();
  // get message from server.
  try {
    msg = client->receiveMsg();
  } catch (const char *error) {
    cerr << "Failed reading from server" << endl;
    exit(1);
  }
  if (strcmp(msg, "End") == 0) {
    return Cell(row, col);
  }
  if (strcmp(msg, "NoMove") == 0) {
    return Cell(row, col);
  }
  // parse message.
  string check = msg;
  if (check.find(SEPARATOR) == string::npos) {
    return Cell(-1, -1);
  }
  row = atoi(strtok(msg, SEPARATOR));
  col = atoi(strtok(NULL, SEPARATOR));
  display->displayAIChoice(*this, Cell(row, col));
  return Cell(row, col);
}
char NetworkPlayer::getColor() const {
  return color;
}
void NetworkPlayer::endGame() const {
}
