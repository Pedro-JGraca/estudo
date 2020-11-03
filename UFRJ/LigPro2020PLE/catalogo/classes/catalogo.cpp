#include "catalogo.h"
#include <algorithm>

string  
catalogo::operator+=(filme novo){
   
    string saida = "";
    
    if (isEmpty(novo)){ //verificar se novo é vazio
        saida +="filme vazio. Não adicionado.\n";
    }
    else{//verificar se novo já existe ( implementar == para filmes, verificando o nome)
        if (filmeIn(novo)){
            saida+="filme já presente. Não adicionado\n";
        }
        else{
            if (filmes.size() == MAXIMO){
                saida +="limite de filmes no catalogo. Não adicionado.\n";
            }
            else {
                filmes.push_back(novo);
                saida +="adicionado.\n";
                if (filmes.size()>2)
                    ordenar();
            }
        }
    }
    return saida;
}

string 
catalogo::operator+=(vector<filme> rajada){
    for (unsigned short index=0;index<rajada.size();index++){
        operator+=(rajada[index]);
    }
    return "";
}


bool
operator==(filme novo, filme outro){//global para esse contexto
    
    if(novo.nome.size()!=outro.nome.size())
    {
        return false;
    }
    for (unsigned short i = 0 ;i < novo.nome.size();i++){
        if(novo.nome[i]!=outro.nome[i]){
            return false;
        }
    }
    
    return true;
}

bool 
operator<(filme novo, filme outro){//global para esse contexto
    
    unsigned short menor;
    if(novo.nome.size()<outro.nome.size())
    {
        menor = novo.nome.size();
    }
    else{
        menor = outro.nome.size();
    }

    for (unsigned short i=0 ; i < menor ; i++){
        if (novo.nome[i]<outro.nome[i]){  //a é menor que b?
            return true;
        }
        else if (novo.nome[i]>outro.nome[i]){
            return false;
        }
    }
    
    if (novo.nome.size() == menor){
        return true;
    }
    else{
        return false;
    }
}

bool
operator>(filme novo, filme outro){//global para esse contexto

    unsigned short menor;
    if(novo.nome.size()<outro.nome.size())
    {
        menor = novo.nome.size();
    }
    else{
        menor = outro.nome.size();
    }

    for (unsigned short i=0 ; i < menor ; i++){
        if (novo.nome[i]<outro.nome[i]){  //a é menor que b?
            return false;
        }
        else if (novo.nome[i]>outro.nome[i]){
            return true;
        }
    }
    
    if (novo.nome.size() == menor){
        return false;
    }
    else{
        return true;
    }

}

void
catalogo::ordenar(){
    
    unsigned short isOrdered = 0; 
   
    unsigned short tamanho = filmes.size();
    while(isOrdered == 0){ 
     
        isOrdered = 1; //presume ordem
     
        for(unsigned short i=0; i < tamanho-1; i++){
            if(filmes[i] > filmes[i+1]){ //se não estiver em ordem, troca
                filme temp = filmes[i];
                filmes[i] = filmes[i+1];
                filmes[i+1] = temp;
        
                isOrdered = 0; // informa falta de ordem
            }
        }
    }
    
    //sort(filmes[0], filmes[filmes.size()-1]); 
}



bool
catalogo::isEmpty(filme novo){

    bool nomeIsEmpty = novo.nome.empty();
    bool produtoraIsEmpty = novo.produtora.empty();
    return nomeIsEmpty && produtoraIsEmpty;

}

string
catalogo::getLista(){
    string saida = "";
    for (unsigned short index = 0; index < filmes.size(); index++){
        saida += filmes[index].nome;
        saida += "\n";
    }
    return saida;
}

bool 
catalogo::filmeIn(filme novo){
    if (filmes.size()==0){
        return false;
    }
    for (unsigned short index = 0; index< filmes.size(); index++){
        if(filmes[index]==novo){
            return true;
        }
    }
    
    return false;
}