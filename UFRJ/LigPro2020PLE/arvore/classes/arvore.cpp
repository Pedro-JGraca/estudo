#include <iostream>
#include <vector>

#include "arvore.h"
#include "paciente.h"
#include "noht.h"
using namespace std;


Arvore::Arvore(){
    comeco = nullptr;
}

nohT<paciente>*
Arvore::getComeco(){
    return comeco;
}


void
Arvore::percorrer(nohT<paciente>* local){
    if (local != NULL )
    {    
        percorrer (local->esquerda);
        cout << local->data;
        percorrer (local->direita);
    }
}


ostream&
operator<<(ostream& output,Arvore &entrada){
    nohT<paciente> *local = entrada.getComeco();
    
    entrada.percorrer(local);

    return output;
}

void
Arvore::insere(nohT<paciente> **local, paciente * adicionado){
    if ((*local) == NULL){
        *local = new nohT<paciente>;
        (*local)->data = *adicionado;
    }
    else if ((*local)->data < *adicionado)
       insere(&((*local)->direita),adicionado);
    else
       insere(&((*local)->esquerda),adicionado);
}

paciente *
Arvore::operator+=(paciente* adicionar){ // inserir na arvore
    if (adicionar==NULL){
        return NULL;
    }

    nohT<paciente> * achou = (busca(getComeco(),adicionar));
    if (achou != NULL){
        return NULL;
    }
    insere(&(comeco),adicionar);
    return &(busca(getComeco(),adicionar)->data);

}

paciente *
Arvore::operator()(paciente* buscar){ //busca 
    if (comeco==NULL){
        return NULL;
    }

    return &(busca(getComeco(),buscar)->data);

}

nohT<paciente> *
Arvore::busca(nohT<paciente> *local, paciente*buscado) {
    if (local == NULL)
        return NULL;
    else if (local->data==*buscado)
        return local;
    else if (local->data < *buscado)
        return busca(local->direita,buscado);
    else
        return busca(local->esquerda,buscado);

}