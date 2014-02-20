/** @file Cryptor.h
Fichier contenant les ent�tes de fonctions et proc�dures ainsi
que les d�clarations de constantes.
@author   Alex Moreau
@author   Francois Chantal
@date     21 fevrier 2014
@version  1.2
*/

#pragma once
#include <string>

using namespace std;

class Crypthor
    {
    public:
        string Crypt(string _Password, string _Key);
    private:
        char cryptChar(char _charPassword, char _charKey);
        string convertCharToHex(char  _char);
    };
