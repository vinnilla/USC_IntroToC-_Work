#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>

using namespace std;

int main() {
	struct Team {
		string Name;
		int Wins;
		int Losses;
	};

//1

	string filename;
	do {
		cout << "Enter the file name: ";
		cin >> filename;
		cout << endl;

		if (cin.fail()){
			cin.clear();
			cin.ignore (10000, '\n');
			cout << "That is an invalid file name." << endl;
			continue;
		}
		else{
			cin.ignore (10000, '\n');
			break;
		}

	} while (true);

//2

	Team *Teams;
	string Part2;
	int counter = 0;

	istringstream ifile(filename);
	if (ifile.fail()){
		cout << "The file could not be opened. " << endl;
		return 0;
	}

	do {
		Teams = new Team[1];
		ifile >> Teams[counter].Name;
		ifile >> Part2;
		Teams[counter].Name += Part2;
		ifile >> Teams[counter].Wins;
		ifile >> Teams[counter].Losses;
		counter++;
	} while (Teams[counter].Name != "\n");
	counter --;


//3
	string TempName;
	int TempWin;
	int TempLoss;
	int Runs = 0;

	do {
		for (int i = 0; i < counter; i++){
			Runs = 0;
			if (Teams[i].Wins < Teams[i+1].Wins){
				TempName = Teams[i].Name;
				TempWin = Teams[i].Wins;
				TempLoss = Teams[i].Losses;
				Teams[i].Name = Teams[i+1].Name;
				Teams[i].Wins = Teams[i+1].Wins;
				Teams[i].Losses = Teams[i+1].Losses;
				Teams[i+1].Name = TempName;
				Teams[i+1].Wins = TempWin;
				Teams[i+1].Losses = TempLoss;
				Runs++;
			}
		}
	} while (Runs !=0);

	for (int i = 0; i < counter; i++) {
		cout << Teams[i].Name << " " << Teams[i].Wins << " " << Teams[i].Losses << endl;
	}


//4
	string TeamName;
	cout << "Enter the team name: ";
	cin >> TeamName;
	cout << endl;
	bool Status = true;

	while (TeamName != "\0") {
		for (int i = 0; i < counter; i++){
			if (TeamName == Teams[i].Name){
				cout << "Wins: " << Teams[i].Wins << endl;
				cout << "Losses: " << Teams[i].Losses << endl;
				Status = false;
			}
		}

		if (Status){
			cout << "No such team exists." << endl;
		}
	}


//5
	int TotalWins = 0;
	int TotalLosses = 0;

	for (int i = 0; i < counter; i++){
		TotalWins += Teams[i].Wins;
		TotalLosses += Teams[i].Losses;
	}

	cout << "Wins: " << TotalWins << " Losses: " << TotalLosses << endl;

	
	for (int i = 0; i < counter+1; i++)
		delete [] Teams;
		
	return 0;
}



