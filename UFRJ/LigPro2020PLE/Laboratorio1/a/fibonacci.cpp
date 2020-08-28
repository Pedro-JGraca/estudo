#include "fibonacci.h"

unsigned long long
fibonacci ( unsigned n) 
{
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
