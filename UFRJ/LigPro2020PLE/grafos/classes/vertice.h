#ifndef vertice_H
#define vertice_H

#include <iostream>
#include <vector>
#include "aresta.h"

using namespace std;

class vertice
{
private:
    string nome;
    vector <aresta *> recebe;
    vector <aresta *> aponta;
    unsigned short chamadas;

public:

    vertice(string);

    ~vertice();

    string
    getNome();

    void
    setChamadas();

    unsigned short
    getChamadas();
    
    void
    setRecebeAresta(aresta *);

    void
    setApontaAresta(aresta *);

    aresta *
    getAponta(unsigned short);

    unsigned short
    getApontaSize();
    unsigned short
    getBaseSize();

    aresta *
    getRecebe(unsigned short n);



    
};



#endif