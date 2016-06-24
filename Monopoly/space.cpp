//space.cpp

#include "space.h"
#include "player.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void Space::populate(bool Color, string Brand, string Model, int Next, string Pieces, 
	char Purchased, int Buy, int Rent, int Sell, string line1, string line2, string line3) { //essentially a constructor
	color = Color;
	nameBrand = Brand;
	nameModel = Model;
	nextSpace = Next;
	pieces = Pieces;
	purchased = Purchased;
	buyPrice = Buy;
	rentPrice = Rent;
	sellPrice = Sell;
	actions[0] = line1;
	actions[1] = line2;
	actions[2] = line3;
}

bool Space::returnColor () {//access private variable outside of class
	return color;
}

string Space::returnBrand() {//access private variable outside of class
	return nameBrand;
}

string Space::returnModel() {//access private variable outside of class
	return nameModel;
}

int Space::returnBuy() {//access private variable outside of class
	return buyPrice;
}

char Space::returnPurchased() {//access private variable outside of class
	return purchased;
}

int Space::returnRent() {//access private variable outside of class
	return rentPrice;
}

string Space::returnPieces() {//access private variable outside of class
	return pieces;
}

void Space::updatePieces(int Num, char Char){//update pieces string for the space the player landed on (or left)
	pieces.replace(Num, 1, 1, Char);
}

/*
void Space::modify(int change) {
	if (change == 1){
		purchased = '1';
	}

	else if (change == 2) {
		purchased = '2';
	}

	else if (change == 3) {
		purchased = '3';
	}
	
	else if (change == 4) {
		purchased = '4';
	}

} 

void Space::realPrint(Space* spaces, int player) {
	char compare;
	stringstream ss;
	ss << player;
	ss >> compare;
	cout << "\n" << endl;
	for (int i = 0; i < 40; i++) {
		if (spaces[i].purchased == compare) {
			cout << spaces[i].nameBrand << spaces[i].nameModel << "$" << spaces[i].buyPrice << endl;
		}
	}
}*/