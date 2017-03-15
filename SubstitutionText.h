#pragma once 

#include <string>
#include <iostream>
#include <fstream>
#include "ShiftText.h"

using namespace std;

class SubstitutionText : public PlainText
{
public:
	SubstitutionText(string text, fstream& dictionary);
	void decrypt(fstream& dictionary);

protected:
	string encrypt(string text, fstream& dictionary);
	
	string _dictionary[26];

};