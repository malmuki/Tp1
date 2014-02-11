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
    for (int i = 0; i <= crypter.length()-1; i++)
	{
		crypter[i] = toupper(crypter[i]);
	}

    return crypter;
    }

char Crypthor::cryptChar(char _charPassword, char _charKey)
    {
    int temp = _charPassword + _charKey;
    int resultat = ~temp;
    //cout << resultat;
    return resultat;
    }

string Crypthor::convertCharToHex(char  _char)
    {
    int charactere = _char;

    stringstream hexa;

    hexa << hex << charactere;

    return hexa.str();
    }