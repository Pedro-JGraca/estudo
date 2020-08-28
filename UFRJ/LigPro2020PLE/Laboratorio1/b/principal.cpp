#include <iostream>
#include "fibonacci.h"

using namespace std;

int 
main(int argc, char const *argv[])
{
    unsigned entrada;
    fibonacci a;
    
    cout << "entre com: ";
    cin >> entrada;
    a.setFibonacci(entrada);

    cout << a.getFibonacci() << endl;

    return 0;
}