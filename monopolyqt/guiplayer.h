//guiplayer.h
#include <QtGui>

#ifndef GUIPLAYER_H
#define GUIPLAYER_H

#include "player.h"

class GUIPlayer : public QWidget {
  Q_OBJECT

  protected:
    Player* player;
    QLabel *nameLabel;

    QLabel *money;
    QLabel *moneyLabel;

    QLabel *propertyLabel;
    QWidget *property;

    QLabel *tokenLabel;
    QLabel *token;

  public:
    GUIPlayer( Player* p);
    void setToken(QPixmap);
    void update(Player* p);

};

#endif
