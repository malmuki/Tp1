#include "Crypthor.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

string Crypthor::Crypt(string _Password, string _Key)
{
	string crypter;
	string finalHexa;
	char needsConvert;
	int j = 0;
	

	for (int i = 0; i <= _Password.length()-1; i++)
	{
		needsConvert = cryptChar(_Password[i], _Key[j]);
		finalHexa = convertCharToHex(needsConvert);

		crypter += finalHexa;

		j++;
		if (j == _Key.length())
		{
			j = 0;
		}
	}

	return crypter;
}

char Crypthor::cryptChar(char _charPassword, char _charKey)
{
	int temp = _charPassword + _charKey;
	int resultat = temp^1;

	return resultat;

}

string Crypthor::convertCharToHex(char  _char)
{
	stringstream hexa;

	hexa << hex << _char;

	return hexa.str();

}