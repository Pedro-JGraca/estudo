#include <iostream>
#include "agenda.h"

using namespace std;

Agenda::Agenda(unsigned short n){
    maxNomes = n;
}

void
Agenda::insereCadastro(Cadastro &entrada){
    if (cadastro.size() == maxNomes) {
        cout << endl << "Limite de " << maxNomes << " contatos cadastrados!" << endl;
    }
    else {
        cadastro.push_back(entrada);
    }
}

void
Agenda::mostraCadrastro(){
    for (unsigned short i; i<cadastro.size();i++){
        cout << i <<". Nome: "<< cadastro[i].getNome() << "\t|  Profissao: " << cadastro[i].getProfissao() << "\t|  Idade: " << cadastro[i].getIdade() << endl;
    }
}

Cadastro::Cadastro()
{
}

string
Cadastro::substr(string Entrada,unsigned const n=10){
    
    if (Entrada.length()>n){
        cout << "Maior que "<< n <<"! FOI TRUNCADO!" << endl;
        Entrada=Entrada.substr(0,n);
    }
    return Entrada;
}



void
Cadastro::setNome(string Nome){
    nome=substr(Nome);
}

void
Cadastro::setProfissao(string Profissao){
    profissao = substr(Profissao,(unsigned)20);
}

void
Cadastro::setIdade(unsigned short Idade){
    idade=Idade;
}

string
Cadastro::getNome(){
    return nome;
}

string
Cadastro::getProfissao(){
    return profissao;
}

unsigned short
Cadastro::getIdade(){
    return idade;
}