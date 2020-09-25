#include <stdlib.h>
#include <fstream>
#include <limits>
#include "estadual.h"

estadual::estadual(string estadoNome, unsigned char n)
{
    setEstado(estadoNome); //original?
    importarDados(&dados);
    
    if (n!=0){
        this->N = n;
    }
    else {
        this->N = dados.size();
    }

}

void
estadual::setEstado(string estadoNome){
    if (verificaEstado(estadoNome)){
        this->estado = estadoNome;
        
    }
}

bool
estadual::verificaEstado(string estado){
    vector <string> ListaEstado;
    listaEstados(&ListaEstado);
    bool achou = false;
    for (unsigned char index=0;index<ListaEstado.size();index++) {
        if (ListaEstado[index] == estado){
            achou = true;
        }
    }
    if (!achou){
        cout << "Fora da lista de estados possiveis" << endl;
        cout << "Lista de estados:" << endl;
        for (unsigned char index=0;index<ListaEstado.size();index++) {
            cout << "[" <<ListaEstado[index] << "] ";
        }
        cout << endl;
    }
   

    return achou;
}

tipoErro
estadual::listaEstados(vector <string> *ptr){
    vector <string> listaEstado;

    DIR *d;
    struct dirent *dir;
    d = opendir("./dados/estados");
    if (d != NULL)
    {
        while ((dir = readdir(d)) != NULL) //lsita todos os arquivos do diretorio
        {
            if (((string)(dir->d_name)!= "..") and ((string)(dir->d_name)!= "."))
                listaEstado.push_back(((string)(dir->d_name)).substr(0,2));

        }
          closedir(d);
    }
    else {
        return erroAbrirArquivo;
    }

    *ptr = listaEstado;
    return ok;
}

string
estadual::getEstado(){
    return this->estado;
}

unsigned char
estadual::getN(){
    return this->N;
}

void
estadual::importarDados(vector <unsigned short> *ptr){
    if (getEstado().size()) {
        covid uteis;
        char a[6];
        
        ifstream fin("./dados/estados/" + getEstado() + ".txt");
        //ifstream fin("./dados/TESTE.txt");
        if (fin){
            while (fin){
                fin.getline(a,6);
                if (uteis.isDigit((string)a)) {
                    int obitosDia = stoi(a);
                    dados.push_back((unsigned short) obitosDia);
                }
            }
        }
        else {
            cout << "Arquivo nao achado" << endl;
            cout << "O Arquivo deve se encontrar dento do diretorio ./dados/estados/" << endl;
            cout << "onde ./ siginifica o local onde esta o binario AnalisadorCovid" << endl;
        }
    }

    *ptr = dados;
} 


unsigned
estadual::getSizeDados(){
    return dados.size();
}

void
estadual::somaMovel(vector <unsigned>* ptr) {
    
    vector <unsigned> somados;
    unsigned hoje=0;
    unsigned somado;
    
    //n=3
    //1,4,5,7,3
    //1,(1)+4,((1)+4)+5,(((1)+4)+5)+7-(1),((((1)+4)+5)+7+3)-(1)+3
    
    //inicializa o dia 1
    somados.push_back(dados[0]);
    for (hoje=1; hoje<dados.size();hoje++){
        //construir ate N
        if(hoje<getN()){
            somado=somados[hoje-1]+dados[hoje];
        }
        else{//depois de N avancamos no procimo dia e tiramos do N anterior
            somado=somados[hoje-1]+dados[hoje]-dados[hoje-(getN())];
        }
        somados.push_back(somado);
    }

    *ptr = somados;
}

void
estadual::mediaMovel(vector <unsigned short>* ptr){

    vector <unsigned short> mediados;
    vector <unsigned> somados;
    somaMovel(&somados);
    
    for (unsigned i=0; i<somados.size();i++){
        mediados.push_back((somados[i]/getN()));
    }
    
    *ptr = mediados;

}

void
estadual::porcentagemMovel(vector <float>* ptr){
    vector <float> porcentagem;
    vector <unsigned short> mediaMovel;
    estadual::mediaMovel(&mediaMovel);
    if (mediaMovel[0]!=0){
        porcentagem.push_back(numeric_limits<float>::infinity());
    }
    else
    {
        porcentagem.push_back(0);
    }
        

    for (unsigned i=1 ; i < mediaMovel.size(); i++){
        unsigned short hoje =mediaMovel[i];
        unsigned short ontem =mediaMovel[i-1];
        porcentagem.push_back(estadual::porcentagem(hoje,ontem));
    }


    *ptr = porcentagem;

}

float
estadual::porcentagem(unsigned short a, unsigned short b){
    if (b){
        return ((((float)a)-b)/b)*100;
    }
    else{//b = 0
        return numeric_limits<float>::infinity();
    }
}


