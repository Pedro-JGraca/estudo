#ifndef NACIONAL_H
#define NACIONAL_H
#include "covid.h"
#include "estadual.h"

class nacional
{
private:
    /* data */
    unsigned char n;
    vector <estadual> estados;
    vector <string> listaEstados;

    bool
    verificaTamanho();

public:
    nacional(unsigned char);
    void
    somaMovel(vector <unsigned>*);
    void
    mediaMovel(vector <unsigned> *);
    void
    porcentagemMovel(vector <float> *);
    float
    porcent(unsigned short a, unsigned short b);
};


#endif