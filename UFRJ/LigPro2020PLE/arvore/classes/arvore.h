#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
//#include <vector>
#include "paciente.h"
#include "noht.h"
using namespace std;

class Arvore
{
    friend ostream&
    operator<<(ostream& output,Arvore  &entrada); // cout << arvore*/

private:
    nohT<paciente> *comeco;

public:

    Arvore ();

    nohT<paciente>*
    getComeco();
    
    paciente*
    operator+=(paciente* adicionar); // paciente *ptr_paci=(arvore += paciente);
    
    paciente*
    operator()(paciente* buscar);// paciente *ptr_paci=(arvore(paciente);

    void
    insere(nohT<paciente> **local, paciente * adicionado);

    nohT<paciente>*
    busca(nohT<paciente> *local, paciente * buscado);

    void
    percorrer(nohT<paciente> *local);

};
#endif