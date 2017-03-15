#pragma once 

#include <string>
#include "DecryptException.h"
using namespace std;
using std::string;

class PlainText
{
public:
	PlainText(string text);
	bool isEnc();
	string getText();

protected:
	string _text;
	bool _isEnc;

};