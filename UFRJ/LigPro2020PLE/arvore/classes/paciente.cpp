#include "paciente.h"

void
paciente::setNome(string n){
    nome = n;
}

string
paciente::getNome(){
    return nome;
}

paciente::paciente(string n){
    nome = n;
}

paciente::paciente(const paciente &n){
    nome = n.nome;
}

bool
operator==(paciente novo, paciente outro){//global para esse contexto
    
    if(novo.getNome().size()!=outro.getNome().size())
    {
        return false;
    }
    for (unsigned short i = 0 ;i < novo.getNome().size();i++){
        if(novo.getNome()[i]!=outro.getNome()[i]){
            return false;
        }
    }
    
    return true;
}

bool 
operator<(paciente novo, paciente outro){//global para esse contexto
    
    unsigned short menor;
    if(novo.getNome().size()<outro.getNome().size())
    {
        menor = novo.getNome().size();
    }
    else{
        menor = outro.getNome().size();
    }

    for (unsigned short i=0 ; i < menor ; i++){
        if (novo.getNome()[i]<outro.getNome()[i]){  //a é menor que b?
            return true;
        }
        else if (novo.getNome()[i]>outro.getNome()[i]){
            return false;
        }
    }
    
    if (novo.getNome().size() == menor){
        return true;
    }
    else{
        return false;
    }
}

bool
operator>(paciente novo, paciente outro){//global para esse contexto

    unsigned short menor;
    if(novo.getNome().size()<outro.getNome().size())
    {
        menor = novo.getNome().size();
    }
    else{
        menor = outro.getNome().size();
    }

    for (unsigned short i=0 ; i < menor ; i++){
        if (novo.getNome()[i]<outro.getNome()[i]){  //a é menor que b?
            return false;
        }
        else if (novo.getNome()[i]>outro.getNome()[i]){
            return true;
        }
    }
    
    if (novo.getNome().size() == menor){
        return false;
    }
    else{
        return true;
    }

}
