#ifndef PROXY_H
#define PROXY_H
#include <iostream>
#include <vector>
#include "catalogo.h"

#define NUMERO_ARGUMENTOS                   3
#define ARQUIVO                 "./BD/catalogo.txt"
#define BUFFER                              500
#define EOS                                 '\0'
using namespace std;


typedef enum {
    ok,
    numeroArgumentosInvalido,
    numeroArgumentosInvalidoParaComando,
    erroAbrirArquivo,
    arquivoCorrompido,
    comandoNaoAchado,
    Ninvalido,
    filmeNaoAchado,
    erroDesconhecido
}tipoErro;



class proxyCatalogo
{
private:

    tipoErro erro;

    catalogo Catalogo; 

public:

    proxyCatalogo();

    catalogo
    getCatalogo();

    tipoErro
    getErro();

    double 
    paraDouble(string);

    string
    help(string argv, string);

    tipoErro 
    lerBD();

    void
    listarCatalogo();

    void 
    listarFilmes();

    string
    melhorFilme();

    void
    removerFilme(string Filme);

    bool
    buscarFilme(string Filme);

    tipoErro 
    listarFilme(string Filme);

    string
    inserirFilme(string Filme, string Produtora, string Nota);

    tipoErro 
    editarFilme(string Filme, string Produtora, string Nota);
    
    tipoErro
    escreverBD();

    tipoErro
    editarProdutora(const string Filme, string Produtora);

    tipoErro
    editarNota(const string Filme, string Nota);

    tipoErro
    editarNome(const string Filme, string Nome);
    

};






const vector <string> comandos = {"help","listarCatalogo","listarFilmes","melhorFilme","help","removerFilme","buscarFilme","listarFilme","editarNome","editarProdutora","editarNota","inserirFilme","editarFilme"};

const vector <unsigned short> rang = {0,4,8,11,12};



#endif