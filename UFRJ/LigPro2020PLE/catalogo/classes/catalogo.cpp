#include "catalogo.h"
#include <string.h>

void 
catalogo::operator+=(filme novo){
    //verificar se novo é vazio ().isEmpty
    if (isEmpty(novo)){
        cout << "filme vazio. Não adicionado." << endl;
    }
    else{
        //verificar se novo já existe ( implementar == para filmes, verificando o nome)
        if (filmeIn(novo)){
            cout << "filme já presente. Não adicionado" << endl;
        }
        //verifica se ta no limite
        else{
            filmes.push_back(novo);
        //fazer ordenarVetor (implementar < e >)
        }
        
        
    }
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
catalogo::isEmpty(filme novo){

    bool nomeIsEmpty = novo.nome.empty();
    bool produtoraIsEmpty = novo.produtora.empty();
    return nomeIsEmpty + produtoraIsEmpty;

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