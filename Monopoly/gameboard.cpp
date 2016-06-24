//gameboard.cpp

#include "gameboard.h"
#include "player.h"
#include "space.h"
#include <iostream>

using namespace std;

Game_Board::Game_Board() {}

Game_Board::Game_Board(int numberofspaces) {
	allSpaces = new Space[numberofspaces];
	int spaceNum = 0;
	allSpaces[spaceNum].populate(false, "        GO       ", "                 ",  spaceNum+1, "    ", 'n', 0, 0, 0,
	"",
	 "",
	  "");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Mazda      ", "        2        ",  spaceNum+1, "    ", '0', 14720, 1472, 4416,
	"You see the Mazda 2! You may purchase the vehicle for $14,720 if you'd like to.",
	 "You see Player ",
	  "'s Mazda 2 and rent it! You pay $1,472 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "    Community    ", "      Chest      ",  spaceNum+1, "    ", '5', 0, 0, 0,
	"You draw a community chest card.",
	 "",
	  "");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Mazda      ", "        3        ", spaceNum+1, "    ", '0', 16945, 1695, 5084,
	"You see the Mazda 3! You may purchase the vehicle for $16,945 if you'd like to.",
	 "You see Player ",
	  "'s Mazda 3 and rent it! You pay $1,695 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "      Income     ", "       Tax       ",  spaceNum+1, "    ", '7', 0, 0, 0,
	"You pay income tax.",
	 "",
	  "");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Bus       ", "       Stop      ",  spaceNum+1, "    ", '0', 50000, 5000, 15000,
	"You see a Bus Stop! You may purchase the this bus stop for $50,000 if you'd like to.",
	 "You see Player ",
	  "'s Bus Stop and rent a bus! You pay $5,000 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Honda      ", "      Civic      ",  spaceNum+1, "    ", '0', 18390, 1839, 5517,
	 "You see the Honda Civic! You may purchase the vehicle for $18,390 if you'd like to.",
	 "You see Player ",
	  "'s Honda Civic and you rent it! You pay $1,839 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "      Chance     ", "                 ",  spaceNum+1, "    ", '6', 0, 0, 0,
	 "You draw a chance card.",
	 "",
	  "");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Honda      ", "       CR-Z      ",  spaceNum+1, "    ", '0', 19995, 2000, 6000,
	 "You see the Honda CR-Z! You may purchase the vehicle for $19,995 if you'd like to.",
	 "You see Player ",
	  "'s Honda CR-Z and you rent it! You pay $2,000 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Honda      ", "      Accord     ",  spaceNum+1, "    ", '0', 21955, 2196, 6587,
	 "You see the Honda Accord! You may purchase the vehicle for $21,955 if you'd like to.",
	 "You see Player ",
	  "'s Honda Accord and you rent it! You pay $2,196 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Jail      ", "                 ",   spaceNum+1, "    ", 'n', 0, 0, 0,
	 "You are visiting the jail.",
	 "",
	  "");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Toyota     ", "      Camry      ",   spaceNum+1, "    ", '0', 22425, 2243, 6728,
	 "You see the Toyota Camry! You may purchase the vehicle for $22,425 if you'd like to.",
	 "You see Player ",
	  "'s Toyota Camry and you rent it! You pay $2,243 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Taxi      ", "                 ",   spaceNum+1, "    ", '0', 25000, 2500, 7500,
	 "You see a taxi! You may purchase the vehicle for $25,000 if you'd like to.",
	 "You see Player ",
	  "'s taxi and you rent it! You pay $2,500 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Toyota     ", "      Sienna     ",   spaceNum+1, "    ", '0', 26200, 2620, 7860,
	 "You see the Toyota Sienna! You may purchase the vehicle for $26,200 if you'd like to.",
	 "You see Player ",
	  "'s Toyota Sienna and you rent it! You pay $2,620 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Toyota     ", "      Tundra     ",   spaceNum+1, "    ", '0', 26920, 2692, 8076,
	 "You see the Toyota Tundra! You may purchase the vehicle for $26,920 if you'd like to.",
	 "You see Player ",
	  "'s Toyota Tundra and you rent it! You pay $2,692 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Bus       ", "       Stop      ",   spaceNum+1, "    ", '0', 50000, 5000, 15000,
	 "You see a Bus Stop! You may purchase the this bus stop for $50,000 if you'd like to.",
	 "You see Player ",
	  "'s Bus Stop and you rent a bus! You pay $5,000 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Mercedes    ", "      CLA250     ",   spaceNum+1, "    ", '0', 29900, 2990, 8970,
	 "You see the Mercedes CLA250! You may purchase the vehicle for $29,900 if you'd like to.",
	 "You see Player ",
	  "'s Mercedes CLA250 and you rent it! You pay $2,990 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "    Community    ", "      Chest      ",   spaceNum+1, "    ", '5', 0, 0, 0,
	 "You draw a community chest card.",
	 "",
	  "");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Mercedes    ", "    C250 Sport   ",   spaceNum+1, "    ", '0', 35800, 3580, 10740,
	 "You see the Mercedes C250 Sport! You may purchase the vehicle for $35,800 if you'd like to.",
	 "You see Player ",
	  "'s Mercedes C250 Sport and you rent it! You pay $3,580 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Mercedes    ", "    C250 Coupe   ",   spaceNum+1, "    ", '0', 38200, 3820, 11460,
	 "You see the Mercedes C250 Coupe! You may purchase the vehicle for $38,200 if you'd like to.",
	 "You see Player ",
	  "'s Mercedes C250 Coupe and you rent it! You pay $3,820 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Free      ", "     Parking     ",   spaceNum+1, "    ", 'n', 0, 0, 0,
	 "You land on free parking!",
	 "",
	  "");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "       Audi      ", "        A5       ",   spaceNum+1, "    ", '0', 39000, 3900, 11700,
	 "You see the Audi A5! You may purchase the vehicle for $39,000 if you'd like to.",
	 "You see Player ",
	  "'s Audi A5 and you rent it! You pay $3,900 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "     Chance      ", "                 ",   spaceNum+1, "    ", '6', 0, 0, 0,
	 "You draw a chance card.",
	 "",
	  "");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "       Audi      ", "        A6       ",   spaceNum+1, "    ", '0', 43100, 4310, 12930,
	 "You see the Audi A6! You may purchase the vehicle for $43,100 if you'd like to.",
	 "You see Player ",
	  "'s Audi A6 and you rent it! You pay $4,310 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "       Audi      ", "        S4       ",   spaceNum+1, "    ", '0', 48100, 4810, 14430,
	 "You see the Audi S4! You may purchase the vehicle for $48,100 if you'd like to.",
	 "You see Player ",
	  "'s Audi S4 and you rent it! You pay $4,810 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Bus       ", "       Stop      ",   spaceNum+1, "    ", '0', 50000, 5000, 15000,
	 "You see a Bus Stop! You may purchase the this bus stop for $50,000 if you'd like to.",
	 "You see Player ",
	  "'s Bus Stop and you rent a bus! You pay $5,000 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "       BMW       ", "    535i Sedan   ",   spaceNum+1, "    ", '0', 55100, 5510, 16530,
	 "You see the BMW 535i Sedan! You may purchase the vehicle for $55,100 if you'd like to.",
	 "You see Player ",
	  "'s BMW 535i Sedan and you rent it! You pay 5,510 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "       BMW       ", "      X535i      ",   spaceNum+1, "    ", '0', 55100, 5510, 16530,
	 "You see the BMW X535i! You may purchase the vehicle for $55,100 if you'd like to.",
	 "You see Player ",
	  "'s BMW X535i and you rent it! You pay $5,510 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Taxi      ", "                 ",   spaceNum+1, "    ", '0', 25000, 2500, 7500,
	 "You see a taxi! You may purchase the vehicle for $25,000 if you'd like to.",
	 "You see Player ",
	  "'s taxi and you rent it! You pay $2,500 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "       BMW       ", "      X635i      ",   spaceNum+1, "    ", '0', 60800, 6080, 18240,
	 "You see the BMW X635i! You may purchase the vehicle for $60,800 if you'd like to.",
	 "You see Player ",
	  "'s BMW X635i and you rent it! You pay $6,080 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "      Go To      ", "       Jail      ",   spaceNum+1, "    ", '9', 0, 0, 0,
	 "You are arrested and sent to jail.",
	 "",
	  "");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Porsche     ", "    Boxster S    ",   spaceNum+1, "    ", '0', 62100, 6210, 18630,
	 "You see the Porsche Boxster S! You may purchase the vehicle for $62,100 if you'd like to.",
	 "You see Player ",
	  "'s Porsche Boxster S and you rent it! You pay $6,210 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Porsche     ", "     Cayman S    ",   spaceNum+1, "    ", '0', 63800, 6380, 19140,
	 "You see the Porsche Cayman S! You may purchase the vehicle for $63,800 if you'd like to.",
	 "You see Player ",
	  "'s Porsche Cayman S and you rent it! You pay $6,380 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "    Community    ", "      Chest      ",   spaceNum+1, "    ", '5', 0, 0, 0,
	 "You draw a community chest card.",
	 "",
	  "");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Porsche     ", "   911 Carrera   ",   spaceNum+1, "    ", '0', 84300, 8430, 25290,
	 "You see the Porsche 911 Carrera! You may purchase the vehicle for $84,300 if you'd like to.",
	 "You see Player ",
	  "'s Porsche 911 Carrera and you rent it! You pay $8,430 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Bus       ", "       Stop      ",   spaceNum+1, "    ", '0', 50000, 5000, 15000,
	 "You see a Bus Stop! You may purchase the this bus stop for $50,000 if you'd like to.",
	 "You see Player ",
	  "'s Bus Stop and you rent a bus! You pay $5,000 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "      Chance     ", "                 ",   spaceNum+1, "    ", '6', 0, 0, 0,
	 "You draw a chance card.",
	 "",
	  "");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Maserati    ", "   Quattroporte  ",   spaceNum+1, "    ", '0', 102500, 10250, 30750,
	 "You see the Maserati Quattroporte! You may purchase the vehicle for $102,500 if you'd like to.",
	 "You see Player ",
	  "'s Maserati Quattroporte and you rent it! You pay $10,250 to Player ");
	spaceNum++;
	allSpaces[spaceNum].populate(false, "      Luxury     ", "       Tax       ",   spaceNum+1, "    ", '8', 0, 0, 0,
	 "You pay luxury tax.",
	 "",
	  "");
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Maserati    ", "   Granturismo   ",   spaceNum+1, "    ", '0', 126500, 12650, 37950,
	 "You see the Maserati Granturismo! You may purchase the vehicle for $126,500 if you'd like to.",
	 "You see Player ",
	  "'s Maserati Granturismo and you rent it! You pay $12,650 to Player "); //constructor


}

Game_Board::~Game_Board() { //deconstructor
	delete [] allSpaces;
}

int Game_Board::counterIncrement(int start, int end, int value) {
	//check to see if it is top row of board or bottom row of board -- increment counter differently for the two cases
	if (start < end) {//top row
		return start+value;
	}

	else if (start > end) {//bottom row
		return start-value;
	}
	return 0;
}

void Game_Board::updatePieces(int playerNum, int currentSpace, int previousSpace, char character) {
	for (int i = 0; i < 40; i++) {
		if (currentSpace == i) { //finds the space the player is currently at (the one the player just moved to) and adds the player's piece to the space
			allSpaces[i].updatePieces(playerNum, character);
		}

		if (previousSpace == i) { //find the previous space the player was at before moving and removes the player's piece from the space
			allSpaces[i].updatePieces(playerNum, ' ');
		}
	}
}

void Game_Board::updateSpaces(Player players[], int numPlayers) { //retrieves the player's current position and previous position and alters the corrent spaces
	for (int i = 0; i < numPlayers; i++) {
		int tempCurrentSpace;
		int tempPreviousSpace;
		char tempChar;
		tempCurrentSpace = players[i].returnSpace();
		tempPreviousSpace = players[i].returnSpace2();
		tempChar = players[i].returnChar();
		updatePieces(i, tempCurrentSpace, tempPreviousSpace, tempChar);
	}
}
/*
string Game_Board::retrieveAction() {
	if (purchased == '0' or purchased == 'n' or purchased == '5' or purchased == '6' or purchased == '7' or purchased == '8' or purchased == '9') { 
		return actions[0];
	}
	else if (purchased == '1' or purchased == '2' or purchased == '3' or purchased == '4') {
		return actions[1] + purchased + actions[2] + purchased + ".\n";
	}
	return " ";
}

char Space::retrievePurchased() {
	return purchased;
}

int Space::retrieveBuy() {
	return buyPrice;
}

int Space::retrieveRent() {
	return rentPrice;
}
*/



void Game_Board::outputRow(int start, int end){ //output entire row

	cout << "  -";
	for (int i = 0; i < 11; i++) {
		//output top line of tile
		cout << "------------------";
	}
	cout << endl;

/*	cout << "|";
	for (int i = 0; i < 11; i++) {
		//output color bar line
		cout <<	"                 |";
	}
	cout << endl;
*/
	cout << "  |";
	for (int i = 0; i < 11; i++) {
		//output bottom of color bar line (if it exists)
		//check color bool to see if the space has a color bar
		int counter = counterIncrement(start, end, i);

		if (allSpaces[counter].returnColor() == true) {
			cout << "-----------------|";
		}
		else if (allSpaces[counter].returnColor() == false) {
			cout << "                 |";
		}
		
	}
	cout << endl;

	cout << "  |";
	for (int i = 0; i < 11; i++ ) {
		//output first line of name of tile
		//reset counter
		int counter = counterIncrement(start, end, i);

		cout << allSpaces[counter].returnBrand() << "|";
	}
	cout << endl;

	cout << "  |";
	for (int i = 0; i < 11; i++ ) {
		//output second line of name of tile
		//reset counter
		int counter = counterIncrement(start, end, i);

		cout << allSpaces[counter].returnModel() << "|" ;
	}
	cout << endl;

	cout << "  |";
	for (int i = 0; i < 11; i++ ) {
		//output price
		//reset counter
		int counter = counterIncrement(start, end, i);

		//check type of tile (ones that can be bought have buyPrice > 0)
		if (allSpaces[counter].returnBuy() > 0) {
			// 0 means tile is not owned
			if (allSpaces[counter].returnPurchased() == '0') {
				cout << "    Buy: " << allSpaces[counter].returnBuy() << "   |";
			}

			// 1 means tile is owned and at basic rent (no upgrades)
			else if (allSpaces[counter].returnPurchased() == '1' or '2' or '3' or '4') {
				cout << "    Rent: " << allSpaces[counter].returnRent() << "   |";
			}	
		}

		else {
			cout << "                 |";
		}
	}
	cout << endl;

	cout << "  |";
	for (int i = 0; i < 11; i++ ) {
		//output characters on tile (if any)
		//reset counter
		int counter = counterIncrement(start, end, i);

		cout << "       " << allSpaces[counter].returnPieces() << "      |" ;
	}
	cout << endl;

	cout << "  -";
	for (int i = 0; i < 11; i++) {
		//output bottom line of tile
		cout << "------------------";
	}
	cout << endl;
}

void Game_Board::outputColumn(int left, int right, bool bottom) {
	
	cout << "  |";
	//output bottom of color bar line (if it exists)
	//check color bool to see if the space has a color bar
	if (allSpaces[left].returnColor() == true) {
		cout << "-----------------|";
	}
	else if (allSpaces[left].returnColor() == false) {
		cout << "                 |";
	}
	//create the space in the middle of the board
	for (int i = 0; i < 8; i++) { 
		cout << "                  ";
	}
	cout << "                 |";
	if (allSpaces[right].returnColor() == true) {
		cout << "-----------------|";
	}
	else if (allSpaces[right].returnColor() == false) {
		cout << "                 |";
	}
	cout << endl;

	cout << "  |";
	//output first line of name of tile
	cout << allSpaces[left].returnBrand() << "|";
	//create the space in the middle of the board
	for (int i = 0; i < 8; i++) { 
		cout << "                  ";
	}
	cout << "                 |";
	cout << allSpaces[right].returnBrand() << "|";
	cout << endl;

	cout << "  |";
	//output second line of name of tile
	cout << allSpaces[left].returnModel() << "|" ;
	//create the space in the middle of the board
	for (int i = 0; i < 8; i++) { 
		cout << "                  ";
	}
	cout << "                 |";
	cout << allSpaces[right].returnModel() << "|" ;
	cout << endl;

	cout << "  |";
	//output price
	//check type of tile (ones that can be bought have buyPrice > 0)
	if (allSpaces[left].returnBuy() > 0) {
		// 0 means tile is not owned
		if (allSpaces[left].returnPurchased() == '0') {
			if (allSpaces[left].returnBuy() < 100000){
				cout << "    Buy: " << allSpaces[left].returnBuy() << "   |";
			}
			else {
				cout << "   Buy: " << allSpaces[left].returnBuy() << "   |";
			}
		}

		// 1 means tile is owned and at basic rent (no upgrades)
		else if (allSpaces[left].returnPurchased() == '1' or '2' or '3' or '4') {
			if (allSpaces[left].returnRent() < 10000){
				cout << "    Rent: " << allSpaces[left].returnRent() << "   |";
			}
			else {
				cout << "   Rent: " << allSpaces[left].returnRent() << "   |";
			}
			
		}	
	}

	else {
		cout << "                 |";
	}
	//create the space in the middle of the board
	for (int i = 0; i < 8; i++) { 
		cout << "                  ";
	}
	cout << "                 |";
	if (allSpaces[right].returnBuy() > 0) {
		// 0 means tile is not owned
		if (allSpaces[right].returnPurchased() == '0') {
			if (allSpaces[right].returnBuy() < 100000){
				cout << "    Buy: " << allSpaces[right].returnBuy() << "   |";
			}
			else {
				cout << "   Buy: " << allSpaces[right].returnBuy() << "   |";
			}
		}

		// 1 means tile is owned and at basic rent (no upgrades)
		else if (allSpaces[right].returnPurchased() == '1' or '2' or '3' or '4') {
			if (allSpaces[right].returnRent() < 10000){
				cout << "    Rent: " << allSpaces[right].returnRent() << "   |";
			}
			else {
				cout << "   Rent: " << allSpaces[right].returnRent() << "   |";
			}
			
		}	
	}

	else {
		cout << "                 |";
	}
	cout << endl;

	cout << "  |";
	//output characters on tile (if any)
	cout << "       " << allSpaces[left].returnPieces() << "      |" ;
	//create the space in the middle of the board
	for (int i = 0; i < 8; i++) { 
		cout << "                  ";
	}
	cout << "                 |";
	cout << "       " << allSpaces[right].returnPieces() << "      |" ;
	cout << endl;

	if (!bottom) {
		cout << "  -";
		//output bottom line of tile
		cout << "------------------";
		//create the space in the middle of the board
		for (int i = 0; i < 8; i++) { 
			cout << "                  ";
		}
		cout << "                 |";
		cout << "------------------";
		cout << endl;
	}
}

void Game_Board::print_Board() {
	outputRow(20, 30); //outputs the top row
	for (int i = 0; i < 8; i++) {
		outputColumn(19-i, 31+i, false); //outputs the first 8 rows of the column
	}
	outputColumn(11, 39, true);//outputs the last row fo the column with true bool telling function it is the last row of the column
	outputRow(10, 0); //outputs the bottom row

}