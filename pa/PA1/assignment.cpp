#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip> 

using namespace std;


void deckCreation (int Values[], char Suits[], int deck) {		//This function is the deck creation function. It will create up to 5 decks.
	for (int i=0; i<4*deck; i++) {					
		for (int j=0; j<13; j++) {
			Values [i*13+j] = j+2;
			if (i%4 == 0) {
				for (int y=0; y<13; y++) {
					Suits[i*13+y] = 'h';
				}//end of for
			}//end of if
			else if (i%4 == 1) {
				for (int y=0; y<13; y++) {
					Suits[i*13+y] = 'c';
				}//end of for
			}//end of else if
			else if (i%4 == 2) {
				for (int y=0; y<13; y++) {
					Suits[i*13+y] = 's';
				}//end of for
			}//end of else if
			else if (i%4 == 3) {
				for (int y=0; y<13; y++) {
					Suits[i*13+y] = 'd';
				}//end of for
			}//end of else if
		}//end of nested for
	}//end of for
	return;
}//end of deckCreation function

void shuffle (int Values[], char Suits[], int deck) {		//This is the shuffle function. 
	int a = rand() % 52*deck;
	int b = (rand() % 51*deck)+1;
	int c = (rand() % 50*deck)+2;
	int d = (rand() % 49*deck)+3;
	int tempValue = Values[a];
	char tempSuit = Suits[a];
	Values[a] = Values[b];
	Suits[a] = Suits[b];
	Values[b] = Values[c];
	Suits[b] = Suits[c];
	Values[c] = Values[d];
	Suits[c] = Suits[d];
	Values[d] = tempValue;
	Suits[d] = tempSuit;
	return;


}//end of shuffle function

string p1words (int P1currentcard, string P1cardword) {		//This function serves to replace integer values for cards in deck 1 with words (11 -> Jack)

	if (P1currentcard == 1) {
		P1cardword = "1";
	}
	
	else if (P1currentcard == 2) {
		P1cardword = "2";
	}
	
	else if (P1currentcard == 3) {
		P1cardword = "3";
	}
	
	else if (P1currentcard == 4) {
		P1cardword = "4";
	}
	
	else if (P1currentcard == 5) {
		P1cardword = "5";
	}
	
	else if (P1currentcard == 6) {
		P1cardword = "6";
	}
	
	else if (P1currentcard == 7) {
		P1cardword = "7";
	}
	
	else if (P1currentcard == 8) {
		P1cardword = "8";
	}
	
	else if (P1currentcard == 9) {
		P1cardword = "9";
	}
	
	else if (P1currentcard == 10) {
		P1cardword = "10";
	}

	else if (P1currentcard == 11) {
		P1cardword = "Jack";
	}
	
	else if (P1currentcard == 12) {
		P1cardword = "Queen";
	}
	
	else if (P1currentcard == 13) {
		P1cardword = "King";
	}

	else if (P1currentcard == 14) {
		P1cardword = "Ace";
	}
	
	return P1cardword;
}

string p2words (int P2currentcard, string P2cardword) {		//This function serves to replace integer values for cards in deck 2 with words (11 -> Jack)


	if (P2currentcard == 1) {
		P2cardword = "1";
	}
	
	else if (P2currentcard == 2) {
		P2cardword = "2";
	}
	
	else if (P2currentcard == 3) {
		P2cardword = "3";
	}
	
	else if (P2currentcard == 4) {
		P2cardword = "4";
	}
	
	else if (P2currentcard == 5) {
		P2cardword = "5";
	}
	
	else if (P2currentcard == 6) {
		P2cardword = "6";
	}
	
	else if (P2currentcard == 7) {
		P2cardword = "7";
	}
	
	else if (P2currentcard == 8) {
		P2cardword = "8";
	}
	
	else if (P2currentcard == 9) {
		P2cardword = "9";
	}
	
	else if (P2currentcard == 10) {
		P2cardword = "10";
	}

	else if (P2currentcard == 11) {
		P2cardword = "Jack";
	}
	
	else if (P2currentcard == 12) {
		P2cardword = "Queen";
	}
	
	else if (P2currentcard == 13) {
		P2cardword = "King";
	}

	else if (P2currentcard == 14) {
		P2cardword = "Ace";
	}
	return P2cardword;
}

string p1suitword (int P1currentsuit, string P1suitword) {		//This function serves to replace single character values for cards in deck 1 with words (c -> Clubs)


	if (P1currentsuit == 'c') {
		P1suitword = "Clubs";
	}
	
	else if (P1currentsuit == 'd') {
		P1suitword = "Diamonds";
	}

	else if (P1currentsuit == 's') {
		P1suitword = "Spades";
	}
	
	else if (P1currentsuit == 'h') {
		P1suitword = "Hearts";
	}

	return P1suitword;
}

string p2suitword (int P2currentsuit, string P2suitword) {		//This function serves to replace single character values for cards in deck 2 with words (c -> Clubs)

	if (P2currentsuit == 'c') {
		P2suitword = "Clubs";
	}
	
	else if (P2currentsuit == 'd') {
		P2suitword = "Diamonds";
	}

	else if (P2currentsuit == 's') {
		P2suitword = "Spades";
	}
	
	else if (P2currentsuit == 'h') {
		P2suitword = "Hearts";
	}

	return P2suitword;
}


int main () {		//main function
	srand(time(NULL));	//randomizes the pool for rand() which is used in the shuffle function

	int deck = 0;		//initialize counter for number of decks
	
	do {	
		cout << "How many decks are being used? (max 5) ";
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

	char watching = ' ';		//initialize variable for watching
	
	do {	
		cout << "Would you like to watch the game (y for yes, n for no)? ";
		cin >> watching;
		cout << endl;

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

	int cardValues[52*deck];		//initialize array for the numbers of the decks
	char cardSuits[52*deck];		//initialize array for the suits of the decks
	
	deckCreation (cardValues, cardSuits, deck);
	
	
	for (int x=0; x<1000; x++) { 					//shuffle
		shuffle (cardValues, cardSuits, deck); 
	}//end of for loop 

	int half = (261);	

	int P1value [half];		//initialize arrays for the 2 decks for the 2 players
	char P1suit [half];
	int P2value[half];
	char P2suit[half];


	int countera = 0;
	int counterb = 0;

	for (int i=0; i<13*deck; i++) { 					//split the deck
		P1value[countera] = cardValues[i];
		P1suit[countera] = cardSuits[i];
		countera++;	
	}

	for (int i=13*deck; i<26*deck; i++) {
		P2value[counterb] = cardValues[i];
		P2suit[counterb] = cardSuits[i];
		counterb++;
	}

	for (int i=26*deck; i<39*deck; i++) {
		P2value[counterb] = cardValues[i];
		P2suit[counterb] = cardSuits[i];
		counterb++;
	}

	for (int i=39*deck; i<52*deck; i++) {
		P1value[countera] = cardValues[i];
		P1suit[countera] = cardSuits[i];
		countera++;
	}


	string P1cardword = " ";		//initialize variables for words -- serves as the output for the 'words' functions that transform single characters in words
	string P2cardword = " ";
	string P1suitword = " ";
	string P2suitword = " ";

	int tempcard = 0;
	char tempsuit = ' ';
	int P1counter = 26*deck;						//set up counter for statistics
	int P2counter = 26*deck;
	int HandNum = 0;
	int P1wins = 0;
	int P2wins = 0;
	int WarHands = 0;
	int P1wars = 0;
	int P2wars = 0;
	int P1currentcard = 0;
	char P1currentsuit = ' ';
	int P2currentcard = 0;
	char P2currentsuit = ' ';
	int warspoilscard[52*deck];
	char warspoilssuit[52*deck];
	int warspoilscounter = 0;
	bool truth = true;


	while (P1counter != 0 and P2counter !=0) {		//while loop that runs the game

		HandNum++;
		if (watching == 'y') {		//output only if user requested yes for watching
			cout << "Player 1 now has " << P1counter << " cards." << endl;
			cout << "Player 2 now has " << P2counter << " cards." << endl;
			cout << "\n------------------------------\n";
			cout << "Hand #" << HandNum << endl;
		}

		P1currentcard = P1value[0];					//save value of top cards from both decks
		P1currentsuit = P1suit[0];
		P2currentcard = P2value[0];
		P2currentsuit = P2suit[0];
		warspoilscounter = 0;
		
		P1cardword = p1words(P1currentcard, P1cardword);		//set up variables for output
		P1suitword = p1suitword(P1currentsuit, P1suitword);
		P2cardword = p2words(P2currentcard, P2cardword);
		P2suitword = p2suitword(P2currentsuit, P2suitword);
	
		if (watching == 'y') {
			cout << "Player 1: " << P1cardword << " of " << P1suitword << endl;
			cout << "Player 2: " << P2cardword << " of " << P2suitword << endl;
		}	

		for (int i = 1; i < P1counter; i++) {					//Move cards up in each deck		
			P1value[i-1] = P1value[i];
			P1suit[i-1] = P1suit[i];
		}
		P1counter--;

		for (int i = 1; i < P2counter; i++) {		
			P2value[i-1] = P2value[i];
			P2suit[i-1] = P2suit[i];
		}
		P2counter--;


		if (P1currentcard > P2currentcard) {					//what happens when P1 Wins!
			P1value[P1counter] = P2currentcard;
			P1suit[P1counter] = P2currentsuit;
			P1counter++;
			P1value[P1counter] = P1currentcard;
			P1suit[P1counter] = P1currentsuit;
			P1counter++;
			if (watching == 'y') {
				cout << "Player 1 wins.\n" << endl;
			}
		P1wins ++;
		}//end of if
	
		else if (P2currentcard > P1currentcard) {				//what happens when P2 Wins!
			P2value[P2counter] = P1currentcard;
			P2suit[P2counter] = P1currentsuit;
			P2counter++;
			P2value[P2counter] = P2currentcard;
			P2suit[P2counter] = P2currentsuit;
			P2counter++;
			if (watching == 'y') {
				cout << "Player 2 wins.\n" << endl;
			}
		P2wins ++;
		}//end of else if

		else if (P1currentcard == P2currentcard) {				//what happens when a tie occurs. WAR!
			bool status = true;			
			while (status) {					//while loop keeps the game in war mode if multiple ties occur
				if (watching == 'y') {		
					cout << "\nWar!\n" << endl;
				}
				if (P1counter < 4) {		//automatic win for player 2 if player 1 does not have enough cards to participate in war
					if (watching == 'y') {
						cout << "Player 1 does not have enough cards to participate in the war." << endl;
						cout << "\nPlayer 1 forfeits the war.\n";
					}
				P2wins++;
				P2wars++;
				P1counter = 0;
				status = false;
				continue;
				}

				if (P2counter < 4) { //auto win for player 1
					if (watching == 'y') {
						cout << "Player 2 does not have enough cards to participate in the war." << endl;
						cout << "\nPlayer 2 forfeits the war.\n";
					}
				P1wins++;
				P1wars++;
				P2counter = 0;
				status = false;
				continue;
				}

				warspoilscard[warspoilscounter] = P1currentcard;		//place the two tied cards into another array that keeps track of all the cards
				warspoilssuit[warspoilscounter] = P1currentsuit;
				warspoilscounter ++;
				warspoilscard[warspoilscounter] = P2currentcard;
				warspoilssuit[warspoilscounter] = P2currentsuit;
				warspoilscounter ++;

				for (int f = 0; f < 3; f++) {			//this represents the discarding of the next three cards from both players
			
					P1currentcard = P1value[0];		//takes the values of the next cards
					P1currentsuit = P1suit[0];
					P2currentcard = P2value[0];
					P2currentsuit = P2suit[0];		

			
					for (int i = 1; i < P1counter; i++) {					//Move cards up in each deck		
						P1value[i-1] = P1value[i];
						P1suit[i-1] = P1suit[i];
					}
					P1counter--;

					for (int i = 1; i < P2counter; i++) {		
						P2value[i-1] = P2value[i];
						P2suit[i-1] = P2suit[i];
					}
					P2counter--;
	
					warspoilscard[warspoilscounter] = P1currentcard;		//places cards into war array
					warspoilssuit[warspoilscounter] = P1currentsuit;
					warspoilscounter ++;
					warspoilscard[warspoilscounter] = P2currentcard;
					warspoilssuit[warspoilscounter] = P2currentsuit;
					warspoilscounter ++;


		
				}//end of for 
		
				if (watching == 'y') {
					cout << "Player 1 places 3 cards down.\nPlayer 2 places 3 cards down.\n" << endl;	
				}


				P1currentcard = P1value[0]; //takes value of the fourth card from each player -- this is the one that will determine who will win the war
				P1currentsuit = P1suit[0];
				P2currentcard = P2value[0];
				P2currentsuit = P2suit[0];

				P1cardword = p1words(P1currentcard, P1cardword);		//prepare variables for output
				P1suitword = p1suitword(P1currentsuit, P1suitword);
				P2cardword = p2words(P2currentcard, P2cardword);
				P2suitword = p2suitword(P2currentsuit, P2suitword);

				for (int i = 1; i < P1counter; i++) {					//Move cards up in each deck		
					P1value[i-1] = P1value[i];
					P1suit[i-1] = P1suit[i];
				}
				P1counter--;

				for (int i = 1; i < P2counter; i++) {		
					P2value[i-1] = P2value[i];
					P2suit[i-1] = P2suit[i];
				}
				P2counter--;

				if (watching == 'y') {		//output
					cout << "Player 1: " << P1cardword << " of " << P1suitword << endl;
					cout << "Player 2: " << P2cardword << " of " << P2suitword << endl;
				}

						//Decide who wins

				if (P1currentcard > P2currentcard) {					//P1 Wins!
					for (int i = 0; i < warspoilscounter; i++) {				
						P1value[P1counter] = warspoilscard[i];
						P1suit[P1counter] = warspoilssuit[i];
						P1counter++;
					}
					P1value[P1counter] = P2currentcard;
					P1suit[P1counter] = P2currentsuit;
					P1counter++;
					P1value[P1counter] = P1currentcard;
					P1suit[P1counter] = P1currentsuit;
					P1counter++;

					if (watching == 'y') {
						cout << "Player 1 wins.\n" << endl;
	

					}

					P1wins ++;
					P1wars ++;
					status = false;
				}//end of if
	
				else if (P2currentcard > P1currentcard) {				//P2 Wins!
					for (int i = 0; i < warspoilscounter; i++) {				
						P2value[P2counter] = warspoilscard[i];
						P2suit[P2counter] = warspoilssuit[i];
						P2counter++;
					}

					P2value[P2counter] = P1currentcard;
					P2suit[P2counter] = P1currentsuit;
					P2counter++;
					P2value[P2counter] = P2currentcard;
					P2suit[P2counter] = P2currentsuit;
					P2counter++;

					if (watching == 'y') {
						cout << "Player 2 wins.\n" << endl;
					}

					P2wins ++;
					P2wars ++;
					status = false;
				}//end of else if

				else{		//tie. status remains true and the game remains in the while loop
					status = true;
				}
			}//end of while
			WarHands ++;
		}//end of war else if statement

	}//end of while!!!
	
	cout << "---------------------------\n" << endl;
	if (P1counter == 0) {
		cout << "Player 2 WINS the game!\n" << endl;
	}
	else if (P2counter == 0) {
		cout << "Player 1 WINS the game!\n" << endl;
	}
	cout << "---------------------------\n" << endl;

	double P1winspercent = 100.0*P1wins/HandNum;		//statistics calculations
	double P2winspercent = 100.0*P2wins/HandNum;
	double P1warspercent = 100.0*P1wars/WarHands;
	double P2warspercent = 100.0*P2wars/WarHands;
	double Warhandspercent = 100.0*WarHands/HandNum;

	cout << "Statistics\n" << endl;
	cout << "Number of Hands: " << HandNum << endl;
	cout << fixed;
	cout << "Number of Hands Player 1 Won: " << P1wins << " (" << setprecision(1) << P1winspercent << "%" << ")" << endl;
	cout << "Number of Hands Player 2 Won: " << P2wins << " (" << setprecision(1) << P2winspercent << "%" << ")" << endl;
	cout << "Number of War Hands: " << WarHands << " (" << setprecision(1) << Warhandspercent << "%" << ")" << endl;
	cout << "Number of War Hands Player 1 Won: " << P1wars << " (" << setprecision(1) << P1warspercent << "%" << ")" << endl;
	cout << "Number of War Hands Player 2 Won: " << P2wars << " (" << setprecision(1) << P2warspercent << "%" << ")" << endl;

return 0;

}//end of main

