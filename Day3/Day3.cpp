/*
* Author: Joshua McKinniss
*
* Date: 3/23/2023
*
* Purpose of code: Solution for day 3 of advent of code 2015
* 
* Note: This code is EXTREMELY inefficient, it will take a couple seconds to run
* I tried to make it a bit more understandable for my sake and yours but this 
* takes about 13 seconds to run on my machine for part 1 and xx for part 2
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>

using namespace std;

//using the previous co-ordinates along with the character for the move
//generates the current co-ordinates in the form of a string
string GetCoords(int* x, int* y, char move) {
	//creates co-ordinates for what house we are at
	switch (move) {
	case('<'):
		*x = *x - 1;
		break;
	case('>'):
		*x = *x + 1;
		break;
	case('v'):
		*y = *y - 1;
		break;
	case('^'):
		*y = *y + 1;
		break;
	}
	int a = *x;
	int b = *y;
	//turns the co-ordinate (x,y) into a string "x + y"
	stringstream ss, rr;
	ss << a;
	rr << b;
	string str = ss.str();
	return str + '+' + rr.str();
}

//if the current co-ordinate exists in the vector locations 
//(which is the list of co-ordinates of visited houses) return true
bool Exists(vector<string> locations, string current) {	
	for (int j = 0; j < locations.size(); j++) {
		if (current == locations[j]) {
			return true;
		}
	}
	return false;
}

int Part1(string line) {
	//these are pointers so I can affect then in the function GetCoords
	int* x = new int(0);
	int* y = new int(0);

	//adds the starting locations as visited already
	int sum = 1;
	vector<string> locations;
	locations.push_back("0+0");
	string str;

	for (int i = 0; i < line.size(); i++) {
		str = GetCoords(x, y, line[i]);
		
		//if this locations has not been visited yet, inc sum and add it to the
		//vector locations
		if (!Exists(locations, str)) {
			sum++;
			locations.push_back(str);
		}
	}
	return sum;
}

int Part2(string line) {
	//Same deal with this as in Part 1 just doubled
	int* xSanta = new int(0);
	int* ySanta = new int(0);
	int* xRobo = new int(0);
	int* yRobo = new int(0);

	//See previous comment
	int sum = 1;
	vector<string> locations;
	locations.push_back("0+0");
	string str;

	for (int i = 0; i < line.size(); i++) {
		if (i % 2 == 0) {
			//if it is santa's turn affect santa's coords
			str = GetCoords(xSanta, ySanta, line[i]);
		}
		else {
			//if it is robo's turn affect robo's coords
			str = GetCoords(xRobo, yRobo, line[i]);
		}
		//if no one has visited this locations, inc sum and add the location
		//to the vector locations
		if (!Exists(locations, str)) {
			sum++;
			locations.push_back(str);
		}
	}
	return sum;
}

int main() {
	int result = 0;

	//read the file to the string line
	string line;
	fstream file;
	file.open("Text.txt");
	getline(file, line);
	file.close();

	//comment out the part you are not solving to use this code
	//result = Part1(line);
	result = Part2(line);

	cout << result << endl;

	return 0;
}
