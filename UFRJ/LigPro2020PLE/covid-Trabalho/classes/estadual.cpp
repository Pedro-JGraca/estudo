#include "estadual.h"


estadual::estadual(string estadoNome,unsigned char n)
{
    setEstado(estadoNome);

}

tipoErro
estadual::setEstado(string estadoNome){

    vector <string> ListaEstado;
    listaEstados(&ListaEstado);
    bool achou = false;
    for (unsigned char index=0;index<ListaEstado.size();index++) {

        if (ListaEstado[index] == estadoNome){
            achou = true;
        }
    }
    if (achou){
        this->estado = estadoNome;
        return ok;
    }
    cout << "Fora da lista de estados possiveis" << endl;
    cout << "Lista de estados:" << endl;
    for (unsigned char index=0;index<ListaEstado.size();index++) {
        cout << "[" <<ListaEstado[index] << "] ";
    }
    cout << endl;
    return estadoNaoAchado;
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