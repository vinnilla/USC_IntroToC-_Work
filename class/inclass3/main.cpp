//main.cpp

#include "servicechargechecking.h"
#include "noservicechargechecking.h"
#include "highinterestsavings.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int askForAccount(int counter) {
	int num;
	do {
		cout << "Enter your account number: ";
		cin >> num;
		cout << endl;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input." << endl;
			continue;
		}

		else if (num < 0 or num > counter) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "That is not a valid account number." << endl;
			continue;
		}

		else {
			return num;
		}

	}while (true)
}

int askForMoney() {
	int num;
	do {
		cout << "Enter the amount of money: ";
		cin >> num;
		cout << endl;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input." << endl;
			continue;
		}

		else if (num < 0) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "You cannot enter a negative number." << endl;
			continue;
		}

		else {
			return num;
		}

	}while (true)
}

int main () {
	vector <*BankAccount> accounts;
	char accountChoice;
	string name;
	int startbal;
	int counter = 0;
	int menuChoice;


	//prompt user for 5 accounts
	for (int i = 0; i < 5; i++){
		//prompt user for account type
		do {
			cout << "Choose the account type. You may choose between:
			\nA. Service Charge Checking Account
			\nB. No Service Charge Checking Account
			\nC. Normal Savings Account
			\nD. High Interest Savings Account.
			\nPlease enter the letter of the corresponding account you'd like to open!\n";
			cin >>  accountChoice;
			cout << endl;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input." << endl;
				continue;
			}

			else if (choice != 'A' or 'a' or 'B' or 'b' or 'C' or 'c' or 'D' or 'd') {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Enter a valid choice please." << endl;
				continue;
			}

			else {
				cin.ignore(10000, '\n');
				break;
			}

		} while(true);

		//prompt user for name
		do {
			cout << "Enter your name: "
			cin >> name;
			cout << endl;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input." << endl;
				continue;
			}

			else {
				cin.ignore (10000, '\n');
				break;
			}

		}while (true);

		//prompt user for starting balance
		do {
			cout << "Enter the starting balance: "
			cin >> startbal;
			cout << endl;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input." << endl;
				continue;
			}

			else {
				cin.ignore(10000, '\n');
				break;
			}

		}while (true);

		if (accountChoice == 'A' or 'a') {
			accounts.push_back(new ServiceChargeChecking(counter, name, startbal, accountChoice));
			counter++;
		}

		else if (accountChoice == 'B' or 'b') {
			accounts.push_back(new NoServiceChargeChecking(counter, name, startbal, accountChoice));
			counter++;
		}

		else if (accountChoice == 'C' or 'c') {
			accounts.push_back(new SavingsAccount(counter, name, startbal, accountChoice));
			counter++;
		}

		else if (accountChoice == 'D' or 'd') {
			accounts.push_back(new HighInterestSaving(counter, name, startbal, accountChoice));
			counter++;
		}

	}//end of for prompting user for 5 accounts
		
	do {
		cout << "Please choose from this menu of options.
		\n1. Display Balance
		\n2. Deposit Money
		\n3. Withdraw Money
		\n4. Write a Check
		\n5. Apply Month End Interest
		\n6. Quit Program\n";
		cin >> menuChoice;
		cout << endl;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input." << endl;
			continue;
		}

		else if (menuChoice != 1 or 2 or 3 or 4 or 5 or 6) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Please choose a valid option." << endl;
			continue;
		}


		else {
			cin.ignore(10000, '\n');
			
			if (menuChoice != 6) {
				int accountNumber = askForAccount(counter);
			}
			
			if (menuChoice == 1){
				cout << "Balance: " << accounts[accountNumber].retrieveBalance(); << endl;
			}

			else if (menuChoice == 2) {
				int monies = askForMoney();
				accounts[accountNumber].deposit(monies);
				cout << "$" << monies << " has been deposited." << endl;
			}

			else if (menuChoice == 3) {
				cout << "Under Construction" << endl;
			}

			else if (menuChoice == 4) {
				cout << "Under Construction" << endl;
			}

			else if (menuChoice == 5) {
				accounts[accountNumber].monthEnd();
				cout << "Month End Interest has been applied."<< endl;
			}

			else if (menuChoice == 6) {
				cout << "Thank you for using the bank program!" << endl;
			}
		}


	}while (menuChoice != 6);

	return 0;
}// end of main