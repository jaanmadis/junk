#include <vector>

using namespace std;

class Converter
{
public:
	Converter(char* input);
	int Convert();
private:
	vector<bool> _binary;
};