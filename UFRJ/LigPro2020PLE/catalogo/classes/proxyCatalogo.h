#ifndef PROXY_H
#define PROXY_H
#include <iostream>
#include <vector>
#include "catalogo.h"

#define NUMERO_ARGUMENTOS                   3
#define ARQUIVO                 "./BD/catalogo.txt"

using namespace std;

class proxyCatalogo
{
private:

    catalogo Catalogo; 

public:

    string
    help(string argv, string);

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
    



};

typedef enum {
    ok,
    numeroArgumentosInvalido,
    numeroArgumentosInvalidoParaComando,
    erroAbrirArquivo,
    comandoNaoAchado,
    Ninvalido,
    erroDesconhecido
}tipoErro;





const vector <string> comandos = {"help","listarCatalogo","listarFilmes","melhorFilme","help","removerFilme","buscarFilme","listarFilme","inserirFilme","editarFilme"};

const vector <unsigned short> rang = {0,4,8,10};



#endif