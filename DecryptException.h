#pragma once 

#include <string>
#include <exception>

using namespace std;
using std::string;

class DecryptException : public exception
{
public:
	DecryptException(string t1);
	const char* what() const;
		
};