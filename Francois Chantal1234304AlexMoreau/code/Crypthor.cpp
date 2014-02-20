/** @file Cryptor.cpp
Fichier contenant les definitions des fonctions et methodes de Cryptor.h
@author   Alex Moreau
@author   Francois Chantal
@date     21 fevrier 2014
@version  1.2
*/

#include "Crypthor.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

/*
Fonction qui permet de cryper un mot de passe grace a la clef de cryptage.
@param[in] _Password mot de passe a crypter
@param[in] _Key  clef de cryptage du mot de passe
@return le mot de passe crypter
@see cryptChar
@see convertCharToHex
*/
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
/*
Fonction qui additionne les valeures integrales des characteres
du mot de passe et de la clef de cryptage et inverse les bit du resultat.
@param[in] _charPassword un charactere du mot de passe
@param[in] _charKey un caractere de la clef de cryptage
@return le charactere avec les bits inverser
*/
char Crypthor::cryptChar(char _charPassword, char _charKey)
    {
    int temp = _charPassword + _charKey;
    int resultat = ~temp;
    //cout << resultat;
    return resultat;
    }

/*
utilise le charactere crypter et le convertie en hexadecimal
@param[in] _char le char crypter
@return l'hexadecimal du char crypter dans un string
*/
string Crypthor::convertCharToHex(char  _char)
    {
    int charactere = _char;

    stringstream hexa;

    hexa << hex << charactere;

    return hexa.str();
    }