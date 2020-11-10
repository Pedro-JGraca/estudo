#ifndef ARVORE_H
#define ARVORE_H

/*#include <iostream>
#include <vector>
using namespace std;
*/
template <typename type>
class noh
{
public:
    type data;
    noh *direita;
    noh *esquerda;
};



template <class T> 
class Arvore
{

    template <class U>
    friend ostream &
    operator<<(ostream &output, T &entrada); // cout << arvore

private:
    noh <T> *comeco;

public:

    Arvore ();

    

    T*
    operator+=(const T adicionar); // paciente *ptr_paci=(arvore += paciente);
    
    T*
    operator()(const T buscar);// paciente *ptr_paci=(arvore(paciente.getNome()));

};

template <class T> 
Arvore<T>::Arvore(){
    comeco = NULL;
}

template <class T> 
T* 
Arvore<T>::operator+=(const T adicionar){
    if (!comeco){
        comeco = adicionar;
        return &adicionar;
    }
    noh <T> local = comeco;
    noh <T> anterior;
    
    while (local)
    {
        if (local.data > adicionar) {
            local = local.esquerda;
            if (!local){
                local = new noh <T>;
                local.data = adicionar;
                return &local;
            }
        }
        else if ( local.data < adicionar ){
            local = local.direita;
            if (!local){
                local = new noh <T>;
                local.data = adicionar;
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
Arvore<T>::operator()(const T buscar){
    if (!comeco){
        return NULL;
    }
    noh <T> local = comeco;
    noh <T> anterior;
    
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
    return &local;


}

template <class U>
ostream&
operator<<(ostream &output, U &entrada){       
    output  << entrada;
    return output;
}



#endif