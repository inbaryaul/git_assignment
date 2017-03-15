#include "PlainText.h"
#include <string.h>
#include <iostream>



PlainText::PlainText(string text)
{
	_text = text;
	_isEnc = false;
}

bool PlainText::isEnc()
{
	return _isEnc;
}

string PlainText::getText()
{
	return _text;
}