#include <iostream>
#include "agenda.h"

using namespace std;

Agenda::Agenda(unsigned long N = 3){
    max = N;
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
    if (nomes.size() >= max) {
        cout << endl << "Limite de " << max << " contatos cadastrados!" << endl << endl;
    }
    else {
       nomes.push_back(substr(Entrada));
    }

}

void
Agenda::mostraNomes(){
    for (long unsigned index = 0; index < nomes.size();index++){
            cout << nomes[index] <<endl << endl;
    }
}