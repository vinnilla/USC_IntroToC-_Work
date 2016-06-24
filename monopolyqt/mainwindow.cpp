//mainwindow.cpp
#include "mainwindow.h"
#include "centralwidget.h"

MainWindow::MainWindow() : QWidget() {

	//Display startmenu;
	StartMenu();

	//Create the players and hide the gui
	for (int i = 0; i < 4; i++) {
		players[i] = new Player(i+1);
		guiPlayers[i] = new GUIPlayer(players[i]);
		guiPlayers[i] -> hide();
	}

	//Initialize the board and hide it
	centralWidget = new CentralWidget(players, guiPlayers, this);
	centralWidget -> hide();

	//Display characters to choose;
	PlayerSetupMenu();

	//Initialize tax question menu and hide it
	TaxQuestion();
	hidetaxQuestion();

	layout = new QGridLayout;
	layout -> addWidget (centralWidget, 0, 0, 10, 10);
	for (int i = 0; i < 4; i++) {
		layout -> addWidget (guiPlayers[i], 0, 5, 2, 1);
	}
	layout -> addLayout (playersetup, 3, 4);
	layout -> addLayout (startmenu, 3, 4);
	layout -> addLayout (taxQuestion, 3, 4);
	setLayout(layout);

}

void MainWindow::StartMenu() {

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

	
	startmenu = new QGridLayout;
  	startmenu -> addWidget(question, 0, 0);
	startmenu -> addWidget(two, 1, 0);
	startmenu -> addWidget(three, 2, 0);
	startmenu -> addWidget(four, 3, 0);

}

void MainWindow::hideStartMenu() {
	question -> hide();
	two -> hide();
	three -> hide();
	four -> hide();

	setupMenuQ -> show();
	setupMenuPlayer -> show();
	heart -> show();
	paw -> show();
	sun -> show();
	target -> show();
	sword -> show();
	yingyang -> show();
}

void MainWindow::twoAct() {
	numPlayers = 2;
	centralWidget -> setnumPlayers(2);
	hideStartMenu();
}

void MainWindow::threeAct() {
	numPlayers = 3;
	centralWidget -> setnumPlayers(3);
	hideStartMenu();
}

void MainWindow::fourAct() {
	numPlayers = 4;
	centralWidget -> setnumPlayers(4);
	hideStartMenu();
}

void MainWindow::PlayerSetupMenu() {
	setupcounter = 0;
	//setup prompt
	setupMenuQ = new QLabel( this);
	setupMenuQ -> setText ("Choose your pieces in order.");
	setupMenuQ -> setFont(QFont("Times", 14, QFont::Bold));

	setupMenuPlayer = new QLabel( this);
	setupMenuPlayer -> setText ("Player: " + QString::number(setupcounter+1));
	setupMenuPlayer -> setFont(QFont("Times", 14, QFont::Bold));

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

	playersetup = new QGridLayout;
	playersetup -> addWidget(setupMenuQ, 0, 0);
	playersetup -> addWidget(setupMenuPlayer, 1, 0);
	playersetup -> addWidget(heart, 2, 0);
	playersetup -> addWidget(paw, 3, 0);
	playersetup -> addWidget(sun, 4, 0);
	playersetup -> addWidget(target, 5, 0);
	playersetup -> addWidget(sword, 6, 0);
	playersetup -> addWidget(yingyang, 7, 0);

	//hide menu
	setupMenuQ -> hide();
	setupMenuPlayer -> hide();
	heart -> hide();
	paw -> hide();
	sun -> hide();
	target -> hide();
	sword -> hide();
	yingyang -> hide();

}

void MainWindow::hidePlayerSetupMenu() {
	setupMenuQ -> hide();
	setupMenuPlayer -> hide();
	heart -> hide();
	paw -> hide();
	sun -> hide();
	target -> hide();
	sword -> hide();
	yingyang -> hide();

	centralWidget -> show();
	guiPlayers[0] -> show();
	centralWidget -> enableButtons();

}

void MainWindow::heartAct() {
	centralWidget -> setToken(setupcounter, *heartpic);
	guiPlayers[setupcounter] -> setToken(*heartpic);
	heart -> setEnabled(false);
	setupcounter++;
	setupMenuPlayer -> setText ("Player: " + QString::number(setupcounter+1));
	if (setupcounter == numPlayers){
		hidePlayerSetupMenu();
	}
}

void MainWindow::pawAct() {
	centralWidget -> setToken(setupcounter, *pawpic);
	guiPlayers[setupcounter] -> setToken(*pawpic);
	paw -> setEnabled(false);
	setupcounter++;
	setupMenuPlayer -> setText ("Player: " + QString::number(setupcounter+1));
	if (setupcounter == numPlayers){
		hidePlayerSetupMenu();
	}
}

void MainWindow::sunAct() {
	centralWidget -> setToken(setupcounter, *sunpic);
	guiPlayers[setupcounter] -> setToken(*sunpic);
	sun -> setEnabled(false);
	setupcounter++;
	setupMenuPlayer -> setText ("Player: " + QString::number(setupcounter+1));
	if (setupcounter == numPlayers){
		hidePlayerSetupMenu();
	}
}

void MainWindow::targetAct() {
	centralWidget -> setToken(setupcounter, *targetpic);
	guiPlayers[setupcounter] -> setToken(*targetpic);
	target -> setEnabled(false);
	setupcounter++;
	setupMenuPlayer -> setText ("Player: " + QString::number(setupcounter+1));
	if (setupcounter == numPlayers){
		hidePlayerSetupMenu();
	}
}

void MainWindow::swordAct() {
	centralWidget -> setToken(setupcounter, *swordpic);
	guiPlayers[setupcounter] -> setToken(*swordpic);
	sword -> setEnabled(false);
	setupcounter++;
	setupMenuPlayer -> setText ("Player: " + QString::number(setupcounter+1));
	if (setupcounter == numPlayers){
		hidePlayerSetupMenu();
	}
}

void MainWindow::yingyangAct() {
	centralWidget -> setToken(setupcounter, *yingyangpic);
	guiPlayers[setupcounter] -> setToken(*yingyangpic);
	yingyang -> setEnabled(false);
	setupcounter++;
	setupMenuPlayer -> setText ("Player: " + QString::number(setupcounter+1));
	if (setupcounter == numPlayers){
		hidePlayerSetupMenu();
	}
}

void MainWindow::TaxQuestion() {
	taxQ = new QLabel( this);
	taxQ -> setText ( "Would you like to pay $40,000 straight up or pay 10% of your total assets?" );
	taxQ -> setFont(QFont("Times", 14, QFont::Bold));

	percent = new QPushButton(tr("10%"));
	percent -> setFont(QFont("Times", 12, QFont::Bold));
	//Connect the button to action
	connect( percent, SIGNAL(clicked()), centralWidget, SLOT(percentTax()) );

	straightup = new QPushButton(tr("$40,000"));
	straightup -> setFont(QFont("Times", 12, QFont::Bold));
	//Connect the button to action
	connect( straightup, SIGNAL(clicked()), centralWidget, SLOT(straightupTax()) );

	taxQuestion = new QGridLayout;
	taxQuestion ->addWidget(taxQ, 0, 0);
	taxQuestion -> addWidget(percent, 1, 0);
	taxQuestion -> addWidget(straightup, 2, 0);
}

void MainWindow::showtaxQuestion() {
	taxQ -> show();
	percent -> show();
	straightup -> show();
}

void MainWindow::hidetaxQuestion() {
	taxQ -> hide();
	percent -> hide();
	straightup -> hide();
}

void MainWindow::changePlayerGui(int player) {
	for (int i = 0; i < 4; i++){
		guiPlayers[i] -> hide();
	}
	guiPlayers[player] -> show();
}

void MainWindow::updatePlayerGui (int player) {
	guiPlayers[player] -> update(players[player]);
}