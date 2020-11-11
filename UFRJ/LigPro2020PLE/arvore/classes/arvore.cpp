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


vector <paciente>
percorrer(Arvore* arvore){

    noh *local = (arvore->getComeco());
    noh *comeco = (arvore->getComeco());
    local->anterior=comeco;
    vector <paciente> saida;
    paciente novo;

    if (comeco!=nullptr){
        while (!comeco->pintado)
        {
            if (local->esquerda!=NULL){
                while(!local->esquerda->pintado){
                    local->anterior = local;
                    local= (local->esquerda);
                    if(local->esquerda!=NULL){
                        if (local->direita!=NULL)
                            while ((local->esquerda==NULL) or (!local->direita->pintado)){
                                if (local->direita==NULL){
                                    
                                    local = local->pinta(local,&novo);
                                    saida.push_back(novo);  
                                }
                                else {
                                    local->anterior = local;
                                    local = local->direita;
                                }
                            }
                        else {
                            local = local->pinta(local,&novo);
                            saida.push_back(novo);
                        }
                    }
                }
                if (local->direita!=NULL) {
                    if (!local->direita->pintado){
                        local->anterior = local;
                        local = local->direita;
                        if ((local->direita==NULL) and (local->esquerda==NULL)){
                            local = local->pinta(local,&novo);
                            saida.push_back(novo);
                        }
                    }
                    else {
                        local = local->pinta(local,&novo);
                        saida.push_back(novo);
                    }
                }
                else {
                    local = local->pinta(local,&novo);
                    saida.push_back(novo);
                }
            }
            else if (local->direita!=NULL){
                if (!local->direita->pintado){
                    local->anterior = local;
                    local = local->direita;
                }
                else {
                    local = local->pinta(local,&novo);
                    saida.push_back(novo);
                }
            }
            else {
                local = local->pinta(local,&novo);
                saida.push_back(novo);
            }
        }
    }
    return saida;
}



ostream&
operator<<(ostream& output,Arvore &entrada){
    vector <paciente> saida = percorrer(&entrada);
    unsigned tamanho = saida.size();
    for (unsigned index = 0;index<tamanho;index ++){
        output << saida[index].getNome();
    }
    return output;
}

paciente *
Arvore::operator+=(paciente* adicionar){ // inserir na arvore
    if (!comeco){
        comeco = new noh;
        comeco->data = *adicionar;
        return &(comeco->data);
    }
    noh *local = comeco;
    noh *anterior = comeco;
    

    while (local!=nullptr){
        if (local->data > *adicionar) {
            anterior = local;
            local->esquerda = new noh;
            local = local->esquerda;
            if (local!=nullptr){ // se o local é nulo eu aponto para ele
                
                local->data = *adicionar;
                anterior->esquerda = local;
                local->anterior = anterior;
                return &(local->data);
            }
        }
        else if ( local->data < *adicionar ){
            anterior = local;
            local->direita = new noh;
            local = local->direita;
            if (local!=nullptr){
                local->data = *adicionar;
                anterior->direita = local;
                local->anterior =  anterior;
                return &(local->data);
            }
        }
        else { // igual
            return NULL;
        }
    }

    return NULL;
}

paciente *
Arvore::operator()(paciente* buscar){ //busca 
    if (!comeco){
        return NULL;
    }
    noh *local = comeco;
    while (local!=nullptr)
    {
        if (local->data > *buscar) {
            local = local->esquerda;
        }
        else if ( local->data < *buscar ){
            local = local->direita;
        }
        else { // igual
            return &(local->data);
        }
    }
    return &(local->data); // NULL

}