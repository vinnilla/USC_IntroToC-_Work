#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct menu {
	string menu_item_name;
	float price;
	int number_ordered;
};

//initialize array that is to be dynamically allocated later
menu* Menu;

int counter = 0;


void displayMenu() {
	int item;
	do {
		cout << setw(24) << left << "Item: " << setw(10) << "Price: " << endl;
			for (int i = 0; i < counter; i++) {
				cout << setw(4) << i+1 << setw(20) << Menu[i].menu_item_name << setw(10) << Menu[i].price << endl;
			}
		cout << "Please enter the number of the item you'd like to order (0 if you're done): ";
		cin >> item;
		cout << endl;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "You have entered an invalid item number." << endl;
			continue;
		}
		
		cin.ignore (10000, '\n');
		if (item > counter) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "That item does not exist." << endl;
			continue;
		}

		else if (item = 0) {
			break;
		}
		
		else {
			Menu[item-1].number_ordered++;
			continue;
		}

	} while (item > 0); 

}

int main() {
	//1 open file
	string filename;
	do {
		cout << "Please enter the name of the file that you'd like to use: ";
		cin >> filename;
		cout << endl;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "You have entered an invalid filename." << endl;
			continue;
		}
		
		cin.ignore (10000, '\n');
		ifstream ifile (filename.c_str());
		if (ifile.fail()) {
			cin.clear();
			cout << "The file cannot be opened." << endl;
			continue;
			ifile.close();
		}
		else {
			ifile.close();
			break;
		}

	} while (true); 

	//2 read file and populate array
	string line;
	string lines[100];


	ifstream ifile(filename.c_str());

	getline(ifile, line);
	lines[counter] = line;
	counter++;
	getline(ifile,line);

	while (line != lines[counter-1]) {

		lines[counter] = line;
		counter++;
		getline (ifile, line);
	}

	Menu = new menu[counter];
	int temp;
	int length;
	string tempname;
	string tempcost;

	for (int i = 0; i < counter; i++) {
		temp = lines[i].find('|');
		length = lines[i].size();
		lines[i].erase(temp, 1);
		tempname = lines[i].substr (0, temp-1);
		tempcost = lines[i].substr (temp, length);
		Menu[i].menu_item_name = tempname;
		stringstream ss;
		ss << tempcost;
		ss >> Menu[i].price;
		Menu[i].number_ordered = 0;
	}

	displayMenu();


	delete [] Menu;
	return 1;
}//end of main