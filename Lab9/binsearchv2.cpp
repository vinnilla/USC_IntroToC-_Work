#include <iostream>
#include <fstream>

using namespace std;

void sortv2(int *, int, int);
void sort(int *, int);
int binsearch(int, int *, int, int);

int main(int argc, char *argv[]){
  int target;
  if(argc < 2){
    cout << "Provide a filename of the data to be searched" << endl;
    return 1;
  }
  ifstream datfile(argv[1], ios::in);
  if( datfile.fail() ){
    cout << "Unable to open file: " << argv[1] << endl;
    return 1;
  }
  int count = 0;
  // Count how many integers are in the file
  while(! datfile.fail()){
    int temp;
    datfile >> temp;
    if(!datfile.fail()){
      count++;
    }
  }
  // When we reach the end of the file, the EOF flag is set
  // To be able to read through the file again we need to clear that flag
  datfile.clear();
  //  We also need to set our internal position in the file back to 0
  datfile.seekg(0,ios::beg);

  // Now allocate an array to store the file data and read in the data
  int *data = new int[count];
  for(int i=0; i < count; i++){
    datfile >> data[i];
  }

  datfile.close();

  cout << "Read " << count << " integers from the data file.\n" << endl;
  cout << "Enter the target positive integer to search for: ";
  cin >> target;

  // Uncomment the line below for part 2... call sort
  sort(data, count);

  // Call binary search
  int retval = binsearch(target,data,0,count);

  // Interpret and print the results
  if(retval == -1){
    cout << target << " does not appear in the data." << endl;
  }
  else {
    cout << target << " appears at index " << retval << " in the data." << endl;
  }

  // Deallocate the data array
  delete [] data;
  return 0;
}


// Returns the index in the data array where target is located
//  or -1 if the target value is not in the list
int binsearch(int target, int *data, int start, int end)
{
  //base check for empty list
  if (end == 0) {
    return -1;
  }

  else {
    //pick mid item
    int mid = ((end - start)/2) + start;
    //if target equals mid, return mid as target has been found
    if (target == data[mid]) {
      return mid;
    }
    //if target is greater than mid, call binsearch with range from mid+1 to count and return result
    else if (target > data[mid]) {
      return binsearch(target, data, mid+1, end);
    }
    //if target is less than mid, call binsearch with range from start to mid and return result
    else if (target < data[mid]) {
      return binsearch(target, data, start, mid);
    }
  }// end of else
  return -1;
}


// implements a selection sort algorithm to sort
//  the integer values in the 'data' array of size 'len'
// You aren't allowed to change the prototype of this function
void sort(int *data, int len)
{
  int counter = 0; //counter will keep track of how many numbers there are in the sorted list
  int location;
  //base check to see if array is sorted
  if (counter+1 == len) {
    return;
  }

  else {
    //find the smallest value in array (and the location of the smallest value)
    int smallest = data[counter];
    location = counter;
    for (int i = counter+1; i<len; i++){
      if (data[i] < smallest){
        smallest = data[i];
        location = i;
      }
    }
    //swap smallest value with first number in the unsorted sequence
    int temp = data[counter];
    data[counter] = smallest;
    data[location] = temp;
    //increment counter by 1 as the sorted list just grew 1 number larger
    counter++;
    //recursively call sort
    sortv2(data,len,counter);
    return;
  }
  return;
}

//sortv2 is basically sort but with an extra parameter to keep track of the sorted part of the list
void sortv2(int *data, int len, int sorted) {
  int location;

  if (sorted+1 == len){
    return;
  }

  else {
      //find the smallest value in array (and the location of the smallest value)
    int smallest = data[sorted];
    location = sorted;
    for (int i = sorted+1; i<len; i++){
      if (data[i] < smallest){
        smallest = data[i];
        location = i;
      }
    }
    //swap smallest value with first number in the unsorted sequence
    int temp = data[sorted];
    data[sorted] = smallest;
    data[location] = temp;
    //increment counter by 1 as the sorted list just grew 1 number larger
    sorted++;
    //recursively call sort
    sortv2(data,len,sorted);
    return;
  }
  return;
}