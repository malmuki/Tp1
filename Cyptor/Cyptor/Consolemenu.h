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