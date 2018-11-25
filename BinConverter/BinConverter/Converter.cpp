#include "stdafx.h"
#include <iostream>

#include "Converter.h"

Converter::Converter(char* input)
{
	for (int i = 0; input[i] != '\0'; ++i) {
		if (input[i] == '0') {
			_binary.push_back(false);
		}
		else if (input[i] == '1') {
			_binary.push_back(true);
		}
		else {
			_binary.clear();
			break;
		}
	}
}

int Converter::Convert()
{
	if (_binary.empty()) {
		return 0;
	}
	int powersOfTwo = 1;
	int result = 0;
	for (vector<bool>::reverse_iterator it = _binary.rbegin(); it != _binary.rend(); ++it) {
		if (*it == true) {
			result = result + powersOfTwo;
		}
		powersOfTwo = powersOfTwo * 2;
	}
	return result;
}