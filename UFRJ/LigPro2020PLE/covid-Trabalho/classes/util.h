#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
using namespace std;

typedef enum {
    ok,
    numeroArgumentosInvalido,
    comandoNaoAchado,
    Ninvalido,
    estadoNaoAchado,
    erroAbrirArquivo,
    erroDesconhecido
}tipoErro;

class util
{
private:

    tipoErro
    showH(vector <string> argv, int numeroArgumentos);

    unsigned char
    nizador(string);
public:
    util();

    void
    showInicial();

    tipoErro
    entrada(vector <string> argv, int numeroArgumentos);

    bool
    isDigit(string);
};

const vector <string> comandos = {"help","mediaMovelEstado","mediaMovelNacao","categoriaEstado","categoriaNacao","extremos","acumuladoEstado","acumuladoNacao"};


#endif