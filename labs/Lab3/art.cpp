#include <iostream>

using namespace std;

int main() {
	int rows = 0;
	cout << "Number of rows: ";
	cin >> rows;
	cout << endl;
	
	for (int r=1; r<rows+1; r++) {
		for (int i = 0; i<r; i++) {
			cout << "*";
		} //end of nested for
	cout << endl;
	} //end of for
} //end of main
