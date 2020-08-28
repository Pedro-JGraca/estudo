#include "fibonacci.h"

unsigned long long
fibonacci::computeFibonacci(){
    unsigned primeiro = 0;
    unsigned segundo = 1;
    unsigned long long resultado = primeiro;
    if (n > 1)
    {
        resultado = segundo;
    }
    while (n>2)
    {
        resultado = segundo + primeiro;
        n--;
        primeiro = segundo;
        segundo = resultado;       
    }
    return resultado;
}

void 
fibonacci::setFibonacci (unsigned serie) {
    n = serie;
    resultado = computeFibonacci();
}
unsigned long long 
fibonacci::getFibonacci (){
    return resultado;
}
    

