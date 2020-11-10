#include "cadastro.h"

cadastro::cadastro(){
    erroBD = lerBD();
    if (erroBD!=ok){
        iniciarBD();
    }
}
cadastro::~cadastro(){
    erroBD = escreverBD();
    if (erroBD!=ok){
        iniciarBD();
    }
}


paciente*
cadastro::inserir(string Nome)
{
    paciente novo;
    novo.setNome(Nome);

    arvore.push_back(novo);
    /*if (!(arvore += paciente)){
        cout << "falha na incersão";
        return NULL;
    }*/
    
    return &arvore.back(); 
}

paciente*
cadastro::buscar(string Nome)
{
    for (unsigned index = 0;index < arvore.size();index++){
        if (arvore[index].getNome()==Nome){
            return &arvore[index];
        }
    }

    /*        
    paciente *p = arvore(Nome);
    if(!p){
        cout << Não achado << endl;
    }
    return p;
    */

    cout << "Não achado" << endl;
    return NULL; 
}

void
cadastro::imprimir(){
    for (unsigned index = 0;index < arvore.size();index++){
        cout << arvore[index].getNome() << endl;
        //cout << paciente;
        //cout << endl;
    }
    //cout << arvore;
}

tipoErro
cadastro::getErroBD(){
    return erroBD;
}

tipoErro
cadastro::lerBD(){

    string b;
    ifstream fin(ARQUIVO);
    vector<paciente> escrita;
    if (fin){
        while (fin){
            paciente novo;
            fin>> b;
            novo.setNome(b);
            escrita.push_back(novo);
        }
    }
    else {
        cout << "arquivo não achado";
        return bancoDeDadosNaoAchado;
    }

    for (unsigned index = 0; index<escrita.size();index++){
        arvore.push_back(escrita[index]);
        //arvore += escrita[indice];
    }
    
    return ok;
}
tipoErro
cadastro::escreverBD(){

    ofstream fin(ARQUIVO);
    if (fin){
        for (unsigned index = 0; index < arvore.size(); index++){
            fin << arvore[index].getNome();
            fin << '\n';
        }
        /* 
        vector <paciente *> lista;
        if (arvore.ordem (&lista)) {
            cout << "arvore corrompida";
            return arvoreCorrompida;
        }
        */
    }
    else {
        cout << "arquivo não achado";
        return bancoDeDadosNaoAchado;
    }
    
    return ok;
}

void
cadastro::iniciarBD(){

    cout << "Iremos criar o diretorio \"BD\" onde se encontrará o arquivo" << endl
    << "É nesse diretório onde está os dados os programa" << endl
    << "Se mover o programa de lugar, lembre de mover o diretorio BD se desejar ter persistência" << endl
    << "Rode o programa novamente que deverá funcionar do \"zero\"" << endl;
    system("mkdir BD");
    string comando = "touch ";
    comando += ARQUIVO;
    /*
    char *c;
    c = (char *) comando.c_str();
    system(c);
    *///no trabalho anterior eu usei o malloc pq não conhecia o método c_str()...
    system(comando.c_str());
    erroBD = ok;
}
