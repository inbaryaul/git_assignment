#include "DecryptException.h"
#include <string>


using namespace std;
using std::string;

DecryptException::DecryptException(string t1) : exception(t1.c_str())
{}

const char* DecryptException::what() const
{
	return "can't decrypt text that is not encrypted.";
}