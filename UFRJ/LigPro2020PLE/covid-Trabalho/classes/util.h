#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
using namespace std;

typedef enum {
    ok,
    numeroArgumentosInvalido,
    comandoNaoAchado,
    erroDesconhecido
}tipoErro;

class util
{
private:
    /* data */
    tipoErro
    showH(vector <string> argv, int numeroArgumentos);
public:
    util(/* args */);

    void
    showInicial();

    tipoErro
    entrada(vector <string> argv, int numeroArgumentos);

    

};

const vector <string> comandos = {"help","mediaMovelEstado","mediaMovelNacao","categoriaEstado","categoriaNacao","extremos","acumuladoEstado","acumuladoNacao"};


#endif