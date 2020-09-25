#include "classes/covid.h" //typedef
#include "classes/estadual.h"
#include <iostream>
#include <vector>
using namespace std;

int
main(int argc, char const *argv[])
{
    covid analise;
    tipoErro erros;
    if (argc < 2) {
        analise.showInicial();
        return ok;
    }
    
    vector <string> entrada;
    for (unsigned char i=0; i<(argc-1) ;i++){
        entrada.push_back(argv[i+1]);
    }

    //
    
    erros = analise.entrada(entrada,argc);
   
 

    return erros;
}
