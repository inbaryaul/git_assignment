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
		_isEnc = false;
		_text = encrypt(_text, 26-key);
	}
	else
	{
		DecryptException de = de.what();
		throw de;
	}
	
	
}

string ShiftText::encrypt(string text, int key) 
{
	for (int i = 0; i < text.length() ; i++)
	{
		if(!(text[i] == ' ' || text[i] == ',' || text[i] == '.'))
			text[i] = (text[i]-'a' + key) % 26 + 'a';
	}

	_isEnc = true;
	
	return text;
}