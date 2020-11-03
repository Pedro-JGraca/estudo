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
    erroDesconhecido
}tipoErro;



class proxyCatalogo
{
private:

    tipoErro erro;

    catalogo Catalogo; 

public:

    proxyCatalogo();

    tipoErro
    getErro();

    double 
    paraDouble(string);

    string
    help(string argv, string);

    tipoErro 
    construirPersistencia();

    void
    listarCatalogo();

    void 
    listarFilmes();

    string
    melhorFilme();

    string
    removerFilme(string Filme);

    bool
    BuscarFilme(string Filme);

    void 
    ListarFilme(string Filme);

    string
    inserirFilme(string Filme, string Produtora, string Nota);

    void
    editarFilme(string Filme, string Produtora, string Nota);
    
    void
    escreverBD();
    

};






const vector <string> comandos = {"help","listarCatalogo","listarFilmes","melhorFilme","help","removerFilme","buscarFilme","listarFilme","inserirFilme","editarFilme"};

const vector <unsigned short> rang = {0,4,8,10};



#endif