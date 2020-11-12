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

    paciente();
    paciente(string n);
    //paciente(const paciente &n);

    void
    setNome(string);

    virtual string
    getNome();

};


    bool
    operator<(paciente novo, paciente outro);
    bool
    operator>(paciente novo, paciente outro);
    bool
    operator==(paciente novo, paciente outro);


#endif