#include "ConsoleMenu.h"
#include <iostream>


void ConsoleMenu::Run()
    {
    char input;     
    char tabValidInputs[] = {'E', 'e', 'Q', 'q'};
    const int NB_ELEMENTS = 4;
    do{     
        system("cls"); 
        input = readValidInput(tabValidInputs, NB_ELEMENTS);
        }while(manageChoice(input));

    }
bool ConsoleMenu::manageChoice(char _input)
    {


    }