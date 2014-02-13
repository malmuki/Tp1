#include "ConsoleMenu.h"
#include "Crypthor.h"
#include <iostream>

using namespace std;

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

bool ConsoleMenu::manageChoice(char input)
    {
    bool choix;
    Crypthor cryptor;
    string password;
    string clef;
    switch (input)
        {
        case 'Q':
        case 'q' :
            choix = false;
            break;
        case 'E':
        case 'e' :
            cout << "entrer un mot de passe a cryter" << endl;
            getline(cin,password);
            cout << endl << "entrer la clef de cryptage" << endl;
            getline(cin,clef);
            cryptor.Crypt(password,clef);
            cout << cryptor.Crypt(password,clef) << endl;
            system("pause");
            choix = true;
            break;
        }
    return choix;
    }
char ConsoleMenu::readValidInput(char  _tabValidInputs[], int _nbElements)
    {
    string input;
    bool valid = false;

    displayMenu();

    do {
        getline(cin,input);

        for (int i = 0; i < _nbElements; i++)
            {
            if (_tabValidInputs[i] == input[0])
                {
                valid = true;
                }
            }
        if (!valid){
                cout << "le type d'entr� est invalide!";
                }
        }while(!valid);
    return input[0];
    }
void ConsoleMenu::displayMenu()
    {
    cout << "+------------------------------------+\n";
    cout << "+------------------------------------+\n";
    cout << "+---------------Cryptor--------------+\n";
    cout << "+------------------------------------+\n";
    cout << "+------------------------------------+\n";
    cout << "pour crypter appuyer sur e \n";
    cout << "pour quitter appuyer sur q \n";
    }
