#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
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
    showH(vector <string> argv, int numeroArgumentos);
};

#endif