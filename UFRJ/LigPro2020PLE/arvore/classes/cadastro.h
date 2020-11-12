#ifndef CADASTRO_H
#define CADASTRO_H
#include <iostream>
#include <vector>

#include <fstream>

#include "../main.h"
#include "paciente.h"
#include "arvoret.h"

#define ARQUIVO                 "./BD/arvore.txt"

using namespace std;

typedef enum {
    ok,
    numeroArgumentosInvalido,
    numeroArgumentosInvalidoParaComando,
    comandoNaoAchado,
    pacienteNaoAchado,
    bancoDeDadosNaoAchado,
    bancoDeDadosCorrompido,
    arvoreCorrompida,
    erroDesconhecido
}tipoErro;

class cadastro
{
private:
    /* data */
    tipoErro erroBD = ok;

    ArvoreT<paciente> arvore;
    tipoErro
    lerBD();

    tipoErro
    escreverBD(string n);

    string
    iniciarBD();  

public:
    cadastro(/* args */);

    paciente*
    inserir(string nome);

    paciente*
    buscar(string nome);
    
    void
    imprimir();

    tipoErro
    getErroBD();

    
    string saida;

    ~cadastro();
};

#endif 