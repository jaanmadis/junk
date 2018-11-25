#include "stdafx.h"
#include <iostream>

#include "Converter.h"

vector<char> init(char* input) {
	vector<char> result;
	char symbol;
	int i = 0;
	while (true) {
		symbol = input[i];
		if (symbol == '\0') {
			break;
		}
		result.push_back(symbol);
		++i;
	}
	return result;
}

int digitValue(char& digit, vector<char>& symbols) {
	int result = 0;
	for (vector<char>::iterator it = symbols.begin(); it != symbols.end(); ++it) {
		if (*it == digit) {
			return result;
		}
		++result;
	}
	return 0;
}

Converter::Converter(char* digits, char* symbols)
{
	_digits = init(digits);
	_symbols = init(symbols);
}

int Converter::Convert()
{
	if (_digits.empty() || _symbols.empty()) {
		return 0;
	}
	int base = _symbols.size();
	int powersOfBase = 1;
	int result = 0;
	for (vector<char>::reverse_iterator it = _digits.rbegin(); it != _digits.rend(); ++it) {
		int value = digitValue(*it, _symbols);
		result = value * powersOfBase + result;
		powersOfBase = powersOfBase * base;
	}
	return result;
}