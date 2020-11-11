#include <iostream>
#include "noh.h"

using namespace std;

noh*
noh::pinta(noh *local, paciente * l){
    l->setNome(local->data.getNome());
    local->pintado = true;
    return local->anterior;
}

bool
noh::operator!=(noh comparador) {
    if (this->data==comparador.data){
        return false;
    }
    return true;
}

noh::noh(){
    pintado = false;
}