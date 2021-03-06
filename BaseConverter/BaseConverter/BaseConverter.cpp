#include "stdafx.h"
#include <iostream>

#include "Converter.h"

using namespace std;

// Expected: 1) base10 number 2) target-base digit symbols (binary by default)
int main(int argc, char *argv[])
{
	if (!argv[1])
	{
		return 0;
	}
	Converter converter(
		strtol(argv[1], NULL, 10), 
		argv[2] ? argv[2] : NULL);
	cout << converter.Convert();
	return 0;
}
