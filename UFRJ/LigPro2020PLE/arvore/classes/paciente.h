#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>

using namespace std;

class paciente
{
private:
    string nome;

    friend ostream&
    operator<<(ostream& output,paciente &entrada); // cout << paciente
    

public:

    paciente(string n);
    paciente(const paciente &n);

    void
    setNome(string);

    string
    getNome();

};




#endif