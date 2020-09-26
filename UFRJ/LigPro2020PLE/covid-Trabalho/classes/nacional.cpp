#include "covid.h"
#include "estadual.h"
#include "nacional.h"
#include <vector>
#include <limits>


nacional::nacional(unsigned char n)
{
    this->n = n;
    estados.push_back(estadual("AL",3));
    estados[0].listaEstados(&listaEstados);
    estados.pop_back();
    for (unsigned i = 0; i< listaEstados.size() ; i++){
        estados.push_back(estadual(listaEstados[i],this->n));
    }
}

void
nacional::somaMovel(vector <unsigned>* ptr){

    if (!verificaTamanho()) {
        cout << "Erro: Estados nao sincronizados" << endl;
    }
    else {
        vector <unsigned> soma;
        vector <unsigned> total;
        for ( unsigned i = 0; i < estados[0].getSizeDados(); i++){
            total.push_back(0);
        }
        
        for (unsigned i = 0 ; i< estados.size() ; i++){
            estados[i].somaMovel(&soma);
            for (unsigned a = 0 ; a< soma.size() ; a++){
                total[a] += soma[a];
            }
            soma.clear();
        }

        *ptr = total;
    }
    
}

void
nacional::mediaMovel(vector <unsigned> *ptr){
    vector <unsigned> mediado;
    vector <unsigned> somado;
    somaMovel(&somado);

    for (unsigned i=0; i<somado.size();i++){
        mediado.push_back((somado[i]/n));
    }
    
    *ptr = mediado;
}

void
nacional::porcentagemMovel(vector <float> *ptr){
    vector <unsigned> mediado;
    vector <float> porcentagem;
    mediaMovel(&mediado);

    if (mediado[0]!=0){
        porcentagem.push_back(numeric_limits<float>::infinity());
    }
    else
    {
        porcentagem.push_back(0);
    }
        

    for (unsigned i=1 ; i < mediado.size(); i++){
        unsigned short hoje =mediado[i];
        unsigned short ontem =mediado[i-1];
        porcentagem.push_back(porcent(hoje,ontem));
    }


    *ptr = porcentagem;
}

float
nacional::porcent(unsigned short a, unsigned short b){
    if (b){
        return ((((float)a)-b)/b)*100;
    }
    else{//b = 0
        return numeric_limits<float>::infinity();
    }
}



bool
nacional::verificaTamanho(){

    unsigned referencia = estados[0].getSizeDados();
    
    for (unsigned i =0; i<estados.size();i++){
        if (referencia - estados[i].getSizeDados()){
            return false;
        }
    }
    return true;

}

string
nacional::categoria(vector <string> *alto, vector <string> *medio, vector <string> *baixo){
    vector <float> lista;
    
    vector <float> categoria;
    
    vector <string> alta;
    vector <string> baixa;
    vector <string> media;
    string tmp;
    string maior;
    string menor;
    float auxMaior= 0;
    float auxMenor= 0;
    for (unsigned i = 0; i < listaEstados.size(); i++){
        estados[i].porcentagemMovel(&lista);
        categoria.push_back(lista[lista.size() -1]);
        if (categoria[i] > 15){
            tmp = "[" + listaEstados[i] + "](" + zeroCasas(categoria[i]) + "%)  ";
            alta.push_back(tmp);
            if (categoria[i]>auxMaior){
                auxMaior = categoria[i];
                maior = "maior: [" + listaEstados[i] + "] (" + zeroCasas(categoria[i]) + "%) ";
            }
        }
        else if (categoria[i] < -15){
            tmp = "[" + listaEstados[i] + "](" + zeroCasas(categoria[i]) + "%)  ";
            baixa.push_back(tmp);
            if (categoria[i]<auxMenor){
                auxMenor = categoria[i];
                menor = "menor: [" + listaEstados[i] + "] (" + zeroCasas(categoria[i]) + "%) ";
            }
        }
        else {
            tmp = "[" + listaEstados[i] + "](" + zeroCasas(categoria[i]) + "%)  ";
            media.push_back(tmp);
        }
    }

    *alto = alta;
    *medio = media;
    *baixo = baixa;
    if (maior == "") {
        maior = "maior: Não existem estados em alta";
    }
    if (menor == "") {
        menor = "menor: Não existem estados em baixa";
    }
    return maior + "\n" + menor;
}

string
nacional::zeroCasas(float a){
    char str[7];
    sprintf(str,"%2.f",a);
    return str;
}


string
nacional::situacaoNacional(){
    vector <unsigned> soma;
    somaMovel(&soma);
    unsigned short ontem = (soma [soma.size() -2])/n;
    unsigned short hoje = (soma [soma.size() -1])/n;

    float atual = porcent(hoje,ontem);
    string sit;
    if (atual > 15){
        sit = "em Alta (";
    }
    else if (atual < -15){
        sit = "em Baixa (";
    }
    else {
        sit = "estavel (";
    }

    sit += zeroCasas(atual) + "%) ";
    
    return sit;
}