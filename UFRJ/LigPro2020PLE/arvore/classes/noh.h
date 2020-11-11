#ifndef NOH_H
#define NOH_H

#include "paciente.h"

class noh
{
public:
    paciente data;
    bool pintado;
    noh *anterior;
    noh *direita;
    noh *esquerda;

    noh ();
    
    noh * 
    pinta ( noh *local, paciente * l);

    bool
    operator!=(noh a);
};

#endif