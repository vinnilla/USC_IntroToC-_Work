//read input file for PA3
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
	//set structures up
	struct Room { 
	 string building_code; 
	 int room_number; 
	 int max_students; 
	}; 
	 
	struct Course { 
	 string prefix; 
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

	//ask for file name
	string Filename;
	cout << "\n Please enter the name of the file you'd like to read: ";
	cin >> Filename;
	cout << endl;

	
	//open file
	ifstream ifile (Filename.c_str());

	//check fail()
	if (ifile.fail()) {
		cout << "Couldn't open file." << endl;
		return 0;
	}

	//start reading from file 
	// Room Section
	int LinesIndex = 0;
	int BuildingLines = 0;
	string Line;
	string Lines[100];
	Room* Rooms;

	getline(ifile, Line); //check to see if file has anything, quit if empty
	if (ifile.fail()) {
		cout << "File appears to be empty." << endl;
		return 0;
	}

	while (!Line.empty()) {
		if (Line.find("--") != 0) {
			Lines[LinesIndex] = Line;
			LinesIndex++;
			BuildingLines++;
		}
		getline(ifile, Line);
	}

	Rooms = new Room[BuildingLines]; //fill array with information
	for (int i = 0; i < BuildingLines; i++) {
		stringstream ss;
		ss << Lines[i];
		if (!ss.fail()){
			ss >> Rooms[i].building_code >> Rooms[i].room_number >> Rooms[i].max_students;
		}
		else {
			cout << "File is formatted incorrectly" << endl;
			return 0;
		}
	}


	// Course Section
	int CourseLines = 0;
	LinesIndex = 0;
	Course* Courses;
	Section_Constraints* Constraints;
	Section* Sections;

	getline(ifile, Line); //check to see if file has anything, quit if empty
	if (ifile.fail()) {
		cout << "File appears to be missing the course section." << endl;
		return 0;
	}

	while (Line.size() != 0) {
		if (Line.find("--") != 0) {
			Lines[LinesIndex] = Line;
			LinesIndex++;
			CourseLines++;
		}
		getline(ifile, Line);
	}

	Courses = new Course[CourseLines];//fill array with information
	Constraints = new Section_Constraints[CourseLines];
	Sections = new Section[CourseLines];

	for (int i = 0; i < CourseLines; i++) {
		stringstream ss;
		ss << Lines[i];
		if (!ss.fail()){
			ss >> Sections[i].section_id >> Courses[i].prefix >> Courses[i].course_number >> Sections[i].section_number >> Courses[i].num_minutes >> Courses[i].num_lectures >> Sections[i].num_students;
		}
		else {
			cout << "File is formatted incorrectly" << endl;
			return 0;
		}
	}

	// Section Constraints Section
	LinesIndex = 0;

	getline(ifile, Line); //check to see if file has anything, quit if empty
	if (ifile.fail()) {
		cout << "File appears to be missing the constraints section." << endl;
		return 0;
	}

	for (int i = 0; i < CourseLines + 1; i++) {
		if (Line.find("--") != 0) {
			Lines[LinesIndex] = Line;
			LinesIndex++;
		}
		getline(ifile, Line);
	}

	string days[CourseLines];

	for (int i = 0; i < CourseLines; i++) {
		stringstream ss;
		ss << Lines[i];
		if (!ss.fail()){
		 	ss >> Sections[i].section_id >> days[i] >> Constraints[i].earliest_start_time >> Constraints[i].latest_end_time;
		}
		else {
			cout << "File is formatted incorrectly" << endl;
			return 0;
		}	
		
	}

	//output to check
	cout << "Part 1" << endl;
	for (int i = 0; i < BuildingLines; i++) {
		cout << Rooms[i].building_code  << ' ' << Rooms[i].room_number  << ' ' << Rooms[i].max_students  << ' ' << endl;
	}

	cout << "Part 2" << endl;
	for (int i = 0; i < CourseLines; i++) {
		cout << Sections[i].section_id  << ' ' << Courses[i].prefix  << ' ' << Courses[i].course_number  << ' ' << Sections[i].section_number  << ' ' << Courses[i].num_minutes  << ' ' << Courses[i].num_lectures  << ' ' << Sections[i].num_students  << ' ' << endl;
	}

	cout << "Part 3" << endl;
	for (int i = 0; i < CourseLines; i++) {
		cout << Sections[i].section_id << ' ' << days[i]  << ' ' << Constraints[i].earliest_start_time  << ' ' << Constraints[i].latest_end_time  << ' ' << endl;
	}

	delete [] Rooms;
	delete [] Courses;
	delete [] Constraints;
	delete [] Sections;

	return 0;
}//end of main


