#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>

using namespace std;

class paciente
{
private:
    string nome;
    
    paciente *esquerda;
    paciente *direita;

public:

    void
    setNome(string);

    string
    getNome();

};

#endif