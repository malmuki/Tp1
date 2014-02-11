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
