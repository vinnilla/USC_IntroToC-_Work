#include <iostream>
using namespace std;

int main()
{
	char y[80];
  int x;

do {
  cout << "Enter some text: " << endl;
  cin.getline  (y, 80);

	if (cin.fail()) {
		cin.clear(); //reset cin.fail to false
		cin.ignore(10000, '\n'); //clear cin
		cout << "You entered a bad value\n";
		continue; //sends you to while so that it loops back into the do loop
	} //end of cin.fail if statement	

		//user entered a line
		cout << "Good you entered: " << y << endl;	
		break; //escape do loop
} while(true);

do {
  cout << "Enter an integer: " << endl;
  cin >> x;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "You entered a bad value\n";
		continue;
	} //end of cin.fail if statement	
		//user entered an integer
		cin.ignore( 10000, '\n'); //clear cin of any extraneous characters
		cout << "Good you entered: " << x << endl;	
		break;	
} while(true);

 return 0;
}
