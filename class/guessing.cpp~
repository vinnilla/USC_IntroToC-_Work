#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	srand(time(0));
	int secretNum = rand() % 20;
	int guess;
	char userEntry;
	
	while (true) {	
	userEntry = 'n'	
		for (int i=0; i<5; i++) {
			cout << "Guess a number between 0 and 19: ";
			cin >> guess;
			cout << endl;

			if (guess > secretNum) {
				cout << "The number is too high." << endl;
			} else if (guess < secretNum) {
				cout << "The number is too low." << endl;
			} else {
				cout << "Your guess is correct!" << endl;
				
				cout << "Do you want to play again? 'y' to play again.\n";
				cin >> userEntry;
				if (userEntry == 'y'){
				break;
				} else {
				return 0;
				}
			}
		}	
		if (userEntry == 'y') {
		continue;
		}
		cout << "You lost." << endl;
		return 0;
	}
	return 0;	
}
