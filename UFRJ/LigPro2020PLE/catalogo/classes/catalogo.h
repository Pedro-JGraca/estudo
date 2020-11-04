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

    string
    operator-=(filme);

    friend ostream & operator<<(ostream &, const catalogo);
    
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

    string
    getFilmes();

    string
    getNomes();

    filme*
    getFilmeMaiorNota();

    void
    getFilmeByNome(string Nome, filme *);

    filme*
    operator()(string nome);

    filme*
    operator()(const string nome, string novaProdutora);

    filme*
    operator()(const string nome, double novaNota);

    void
    novoNome(const string Entrada, string novoNome);

    unsigned short 
    getTamanho();

    filme
    getFilmebyIndex(unsigned short index);

};


istream & operator>>(istream &input, filme &saida);
ostream & operator<<(ostream &output, const filme A);
ostream & operator<<(ostream &output, const catalogo A);





#endif