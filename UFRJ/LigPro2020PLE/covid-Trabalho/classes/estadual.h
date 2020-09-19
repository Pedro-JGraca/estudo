#ifndef ESTADUAL_H
#define ESTADUAL_H

#include <iostream>
#include <vector>
#include <dirent.h>
#include "util.h"
using namespace std;


class estadual
{
private:
    unsigned char N;
    string estado;

    vector <unsigned short> dados;

    void
    setEstado(string);

public:
    estadual(string,unsigned char);

    bool
    verificaEstado(string);
    tipoErro
    listaEstados(vector <string> *);

    string
    getEstado();

    unsigned char
    getN();

    void
    importarDados();


};

#endif