#include "aresta.h"

aresta::aresta(string A, string B){
    this->base=A;
    this->ponta=B;
    this->sit=1;

}

unsigned
aresta::getSit(){
    return this->sit;
}

void
aresta::setSit(unsigned m1) {
   this->sit +=m1; 
}

string
aresta::getBase(){
    return this->base;
}
string
aresta::getPonta(){
    return this->ponta;
}