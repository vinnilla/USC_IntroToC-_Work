/* This program is designed to determine if a natural number has 2 or 3 as prime factors. If the number does have 2 or 3 as prime factors, the program will count how many of each it has.
*/

#include <iostream>

using namespace std;

int main() {
int twos = 0;
int threes = 0;
int num;

	//Prompt user for natural number
	cout << "Enter any natural number: ";
	cin >> num;
	cout << endl;
	
	//Use loops to process prime factors
	while (true) {
		if (num%3 == 0) {
			threes ++;
			num /= 3;
			continue;
		}//end of if statement
		else if (num%2 == 0) {
			twos ++;
			num /= 2;
			continue;
		}//end of else if statement
	break;
	} //end of while loop

	//Print solution
	if (twos > 0 or threes > 0) {
		cout << "Yes" << endl;
		cout << "Twos = " << twos << ", Threes = " << threes << endl;
	}//end of if statement
	else {
		cout << "No" << endl;	
	}
return 0;
} //end of main function
