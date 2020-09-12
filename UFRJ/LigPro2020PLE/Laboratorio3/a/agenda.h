#include <string>
#include <vector>

using namespace std;

class Agenda
{
private:
    vector <string> nomes;
    unsigned long max;
    string
    substr(string,unsigned);

public:

    Agenda(size_t);

    /*string
    substr(size_t pos = 0, size_t n = 10) const;
*/

    void
    insereNomes(string);

    void
    mostraNomes();
};
