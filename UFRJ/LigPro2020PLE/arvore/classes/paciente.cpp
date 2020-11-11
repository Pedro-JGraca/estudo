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

paciente::paciente(){
}

ostream&
operator<<(ostream& output,paciente &entrada){
    
    output << (entrada).getNome() << "\n";
    return output;

}

bool
operator==(paciente novo, paciente outro){//global para esse contexto
    
    return (novo.getNome() == outro.getNome());
}


bool 
operator<(paciente novo, paciente outro){//global para esse contexto

    return (novo.getNome() < outro.getNome());
}

bool
operator>(paciente novo, paciente outro){//global para esse contexto

    return (novo.getNome() > outro.getNome());

}