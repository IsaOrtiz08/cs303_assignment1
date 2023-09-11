#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// creates an array of a given size
void init_array(int* values, int size);

//output the values in the array
void print_array(int* values, int size);

// reads values from desired file to be included in the array
void read_file(int values[]);

//required function #1: returns index of a value
int find_val(int* values, int size, int target_val);

//required function #2: modifies a value to a desired integer, outputing the original and new values
void modify_val(int* values,int size, int index);

//required function #3: add a new value to the array
void add_val(int* values, int new_int);

//Required function #4: removes a value from array
void remove_val(int* values, int index);

//Displays options and takes user input for which action to take until q is inputed
void menu(int* values, int size);