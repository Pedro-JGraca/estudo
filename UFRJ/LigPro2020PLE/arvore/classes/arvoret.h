#ifndef ARVORET_H
#define ARVORET_H

#include <iostream>
#include <vector>
//#include "paciente.h"
#include "noht.h"

using namespace std;

template <class T> 
class ArvoreT
{
    template <class U> 
    friend ostream&
    operator<<(ostream& output,ArvoreT<U>  &entrada); // cout << arvore*/

private:
    nohT<T> *comeco;

public:

    ArvoreT ();

    nohT<T>*
    getComeco();
    
    T*
    operator+=(T* adicionar); // paciente *ptr_paci=(arvore += paciente);
    
    T*
    operator()(T* buscar);// paciente *ptr_paci=(arvore(paciente);

    void
    insere(nohT<T> **local, T * adicionado);

    nohT<T>*
    busca(nohT<T> *local, T * buscado);

    void
    percorrer(nohT<T> *local);


};

template <class T> 
ArvoreT<T>::ArvoreT (){
    comeco = nullptr;
}

template <class T> 
nohT<T>*
ArvoreT<T>::getComeco(){
    return comeco;
}

template <class T> 
void
ArvoreT<T>::percorrer(nohT<T>* local){
    if (local != NULL )
    {    
        percorrer (local->esquerda);
        cout << local->data;
        percorrer (local->direita);
    }
}

template <class U> 
ostream&
operator<<(ostream& output,ArvoreT<U> &entrada){
    nohT<U> *local = entrada.getComeco();
    
    entrada.percorrer(local);

    return output;
}

template <class T> 
void
ArvoreT<T>::insere(nohT<T> **local, T * adicionado){
    if ((*local) == NULL){
        *local = new nohT<T>;
        (*local)->data = *adicionado;
    }
    else if ((*local)->data < *adicionado)
       insere(&((*local)->direita),adicionado);
    else
       insere(&((*local)->esquerda),adicionado);
}

template <class T> 
T *
ArvoreT<T>::operator+=(T* adicionar){ // inserir na arvore
    if (adicionar==NULL){
        return NULL;
    }

    nohT<T> * achou = (busca(getComeco(),adicionar));
    if (achou != NULL){
        return NULL;
    }
    insere(&(comeco),adicionar);
    return &(busca(getComeco(),adicionar)->data);

}

template <class T> 
T *
ArvoreT<T>::operator()(T* buscar){ //busca 
    if (comeco==NULL){
        return NULL;
    }

    return &(busca(getComeco(),buscar)->data);

}

template <class T> 
nohT<T> *
ArvoreT<T>::busca(nohT<T> *local, T*buscado) {
    if (local == NULL)
        return NULL;
    else if (local->data==*buscado)
        return local;
    else if (local->data < *buscado)
        return busca(local->direita,buscado);
    else
        return busca(local->esquerda,buscado);

}



#endif