/** @file ConsoleMenu.h
Fichier contenant les ent�tes de fonctions et proc�dures ainsi
que les d�clarations de constantes.
@author   Alex Moreau
@author   Francois Chantal
@date     21 fevrier 2014
@version  1.2
*/

#pragma once
class ConsoleMenu
    {
    public:
        void Run();
    private:
        bool manageChoice(char _input);
        char readValidInput(char  _tabValidInputs[], int _nbElements);
        void displayMenu();
    };
