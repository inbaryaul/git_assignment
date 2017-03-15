#include "ShiftText.h"
#include "SubstitutionText.h"
#include "Shift3Text.h"
#include "DecryptException.h"
#include <iostream>

#define SHIFTING_KEY 10
#define DICTIONARY_PATH "dictionary.csv"

using namespace std;

void Alice();
PlainText Bob(SubstitutionText msg);
PlainText Bob(ShiftText msg);
PlainText Bob(Shift3Text msg);

/*
This is the main function of the program.
It starts the conversation between Alice and Bob
*/
int main()
{
	Alice();
	
	cout << endl;
	system("PAUSE");
	return 0;
}

/*
This is Alice's part in the conversation.
It gets a legal string from the user ans sends it to Bob in
three different kinds of encryptions.
It also prints every response from Bob.
*/
void Alice()
{
	string msg;
	cout << "Enter a Message to send to Bob:" << endl;
	getline(cin, msg);

	cout << msg << endl;

	fstream dic;
	dic.open(DICTIONARY_PATH);
	SubstitutionText eMsg(msg, dic);

	cout << "Sending in Substitution mode" << endl;

	PlainText txt1(Bob(eMsg));
	cout << "Alice:" << endl;
	cout << "Received Back: ";
	cout << txt1.getText() << endl;

	cout << "Sending in Shift mode" << endl;
	
	ShiftText shift(msg, SHIFTING_KEY);
	PlainText txt2(Bob(shift));

	cout << "Alice:" << endl;
	cout << "Received Back: ";
	cout << txt2.getText() << endl;

	cout << "Sending in Shift-3 mode" << endl;

	Shift3Text shift3(msg);
	PlainText txt3(Bob(shift3));

	cout << "Alice:" << endl;
	cout << "Received Back: ";
	cout << txt3.getText() << endl;



	 
}

/*
This function handles Bob's part of the conversation 
when he receives a message encrypted in Substitution mode
*/
PlainText Bob(SubstitutionText msg)
{
	cout << "Bob:" << endl;
	cout << "The received message: ";
	cout << msg.getText() << endl;
	fstream dic;
	dic.open(DICTIONARY_PATH);
	try
	{
		msg.decrypt(dic);
		cout << "The decrypted message is: " << msg.getText() << endl;
	}
	catch (DecryptException de)
	{
		cout << de.what() << endl;
	}

	dic.close();
	return PlainText("Thank you Alice!");
}

/*
This function handles Bob's part of the conversation
when he receives a message encrypted in Shift mode
*/
PlainText Bob(ShiftText msg)
{
	cout << "Bob:" << endl;
	cout << "The received message: ";
	cout << msg.getText() << endl;

	try
	{
		msg.decrypt(SHIFTING_KEY);
		cout << "The decrypted message is: " << msg.getText() << endl;
	}
	catch (DecryptException de)
	{
		cout << de.what() << endl;
	}

	return PlainText("Thank you again Alice!");
}

/*
This function handles Bob's part of the conversation
when he receives a message encrypted in Shift-3 mode
*/
PlainText Bob(Shift3Text msg)
{
	cout << "Bob:" << endl;
	cout << "The received message: ";
	cout << msg.getText() << endl;

	try
	{
		msg.decrypt();
		cout << "The decrypted message is: " << msg.getText() << endl;
	}
	catch (DecryptException de)
	{
		cout << de.what() << endl;
	}

	return PlainText("Thank you again Alice!");
	return PlainText("Many Thanks Alice!");
}