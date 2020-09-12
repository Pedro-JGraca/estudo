#include <iostream>
#include "agenda.h"

using namespace std;

unsigned Agenda::numerosNomes;

Agenda::Agenda(){
    numerosNomes = 0;
}

string
Agenda::substr(string Entrada,unsigned const n=10){
    
    if (Entrada.length()>n){
        cout << "Maior que 10, FOI TRUNCADO!" << endl;
        Entrada=Entrada.substr(0,n);
    }
    return Entrada;
}

void
Agenda::insereNomes(string Entrada){
    if (numerosNomes == maxNomes) {
        cout << endl << "Limite de " << maxNomes << " contatos cadastrados!" << endl << endl;
    }
    else {
       nomes[numerosNomes] = substr(Entrada);
       numerosNomes++;
    }

}

void
Agenda::mostraNomes(){
    for (long unsigned index = 0; index < numerosNomes;index++){
            cout << nomes[index] <<endl << endl;
    }
}