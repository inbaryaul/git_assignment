#pragma once 

#include <string>
#include "PlainText.h"

using namespace std;
using std::string;

class ShiftText : public PlainText
{
public:
	ShiftText(string text, int key);
	void decrypt(int key);

private:
	string encrypt(string text, int key);
	int _key;
};