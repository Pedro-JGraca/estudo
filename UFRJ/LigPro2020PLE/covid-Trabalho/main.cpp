#include "classes/util.h" //typedef


int
main(int argc, char const *argv[])
{
    util utils;
    tipoErro erros;
    if (argc < 2) {
        utils.showInicial();
        return ok;
    }
    
    vector <string> entrada;
    for (unsigned char i=0; i<(argc-1) ;i++){
        entrada.push_back(argv[i+1]);
    }
   
    if (entrada[0]=="help") {
        erros = utils.showH(entrada,argc);
        return erros;
    }

    return ok;
}
