/** @file ConsoleMenu.h
Fichier contenant les entêtes de fonctions et procédures ainsi
que les déclarations de constantes.
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
