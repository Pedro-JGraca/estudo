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
    
    string primeiro = argv[1];
    string segundo = argv[2];
    
    if (primeiro=="help") {
        erros = utils.showH(primeiro,segundo,argc);
        return erros;
    }

    return ok;
}
