
#include <iostream>
#include "Paralelepipedo.h"


using namespace std;

Paralelepipedo::Paralelepipedo(){
    setX(1);
    setY(1);
    setZ(1);
    computeVolume();
}

void
Paralelepipedo::setX(int entrada){
    if (entrada <= 0){
        x = 1;
        cout << " Nao pode Pessoa! Valor 1 definido para X" << endl;
    }
    else {
        x = entrada;
    }
}

void
Paralelepipedo::setY(int entrada){
    if (entrada <= 0){
        y = 1;
        cout << " Nao pode Pessoa! Valor 1 definido para Y" << endl;
    }
    else {
        y = entrada;
    }
}

void
Paralelepipedo::setZ(int entrada){
    if (entrada <= 0){
        z = 1;
        cout << " Nao pode Pessoa! Valor 1 definido para Z" << endl;
    }
    else {
        z = entrada;
    }    
}


int
Paralelepipedo::getX(){
    return x;
}

int
Paralelepipedo::getY(){
    return y;
}

int
Paralelepipedo::getZ(){
    return z;
}

void
Paralelepipedo::computeVolume() {
    volume = getX()*getY()*getZ();
}

int
Paralelepipedo::getVolume() {
    computeVolume();
    return volume;
}
