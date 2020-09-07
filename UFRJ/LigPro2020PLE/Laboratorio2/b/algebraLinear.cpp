#include <iostream>
#include <cmath>
#include "algebraLinear.h"

Ponto::Ponto(/* args */)
{
    setX(1);
    setY(1);
    setZ(1);
} //construtor

void
Ponto::setX(int X){
    coordenada[0] = X;
}
void
Ponto::setY(int Y){
    coordenada[1] = Y;
}
void
Ponto::setZ(int Z){
   coordenada[2] = Z;
}
    
int
Ponto::getX(){
    return coordenada[0];
}
int
Ponto::getY(){
    return coordenada[1];
}

int
Ponto::getZ(){
    return coordenada[2];
}

int*
Ponto::getCoordenadas(){
    return coordenada;
}
    
void
Ponto::printCoordenadas(){
    static unsigned chamadas = 1;
    int a[3];
    a[0] = *getCoordenadas();
    a[1] = *(getCoordenadas()+1);
    a[2] = *(getCoordenadas()+2);

    std::cout << "[Impressao no. [" << chamadas <<"]] " << "Coordenadas do ponto:(" << a[0] <<","<< a[1]<<","<<a[2]<<")" << std::endl;
    chamadas++;
}

Linha::Linha(Ponto um, Ponto dois){
    p1.setX(um.getX());
    p1.setY(um.getY());
    p1.setZ(um.getZ());
    p2.setX(dois.getX());
    p2.setY(dois.getY());
    p2.setZ(dois.getZ());    
}

void
Linha::setPontoUm(int x, int y, int z){
    p1.setX(x);
    p1.setY(y);
    p1.setZ(z);
}

void
Linha::setPontoDois(int x, int y, int z){
    p2.setX(x);
    p2.setY(y);
    p2.setZ(z);
}
    
int *
Linha::getPontoUm(){
    return p1.getCoordenadas();
}

int *
Linha::getPontoDois(){
    return p2.getCoordenadas();
}

double
Linha::getComprimento(){
    return pow(pow((double) (p1.getX()-p2.getX()) ,2) + pow((double) (p1.getY()-p2.getY()),2) + pow((double) (p1.getZ()-p2.getZ()),2),0.5);
}