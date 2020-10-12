#ifndef TRATAMENTI_H
#define TRATAMENTO_H
#include <iostream>
#include <vector>

#define BUFFER                              500
#define NUMERO_ARGUMENTOS                   3

typedef enum {
    ok,
    numeroArgumentosInvalido,
    erroAbrirArquivo,
    comandoNaoAchado,
    Ninvalido,
    estadoNaoAchado,
    dataInvalida,
    erroDesconhecido
}tipoErro;

const std::vector <std::string> comandos = {"help","palavra", "sequencia"};

#endif