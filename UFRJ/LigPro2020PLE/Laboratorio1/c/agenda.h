#include <iostream>
#include <string>

using namespace std;

#define TAMANHO_STRING                                 3

class agenda
{
private:
    string names[TAMANHO_STRING];
public:
    void 
    setNames();
    
    void
    getNames();
};
