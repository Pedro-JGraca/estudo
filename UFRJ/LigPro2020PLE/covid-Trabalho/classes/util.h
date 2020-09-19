#ifndef UTIL_H
#define UTIL_H

#include <iostream>
using namespace std;

typedef enum {
ok,
numeroArgumentosInvalido,
erroDesconhecido

}tipoErro;

class util
{
private:
    /* data */
public:
    util(/* args */);

    void
    showInicial();
    tipoErro
    showH(string help, string comando, int numeroArgumentos);
};

#endif