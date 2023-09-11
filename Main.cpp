#include "Functions.h"
using namespace std;

/*
Isa Ortiz-Acosta
COMP-SCI 303 - Data Structures
Assignment 1
Due 9/11/23
*/

// creates an array of a given size
void init_array(int* values, int size) {
	//fills every value with 0 so that they can be adjusted
	for (int i = 0; i < size; i++) {
		values[i] = 0;
	}
}

//output the values in the array
void print_array(int* values, int size) {
	for (int i = 0; i < size; i++) {
		//since zero is considered an empty space, do not output
		if(values[i] != 0)
			cout << values[i] << " ";
	}
	// end with a new line
	cout << endl;
}

// reads values from desired file to be included in the array
void read_file(int values[]) {
	string filename;
	int  tempVar, count = 0;
	//input file name
	cout << "Input the filename: ";
	cin >> filename;
	cout << endl;
	// begin file stream and open file
	ifstream infile;
	infile.open(filename);

	//read values from file until there are none left to receive
	while (!infile.eof()) {
		infile >> tempVar;
		// assign values to the array
		values[count] = tempVar;
		// increment the index to where values are assigned
		count++;
	}
	// close file
	infile.close();
}

//required function #1: returns index of a value
int find_val(int* values, int size, int target_val) {
	// cycle through the array to find target_val
	for (int i = 0; i < size; i++) {
		// if a value in the array matches the target_val, return the index value
		if (values[i] == target_val) {			
			return i;
		}
	}
	// if it is unable to find the target_val, return a negative integer
	return -1;
}

//required function #2: modifies a value to a desired integer, outputing the original and new values
void modify_val(int* values, int size, int index) {
	try {
		// throws an error if the input index is larger than the size of the array
		if (index > size)
			throw out_of_range("Given index is outside the size of the array");
		cout << "What would you like to change this number to? ";
		int newVal, oldVal;

		// get user input for the new value
		cin >> newVal;
		oldVal = values[index];

		// update the value utilizing the given index position
		values[index] = newVal;

		// display the original value using the index and display the new value
		cout << "Original Value: " << oldVal << endl << "New Value: " << newVal << endl;		
	}// output the error to the user and abort the function
	catch (std::out_of_range& error) {
		cout << error.what() << endl;
		return;
	}
}

//required function #3: add a new value to the array
void add_val(int* values, int new_int) {
	try {
		// function does not accept values that are less than 1
		if (new_int < 1)
			throw std::exception("Invalid integer input");
		int count = 0;
		// increment through the array using index until a zero is found ( considered an empty position in this circumstance )
		while (values[count] != 0)
			count++;

		// change the first found zero into the desired integer using the index
		values[count] = new_int;
	}

	//return an error and abort this function
	catch (std::exception& error) {
		cout << error.what() << endl;
		return;
	}
}

//Required function #4: removes a value from array
void remove_val(int* values, int index) {
	// cycle through the values starting at the index of the removed integer, as long as the end of the "real" values haven't been reached
	while (values[index + 1] != 0) {
		// replace the current integer with the value of the next integer
		values[index] = values[index + 1];
		index++;
	}

	// replaces the value at the current index position with zero to not repeat the last "real" value
	values[index] = 0;
}

//Displays options and takes user input for which action to take until q is inputed
void menu(int* values, int size) {
	// preliminary choice is set
	char choice = 'c';
	while (choice != 'q') {
		cout << "Choose An Option:" << endl << endl << 
			"1 - Find an Integer" << endl << "2 - Modify an Integer" << endl << "3 - Add an Integer" << endl << "4 - Remove an Integer" << endl << "5 - Print Array" << endl << "q - Quit" << endl;
		cin >> choice;
		if (choice == '1') {
			int value, index;
			cout << "Find which value? ";
			cin >> value; 
			index = find_val(values, size, value);
			if (index < 0)
				cout << endl << "Value was not found." << endl;
			else
				cout << endl << "The value " << value << " is at index " << index << "." << endl;
		}
		else if (choice == '2') {
			int index;
			cout << "Modify integer at which index? ";
			cin >> index;
			cout << endl;
			modify_val(values, size, index);
		}
		else if (choice == '3') {
			int new_val;
			cout << "Add which integer? ";
			cin >> new_val; 
			cout << endl;
			add_val(values, new_val); 
		}
		else if (choice == '4') {
			int index;
			cout << "Remove integer at which index? ";
			cin >> index;
			cout << endl;
			remove_val(values, index);
		}
		else if (choice == '5') {
			print_array(values, size);
		}
		else if (choice == 'q') {
			return;
		}
	}

}

int main() {
// defines array of size 150
	const int size = 150;
	int values[size];
	//initializes array
	init_array(values, size);
	read_file(values);
	//begin user input for adjustments to array
	menu(values, size);
}
