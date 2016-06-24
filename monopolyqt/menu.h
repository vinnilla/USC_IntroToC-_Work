//menu.h
#include <QtGui>

#ifndef MENU_H
#define MENU_H

#include "player.h"
#include <QPushButton>

class Menu : public QWidget {
  Q_OBJECT

  protected:
    QPushButton *roll;
    QPushButton *upgrade;
    QPushButton *resign;
    QPushButton *end;
    Player* players[4];
  public:
    Menu ( Player* p[] );

};

#endif