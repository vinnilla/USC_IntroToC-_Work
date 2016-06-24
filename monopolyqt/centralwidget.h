//centralwidget.h
#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include "space.h"
#include "player.h"
#include "guiplayer.h"
#include <QtGui>

class MainWindow;

class CentralWidget: public QWidget {
	Q_OBJECT

private:
	MainWindow* mw;

	Space* spaces[40];
	QPushButton* spaceTokens[40];

	QLabel* upgradeStars[200];


	int numPlayers;
	int currentPlayer;
	Player* centralplayers[4];
	GUIPlayer* centralguiplayers[4];
	QPushButton* p[4];
	QPixmap playerIcons[4];
	QPixmap* test;

	QPushButton* chanceDeckButton;
	QPushButton* communityDeckButton;

	QLabel* boardLabel;
	QPixmap* chanceFaceDown;
	QPixmap* chanceFaceUp;
	QPixmap* communityFaceDown;
	QPixmap* communityFaceUp;

	QPixmap* faceOne;
	QPixmap* faceTwo;
	QPixmap* faceThree;
	QPixmap* faceFour;
	QPixmap* faceFive;
	QPixmap* faceSix;
	QPushButton* diceButton;
	QPushButton* diceButton2;

	QPixmap* buy;
	QPushButton* buyButton;

	QPixmap* upgrade;
	QPushButton* upgradeButton;
	QPushButton* upgradeButtons[40];
	QSignalMapper* signalMapper;

	QPixmap* endTurn;
	QPushButton* endButton;

	QPushButton* communitycards[16];
	QPushButton* chancecards[16];

	QPushButton* fliptable;
	QPushButton* end;

	private slots:
	void drawCard();
	void rollDie();
	void determineDieFace(QPushButton*, int);
	void nextTurn();
	void buySpace();
	void chance();
	void community();
	void percentTax();
	void straightupTax();
	void upgradeAct();
	void tinyupgrade(int);

	void advancetoSpace(int);
	void moveSpaces(int);
	void GainMoney(int);
	void LoseMoney(int);
	void gotoJail(int);
	void duud(int);

	void flip();
	
public:
	CentralWidget(Player**, GUIPlayer**, MainWindow*);
	void GameFunction();
	void enableButtons();
	void disableButtons();
	void hideAll();
	void showAll();
	void setupSpaces();
	void showPieces(Player**);
	void setnumPlayers(int);
	void setToken(int, QPixmap);
	void setSpaceOwnerToken(int, int);
	void setupSpaceTokens();

	void updateBuses();
	void updateMonopoly();

	void checkUpgrade();
	void createUpgradeButtons();
	void showUpgradeButton(int);
	void setupUpgradeStars();

	void setupCards();
	void hideAllCards();
};

#endif