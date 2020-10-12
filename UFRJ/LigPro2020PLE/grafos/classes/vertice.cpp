#include "vertice.h"

using namespace std;

vertice::vertice(string A){
    nome = A;
    chamadas = 1;
}
vertice::~vertice(){
    /*for (unsigned i =0; i < aponta.size();i++){
        delete aponta[i];
    }*/
}

void
vertice::setChamadas(){
    this->chamadas+=1;
}

unsigned short
vertice::getChamadas(){
    return this->chamadas;
}

string
vertice::getNome(){
    return nome;
}
    
void
vertice::setRecebeAresta(aresta * ptr){
    recebe.push_back(ptr);
}

void
vertice::setApontaAresta(aresta * ptr){
    aponta.push_back(ptr);

}

aresta *
vertice::getAponta(unsigned short n){
    if (aponta.size()>n){
        return aponta[n];
    }
    else {
        return NULL;
    }
}

aresta *
vertice::getRecebe(unsigned short n){
    if (recebe.size()>=n){
        return recebe[n];
    }
    else {
        return NULL;
    }
}

unsigned short
vertice::getApontaSize(){
    return aponta.size();
}

unsigned short
vertice::getBaseSize(){
    return recebe.size();
}
    