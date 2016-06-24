//playersetup.cpp

#include "playersetup.h"

PlayerSetup::PlayerSetup(): QWidget() {

	//setup QPixmaps
	heartpic = new QPixmap ("images/pieces/heart.png");
	pawpic = new QPixmap ("images/pieces/paw.png");
	sunpic = new QPixmap ("images/pieces/sun.png");
	targetpic = new QPixmap ("images/pieces/target.png");
	swordpic = new QPixmap ("images/pieces/sword.png");
	yingyangpic = new QPixmap ("images/pieces/yingyang.png");	

	//setup all the piece buttons
	heart = new QPushButton (this);
	heart ->setIcon(*heartpic);
	heart ->setIconSize ( QSize(50, 50));
	connect( heart, SIGNAL(clicked()), this, SLOT(heartAct()) );

	paw = new QPushButton (this);
	paw ->setIcon(*pawpic);
	paw ->setIconSize ( QSize(50, 50));
	connect( paw, SIGNAL(clicked()), this, SLOT(pawAct()) );

	sun = new QPushButton (this);
	sun ->setIcon(*sunpic);
	sun ->setIconSize ( QSize(50, 50));
	connect( sun, SIGNAL(clicked()), this, SLOT(sunAct()) );

	target = new QPushButton (this);
	target ->setIcon(*targetpic);
	target ->setIconSize ( QSize(50, 50));
	connect( target, SIGNAL(clicked()), this, SLOT(targetAct()) );

	sword = new QPushButton (this);
	sword ->setIcon(*swordpic);
	sword ->setIconSize ( QSize(50, 50));
	connect( sword, SIGNAL(clicked()), this, SLOT(swordAct()) );

	yingyang = new QPushButton (this);
	yingyang ->setIcon(*yingyangpic);
	yingyang ->setIconSize ( QSize(50, 50));
	connect( yingyang, SIGNAL(clicked()), this, SLOT(yingyangAct()) );

}

void PlayerSetup::hideAll() {
}

void PlayerSetup::heartAct() {
	
}

void PlayerSetup::pawAct() {}

void PlayerSetup::sunAct() {}

void PlayerSetup::targetAct() {}

void PlayerSetup::swordAct() {}

void PlayerSetup::yingyangAct() {}

void PlayerSetup::setPlayers() {}
