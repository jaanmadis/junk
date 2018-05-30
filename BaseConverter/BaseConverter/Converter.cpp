#include "stdafx.h"
#include <string>

#include "Converter.h"

using namespace std;

Converter::Converter(int input = 0, char *symbols = NULL)
	:_input(input)
{
	if (!symbols) {
		_symbols = { '0', '1' };
	}
	else
	{
		char symbol;
		int i = 0;
		while (true)
		{
			symbol = symbols[i];
			if (symbol == '\0')
			{
				break;
			}
			_symbols.push_back(symbol);
			++i;
		}
	}
}

string Converter::Convert()
{
	string result;
	if (_input == 0)
	{
		result = _symbols[0];
	}
	else
	{
		int base = _symbols.size();
		int remainder = _input;
		while (remainder > 0)
		{
			result = _symbols[remainder % base] + result;
			remainder = remainder / base;
		}
	}
	return result;
}
