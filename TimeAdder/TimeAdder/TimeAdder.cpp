// TimeAdder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

set<string> exitCodes = { "q", "Q" };
set<string> helpCodes = { "h", "H" };

bool isCode(const set<string>& codes, const string& input) {
	return codes.count(input);
}

bool isModifier(const string& input) {
	return regex_match(input, regex("x[0-9]+((.|,)[0-9]+)?"));
}

bool isTime(const string& input) {
	return regex_match(input, regex("([0-9]+(.|,|:)([0-9]|[0-5][0-9])(.|,|:)([0-9]|[0-5][0-9]))|(([0-9]|[0-5][0-9])((.|,|:)([0-9]|[0-5][0-9]))?)"));
}

size_t getLastSeparatorPos(const string& input, const size_t pos) {
	vector<char> separators{ '.', ',', ':' };
	size_t result = input.npos;
	for (vector<char>::iterator it = separators.begin(); it != separators.end(); ++it) {
		result = input.find_last_of(*it, pos);
		if (result != input.npos) {
			break;
		}
	}
	return result;
}

void split(const string& input, vector<int>& output) {
	size_t currSeparator = input.npos;
	size_t lastSeparator = input.npos;
	string fragment;
	do {
		currSeparator = getLastSeparatorPos(input, lastSeparator);
		fragment = input.substr(
			currSeparator == input.npos
				? 0
				: currSeparator + 1, 
			lastSeparator == input.npos 
				? input.npos 
				: lastSeparator - currSeparator);
		lastSeparator = currSeparator - 1;
		output.push_back(stoi(fragment));
	} while (currSeparator != input.npos);
}

float getModifier(const string& input, const bool trustInput = false) {
	float result = 0;
	if (trustInput || isModifier(input)) {
		vector<int> fragments;
		split(input.substr(1), fragments);
		return fragments[1] + fragments[0] / 10;
	}
	return result;
}

float getTime(const string& input, const bool trustInput = false) {
	float result = 0;
	if (trustInput || isTime(input)) {
		vector<int> fragments;
		split(input, fragments);
		cout << fragments[0] << '\n';
		cout << fragments[1] << '\n';
		cout << fragments[2] << '\n';
	}
	return result;
}

void handleHelp() {
	printf("h - help\n");
	printf("q - quit\n\n");
}

/*
Return vector is constructed with two iterators (fist, last):
	istream_iterator constructed with input string is first,
	default constructed istream_iterator is finished by default.
*/

// copy the string? reference the string??

vector<string> splitx(const string& input) {
	istringstream iss(input);
	istream_iterator<string> first(iss);
	istream_iterator<string> last;
	vector<string> result(first, last);
	return result;
}

vector<string> split(const string& input, const char& delimiter) {
	vector<string> result = { "not", "implemented" };
	return result;
}

/*
	Default modifier to 1.
	Default time to 0.
	Loop until exit character is found.
	Display help when help character is found.
	Change modifier when input xNUMBER is found.
Add to time when input NUMBER is found.
Subtract from time when -NUMBER is found.
	Ignore input that can't be understood, doesn't match the pattern.
	Print time x modifier = result upon exit.
*/

int main()
{
	float modifier = 1;
	int time = 0;
	string input;

	do {
		cin >> input;
		if (isCode(helpCodes, input)) {
			handleHelp();
		}
		else if (isModifier(input)) {
			modifier = getModifier(input, true);
		}
		else if (isTime(input)) {
			time = getTime(input, true);
		}
//		cout << "time=" << time << '\n';
	cout << "modifier=" << modifier << '\n';
	} while (!isCode(exitCodes, input));

	printf("%d x %f = %f\n", time, modifier, time * modifier);




	handleHelp();
	do {
		getline(cin, input);
		if (isCode(helpCodes, input)) {
			handleHelp();
		}
		else {
			vector<string> test = splitx(input);
			for (unsigned int i = 0; i < test.size(); ++i) {
				cout << test[i] << '\n';
			}
		}
	} while (!isCode(exitCodes, input));

	return 0;
}

