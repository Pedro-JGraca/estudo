#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include "aresta.h"
#include "vertice.h"
using namespace std;

class grafo
{
private:
    vector <string> linha;
    

public:
    vector <vertice> vertices;

    grafo(string entrada = "");

    void
    getLinha();

    string
    getMaior();
    
    void
    setCaminho(string);

    void
    setAresta(string, string);

    void
    setVertice(string);

    bool
    verificaVertice(string);

    vertice *
    encontraVertice(string);

    string
    strip(string);

    string
    getSequencia( unsigned);

};



#endif