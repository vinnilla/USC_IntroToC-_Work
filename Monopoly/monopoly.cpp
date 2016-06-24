// monopoly.cpp

#include "space.h"
#include "player.h"
#include "bank.h"
#include "card.h"
#include "gameboard.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>


using namespace std;

const int NUMSPACES = 40;
//Space spaces[NUMSPACES];
Player* players;
Bank bank;
Card community[16];
Card chance[16];
string Pieces = "1234!@#%^&*+~$";

int rollDie () {
	int dice1 = rand()%5 + 1;
	int dice2 = rand()%5 + 1;
	return dice1 + dice2;
}

bool rollJail() {
	int dice1 = rand()%5 + 1;
	int dice2 = rand()%5 + 1;
	if (dice1 == dice2) {
		return true;
	}

	else {
		return false;
	}

}

int main() {

	srand (time(0));

	cout << "Welcome to Monopoly 2014 Cars Edition!" << endl;
	int numPlayers;
	do {
		cout << "How many players are playing? ";
		cin >> numPlayers;
		cout << endl;

		if (cin.fail()){
			cin.clear();
			cin.ignore (10000, '\n');
			cout << "That is an invalid input." << endl;
			continue;
		}

		else if (numPlayers < 2 or numPlayers > 4) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "That is an invalid number of players." << endl;
			continue;
		}

		else{
			cin.ignore (10000, '\n');
			break;
		}

	} while (true);

	//dynamically allocate player array
	players = new Player[numPlayers];

	char piece;
	for (int i = 0; i < numPlayers; i++) {
		do {
			cout << "These are the avaiable pieces: " << Pieces << endl;
			cout << "Player " << i+1 << ", choose your playing piece: ";
			cin >> piece;
			size_t found = Pieces.find(piece);
			cout << endl;

			if (cin.fail()){
				cin.clear();
				cin.ignore (10000, '\n');
				cout << "You must enter a single character." << endl;
				continue;
			}

			else if (found == string::npos) {
				cin.clear();
				cin.ignore (10000, '\n');
				cout << "You must choose from the list of pieces provided!" << endl;
				continue;
			}

			else{
				cin.ignore (10000, '\n');
				Pieces.erase (found, 1);
				break;
			}

		} while (true);

		players[i].populate(piece, i+1, 0, -1, 400000, 0, 0, 0);
	}

	//initialize bank
	bank.initialize(1000000);

	//populate spaces array with information
	Game_Board board (NUMSPACES);


	//populate cards
	community[0].populate (1, 0, 
		"Advance to Go", 
		"You advance to go!");

	community[1].populate (1, 1, 
		"Bank Error in your Favor", 
		"");

	community[2].populate (1, 2, 
		"Doctor's Fees", 
		"");

	community[3].populate (1, 3, 
		"Get Out of Jail Free", 
		"");

	community[4].populate (1, 4, 
		"Go to Jail", 
		"You are sent to jail.");

	community[5].populate (1, 5, 
		"Birthday", 
		"");

	community[6].populate (1, 6, 
		"Car Show", 
		"");

	community[7].populate (1, 7, 
		"Income Tax Refund", 
		"");

	community[8].populate (1, 8, 
		"Life Insurance Matures", 
		"");

	community[9].populate (1, 9, 
		"Pay Hospital Fees", 
		"");

	community[10].populate (1, 10, 
		"Pay School Fees", 
		"");

	community[11].populate (1, 11, 
		"Receive Consultancy Fee", 
		"");

	community[12].populate (1, 12, 
		"Car Repairs", 
		"");

	community[13].populate (1, 13, 
		"Beauty Contest", 
		"");

	community[14].populate (1, 14, 
		"Inheritance", 
		"");

	community[15].populate (1, 15, 
		"Stock Sale", 
		"");


	chance[0].populate (2, 0, 
		"Advance to Go", 
		"You advance to go!");

	chance[1].populate (2, 1, 
		"Advance to Audi A6", 
		"");

	chance[2].populate (2, 2, 
		"Advance to Nearest Taxi", 
		"");

	chance[3].populate (2, 3, 
		"Advance to Nearest Bus Stop", 
		"");

	chance[4].populate (2, 4, 
		"Advance to Toyota Camry", 
		"");

	chance[5].populate (2, 5, 
		"Bank Pays Dividend", 
		"");

	chance[6].populate (2, 6, 
		"Get Out of Jail Free", 
		"");

	chance[7].populate (2, 7, 
		"Go Back 3 Spaces", 
		"");

	chance[8].populate (2, 8, 
		"Go to Jail", 
		"");

	chance[9].populate (2, 9, 
		"Car Repairs", 
		"");

	chance[10].populate (2, 10, 
		"Pay Poor Tax", 
		"");

	chance[11].populate (2, 11, 
		"Take a Trip to the First Bus Stop", 
		"");

	chance[12].populate (2, 12, 
		"Admire the Maserati Granturismo", 
		"");

	chance[13].populate (2, 13, 
		"Elected Chairman of the Board", 
		"");

	chance[14].populate (2, 14, 
		"Car Loan Matures", 
		"");

	chance[15].populate (2, 15, 
		"Won a Crossword Competition", 
		"");

	//start of game -- round 0.
	board.updateSpaces(players, numPlayers);
	board.print_Board();

	//GAME LOOP!!!
	while (numPlayers > 1) {
		for (int i = 0; i < numPlayers; i++){
			//each player takes their turn in order
			
			if (players[i].retrieveJail() == 1 and players[i].retrieveCounter() < 3) {
				cout << "Player " << i+1 << ", you are in jail. You must roll a double to get out early or wait 3 turns." << endl;
				cout << "\n\nPress enter to roll the die.";
				cin.ignore(10000, '\n');
				bool criminalStatus = rollJail();
				if (criminalStatus) {
					players[i].updateJail(0);
					cout << "You rolled a double! You are released!" << endl;
				}
				else {
					players[i].updateJailcounter();
					string message;
					stringstream ss;
					ss << 3-players[i].retrieveCounter();
					ss >> message;
					if (message != "0") {
						cout << "You failed to roll a double. You must wait for " << message << " more turns." << endl;
					}
					else {
						cout << "You failed to roll a double. However, you have served your full sentence and have been released." << endl;
					}
					
				}
			}

			if (players[i].retrieveCounter() == 3){
				players[i].updateJail(0);
			}

			if (players[i].retrieveJail() == 0){
				cout << "\n\nPlayer " << i+1 << ", press enter to roll the die. ";
				cin.ignore(10000, '\n');
				int moves = rollDie();
				bool passGo = players[i].updateInfo(moves);
				board.updateSpaces(players, numPlayers);
				board.print_Board();
				cout << "Player " << i+1 << ", you advance " << moves << " spaces." << endl;
				
				cout << "\n\nBEGINNING STATISTICS: ";
				players[i].realPrint();
				spaces[0].realPrint(spaces, i+1);
				
				if (passGo){
					players[i].addMoney(50000);
					cout << "You passed go and received $50,000!" << endl;
				}

				int currentSpace = players[i].returnSpace();
				string actionText = spaces[currentSpace].retrieveAction();
				cout << actionText << endl;

				char purchaseStatus = spaces[currentSpace].retrievePurchased();
				//purchase choice for player who lands on purchasable space
				if (purchaseStatus == '0') {
					char decision;
					if (players[i].retrieveWealth() < spaces[currentSpace].retrieveBuy()) {
						cout << "You do not have enough money to purchase this." << endl;
					}

					else {
						do {
							cout << "Would you like to make this purchase? (Y/N): ";
							cin >> decision;
							cout << endl;

							if (cin.fail()){
								cin.clear();
								cin.ignore (10000, '\n');
								cout << "That is an invalid input." << endl;
								continue;
							}

							else if (decision != 'y' and decision !='Y' and decision !='n' and decision !='N') {
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Please enter Y/N." << endl;
								continue;
							}

							else{
								cin.ignore (10000, '\n');
								break;
							}

						} while (true);
					}
					

					if (decision == 'Y' or decision == 'y'){
						spaces[currentSpace].modify(i+1);
						int cost = spaces[currentSpace].retrieveBuy();
						players[i].deductMoney(cost);
						bank.addFunds(cost);
						players[i].updateProperty(currentSpace);
						cout << "You have purchased the space!" << endl;
						decision = 'N';
					}

				}//end of decision if statement

				//if player lands on space that is owned by another player, then the player must pay the rental fee.
				else if (purchaseStatus == '1' or purchaseStatus == '2' or purchaseStatus == '3' or purchaseStatus == '4') {
					int rental = spaces[currentSpace].retrieveRent();
					char owner = spaces[currentSpace].retrievePurchased();
					int iOwner = (owner - '0');
					iOwner--;

					if (i == iOwner) {
						cout << "Just kidding! This is your space!" << endl;
					}

					else if (players[i].retrieveWealth() < rental) {
						cout << "You do not have enough money to pay for the rental." << endl;
					}

					else {
						players[i].deductMoney(rental);
						players[iOwner].addMoney(rental);
						cout << "You have paid for the rental." << endl;

					}

				}//end of owned spaces else if statement

				else if (purchaseStatus == '7') {
					char decision;
					do {
						cout << "Would you like to pay $15,000 or 10% of your total assets (cash on hand, property and upgrades)? (M for $15,000 or A for assets): ";
						cin >> decision;
						cout << endl;

						if (cin.fail()){
							cin.clear();
							cin.ignore (10000, '\n');
							cout << "That is an invalid input." << endl;
							continue;
						}

						else if (decision != 'm' and decision !='M' and decision !='a' and decision !='A') {
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Please enter M/A." << endl;
							continue;
						}

						else{
							cin.ignore (10000, '\n');
							break;
						}

					} while (true);

					if (decision == 'M' or decision == 'm') {
						players[i].deductMoney(15000);
						bank.addFunds(15000);
						cout << "You have given $15,000 to the bank." << endl;
					}

					else if (decision == 'A' or decision == 'a') {
						int assets = 0;
						assets += players[i].retrieveWealth();
						for (int j = 0; j < 40; j++){
							if (players[i].retrieveProperty(j) == 1){
								assets += spaces[j].retrieveBuy();
							}
						}

						int tenPercent = assets*0.10;
						players[i].deductMoney(tenPercent);
						bank.addFunds(tenPercent);
						string output;
						stringstream ss;
						ss << tenPercent;
						ss >> output;
						cout << "You have given $" << output << " to the bank." << endl;
					}
				}//end of income tax


				//player must pay luxury tax
				else if (purchaseStatus == '8') {
					int luxTax = 7500;
					players[i].deductMoney(luxTax);
					bank.addFunds(luxTax);
					cout << "You have given $" << luxTax << " to the bank." << endl;
				}

				//if player lands on gotojail, player is sent to jail
				else if (purchaseStatus == '9') {
					players[i].updateInfo(20);
					players[i].updateJail(1);

				}//end of jail else if


			}
				
			cout << "\n\nEND STATISTICS:";
			players[i].realPrint();
			spaces[0].realPrint(spaces, i+1);
		}
	}

}