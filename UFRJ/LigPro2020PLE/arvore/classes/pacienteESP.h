#ifndef PACIENTE_ESP_H
#define PACIENTE_ESP_H

#include <iostream>
#include "paciente.h"
using namespace std;

class pacienteESP:public paciente
{

friend ostream&
    operator<<(ostream& output,pacienteESP &entrada); // cout << paciente
private:

public:

    pacienteESP(string n);

    virtual string
    getNome();

};


#endif