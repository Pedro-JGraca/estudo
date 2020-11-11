#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
//#include <vector>
#include "paciente.h"

using namespace std;

template <typename type>
class noh
{
public:
    type data;
    bool pintado;
    noh <type> *anterior;
    noh <type> *direita;
    noh <type> *esquerda;

    noh <type> * 
    pinta ( noh *local);
};

template <typename type>
noh<type>*
noh<type>::pinta(noh <type> *local){
    cout << local->data;
    local->pintado = true;
    return local->anterior;
}

template <class T> 
class Arvore
{
    /*template <class U>
    friend ostream&
    operator<<(ostream& output,Arvore<T>  &entrada); // cout << arvore*/
private:
    noh <T> *comeco;

public:

    Arvore ();

    T*
    operator+=(T* adicionar); // paciente *ptr_paci=(arvore += paciente);
    
    T*
    operator()(T* buscar);// paciente *ptr_paci=(arvore(paciente);

    
    

};

template <class T> 
Arvore<T>::Arvore(){
    comeco = NULL;
}
//ostream&
/*template <class T> 
ostream&
operator<<(ostream& output,Arvore<T> &entrada){
    //percorrer toda a arvore e devolver
    noh <T> local = comeco;
    if (!(comeco==NULL)){
        while (!comeco->pintado)
        {
            if (local.esquerda!=NULL){
                while(!local.esquerda->pintado){
                    local= local.esquerda;
                    if(local.esquerda!=NULL){
                        if (local.direita!=NULL)
                            while ((local.esquerda==NULL) or (!local.direita->pintado)){
                                if (local.direita==NULL){
                                    local = &local.pinta(&local);  
                                }
                                else {
                                    local = local.direita;
                                }
                            }
                        else {
                            local = &local.pinta(&local);
                        }
                    }
                }
                if (local.direita!=NULL) {
                    if (!local.direta.pintado){
                        local = local.direita;
                        if ((local.direita==NULL)and (local.esquerda==NULL)){
                            local = &local.pinta(&local);
                        }
                    }
                    else {
                        local = &local.pinta(&local);
                    }
                }
                else {
                    local = &local.pinta(&local);
                }
            }
            else if (local.direita!=NULL){
                if (!local.direita->pintado){
                    local = local.direita;
                }
                else {
                    local = &local.pinta(&local);
                }
            }
            else {
                local = &local.pinta(&local);
            }
        }
    }
}

*/
template <class T> 
T* 
Arvore<T>::operator+=(T* adicionar){ // inserir na arvore
    if (!comeco){
        comeco->data = *adicionar;
        return adicionar;
    }
    noh <T> local = *comeco;
    noh <T> anterior = *comeco;
    
    while (local==NULL){
        if (local.data > *adicionar) {
            anterior = local;
            local = *local.esquerda;
            if (local==NULL){ // se o local é nulo eu aponto para ele
                //local = new noh <T>;
                local.data = *adicionar;
                anterior.esquerda = &local;
                local.anterior = &anterior;
                return &local;
            }
        }
        else if ( local.data < *adicionar ){
            local = local.direita;
            if (!local){
                //local = new noh <T>;
                local.data = *adicionar;
                anterior.direita = &local;
                local.anterior =  &anterior;
                return &local;
            }
        }
        else { // igual
            return NULL;
        }
    }


}

template <class T> 
T* 
Arvore<T>::operator()(T* buscar){ //busca 
    if (!comeco){
        return NULL;
    }
    noh <T> local = comeco;
    
    while (local)
    {
        if (local.data > buscar) {
            local = local.esquerda;
        }
        else if ( local.data < buscar ){
            local = local.direita;
        }
        else { // igual
            return &local;
        }
    }
    return &local; // NULL

}


#endif