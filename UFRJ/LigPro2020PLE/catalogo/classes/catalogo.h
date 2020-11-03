#ifndef CATALOGO_H
#define CATALOGO_H

#include <iostream>
#include <vector>
using namespace std;

#define MAXIMO              10


typedef struct
{
    string nome;
    string produtora;
    double nota;
}filme;

bool 
operator==(filme,filme);


class catalogo
{
private:
    vector <filme> filmes;

public:
    
    void 
    operator+=(filme);
    
    bool 
    filmeIn(filme);


    bool 
    isEmpty(filme);

    string
    getLista();

};








#endif