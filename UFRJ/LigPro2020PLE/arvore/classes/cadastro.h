#ifndef CADASTRO_H
#define CADASTRO_H
#include <iostream>
#include <vector>

#include <fstream>

#include "../main.h"
#include "arvore.h"
#include "paciente.h"

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
    vector <paciente> arvore; // depois mudar para a classe arvore!

    tipoErro
    lerBD();

    tipoErro
    escreverBD();

    void
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

    

    ~cadastro();
};

#endif 