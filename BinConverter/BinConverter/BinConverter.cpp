// BinConverter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Converter.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (!argv[1]) 
	{
		return 0;
	}
	Converter converter(argv[1]);
	cout << converter.Convert();
	return 0;
}

