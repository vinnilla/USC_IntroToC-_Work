//read input file for PA3
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

//set structures up
struct Room { 
 string building_code; 
 int room_number; 
 int max_students; 
}; 
 
struct Course { 
 char prefix; 
 int course_number; 
 int num_minutes; 
 int num_lectures; 
}; 
 
struct Section_Constraints{ 
 int days[7];
 int earliest_start_time; 
 int latest_end_time; 
}; 
 
struct Section { 
 int section_id; 
 int section_number; 
 int num_students; 
 Course course; 
 Section_Constraints constraints; 
};

void ReadFile (string Filename){

	//open file
	ifstream ifile(Filename);

	//check fail()
	if (ifile.fail()) {
		cout << "Couldn't open file." << endl;
		return 1;
	}

	//start reading from file 
	// Room Section
	int LinesIndex = 0;
	int BuildingLines = 0;
	string Line;
	string Lines[100];
	Room Rooms;

	ifile.getline(Line); //check to see if file has anything, quit if empty
	if (ifile.fail()) {
		cout << "File appears to be empty." << endl;
		return 1;
	}

	if (Line.size() != 0) {
		if (Line.find("--") != 0) {
			Lines[LinesIndex] = Line;
			LinesIndex++;
			BuildingLines++;
		}
	}

	Rooms = new Room[BuildingLines]; //fill array with information
	for (int i = 0; i < BuildingLines; i++) {
		stringstream ss;
		ss << Lines[i];
		ss >> Rooms[i].building_code;
		>> Rooms[i].room_number;
		>> Rooms[i].max_students;
	}


	// Course Section
	int CourseLines = 0;
	LinesIndex = 0;
	Course Courses;

	ifile.getline(Line); //check to see if file has anything, quit if empty
	if (ifile.fail()) {
		cout << "File appears to be empty." << endl;
		return 1;
	}

	if (Line.size() != 0) {
		if (Line.find("--") != 0) {
			Lines[LinesIndex] = Line;
			LinesIndex++;
			CourseLines++;
		}
	}

	Courses = new Course[CourseLines];//fill array with information
	for (int i = 0; i < CourseLines; i++) {
		stringstream ss;
		ss << Lines[i];
		ss >> Courses[i].prefix;
		>> Courses[i].course_number;
		>> Courses[i].num_minutes;
		>> Courses[i].num_lectures;
	}

	// Section Constraints Section
	int ConstraintsLines = 0;
	LinesIndex = 0;
	Section_Constraints Constraints;

	ifile.getline(Line); //check to see if file has anything, quit if empty
	if (ifile.fail()) {
		cout << "File appears to be empty." << endl;
		return 1;
	}

	if (Line.size() != 0) {
		if (Line.find("--") != 0) {
			Lines[LinesIndex] = Line;
			LinesIndex++;
			ConstraintsLines++;
		}
	}

	Constraints = new Section_Constraints[ConstraintsLines];
	for (int i = 0; i < ConstraintsLines; i++) {
		stringstream ss;
		ss << Lines[i];
		ss >> Constraints[i].days[7];
		>> Constraints[i].earliest_start_time;
		>> Constraints[i].latest_end_time;
	}

	ifile.close();
	return;
} // end of ReadFile

int main(int argc, char* argv[]) {
	//ask for file name
	string Filename;
	do {	
			cout << "\n\n\nPlease enter the name of the file you'd like to read: ";
			cin >> Filename;
			cout << endl;

			if (cin.fail()) {
				cin.clear(); //reset cin.fail to false
				cin.ignore(10000, '\n'); //clear cin
				cout << "You entered a bad value.\n";
				continue; //sends you to while so that it loops back into the do loop
			} //end of cin.fail if statement	

		} while(true);

	ReadFile (Filename);

	return 0;
}//end of main


