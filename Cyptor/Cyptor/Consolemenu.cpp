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
            choix = false;
            break;
        case 'q' :
            choix = false;
            break;
        case 'E':
            cout << "entrer un mot de passe a cryter" << endl;
            cin >> password;
            cout << endl << "entrer la clef de cryptage" << endl;
            cin >> clef;
            cout << cryptor.Crypt(password,clef) << endl;
            system("pause");
            choix = true;
            break;
        case 'e' :
            cout << "entrer un mot de passe a cryter" << endl;
            cin >> password;
            cout << endl << "entrer la clef de cryptage" << endl;
            cin >> clef;
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
    char input;
    bool valid = false;

    displayMenu();

    do {
        cin >> input;

        for (int i = 0; i < _nbElements; i++)
            {
            if (_tabValidInputs[i] == input)
                {
                valid = true;
                }
            }
        if (!valid){
                cout << "le type d'entré est invalide!";
                }
        }while(!valid);
    return input;
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