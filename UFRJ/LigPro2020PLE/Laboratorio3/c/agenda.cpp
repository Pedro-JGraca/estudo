#include <iostream>
#include "agenda.h"

using namespace std;

unsigned Agenda::numerosNomes;

Agenda::Agenda(){
    numerosNomes = 0;
}

void
Agenda::insereCadastro(Cadastro &entrada){
    if (numerosNomes == maxNomes) {
        cout << endl << "Limite de " << maxNomes << " contatos cadastrados!" << endl;
    }
    else {
        cadastro[numerosNomes] = entrada;
        numerosNomes++;
    }
}

void
Agenda::mostraCadrastro(){
    for (unsigned short i; i<numerosNomes;i++){
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