#include "classes.h"
#include <iostream>
#include <vector>

using namespace std;

Estadual::Estadual() {

}

void
Estadual::mediaMovel(unsigned short N=3){
    //CARREGAR DIAS puxando de arquivo
    vector <unsigned> dias = {3,1,10,3,4,5};
    vector <unsigned> somados;
    unsigned hoje=1;

    //contruir ate N
    somados.push_back(dias[0]);
    for (; hoje<N;hoje++){
        somados.push_back(somados[hoje-1]+dias[hoje]);
    }
    
    //N elementos em somados pronto
    for (;hoje<dias.size();hoje++){
        somados.push_back(somados[hoje-1]+dias[hoje]-dias[hoje-(N)]);
    }

    //mostra
    for (unsigned index = 0;index<somados.size();index++){
        cout << index << ". " << somados[index] << endl;
    }

}



