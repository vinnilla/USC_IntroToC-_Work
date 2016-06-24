//guiplayer.cpp
#include "guiplayer.h"
#include <QGridLayout>

GUIPlayer::GUIPlayer( Player* p) : QWidget() {
  player = p;
  nameLabel = new QLabel( this );
  nameLabel->setText( player->getName() );

  moneyLabel = new QLabel( this);
  moneyLabel -> setText ("Money: ");
  money = new QLabel ( this );
  money -> setText( QString::number(player->getMoney()) );

  propertyLabel = new QLabel ( this );
  propertyLabel -> setText ("Property: ");
  property = new QWidget( this );

  tokenLabel = new QLabel ( this);
  tokenLabel -> setText ("Token: ");
  token = new QLabel (this);

  QGridLayout *layout = new QGridLayout;
  layout -> addWidget(nameLabel, 0, 0);
	layout -> addWidget(tokenLabel, 1, 0);
  layout -> addWidget(token, 1, 1);
	layout -> addWidget(moneyLabel, 2, 0);
	layout -> addWidget(money, 2, 1);
	layout -> addWidget(propertyLabel, 3, 0);
	layout -> addWidget(property,3, 1, 20, 10);
	
	setLayout(layout);
}

void GUIPlayer::setToken(QPixmap picture) {
  token -> setPixmap(picture);
}

void GUIPlayer::update(Player* p) {
  player = p;
  money -> setText( QString::number(player->getMoney()) );
}