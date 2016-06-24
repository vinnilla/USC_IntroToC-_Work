//player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player {
 private:
  QString playerName;
  int playerMoney;
  int currentSpace;
  bool jail;
  int jailcounter;

 public:
  Player(int);
  void setName( QString n );
  QString getName();

  int getMoney();
  void payMoney(int);
  void getMoney(int);
  
  bool setCurrentSpace(int);
  void movetoSpace(int);
  int getCurrentSpace();

  void setJail(bool);
  bool retrieveJail();
  void incrementJailCounter();
  void setJailCounter(int);
  int retrieveJCounter();

};

#endif
