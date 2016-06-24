//startmenu.cpp

#include "startmenu.h"

StartMenu::StartMenu(): QWidget() {

	blank = new QLabel( this );
	blank->setPixmap( QPixmap("images/blank.jpg") );


	question = new QLabel( this);
	question -> setText ("Welcome to Monopoly 2014 Car Edition!\n          How many players are playing?");
	question -> setFont(QFont("Times", 14, QFont::Bold));

	two = new QPushButton(tr("Two"));
	two -> setFont(QFont("Times", 12, QFont::Bold));
	//Connect the button to action
	connect( two, SIGNAL(clicked()), this, SLOT(twoAct()) );

	three = new QPushButton(tr("Three"));
	three -> setFont(QFont("Times", 12, QFont::Bold));
	//Connect the button to action
	connect( three, SIGNAL(clicked()), this, SLOT(threeAct()) );

	four = new QPushButton(tr("Four"));
	four -> setFont(QFont("Times", 12, QFont::Bold));
	//Connect the button to action
	connect( four, SIGNAL(clicked()), this, SLOT(fourAct()) );

	
	layout = new QGridLayout;
	layout -> addWidget(blank, 0, 0, 8, 9);
  	layout -> addWidget(question, 0, 3, 1, 3);
	layout -> addWidget(two, 1, 4);
	layout -> addWidget(three, 2, 4);
	layout -> addWidget(four, 3, 4);
	
	setLayout(layout);
	
}

void StartMenu::hideAll() {
	blank -> hide();
	question -> hide();
	two -> hide();
	three -> hide();
	four -> hide();
}

void StartMenu::twoAct() {
	Players = 2;
	hideAll();
}

void StartMenu::threeAct() {
	Players = 3;
	hideAll();
}

void StartMenu::fourAct() {
	Players = 4;
	hideAll();
}

int StartMenu::returnPlayers() {
	return Players;
}