#include <vector>

using namespace std;

class Converter
{
public:
	Converter(char* digits, char* symbols);
	int Convert();
private:
	vector<char> _digits;
	vector<char> _symbols;
};
