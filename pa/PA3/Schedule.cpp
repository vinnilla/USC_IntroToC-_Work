//read input file for PA3
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

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
 int days[4];
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

struct Scheduled_Sections {
  int section_id;
  string prefix;
  int course_number;
  int startTime;
  int endTime;
  int days[4];
  Room room;
};

	//global variables
	Room* Rooms;
	Course* Courses;
	Section_Constraints* Constraints;
	Section* Sections;
	Scheduled_Sections* scheduledSections;
	int NumRooms = 0;
	int NumCourses = 0;
	int scheduledCount = 0;


void ReadFile() {
	//ask for file name
	string Filename;
	cout << "\n\nWelcome to the class scheduling program!" << endl;
	cout << "\n Please enter the name of the file you'd like to read: ";
	cin >> Filename;
	cout << endl;

	
	//open file
	ifstream ifile (Filename.c_str());

	//check fail()
	if (ifile.fail()) {
		cout << "Couldn't open file." << endl;
		exit (EXIT_FAILURE);
	}

	//start reading from file 
	// Room Section
	int LinesIndex = 0;
	string Line;
	string Lines[100];

	getline(ifile, Line); //check to see if file has anything, quit if empty
	if (ifile.fail()) {
		cout << "File appears to be empty." << endl;
		exit (EXIT_FAILURE);
	}
	//while loop to extract information from the file into a string array
	while (!Line.empty()) {
		if (Line.find("--") != 0) {
			Lines[LinesIndex] = Line;
			LinesIndex++;
			NumRooms++;
		}
		getline(ifile, Line);
	}

	Rooms = new Room[NumRooms]; //fill dynamically allocated array with information from string array
	for (int i = 0; i < NumRooms; i++) { //iterate through the number of rooms, taking each line at a time and placing them 
		//into the respective variables in the Rooms struct
		stringstream ss;
		ss << Lines[i];
		if (!ss.fail()){
			ss >> Rooms[i].building_code >> Rooms[i].room_number >> Rooms[i].max_students;
		}
		else {
			cout << "File is formatted incorrectly" << endl;
			exit (EXIT_FAILURE);
		}
	}


	// Course Section
	LinesIndex = 0;

	getline(ifile, Line); //check to see if file has anything, quit if empty
	if (ifile.fail()) {
		cout << "File appears to be missing the course section." << endl;
		exit (EXIT_FAILURE);
	}
	//same logic as Room Section
	while (Line.size() != 0) {
		if (Line.find("--") != 0) {
			Lines[LinesIndex] = Line;
			LinesIndex++;
			NumCourses++;
		}
		getline(ifile, Line);
	}

	Courses = new Course[NumCourses];//dynamically allocate arrays so that information can be placed within them
	Constraints = new Section_Constraints[NumCourses];
	Sections = new Section[NumCourses];
	//same logic as Room Section
	for (int i = 0; i < NumCourses; i++) {
		stringstream ss;
		ss << Lines[i];
		if (!ss.fail()){
			ss >> Sections[i].section_id >> Courses[i].prefix >> Courses[i].course_number >> Sections[i].section_number >> Courses[i].num_minutes >> Courses[i].num_lectures >> Sections[i].num_students;
		}
		else {
			cout << "File is formatted incorrectly" << endl;
			exit (EXIT_FAILURE);
		}
	}

	// Section Constraints Section
	LinesIndex = 0;

	getline(ifile, Line); //check to see if file has anything, quit if empty
	if (ifile.fail()) {
		cout << "File appears to be missing the constraints section." << endl;
		exit (EXIT_FAILURE);
	}
	//instead of using while loop here, which would go into an infinite loop with the way the input file is organmized,
	//a for loop is used iterating over the number of courses, which was counted with the previous section
	for (int i = 0; i < NumCourses + 1; i++) {
		if (Line.find("--") != 0) {
			Lines[LinesIndex] = Line;
			LinesIndex++;
		}
		getline(ifile, Line);
	}

	//a temporary string array to hold the input of the days as a string
	string days[NumCourses];

	for (int i = 0; i < NumCourses; i++) {
		stringstream ss;
		ss << Lines[i];
		if (!ss.fail()){
		 	ss >> Sections[i].section_id >> days[i] >> Constraints[i].earliest_start_time >> Constraints[i].latest_end_time;

		 	//using the string array, specific letters are searched for and the correct values are placed into the int days array
		 	size_t found = days[i].find("M");
			if (found != string::npos){
				Constraints[i].days[0] = 1;
			}

			found = days[i].find("T");
			if (found != string::npos) {
				Constraints[i].days[1] = 1;
			}

			found = days[i].find("W");
			if (found != string::npos) {
				Constraints[i].days[2] = 1;
			}

			found = days[i].find("R");
			if (found != string::npos) {
				Constraints[i].days[3] = 1;
			}

		}
		else {
			cout << "File is formatted incorrectly" << endl;
			exit (EXIT_FAILURE);
		}	

		//complete the filling of the Section type struct as the information will be needed later
		Sections[i].course = Courses[i];
		Sections[i].constraints = Constraints[i];

	}
	//close the ifile stream 
	ifile.close();
	return;
}

void Sort_Rooms() {
	int NumChanges = 0; //this counter will test whether the bubble sort is complete (when no changes are made)
	int CurrentRoom;
	Room Temp;
	do { //this bubble sort will sort all the room capacities in descending order so that the scheduling code will work
		NumChanges = 0;
		CurrentRoom = 0;
		for (int i = 1; i < NumRooms; i++) {
			if (Rooms[i].max_students > Rooms[CurrentRoom].max_students) { //if the previous room is smaller than the next room
				//they will swap places

				Temp.building_code = Rooms[i].building_code;
				Temp.room_number = Rooms[i].room_number;
				Temp.max_students = Rooms[i].max_students;

				Rooms[i].building_code = Rooms[CurrentRoom].building_code;
				Rooms[i].room_number = Rooms[CurrentRoom].room_number;
				Rooms[i].max_students = Rooms[CurrentRoom].max_students;

				Rooms[CurrentRoom].building_code = Temp.building_code;
				Rooms[CurrentRoom].room_number = Temp.room_number;
				Rooms[CurrentRoom].max_students = Temp.max_students;

				NumChanges++;
				CurrentRoom++;
			}
		}

	} while (NumChanges != 0);
	return;
}

void Sort_Class() {
	int NumChanges;
	string CurrentPrefix;
	int CurrentCourseNum;
	Scheduled_Sections Temp;
	do { //bubble sort classes so that class prefix and class number are in ascending order
		NumChanges = 0;
		for (int i = 0; i < scheduledCount-1; i++) { //the scheduledCount -1 is needed because i+1 is used throughout the iteration
			if (scheduledSections[i].prefix != CurrentPrefix) {
				CurrentPrefix = scheduledSections[i].prefix;
			}
			if (scheduledSections[i].prefix == CurrentPrefix){ //this test to see if prefix is the same so that sorting of course
				//number is within the same prefix
				if (scheduledSections[i].course_number > scheduledSections[i+1].course_number) { //if previous course number is larger
					//than next course number, they are swapped

					Temp.section_id = scheduledSections[i].section_id;
					Temp.prefix = scheduledSections[i].prefix;
					Temp.course_number = scheduledSections[i].course_number;
					Temp.startTime = scheduledSections[i].startTime;
					Temp.endTime = scheduledSections[i].endTime;
					Temp.days[0] = scheduledSections[i].days[0];
					Temp.days[1] = scheduledSections[i].days[1];
					Temp.days[2] = scheduledSections[i].days[2];
					Temp.days[3] = scheduledSections[i].days[3];
					Temp.room = scheduledSections[i].room;

					scheduledSections[i].section_id = scheduledSections[i+1].section_id;
					scheduledSections[i].prefix = scheduledSections[i+1].prefix;
					scheduledSections[i].course_number = scheduledSections[i+1].course_number;
					scheduledSections[i].startTime = scheduledSections[i+1].startTime;
					scheduledSections[i].endTime = scheduledSections[i+1].endTime;
					scheduledSections[i].days[0] = scheduledSections[i+1].days[0];
					scheduledSections[i].days[1] = scheduledSections[i+1].days[1];
					scheduledSections[i].days[2] = scheduledSections[i+1].days[2];
					scheduledSections[i].days[3] = scheduledSections[i+1].days[3];
					scheduledSections[i].room = scheduledSections[i+1].room;

					scheduledSections[i+1].section_id = Temp.section_id;
					scheduledSections[i+1].prefix = Temp.prefix;
					scheduledSections[i+1].course_number = Temp.course_number;
					scheduledSections[i+1].startTime = Temp.startTime;
					scheduledSections[i+1].endTime = Temp.endTime;
					scheduledSections[i+1].days[0] = Temp.days[0];
					scheduledSections[i+1].days[1] = Temp.days[1];
					scheduledSections[i+1].days[2] = Temp.days[2];
					scheduledSections[i+1].days[3] = Temp.days[3];
					scheduledSections[i+1].room = Temp.room;

					NumChanges++;
				}
			}
		}
		for (int i = 0; i < scheduledCount-1; i++) {
			if (scheduledSections[i].course_number != CurrentCourseNum) { //sort by section_id
				CurrentCourseNum = scheduledSections[i].course_number;
			}
			if (scheduledSections[i].course_number == CurrentCourseNum){ //check course number is the same so changes are only made
				//within the same course number
				if (scheduledSections[i].section_id > scheduledSections[i+1].section_id) { //if previous section id is larger
					//than next section id, they are swapped

					Temp.section_id = scheduledSections[i].section_id;
					Temp.prefix = scheduledSections[i].prefix;
					Temp.course_number = scheduledSections[i].course_number;
					Temp.startTime = scheduledSections[i].startTime;
					Temp.endTime = scheduledSections[i].endTime;
					Temp.days[0] = scheduledSections[i].days[0];
					Temp.days[1] = scheduledSections[i].days[1];
					Temp.days[2] = scheduledSections[i].days[2];
					Temp.days[3] = scheduledSections[i].days[3];
					Temp.room = scheduledSections[i].room;

					scheduledSections[i].section_id = scheduledSections[i+1].section_id;
					scheduledSections[i].prefix = scheduledSections[i+1].prefix;
					scheduledSections[i].course_number = scheduledSections[i+1].course_number;
					scheduledSections[i].startTime = scheduledSections[i+1].startTime;
					scheduledSections[i].endTime = scheduledSections[i+1].endTime;
					scheduledSections[i].days[0] = scheduledSections[i+1].days[0];
					scheduledSections[i].days[1] = scheduledSections[i+1].days[1];
					scheduledSections[i].days[2] = scheduledSections[i+1].days[2];
					scheduledSections[i].days[3] = scheduledSections[i+1].days[3];
					scheduledSections[i].room = scheduledSections[i+1].room;

					scheduledSections[i+1].section_id = Temp.section_id;
					scheduledSections[i+1].prefix = Temp.prefix;
					scheduledSections[i+1].course_number = Temp.course_number;
					scheduledSections[i+1].startTime = Temp.startTime;
					scheduledSections[i+1].endTime = Temp.endTime;
					scheduledSections[i+1].days[0] = Temp.days[0];
					scheduledSections[i+1].days[1] = Temp.days[1];
					scheduledSections[i+1].days[2] = Temp.days[2];
					scheduledSections[i+1].days[3] = Temp.days[3];
					scheduledSections[i+1].room = Temp.room;

					NumChanges++;
				}
			}
		}
	} while (NumChanges != 0);
	return;
}

void Sort_Capacity() {
	int NumChanges;
	string CurrentCapacity;
	int CurrentDays[4];
	Scheduled_Sections Temp;
	do { //bubble sort so that room capacity is in descending order
		NumChanges = 0;
		for (int i = 0; i < scheduledCount-1; i++) {

			if (scheduledSections[i].room.max_students < scheduledSections[i+1].room.max_students) { // if previous room is smaller than
				//next room, swap

					Temp.section_id = scheduledSections[i].section_id;
					Temp.prefix = scheduledSections[i].prefix;
					Temp.course_number = scheduledSections[i].course_number;
					Temp.startTime = scheduledSections[i].startTime;
					Temp.endTime = scheduledSections[i].endTime;
					Temp.days[0] = scheduledSections[i].days[0];
					Temp.days[1] = scheduledSections[i].days[1];
					Temp.days[2] = scheduledSections[i].days[2];
					Temp.days[3] = scheduledSections[i].days[3];
					Temp.room = scheduledSections[i].room;

					scheduledSections[i].section_id = scheduledSections[i+1].section_id;
					scheduledSections[i].prefix = scheduledSections[i+1].prefix;
					scheduledSections[i].course_number = scheduledSections[i+1].course_number;
					scheduledSections[i].startTime = scheduledSections[i+1].startTime;
					scheduledSections[i].endTime = scheduledSections[i+1].endTime;
					scheduledSections[i].days[0] = scheduledSections[i+1].days[0];
					scheduledSections[i].days[1] = scheduledSections[i+1].days[1];
					scheduledSections[i].days[2] = scheduledSections[i+1].days[2];
					scheduledSections[i].days[3] = scheduledSections[i+1].days[3];
					scheduledSections[i].room = scheduledSections[i+1].room;

					scheduledSections[i+1].section_id = Temp.section_id;
					scheduledSections[i+1].prefix = Temp.prefix;
					scheduledSections[i+1].course_number = Temp.course_number;
					scheduledSections[i+1].startTime = Temp.startTime;
					scheduledSections[i+1].endTime = Temp.endTime;
					scheduledSections[i+1].days[0] = Temp.days[0];
					scheduledSections[i+1].days[1] = Temp.days[1];
					scheduledSections[i+1].days[2] = Temp.days[2];
					scheduledSections[i+1].days[3] = Temp.days[3];
					scheduledSections[i+1].room = Temp.room;

					NumChanges++;
				}//end of if
		}//end of for
	} while (NumChanges != 0);
	return;
}

void OutputCheck() {
	
	//output to check code, not actually used to output for assignment
	cout << "Part 1" << endl;
	for (int i = 0; i < NumRooms; i++) {
		cout << Rooms[i].building_code  << ' ' << Rooms[i].room_number  << ' ' << Rooms[i].max_students  << ' ' << endl;
	}

	cout << "Part 2" << endl;
	for (int i = 0; i < NumCourses; i++) {
		cout << Sections[i].section_id  << ' ' << Courses[i].prefix  << ' ' << Courses[i].course_number  << ' ' << Sections[i].section_number  << ' ' << Courses[i].num_minutes  << ' ' << Courses[i].num_lectures  << ' ' << Sections[i].num_students  << ' ' << endl;
	}

	cout << "Part 3" << endl;
	for (int i = 0; i < NumCourses; i++) {
		cout << Sections[i].section_id << ' ' << Constraints[i].days[0] << Constraints[i].days[1] << Constraints[i].days[2] << Constraints[i].days[3] << ' ' << Constraints[i].earliest_start_time  << ' ' << Constraints[i].latest_end_time  << ' ' << endl;
	}
	return;
}

int fixTime(int Time, int Minutes) {
	//convert military time to minutes
	int minTime = Time%100;
	int hourTime = ((Time - minTime)/100)*60;
	//add minutes from military time and class time and return
	int RealTime = minTime+hourTime+Minutes;
	//convert total minutes back to military time and return it
	int EndTime = (RealTime/60)*100 + (RealTime%60);
	return EndTime;
}

bool roomsMatch(Room scheduleRoom, Room room) { //check if room code and number match
	if (scheduleRoom.building_code == room.building_code && scheduleRoom.room_number == room.room_number) {
		return true;
	}
	return false;
}

bool daysMatch (int* scheduleDays, int* days){ //check if days match
	int counter = 0;
	for (int i = 0; i < 4; i++){
		if (scheduleDays[i] != days[i]){ //anytime days do not match, counter is incremented. any incrementation will return false
			counter++;
		}
	}
	if (counter == 0) {
		return true;
	}
	return false;
}

int timesOverlap( int scheduledStartTime, int scheduledEndTime, int constraintStartTime, int constraintEndTime, int numMinutes ) {
  //Looking for a start time and end time, for the current class, that does
  //not overlap the scheduled start and end time, that are provided
  //Returns -1 if we cannot find a time. Otherwise returns the schedulable start time
  bool scheduled = false;
  while (!scheduled) {
    if ( ( constraintStartTime >= scheduledStartTime && 
	 constraintStartTime <= scheduledEndTime ) ||
         ( fixTime(constraintStartTime, numMinutes) >= scheduledStartTime &&
	   fixTime(constraintStartTime, numMinutes) <= scheduledEndTime ) ) {
      //Can't start the new section at this time.
      //Advance the start time by numMinutes plus 10 minutes and return.
      //We must now compare this new start time with all scheduled sections
      return fixTime( constraintStartTime, numMinutes+10 );
    } else {
      //This is a possible scheduable start time. We must use the new times for future
      //schedule checks
      break;
    }
  }

  return constraintStartTime;
}

bool scheduleAvailable( Section sectionToSchedule, int roomIndex ) {
  int* constraintDays = sectionToSchedule.constraints.days; // see explanation below 
  int constraintStartTime = sectionToSchedule.constraints.earliest_start_time; 
  int originalStartTime = constraintStartTime;
  int constraintEndTime = sectionToSchedule.constraints.latest_end_time;
  int courseLength = sectionToSchedule.course.num_minutes; 
  int currentScheduledCount = scheduledCount;
  Course course = sectionToSchedule.course;

  bool canSchedule = false;
  int scheduleRoomIndex = roomIndex;
  int actualStartTime = constraintStartTime;
  int k=0;

  while ( k < scheduledCount ) {
    if ( canSchedule) {
      //We can schedule, so exit the for loop
      break;
    }

    //Check if there is a conflict with an already scheduled section
    Scheduled_Sections scheduledSection = scheduledSections[k];
    int scheduledStartTime = scheduledSection.startTime;
    int scheduledEndTime = scheduledSection.endTime;
    int* scheduledDays = scheduledSection.days;
    Room scheduledRoom = scheduledSection.room;
    
    actualStartTime  = constraintStartTime;

    int possibleStartTime = constraintStartTime;

    while ( true ) {
      if ( scheduleRoomIndex < 0 ) {
	//Have tried all the rooms. This section cannot be scheduled
	canSchedule = false;
	break;
      }

      if ( roomsMatch( scheduledRoom, Rooms[scheduleRoomIndex] ) ) {
	//The needed room matches the already scheduled room
	if ( daysMatch( scheduledDays, constraintDays ) ) {
	  //Days match. Check the times. If the days don't match, no overlap.
	  possibleStartTime = timesOverlap( scheduledStartTime, scheduledEndTime,
					   actualStartTime, constraintEndTime, 
					   courseLength );
	  if ( possibleStartTime != actualStartTime ) {
	    //The start time has changed, we must start over with
	    //checking scheduled sections, using this new start tim,
	    //only if the end time is within the constraintEndTime
	    if ( fixTime( possibleStartTime, courseLength+10 ) >
		 constraintEndTime ) {
	      //This section cannot be scheduled in this room. Try the next
	      //bigger room, and start with the first scheduled section
	      possibleStartTime = originalStartTime;
	      scheduleRoomIndex--;
	      break;
	    }

	    //The new end time is within the constraint end time, so we 
	    //exit the while loop, set k back to 0, and try the new times
	    //against all the scheduled sections
	    break;
	  }

	  if ( actualStartTime == -1 ) {
	    //Cannot schedule in this room. Try the next biggest room
	    actualStartTime = originalStartTime;
	    scheduleRoomIndex--;
	    continue;
	  }

	  break;
	}
      }

      //Current scheduled section does not overlap the needed section. Try the
      //next scheduled section
      break;
    } //end of while

    //Must increment k since we have a for loop now
    k++;

    if ( possibleStartTime != actualStartTime ) {
      //Must start over using this new start time
      canSchedule = false;
      constraintStartTime = possibleStartTime;
      k=0;
    }
  } //end of for

  if ( ( scheduledCount == 0 || scheduledCount == k ) && scheduleRoomIndex != -1 ) {
    //No scheduled sections, so we can schedule, OR we went through all the
    //sections and found a schedulable time
    canSchedule = true;
  }

  if ( canSchedule ) {
    //We can scheule this section. So do it.
    scheduledSections[scheduledCount].startTime = actualStartTime;
    scheduledSections[scheduledCount].section_id = sectionToSchedule.section_id;
    scheduledSections[scheduledCount].prefix = course.prefix;
    scheduledSections[scheduledCount].course_number = course.course_number;
    scheduledSections[scheduledCount].endTime = fixTime( actualStartTime,
							 course.num_minutes );
    scheduledSections[scheduledCount].room = Rooms[scheduleRoomIndex];

    for ( int i=0; i<4; i++ ) {
      //Copy the day values
      scheduledSections[scheduledCount].days[i] = constraintDays[i];
    }
    scheduledCount++;
  }
 
  return canSchedule;
}


bool scheduleSections() {
  //Schedule sections from largest room to smallest room - in section size
  //Schedule all classes that can only fit in the largest room, that hasn't
  //yet been scheduled (starting with the largest room). When that is done
  //go to the next largest room, etc. 
  //This function assumes the rooms array is sorted from largest room to
  //smallest room.
  //roomCount is the total number of rooms that exist

  for ( int i=0; i<NumRooms-1; i++ ) {
    //Use roomCount-1, since we check two room size values at a time
    int bigRoomSize = Rooms[i].max_students;
    int smallRoomSize = Rooms[i+1].max_students;

    //We want to schedule all the rooms that have a size greater than
    //smallRoomSize and less than or equal to bigRoomSize
    for ( int j=0; j<NumCourses; j++ ) {
    	if (Sections[j].num_students > smallRoomSize &&
			Sections[j].num_students <= bigRoomSize ) {
			//This is a room we are to schedule
			bool scheduled = scheduleAvailable( Sections[j], i );
			if ( !scheduled ) {
		    	//Have at least one section that cannot be scheduled
		    	cout<<"have a room that can't be scheduled\n";
		    	return false;
			}
    	}
    }
    if (i == NumRooms-2) {
		for ( int j=0; j<NumCourses; j++ ) {
		    if (Sections[j].num_students <= smallRoomSize) {
				bool scheduled = scheduleAvailable( Sections[j], i+1 );
				if ( !scheduled ) {
			    	//Have at least one section that cannot be scheduled
			    	cout<<"have a room that can't be scheduled\n";
			    	return false;
				}
			}
			
	    
	    }
    	
    }
  }

  return true;
}

void OutputByClass() {
	cout << "\nSchedule by Class" << endl;
	cout << "-----------------\n" << endl;
	int ClassNum = 0;
	string ClassPrefix = " ";
	int CurrentClassNumber;

	for (int i = 0; i<scheduledCount; i++) {
		if (ClassNum != scheduledSections[i].course_number or ClassPrefix != scheduledSections[i].prefix){ //this will output
			//the header for each course
			
			ClassNum = scheduledSections[i].course_number;
			ClassPrefix = scheduledSections[i].prefix;

			for (int j = 0; j<NumCourses; j++){
				if (scheduledSections[i].section_id == Sections[j].section_id){
					CurrentClassNumber = j;
				}
			}
			cout << scheduledSections[i].prefix << " " << scheduledSections[i].course_number << endl;
			cout << "--------" << endl;
			cout << "Course ID: " << scheduledSections[i].section_id << endl;
			cout << "Section #: " << Sections[CurrentClassNumber].section_number << endl;
			cout << "# Students: " << Sections[CurrentClassNumber].num_students << endl;
			cout << "Room : " << scheduledSections[i].room.building_code << " " << scheduledSections[i].room.room_number << endl;
			cout << "Capacity: " << scheduledSections[i].room.max_students << endl;
			cout << "Meeting Day/Time: ";
			//this will convert days array back into characters
			if (scheduledSections[i].days[0] == 1){
				cout << "M";
			}
			if (scheduledSections[i].days[1] == 1){
				cout << "T";
			}
			if (scheduledSections[i].days[2] == 1){
				cout << "W";
			}
			if (scheduledSections[i].days[3] == 1){
				cout << "R";
			}
		
			cout << " " << scheduledSections[i].startTime << "-" << scheduledSections[i].endTime << "\n" << endl;
		}

		else { // if shared header, only other information is outputted

			for (int j = 0; j<NumCourses; j++){
				if (scheduledSections[i].section_id == Sections[j].section_id){
					CurrentClassNumber = j;
				}
			}
			cout << "Course ID: " << scheduledSections[i].section_id << endl;
			cout << "Section #: " << Sections[CurrentClassNumber].section_number << endl;
			cout << "# Students: " << Sections[CurrentClassNumber].num_students << endl;
			cout << "Room : " << scheduledSections[i].room.building_code << " " << scheduledSections[i].room.room_number << endl;
			cout << "Capacity: " << scheduledSections[i].room.max_students << endl;
			cout << "Meeting Day/Time: ";
			if (scheduledSections[i].days[0] == 1){
				cout << "M";
			}
			if (scheduledSections[i].days[1] == 1){
				cout << "T";
			}
			if (scheduledSections[i].days[2] == 1){
				cout << "W";
			}
			if (scheduledSections[i].days[3] == 1){
				cout << "R";
			}
			cout << " " << scheduledSections[i].startTime << "-" << scheduledSections[i].endTime << "\n" << endl;
	 
		}

	}
}

void OutputByRoom() {
	cout << "\nSchedule by Classroom" << endl;
	cout << "---------------------\n" << endl;
	int ClassNum = 0;
	string ClassPrefix = " ";
	int CurrentClassNumber;

	for (int i = 0; i<scheduledCount; i++) { //same logic as outputbyclass, print header if needed, else print without header
		if (ClassPrefix != scheduledSections[i].room.building_code or ClassNum != scheduledSections[i].room.room_number){
			
			ClassNum = scheduledSections[i].room.room_number;
			ClassPrefix = scheduledSections[i].room.building_code;

			for (int j = 0; j<NumCourses; j++){
				if (scheduledSections[i].section_id == Sections[j].section_id){
					CurrentClassNumber = j;
				}
			}
			cout << "\n" << scheduledSections[i].room.building_code << " " << scheduledSections[i].room.room_number << ", Capacity=" << scheduledSections[i].room.max_students << endl;
			cout << "-------" << endl;
			if (scheduledSections[i].days[0] == 1) {
				cout << "M";
			}
			if (scheduledSections[i].days[1] == 1) {
				cout << "T";
			}
			if (scheduledSections[i].days[2] == 1) {
				cout << "W";
			}
			if (scheduledSections[i].days[3] == 1) {
				cout << "R";
			}
			cout << " " << scheduledSections[i].startTime << "-" << scheduledSections[i].endTime;
			cout << " " << scheduledSections[i].prefix << " " << scheduledSections[i].course_number;
			cout << " " << Sections[CurrentClassNumber].section_number << " " << scheduledSections[i].section_id << ", Num_Students=";
			cout << Sections[CurrentClassNumber].num_students << endl;
		}

		else {

			for (int j = 0; j<NumCourses; j++){
				if (scheduledSections[i].section_id == Sections[j].section_id){
					CurrentClassNumber = j;
				}
			}
		if (scheduledSections[i].days[0] == 1) {
				cout << "M";
			}
			if (scheduledSections[i].days[1] == 1) {
				cout << "T";
			}
			if (scheduledSections[i].days[2] == 1) {
				cout << "W";
			}
			if (scheduledSections[i].days[3] == 1) {
				cout << "R";
			}
			cout << " " << scheduledSections[i].startTime << "-" << scheduledSections[i].endTime;
			cout << " " << scheduledSections[i].prefix << " " << scheduledSections[i].course_number;
			cout << " " << Sections[CurrentClassNumber].section_number << " " << scheduledSections[i].section_id << ", Num_Students=";
			cout << Sections[CurrentClassNumber].num_students << endl;
	 
		}

	}
}

int main(int argc, char* argv[]) {

	ReadFile();

	scheduledSections = new Scheduled_Sections[NumCourses];

	Sort_Rooms();

	scheduleSections();

	Sort_Class();

	OutputByClass();

	Sort_Capacity();

	OutputByRoom();

	//delete dynamically allocated arrays
	delete [] Rooms;
	delete [] Courses;
	delete [] Constraints;
	delete [] Sections;
	delete [] scheduledSections;
	return 0;
}//end of main