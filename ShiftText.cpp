#include "ShiftText.h"
#include "DecryptException.h"
#include <string.h>
#include <iostream>


ShiftText::ShiftText(string text, int key) : PlainText(text)
{
	_key = key;
	_text = encrypt(_text, key);

}

void ShiftText::decrypt(int key) 
{

	int i = 0;
	char let = ' ';
	
	if (isEnc())
	{
		_text = encrypt(_text, -1 * key);
		_isEnc = false;
	}
	else
	{
		DecryptException de = de.what();
		throw de;
	}
	
	
}

string ShiftText::encrypt(string text, int key) 
{
	int i = 0;
	char let = ' ';

	for (i = 0; i < text.length(); i++)
	{
		text[i] = tolower(text[i]);
		if (text[i] >= 97 && text[i] <= 122)
		{
			let = text[i] + (key % 26);
			if (let > 122)
			{
				let -= 26;
			}
			else if (let < 97)
			{
				let += 26;
			}
		}
		else
		{
			let = text[i];
		}
		text[i] = let;
	}

	_isEnc = true;
	
	return text;
}