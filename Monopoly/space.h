// space.h
#ifndef SPACE_H
#define SPACE_H

#include "player.h"
#include <string>

using namespace std;

class Space {
private:
	bool color;
	string nameBrand;
	string nameModel;
	int nextSpace;
	string pieces;
	char purchased; // n=not a purchasable space 0=available for purchase 1=player1 2=player2 3=player3 4=player4
	// 5=community chest 6=chance 7=income tax 8=luxury tax 9=gotojail
	int buyPrice;
	int rentPrice;
	int sellPrice;
	string actions[3];

public:
	void populate(bool, string, string, int, string, char, int, int, int, string, string, string);
	bool returnColor();
	string returnBrand();
	string returnModel();
	int returnBuy();
	char returnPurchased();
	int returnRent();
	string returnPieces();
	void updatePieces (int, char);

};

#endif

	