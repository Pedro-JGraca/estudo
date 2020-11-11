#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
//#include <vector>
#include "paciente.h"
#include "noh.h"
using namespace std;

class Arvore
{
    friend ostream&
    operator<<(ostream& output,Arvore  &entrada); // cout << arvore*/

private:
    noh *comeco;

public:

    Arvore ();

    noh*
    getComeco();
    
    paciente*
    operator+=(paciente* adicionar); // paciente *ptr_paci=(arvore += paciente);
    
    paciente*
    operator()(paciente* buscar);// paciente *ptr_paci=(arvore(paciente);

    

};

vector <paciente>
percorrer(Arvore* arvore); /*globais*/
#endif