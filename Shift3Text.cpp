#include "ShiftText.h"
#include "Shift3Text.h"
#include <string.h>
#include <iostream>


Shift3Text::Shift3Text(string text) : ShiftText(text,3)
{
}

void Shift3Text::decrypt()
{
	ShiftText::decrypt(3);
}