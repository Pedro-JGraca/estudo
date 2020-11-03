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

bool 
operator<(filme,filme);

bool
operator>(filme,filme);



class catalogo
{
private:
    vector <filme> filmes;

public:
    
    string  
    operator+=(filme);

    string  
    operator+=(vector <filme>);
    
    bool 
    filmeIn(filme);

    void
    ordenar();

    void
    construir();

    bool 
    isEmpty(filme);

    string
    getLista();

};








#endif