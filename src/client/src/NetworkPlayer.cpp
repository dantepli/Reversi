#include "../include/NetworkPlayer.h"
NetworkPlayer::NetworkPlayer(Display *display, Client *client, char color)
    : display(display), client(client), color(color) {}
NetworkPlayer::~NetworkPlayer() {}
Cell NetworkPlayer::pickMove(vector<Cell *> &moves) const {
  int row = 0, col = 0;
  cout << "WAITING FOR NETWORK MESSAGE" << endl;
  // get message from server.
  char *msg = client->receiveMsg();
  cout << "NETWORK PLAYER RECIEVED: " << msg << endl;
  if (strcmp(msg, "End") == 0) {
    return Cell(row, col);
  }
  if (strcmp(msg, "NoMove") == 0) {
    return Cell(row, col);
  }
  // parse message.
  row = atoi(strtok(msg, SEPARATOR));
  col = atoi(strtok(NULL, SEPARATOR));
  cout << "NETWORK: " << row << " " << col << endl;
  display->displayAIChoice(*this, Cell(row, col));
  return Cell(row, col);
}
char NetworkPlayer::getColor() const {
  return color;
}
void NetworkPlayer::endGame() const {
}
