/*
* Author: Joshua McKinniss
*
* Date: 3/23/2023
*
* Purpose of code: Solution for day 2 of advent of code 2015
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int Part1() {
	fstream file;
	string line;
	int l, w, h;
	size_t pos;
	int sum = 0;

	//Open and parse file
	file.open("Text.txt");
	while (!file.eof()) {
		getline(file, line);

		//breaks the string down
		pos = line.find('x');
		l = stoi(line.substr(0, pos));
		line = line.substr(pos + 1, line.size() - 1);
		pos = line.find('x');
		w = stoi(line.substr(0, pos));
		h = stoi(line.substr(pos + 1, line.size() - 1));

		//finds the sum of paper needed for this box and adds it to sum
		//sorry for the bad code here I couldn't be bothered to improve it
		sum += (2 * l * h) + (2 * w * h) + (2 * l * w);
		if ((l * h) < (w * h)) {
			if ((l * h) < (l * w)) {
				sum += l * h;
			}
			else {
				sum += l * w;
			}
		}
		else {
			if ((w * h) < (l * w)) {
				sum += w * h;
			}
			else {
				sum += l * w;
			}
		}
	}
	return sum;
}


int Part2() {
	fstream file;
	string line;
	int l, w, h;
	size_t pos;
	int sum = 0;

	//Open and parse file
	file.open("Text.txt");
	while (!file.eof()) {
		getline(file, line);

		//breaks the string down
		pos = line.find('x');
		l = stoi(line.substr(0, pos));
		line = line.substr(pos + 1, line.size() - 1);
		pos = line.find('x');
		w = stoi(line.substr(0, pos));
		h = stoi(line.substr(pos + 1, line.size() - 1));

		//finds the sum of ribbon needed for this box and adds it to sum
		//sorry for the bad code here I couldn't be bothered to improve it
		sum += l * w * h;
		if ((l * h) < (w * h)) {
			if ((l * h) < (l * w)) {
				sum += l + l + h + h;
			}
			else {
				sum += l + l + w + w;
			}
		}
		else {
			if ((w * h) < (l * w)) {
				sum += w + w + h + h;
			}
			else {
				sum += l + l + w + w;
			}
		}
	}
	return sum;
}

int main() {
	
	int result = 0;

	//comment out the part you are not solving to use this code
	//result = Part1();
	result = Part2();

	//Output result
	cout << result << endl;

	return 0;
}
