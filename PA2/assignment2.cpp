/*
Pseudo Code:
8 team football 1 round elimination bracket

functions:
ReadFile - read the input file and extract the information
	remember to check to see if format is correct, otherwise terminate program and tell user that file is not formatted correctly

TeamAssignments - randomly assign teams to play

PrintBracket - display the current bracket

Touchdown - touchdown probability using random number between 0 and 1
	if number is less than probability, team scores
	if number is greater, team doesn't score

Fieldgoal - fieldgoal probability using random number between 0 and 1

PlaybyPlay - if user wants to watch, generate the play by play
	otherwise, just display who wins with the score and the game number

TouchdownTable - touchdown statistics for each team at the end of the conference

FieldgoalTable - fieldgoal statistics for each team at the end of the conference
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip> 
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;

// Define arrays
char teamArray[8][40];
char tdArray[8][10];
char fgArray[8][10];

bool Playing2[8];
bool Playing3[8];

// Define global variables

char Game1[40] = "Game 1 W";
char Game2[40] = "Game 2 W";
char Game3[40] = "Game 3 W";
char Game4[40] = "Game 4 W";
char Game5[40] = "Game 5 W";
char Game6[40] = "Game 6 W";

//Statistics for charts
int Tdcounter[8][3]; 
int Fgcounter[8][3];
int Tdattemptcounter[8][3];
int Fgattemptcounter[8][3];
float Totaltd[8] = {0};
float Totaltdattempt[8] = {0};
float Totalfg[8] = {0};
float Totalfgattempt[8] = {0};
float Tdperc[8] = {0};
float Fgperc[8] = {0};
float Difftd[8] = {0};
float Difffg[8] = {0};

int TotalDown[4] = {0};
int TotalAttDown[4] = {0};
int TotalGoal[4] = {0};
int TotalAttGoal[4] = {0};
float TotalDiff[2] = {0};

//Zero Entire Array
void Zero (int Array[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int col = 0; col< 8; col++)
		{
			Array[i][col] = 0;
		}
	}
}

// ReadFile function
void ReadFile(char* inputfile)
{
	char line[80];
	char * token;
	char temp[10];
	int number;

	ifstream file(inputfile);

	//check file
	if (file.fail())
	{
		cout << "There was a problem reading the file. The program will now close.\n" << endl;
		exit(1);
	}

	for (int i = 0; i < 8; i++)
	{
		file.getline(line, 80);
		token = strtok (line, " ,");

		strncpy (teamArray[i], line, sizeof(teamArray[i]));
		token = strtok (NULL, " ,");


		if (token[0] == '0' or token[0] == '1')
		{
			strncpy (tdArray[i], token, sizeof(tdArray[i]));
		}
		else
		{
			cout << "The file is not formatted correctly. The program will now close.\n";
			exit(1);
		}

		token = strtok (NULL, " ,");

		if (token[0] == '0' or token[0] == '1')
		{
			strncpy (fgArray[i], token, sizeof(fgArray[i]));
		}
		else
		{
			cout << "The file is not formatted correctly. The program will now close.\n";
			exit(1);
		}

		token = strtok (NULL, " ,");


	}

	file.close();
	return;
} // end of ReadFile()

void TeamAssignment()
{
	int a = rand() % 8;
	int b = rand() % 8;
	char tempTeam[40];
	char temptd[5];
	char tempfg[5];

	strncpy (tempTeam, teamArray[a], sizeof(teamArray[a]));
	strncpy (temptd, tdArray[a], 4);
	strncpy (tempfg, fgArray[a], 4);

	strncpy (teamArray[a], teamArray[b], sizeof(teamArray[a]));
	strncpy (tdArray[a], tdArray[b], 4);
	strncpy (fgArray[a], fgArray[b], 4);

	strncpy (teamArray[b], tempTeam, sizeof(teamArray[b]));
	strncpy (tdArray[b], temptd, 4);
	strncpy (fgArray[b], tempfg, 4);

	return;
	
} //end of TeamAssignment()

void PrintBracket()
{
	cout << "-------------" << endl;
	cout << "|  " << setw(9) << left << teamArray[0] << "|" << endl;
	cout << "|  GAME 1   |----|" << endl;
	cout << "|  " << setw(9) << left << teamArray[1] << "|    |    -------------" << endl;
	cout << "-------------    |    |  " << setw(9) << left << Game1 << "|" << endl;
	cout << setw(17) << " " << "|----|  GAME 5   " << "|----|" << endl;
	cout << "-------------    |    |  " << setw(9) << left << Game2 << "|    |" << endl;
	cout << "|  " << setw(9) << left << teamArray[2] << "|    |    -------------    |" << endl;
	cout << "|  GAME 2   " << "|----|" << setw(21) << " " << "|" << endl;
	cout << "|  " << setw(9) << left << teamArray[3] << "|" << setw(26) << " " << "|    -------------" << endl;
	cout << "-------------" << setw(26) << " " << "|----|  " << setw(9) << left << Game5 << "|" << endl;
	cout << setw(39) << " " << "|----|  GAME 7   " << "|" << endl;
	cout << "-------------" << setw(26) << " " << "|    |  " << setw(9) << left << Game6 << "|" << endl;
	cout << "|  " << setw(9) << left << teamArray[4] << "|" << setw(26) << " " << "|    -------------" << endl;
	cout << "|  GAME 3   " << "|----|" << setw(21) << " " << "|" << endl;
	cout << "|  " << setw(9) << left << teamArray[5] << "|    |    -------------    |" << endl;
	cout << "-------------    |    |  " << setw(9) << left << Game3 << "|    |" << endl;
	cout << setw(17) << " " << "|----|  GAME 6   " << "|----|" << endl;
	cout << "-------------    |    |  " << setw(9) << left << Game4 << "|" << endl;
	cout << "|  " << setw(9) << left << teamArray[6] << "|    |    -------------" << endl;
	cout << "|  GAME 4   " << "|----|" << endl;
	cout << "|  " << setw(9) << left << teamArray[7] << "|" << endl;
	cout << "-------------" << endl;
}// end of PrintBracket()

int Score(int number)
{	
	double touchdown = atof (tdArray[number]);
	double fieldgoal = atof (fgArray[number]);

	double num = ((double) rand()/(RAND_MAX));
	if (touchdown > num)
	{
		return 7;
	}
	else
	{
		double num2 = ((double) rand()/(RAND_MAX));
		if (fieldgoal > num2)
		{
			return 3;
		}
	}
return 0;
}//end of Score()
	
int Game(int team1, int team2, int game, char watch, int round)
{
	int team1p = 0;
	int team2p = 0;
	int points = 0;
	int quarter = 1;
	int overtime = 1;
	int Gamewinner;

	cout << "\n\n\n\nGame " << game << " - " << teamArray[team1] << " vs " << teamArray[team2] << "\n-----" << endl;


	while (quarter < 5)
	{ 
		points = Score(team1);
		team1p += points;
	
				if (points == 7)
				{
					Tdcounter[team1][round-1]++;
					Tdattemptcounter[team1][round-1]++;
				}
				else if (points == 3)
				{
					Fgcounter[team1][round-1]++;
					Tdattemptcounter[team1][round-1]++;
					Fgattemptcounter[team1][round-1]++;
				}
				else
				{
					Tdattemptcounter[team1][round-1]++;
					Fgattemptcounter[team1][round-1]++;
				}

		if (watch == 'y')
		{
			cout << "\nQUARTER " << quarter << endl;
			cout << teamArray[team1] << " ball - ";
			if (points == 7)
			{
				cout << "TOUCHDOWN" << endl;
			}
			else if (points == 3)
			{
				cout << "FIELD GOAL" << endl;
			}
			else
			{
				cout << "NO SCORE" << endl;
			}


			cout << team1p << "-" << team2p << " ";
			if (team1p > team2p)
			{
				cout << teamArray[team1] << endl;
			}
			else if (team2p > team1p)
			{
				cout << teamArray[team2] << endl;
			}
			else
			{
				cout << "Tie" << endl;
			}
		}//end of if
	// other team's ball

		points = Score(team2);
		team2p += points;

			if (points == 7)
			{
				Tdcounter[team2][round-1]++;
				Tdattemptcounter[team2][round-1]++;
			}
			else if (points == 3)
			{
				Fgcounter[team2][round-1]++;
				Tdattemptcounter[team2][round-1]++;
				Fgattemptcounter[team2][round-1]++;
			}
			else
			{
				Tdattemptcounter[team2][round-1]++;
				Fgattemptcounter[team2][round-1]++;
			}

		if (watch == 'y')
		{		
			cout << teamArray[team2] << " ball - ";
			if (points == 7)
			{
				cout << "TOUCHDOWN" << endl;
			}
			else if (points == 3)
			{
				cout << "FIELD GOAL" << endl;
			}
			else
			{
				cout << "NO SCORE" << endl;
			}


			cout << team1p << "-" << team2p << " ";
			if (team1p > team2p)
			{
				cout << teamArray[team1] << endl;
			}
			else if (team2p > team1p)
			{
				cout << teamArray[team2] << endl;
			}
			else
			{
				cout << "Tie" << endl;
			}

		}// end of watch if
		quarter++;
	}// end of while

//TEAM 1 WINS
	if (team1p > team2p)
	{
		cout << "\n\n" << teamArray[team1] << " beat the " << teamArray[team2] << " " << team1p << "-" << team2p << " in Game " << game << "." << endl;
		Gamewinner = team1;
		if (round == 1)
		{
			Playing2[team1] = true;
		}
		else if (round == 2)
		{
			Playing3[team1] = true;
		}
	}

//TEAM 2 WINS
	else if (team2p > team1p)
	{
		cout << "\n\n" << teamArray[team2] << " beat the " << teamArray[team1] << " " << team2p << "-" << team1p << " in Game " << game << "." << endl;
		Gamewinner = team2;
		if (round == 1)
		{
			Playing2[team2] = true;
		}
		else if (round == 2)
		{
			Playing3[team2] = true;
		}
	}

// OVERTIME
	else if (team1p == team2p)
	{
		while (team1p == team2p) // stay in while loop until tie is broken
		{
			points = Score(team1);
			team1p += points;

				if (points == 7)
				{
					Tdcounter[team1][round-1]++;
					Tdattemptcounter[team1][round-1]++;
				}
				else if (points == 3)
				{
					Fgcounter[team1][round-1]++;
					Tdattemptcounter[team1][round-1]++;
					Fgattemptcounter[team1][round-1]++;
				}
				else
				{
					Tdattemptcounter[team1][round-1]++;
					Fgattemptcounter[team1][round-1]++;
				}

			if (watch == 'y')
			{
				cout << "\nOVERTIME " << overtime << endl;
				cout << teamArray[team1] << " ball - ";
				if (points == 7)
				{
					cout << "TOUCHDOWN" << endl;
				}
				else if (points == 3)
				{
					cout << "FIELD GOAL" << endl;
				}
				else
				{
					cout << "NO SCORE" << endl;
				}


				cout << team1p << "-" << team2p << " ";
				if (team1p > team2p)
				{
					cout << teamArray[team1] << endl;
				}
				else if (team2p > team1p)
				{
					cout << teamArray[team2] << endl;
				}
				else
				{
					cout << "Tie" << endl;
				}
			}// end of if
		// other team's ball

			points = Score(team2);
			team2p += points;			
			
				if (points == 7)
				{
					Tdcounter[team2][round-1]++;
					Tdattemptcounter[team2][round-1]++;
				}
				else if (points == 3)
				{
					Fgcounter[team2][round-1]++;
					Tdattemptcounter[team2][round-1]++;
					Fgattemptcounter[team2][round-1]++;
				}
				else
				{
					Tdattemptcounter[team2][round-1]++;
					Fgattemptcounter[team2][round-1]++;
				}

			if (watch == 'y')
			{
				cout << teamArray[team2] << " ball - ";
				if (points == 7)
				{
					cout << "TOUCHDOWN" << endl;
				}
				else if (points == 3)
				{
					cout << "FIELD GOAL" << endl;
				}
				else
				{
					cout << "NO SCORE" << endl;
				}

				cout << team1p << "-" << team2p << " ";
				if (team1p > team2p)
				{
					cout << teamArray[team1] << endl;
				}
				else if (team2p > team1p)
				{
					cout << teamArray[team2] << endl;
				}
				else
				{
					cout << "Tie" << endl;
				}

			}// end of watch if

			overtime++;

		}//end of while

		if (team1p > team2p)
		{
			cout << "\n\n" << teamArray[team1] << " beat the " << teamArray[team2] << " " << team1p << "-" << team2p << " in Game " << game << "." << endl;
			Gamewinner = team1;
			if (round == 1)
			{
				Playing2[team1] = true;
			}
			else if (round == 2)
			{
				Playing3[team1] = true;
			}
		}
		else if (team2p > team1p)
		{
			cout << "\n\n" << teamArray[team2] << " beat the " << teamArray[team1] << " " << team2p << "-" << team1p << " in Game " << game << "." << endl;
			Gamewinner = team2;		
			if (round == 1)
			{
				Playing2[team2] = true;
			}
			else if (round == 2)
			{
				Playing3[team2] = true;
			}
		}

	}//end of else if for overtime	

return Gamewinner;

}//end of Game()

//main
int main()
{
	srand(time(NULL));	//randomizes the pool for rand()

	char inputfile[40];
	char watch = ' ';		//initialize variable for watching	
	int round = 1;
	int game = 1;
	int team1 = 0;
	int team2 = 1;
	int Game1winner, Game2winner, Game3winner, Game4winner, Game5winner, Game6winner, Game7winner;

	Zero (Tdcounter);		//Zero the global statistic arrays
	Zero (Fgcounter);
	Zero (Tdattemptcounter);
	Zero (Fgattemptcounter);

	cout << "\nWelcome to the Football Conference!" << endl;

	cout << "\nPlease enter the input file: ";
	cin >> inputfile;
	cout << endl;

	ReadFile(inputfile);

	for (int i = 0; i < 5000; i++)		//call the team shuffle function
	{	
		TeamAssignment();
	}

	cout << "\nHere are the brackets: " << endl;		//show the bracket
	
	PrintBracket();	
	
	do {	
		cout << "\n\n\nWould you like to watch the game in Round " << round << " (y for yes, n for no)? ";
		cin >> watch;
		cout << endl;

		if (cin.fail()) {
			cin.clear(); //reset cin.fail to false
			cin.ignore(10000, '\n'); //clear cin
			cout << "You entered a bad value.\n";
			continue; //sends you to while so that it loops back into the do loop
		} //end of cin.fail if statement	

		//user entered a letter
		cin.ignore( 10000, '\n'); //clear cin of any extraneous characters
		if (watch == 'y' or watch == 'n') {
			break;
		}
		else {
			cout << "You entered an invalid character.\n";
			continue;
		}
	} while(true);


// ROUND 1 GAME BEGINS		
	Game1winner = Game(team1, team2, game, watch, round);
	team1 += 2;
	team2 += 2;
	game ++;
	strncpy (Game1, teamArray[Game1winner], sizeof(Game1));

	Game2winner = Game(team1, team2, game, watch, round);
	team1 += 2;
	team2 += 2;
	game ++;
	strncpy (Game2, teamArray[Game2winner], sizeof(Game2));

	Game3winner = Game(team1, team2, game, watch, round);
	team1 += 2;
	team2 += 2;
	game ++;
	strncpy (Game3, teamArray[Game3winner], sizeof(Game3));

	Game4winner = Game(team1, team2, game, watch, round);
	game ++;
	strncpy (Game4, teamArray[Game4winner], sizeof(Game4));

// ROUND 2
	round ++;

	cout << "\n\n";
	
	cout << "\nHere are the brackets: " << endl;		//show the bracket
	
	PrintBracket();	
	
	do {	
		cout << "Would you like to watch the game in Round " << round << " (y for yes, n for no)? ";
		cin >> watch;
		cout << endl;

		if (cin.fail()) {
			cin.clear(); //reset cin.fail to false
			cin.ignore(10000, '\n'); //clear cin
			cout << "You entered a bad value.\n";
			continue; //sends you to while so that it loops back into the do loop
		} //end of cin.fail if statement	

		//user entered a letter
		cin.ignore( 10000, '\n'); //clear cin of any extraneous characters
		if (watch == 'y' or watch == 'n') {
			break;
		}
		else {
			cout << "You entered an invalid character.\n";
			continue;
		}
	} while(true);

// ROUND 2 GAMES BEGIN

	team1 = Game1winner;
	team2 = Game2winner;
	Game5winner = Game(team1, team2, game, watch, round);
	game ++;
	strncpy (Game5, teamArray[Game5winner], sizeof(Game5));

	team1 = Game3winner;
	team2 = Game4winner;
	Game6winner = Game(team1, team2, game, watch, round);
	game ++;
	strncpy (Game6, teamArray[Game6winner], sizeof(Game6));

// ROUND 3
	round ++;

	cout << "\n\n";
	
	cout << "\nHere are the brackets: " << endl;		//show the bracket
	
	PrintBracket();
	
	do {	
		cout << "Would you like to watch the game in Round " << round << " (y for yes, n for no)? ";
		cin >> watch;
		cout << endl;

		if (cin.fail()) {
			cin.clear(); //reset cin.fail to false
			cin.ignore(10000, '\n'); //clear cin
			cout << "You entered a bad value.\n";
			continue; //sends you to while so that it loops back into the do loop
		} //end of cin.fail if statement	

		//user entered a letter
		cin.ignore( 10000, '\n'); //clear cin of any extraneous characters
		if (watch == 'y' or watch == 'n') {
			break;
		}
		else {
			cout << "You entered an invalid character.\n";
			continue;
		}
	} while(true);

// ROUND 3 GAMES BEGIN

	team1 = Game5winner;
	team2 = Game6winner;
	Game7winner = Game(team1, team2, game, watch, round);
	
	cout << "\n\n\n" << teamArray[Game7winner] << " win the conference!" << endl;

//Stats!!

	for (int i = 0; i<8; i++)
	{
		Totaltd[i] = Tdcounter[i][0] + Tdcounter[i][1] + Tdcounter[i][2];
		Totaltdattempt[i] = Tdattemptcounter[i][0] + Tdattemptcounter[i][1] + Tdattemptcounter[i][2];
		Totalfg[i] = Fgcounter[i][0] + Fgcounter[i][1] + Fgcounter[i][2];
		Totalfgattempt[i] = Fgattemptcounter[i][0] + Fgattemptcounter[i][1] + Fgattemptcounter[i][2];
		if (Totaltdattempt[i] == 0)
		{
			Tdperc[i] = 0;
		}
		else
		{
			Tdperc[i] = Totaltd[i]/Totaltdattempt[i];
		}

		if (Totalfgattempt[i] == 0)
		{
			Fgperc[i] = 0;
		}
		else
		{
			Fgperc[i] = Totalfg[i]/Totalfgattempt[i];
		}
		
		if (atof (tdArray[i]) > Tdperc[i])
		{		
			Difftd[i] = atof (tdArray[i]) - Tdperc[i];
		}
		else
		{
			Difftd[i] = Tdperc[i] - atof (tdArray[i]);
		}

		if (atof (fgArray[i]) > Fgperc[i])
		{		
			Difffg[i] = atof (fgArray[i]) - Fgperc[i];
		}
		else
		{
			Difffg[i] = Fgperc[i] - atof (fgArray[i]);
		}
	}

	int a = 0;

	while(a<3)
	{
		for (int i = 0; i<8; i++)
		{
			TotalDown[a] += Tdcounter[i][a];
			TotalAttDown[a] += Tdattemptcounter[i][a];
			TotalGoal[a] += Fgcounter[i][a];
			TotalAttGoal[a] += Fgattemptcounter[i][a];
		}
		a++;
	}

	a = 3;

	for (int i = 0; i<8; i++)
	{
		TotalDown[a] += Totaltd[i];
		TotalAttDown[a] += Totaltdattempt[i];
		TotalGoal[a] += Totalfg[i];
		TotalAttGoal[a] += Totalfgattempt[i];
	}

	for (int i=0; i<8; i++)
	{
		TotalDiff[0] += Difftd[i];
		TotalDiff[1] += Difffg[i];
	}



	cout << "\n\n\nTOUCHDOWN TABLE\n" << endl;
	cout << setw(20) << right << "ROUND #" << endl;
	cout << "Team" << setw(7) << "1" << setw(6) << "2" << setw(6) << "3" << setw(8) << "Total" << setw(4) << "%" << setw(7) << "Prob" << setw(6) << "Diff" << endl;
	cout << "----    ----- ----- ----- ----- ----- ----- -----" << endl;
	for (int i = 0; i<8; i++)
	{
		cout << setw(8) << left << teamArray[i] << setfill(' ') << left << setfill(' ') << right << setw(2) << Tdcounter[i][0] << "/" << Tdattemptcounter[i][0];
		if (Playing2[i])
		{
			cout << setfill(' ') << left << setfill(' ') << right << setw(4) << Tdcounter[i][1] << "/" << Tdattemptcounter[i][1];
		}
		else
		{
			cout << setw(4) << "      ";
		}

		if (Playing3[i])
		{		
			cout << setfill(' ') << left << setfill(' ') << right << setw(4) << Tdcounter[i][2] << "/" << Tdattemptcounter[i][2];
		}		
		else
		{
			cout << setw(4) << "      ";
		}
		cout << setfill(' ') << left << setfill(' ') << right << setw(4) << Totaltd[i] << "/" << setw(2) << left << Totaltdattempt[i];
		cout.precision(2);
		cout << setfill(' ') << left << setfill(' ') << right << setw(5) << fixed << Tdperc[i];
		cout << setw(6) << tdArray[i];
		cout.precision(2);
		cout << setfill(' ') << left << setfill(' ') << right << setw(6) << fixed << Difftd[i] << endl;
		cout.precision(0);
	}
	cout << "------- ----- ----- ----- ----- ----- ----- -----" << endl;
	cout << setw(8) << left << "Total" << setfill(' ') << right << setw(2) << TotalDown[0] << "/" << setfill(' ') << left << setw(2) << TotalAttDown[0] << " ";
	cout << setfill(' ') << right << setw(2) << TotalDown[1] << "/" << setfill(' ') << left << setw(2) << TotalAttDown[1] << " ";
	cout << setfill(' ') << right << setw(2) << TotalDown[2] << "/" << setfill(' ') << left << setw(2) << TotalAttDown[2] << " ";
	cout << setfill(' ') << right << setw(2) << TotalDown[3] << "/" << setfill(' ') << left << setw(2) << TotalAttDown[3] << " ";
	cout << setw(12) << " ";
	cout.precision(2);
	cout << setfill(' ') << setw(5) << TotalDiff[0] << endl;
	cout.precision(0);




	cout << "\n\n\nFIELD GOAL TABLE\n" << endl;
	cout << setw(20) << right << "ROUND #" << endl;
	cout << "Team" << setw(7) << "1" << setw(6) << "2" << setw(6) << "3" << setw(8) << "Total" << setw(4) << "%" << setw(7) << "Prob" << setw(6) << "Diff" << endl;
	cout << "----    ----- ----- ----- ----- ----- ----- -----" << endl;
	for (int i = 0; i<8; i++)
	{
		cout << setw(8) << left << teamArray[i] << setfill(' ') << left << setfill(' ') << right << setw(2) << Fgcounter[i][0] << "/" << Fgattemptcounter[i][0];
		if (Playing2[i])
		{
			cout << setfill(' ') << left << setfill(' ') << right << setw(4) << Fgcounter[i][1] << "/" << Fgattemptcounter[i][1];
		}
		else
		{
			cout << setw(4) << "      ";
		}

		if (Playing3[i])
		{		
			cout << setfill(' ') << left << setfill(' ') << right << setw(4) << Fgcounter[i][2] << "/" << Fgattemptcounter[i][2];
		}		
		else
		{
			cout << setw(4) << "      ";
		}
		cout << setfill(' ') << left << setfill(' ') << right << setw(4) << Totalfg[i] << "/" << setw(2) << left << Totalfgattempt[i];
		cout.precision(2);
		cout << setfill(' ') << left << setfill(' ') << right << setw(5) << fixed << Fgperc[i];
		cout << setw(6) << fgArray[i];
		cout.precision(2);
		cout << setfill(' ') << left << setfill(' ') << right << setw(6) << fixed << Difffg[i] << endl;
		cout.precision(0);
	}
	cout << "------- ----- ----- ----- ----- ----- ----- -----" << endl;
	cout << setw(8) << left << "Total" << setfill(' ') << right << setw(2) << TotalGoal[0] << "/" << setfill(' ') << left << setw(2) << TotalAttGoal[0] << " ";
	cout << setfill(' ') << right << setw(2) << TotalGoal[1] << "/" << setfill(' ') << left << setw(2) << TotalAttGoal[1] << " ";
	cout << setfill(' ') << right << setw(2) << TotalGoal[2] << "/" << setfill(' ') << left << setw(2) << TotalAttGoal[2] << " ";
	cout << setfill(' ') << right << setw(2) << TotalGoal[3] << "/" << setfill(' ') << left << setw(2) << TotalAttGoal[3] << " ";
	cout << setw(12) << " ";
	cout.precision(2);
	cout << setfill(' ') << setw(5) << TotalDiff[1] << endl;
	cout.precision(0);
	cout << "\n\n\n";

	return 0;
}






