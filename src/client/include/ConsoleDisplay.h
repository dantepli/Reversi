#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include "Display.h"
class ConsoleDisplay : public Display {
 public:
  virtual void displayBoard(Board &board) const;
  virtual void displayHumanPlayerChoiceMessage(const Player &player,
                                               const vector<Cell *> &moves) const;
  virtual void displayNoMoves(const Player &player) const;
  virtual void displayEndScreen(const Player &player1,
                                const Player &player2,
                                const Board &board,
                                int player1Score,
                                int player2Score) const;
  virtual void displayAIChoice(const Player &player, const Cell &cell) const;
  virtual void displayWaitingForPlayer() const;
  virtual void displayWaitingForChoice() const;
};

#endif //CONSOLEDISPLAY_H
