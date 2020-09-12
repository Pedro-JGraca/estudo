#include <string>
#include <array>

using namespace std;

class Agenda
{
private:
    static const unsigned maxNomes = 10;
    static unsigned numerosNomes;
    array <string, maxNomes> nomes;
    
    string
    substr(string,unsigned);

public:

    Agenda();

    void
    insereNomes(string);

    void
    mostraNomes();
};
