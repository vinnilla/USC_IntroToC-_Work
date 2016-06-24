//gameboard.h
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "player.h"
#include "space.h"
#include <string>
#include <iostream>

using namespace std;

class Game_Board : public Space {
private:
	Space* allSpaces;

public:
	Game_Board();
	Game_Board(int); 
	~Game_Board();
	int counterIncrement(int, int, int);
	void updatePieces (int, int, int, char);
	void updateSpaces (Player*, int);
/*	string retrieveAction();
	char retrievePurchased();
	int retrieveBuy();
	int retrieveRent();
	void modify(int);
	void realPrint(Space*, int);
*/
	void outputRow(int, int);
	void outputColumn(int, int, bool);
	void print_Board();
	
};

#endif