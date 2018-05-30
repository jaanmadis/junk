#pragma once
#include <string>
#include <vector>

using namespace std;

class Converter
{
public:
	Converter(int input, char *symbols);
	string Convert();
private:
	const int _input;
	vector<char> _symbols;
};
