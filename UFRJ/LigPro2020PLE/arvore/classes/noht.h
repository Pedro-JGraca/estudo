#ifndef NOHT_H
#define NOHT_H


template <typename type>
class nohT
{
public:
    type data;
    nohT *direita;
    nohT *esquerda;

    nohT ();
    
    bool
    operator!=(nohT a);
};

template <typename type>
bool
nohT<type>::operator!=(nohT comparador) {
    if (this->data==comparador.data){
        return false;
    }
    return true;
}

template <typename type>
nohT<type>::nohT(){

}


#endif