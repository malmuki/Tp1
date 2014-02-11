#include <string>

using namespace std;

class Crypthor
    {
    public:
        string Crypt(string entreePassword, string entreeKey);
    private:
        bool manageChoice(char _input);
        char readValidInput(char  _tabValidInputs[], int _nbElements);
    };
