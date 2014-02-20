/** @file Cryptor.cpp
Fichier contenant les definitions des fonctions et methodes de ConsoleMenu.h
@author   Alex Moreau
@author   Francois Chantal
@date     21 fevrier 2014
@version  1.2
*/

#include "ConsoleMenu.h"
#include "Crypthor.h"
#include <iostream>

using namespace std;

/**
Fonction qui contient la boucle pricipale du menu et la liste d'entrer possible de clavier.
*/
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
/**
Fonction qui determine l'action a prendre selon le choix de l'utilisateur.
@param[in] _input l'entrer validé
@return selon le choix de l'utilisateur
@see readValidInput
*/
bool ConsoleMenu::manageChoice(char _input)
    {
    bool choix;
    Crypthor cryptor;
    string password;
    string clef;
    switch (_input)
        {
        case 'Q':
        case 'q' :
            choix = false;
            break;
        case 'E':
        case 'e' :
            cout << "entrer un mot de passe a cryter" << endl;
            bool verifier;
            do {
                verifier = false;
                getline(cin,password);
                if(password.length() != 0 && password.length() <= 64){
                    verifier = true;
                    }else{
                        cout << "entrer un mot de passe a cryter Valide(en dessous de 64 characteres)" << endl;
                    }
                }while(!verifier);

            cout << endl << "entrer la clef de cryptage" << endl;
            do {
                verifier = false;
                getline(cin,clef);
                if(clef.length() != 0 && clef.length() <= 16){
                    verifier = true;
                    }else{
                        cout << "entrer une clef de cryptage Valide(en dessous de 16 characteres)" << endl;
                    }
                }while(!verifier);
            cryptor.Crypt(password,clef);
            cout << cryptor.Crypt(password,clef) << endl;
            system("pause");
            choix = true;

            break;
        }
    return choix;
    }
/*
Fonction qui demande une entrée clavier et qui determine si elle est valide.
Affiche le menu.
@param[in] _tabValidInputs[] la table des entrée valide
@param[in] _nbElements le nombre d'element valide possible
@return l'entré valide
@see manageChoice
@see displayMenu
*/
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
            cout << "le type d'entré est invalide!";
            }
        }while(!valid);
    return input[0];
    }
/*
fonction qui affiche le menu principal.
*/
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