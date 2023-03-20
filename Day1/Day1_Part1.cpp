/*
* Author: Joshua McKinniss
* 
* Date: 3/20/2023
* 
* Purpose of code: Solution for day 1 of advent of code 2015
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Go character by character and change the floor 
int Part1(string input) {
	int floor = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			floor++;
		}
		else {
			floor--;
		}
	}
	return floor;
}

//Go character by character and change the floor 
//and check if floor is negative and return the character number 
//that caused it to go negative
int Part2(string input) {
	int floor = 0;
	
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			floor++;
		}
		else {
			floor--;
			if (floor < 0) {
				return i + 1;
			}
		}
	}
	return floor;
}

int main() {
	fstream file;
	string input;
	int result = 0;

	//Open and parse file
	file.open("Text.txt");
	getline(file, input);

	//comment out the part you are not solving to use this code
	//result = Part1(input);
	result = Part2(input);

	//Output result
	cout << result << endl;

	return 0;
}
