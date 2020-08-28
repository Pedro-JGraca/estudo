#include <iostream>
#include "fibonacci.h"

using namespace std;

int 
main(int argc, char const *argv[])
{
    unsigned entrada;
    
    cout << "entre com: ";
    cin >> entrada;

    cout << fibonacci(entrada) << endl;

    return 0;
}