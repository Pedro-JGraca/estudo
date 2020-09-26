#ifndef COVID_H
#define COVID_H

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
    dataInvalida,
    erroDesconhecido
}tipoErro;

class covid
{
private:

    tipoErro
    showH(vector <string> argv, int numeroArgumentos);

    unsigned char
    nizador(string);

    tipoErro
    setData();

    unsigned short dia;
    unsigned short mes;
    unsigned short ano;


    unsigned short
    strTouc(string a);

public:

    covid();


    void
    showInicial();

    tipoErro
    entrada(vector <string> argv, int numeroArgumentos);

    bool
    isDigit(string);

    string
    datar(unsigned);
};

const vector <string> comandos = {"help","mediaMovelEstado","mediaMovelNacao","categoriaEstado","categoriaNacao","extremos","acumuladoEstado","acumuladoNacao"};


#endif