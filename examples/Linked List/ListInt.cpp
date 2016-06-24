#include <iostream>
#include "ListInt.h"

using namespace std;

  // Initialize an empty list
ListInt::ListInt()
{
  cout << "***Creating ListInt object" << endl;
  head = NULL;
}

// Destructor (free all memory for each item)
ListInt::~ListInt()
{
  cout << "***Deleteing ListInt object" << endl;
  IntItem *tmp;
  // Add your code here to delete all IntItem structures in the list

}

// Returns true if the list is empty
bool ListInt::is_empty()
{
	if (head == NULL) {
		return true;
	}

	return false;
}

// Returns the number of items in the list 
int ListInt::size()
{
	int count = 0;
	IntItem* temp = head;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

// Prints each integer item in the list (separated by a space)
void ListInt::print_list()
{
	IntItem* temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}

}

// Add a new integer, new_val, to the back of the list
void ListInt::push_back(int new_val)
{
	IntItem* newItem = new IntItem;
	newItem->val = new_val;
	newItem->next = NULL;

	if (head == NULL) {
		head = newItem;
	}

	else {
		IntItem* temp = head;
	
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newItem;	
	}

}

// Add a new integer, new_val, to the front of the list
// pushing every other item back one
void ListInt::push_front(int new_val)
{
	IntItem* newItem = new IntItem;
	newItem->val = new_val;
	newItem->next = NULL;

	if (head == NULL) {
		head = newItem;
	}

	else {
		IntItem* temp = head;
		newItem->next = temp;
		head = newItem;
	}

}

// Remove the front item it there is one, returning its value
// and deleting it from the list
int ListInt::pop_front()
{
	if (head != NULL) {
		IntItem* Dead = head;
		IntItem* newHead = Dead->next;
		head = newHead;
		return Dead->val;	
	}
	return 0;
}

// Return the item value at the front of the list
int ListInt::front()
{
	if (head != NULL) {
		return head->val;
	}
	return 0;
}


// IntItem *ListInt::find(int find_val)
// {

// }

// bool ListInt::remove(int del_val)
// {

// }

// ListInt &ListInt::operator+(const ListInt &rhs)
// {

// } 


