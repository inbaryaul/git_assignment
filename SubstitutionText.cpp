#include "SubstitutionText.h"


#define ABC_NUM 26

SubstitutionText::SubstitutionText(string text, fstream& dictionary) : PlainText(text)
{
	int i = 0;
	while (i < ABC_NUM)
	{
		getline(dictionary, _dictionary[i]);
		i++;
	}
	_text = encrypt(text, dictionary);
}

void SubstitutionText::decrypt(fstream& dictionary)
{
	int i = 0;
	int j = 0;

	if (isEnc())
	{
		while (_text.length() > i)
		{
			if (_text[i] >= 97 && _text[i] <= 122 || _text[i] >= 65 && _text[i] <= 90)
			{
				while (_dictionary[j][2] != _text[i])
							{
								j++;
							}
							_text[i] = _dictionary[j][0];
							j = 0;
			}
			
			i++;
		}

		_isEnc = false;
	}
	else
	{
		DecryptException de = de.what();
		throw de;
	}
}
	


string SubstitutionText::encrypt(string text, fstream& dictionary)
{
	int i = 0;
	int j = 0;	


	while (text.length() > i)
	{
		if (text[i] >= 97 && text[i] <= 122 || text[i] >= 65 && text[i] <= 90)
		{
			while (_dictionary[j][0] != text[i])
			{
				j++;
			}
			text[i] = _dictionary[j][2];
			j = 0;
		}
		
		i++;
	}
	_isEnc = true;

	return text;
}