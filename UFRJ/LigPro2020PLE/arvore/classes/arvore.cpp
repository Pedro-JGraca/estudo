#include <iostream>
#include <vector>

#include "arvore.h"
#include "paciente.h"
#include "noh.h"
using namespace std;


Arvore::Arvore(){
    comeco = nullptr;
}

noh*
Arvore::getComeco(){
    return comeco;
}


void
Arvore::percorrer(noh * local){
    if (local != NULL )
    {    
        percorrer (local->esquerda);
        cout << local->data;
        percorrer (local->direita);
    }
}


ostream&
operator<<(ostream& output,Arvore &entrada){
    
    noh *local = entrada.getComeco();
    
    entrada.percorrer(local);

    return output;
}

void
Arvore::insere(noh **local, paciente * adicionado){
    if ((*local) == NULL){
        *local = new noh;
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
    noh * achou = (busca(getComeco(),adicionar));
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


noh *
Arvore::busca(noh *local, paciente*buscado) {
    if (local == NULL)
        return NULL;
    else if (local->data==*buscado)
        return local;
    else if (local->data < *buscado)
        return busca(local->direita,buscado);
    else
        return busca(local->esquerda,buscado);

}