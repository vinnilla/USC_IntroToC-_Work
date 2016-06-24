#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void deckCreation (int Values[], char Suits[], int deck) {
	for (int i=0; i<4*deck; i++) {					//create the deck
		for (int j=0; j<13; j++) {
			Values [i*13+j] = j+2;
			if (i == 0 or i == 4 or i == 8 or i == 12 or i == 16) {
				for (int y=0; y<13; y++) {
					Suits[i*13+y] = 'h';
				}//end of for
			}//end of if
			else if (i == 1 or i == 5 or i == 9 or i == 13 or i == 17) {
				for (int y=0; y<13; y++) {
					Suits[i*13+y] = 'c';
				}//end of for
			}//end of else if
			else if (i == 2 or i == 6 or i == 10 or i == 14 or i == 18) {
				for (int y=0; y<13; y++) {
					Suits[i*13+y] = 's';
				}//end of for
			}//end of else if
			else if (i == 3 or i == 7 or i == 11 or i == 15 or i == 19) {
				for (int y=0; y<13; y++) {
					Suits[i*13+y] = 'd';
				}//end of for
			}//end of else if
		}//end of nested for
	}//end of for
	return;
}//end of deckCreation function

void shuffle (int Values[], char Suits[], int deck) {
	int a = rand() % 52*deck;
	int b = rand() % 52*deck;
	int tempValue = Values[a];
	char tempSuit = Suits[a];
	Values[a] = Values[b];
	Suits[a] = Suits[b];
	Values[b] = tempValue;
	Suits[b] = tempSuit;
	return;

}//end of shuffle function

int main () {
	int deck = 0;
	
	do {	
		cout << "How many decks are being used?";
		cin >> deck;

		if (cin.fail()) {
			cin.clear(); //reset cin.fail to false
			cin.ignore(10000, '\n'); //clear cin
			cout << "You entered a bad value\n";
			continue; //sends you to while so that it loops back into the do loop
		} //end of cin.fail if statement	

		//user entered an integer
		cin.ignore( 10000, '\n'); //clear cin of any extraneous characters
		break;

	} while(true);

	char watching = ' ';
	
	do {	
		cout << "Would you like to watch the game (y for yes, n for no)?";
		cin >> watching;

		if (cin.fail()) {
			cin.clear(); //reset cin.fail to false
			cin.ignore(10000, '\n'); //clear cin
			cout << "You entered a bad value.\n";
			continue; //sends you to while so that it loops back into the do loop
		} //end of cin.fail if statement	

		//user entered a letter
		cin.ignore( 10000, '\n'); //clear cin of any extraneous characters
		if (watching == 'y' or watching == 'n') {
			break;
		}
		else {
			cout << "You entered an invalid character.\n";
			continue;
		}

	} while(true);


	
	int cardValues[52*deck];
	char cardSuits[52*deck];
	int cards = 52*deck;
	
	deckCreation (cardValues, cardSuits, deck);

	int P1value [26*deck];
	char P1suit [26*deck];
	int P2value[26*deck];
	char P2suit[26*deck];
	

	for (int i=0; i<26*deck; i++) { 					//split the deck
		P1value[i] = cardValues[i];
		P1suit[i] = cardSuits[i];
	}

	int counter = 0;
	for (int i=26*deck; i<52*deck; i++) {
		P2value[counter] = cardValues[i];
		P2suit[counter] = cardSuits[i];
		counter++;
	}

	
	for (int i = 0; i < 26*deck; i++){
		cout << P1value[i] << P1suit[i] << endl;
		cout << P2value[i] << P2suit[i] << endl;
	}

return 0;
}
