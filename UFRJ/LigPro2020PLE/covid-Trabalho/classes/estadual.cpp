#include <fstream>
#include "estadual.h"



estadual::estadual(string estadoNome, unsigned char n)
{
    setEstado(estadoNome);
    this->N = n;
    importarDados();
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
estadual::importarDados(){
    if (getEstado().size()) {
        util uteis;
        char a[6];
        
        //ifstream fin("./dados/estados/" + getEstado() + ".txt");
        ifstream fin("./dados/TESTE2.txt");
        
        while (fin){
            fin.getline(a,6);
            if (uteis.isDigit((string)a)) {
                dados.push_back((unsigned short) stoul(a));
            }
        }
        
    }
} 
