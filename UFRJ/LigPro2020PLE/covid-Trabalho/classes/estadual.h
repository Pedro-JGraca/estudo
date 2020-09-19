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

    tipoErro
    setEstado(string);
    
public:
    estadual(string,unsigned char);


    tipoErro
    listaEstados(vector <string> *);


};

#endif