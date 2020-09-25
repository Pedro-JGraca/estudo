#ifndef ESTADUAL_H
#define ESTADUAL_H

#include <iostream>
#include <vector>
#include <dirent.h>
#include "covid.h"
using namespace std;


class estadual
{
private:
    unsigned char N;
    string estado;

    vector <unsigned short> dados;

    void
    setEstado(string);
    
    void
    setDados(vector <unsigned short>);

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
    importarDados(vector <unsigned short>*);

    void
    somaMovel(vector <unsigned>*);
    
    void
    mediaMovel(vector <unsigned short>*);

    void
    porcentagemMovel(vector <float>*);

    float
    porcentagem(unsigned short, unsigned short);

    unsigned
    getSizeDados();


};

#endif