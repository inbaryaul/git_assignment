#pragma once 

#include <string>
#include "ShiftText.h"

using namespace std;

class Shift3Text : public ShiftText
{
public:
	Shift3Text(string text);
	void decrypt();

};