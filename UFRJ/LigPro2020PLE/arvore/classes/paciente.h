#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>

using namespace std;

class paciente
{
private:
    string nome;
    

public:

    paciente(string n);
    paciente(const paciente &n);

    void
    setNome(string);

    string
    getNome();


};

#endif