// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

using namespace std;

class Player {
private:
	char character;
	int playerNum;
	int currentSpace;
	int previousSpace;
	int money;
	int ownedProperty[40];
	int jail; //0=free 1=in custody
	int jailCounter;

public:
	void populate(char, int, int, int, int, int, int, int);
	int returnSpace();
	int returnSpace2();
	char returnChar();
	int returnNum();
	bool updateInfo(int);
	void updateProperty(int);
	void updateJail(int);
	void updateJailcounter();
	int retrieveCounter();
	int retrieveWealth();
	int retrieveJail();
	int retrieveProperty(int);
	void deductMoney(int);
	void addMoney(int);
	void print();
	void realPrint();
};

#endif