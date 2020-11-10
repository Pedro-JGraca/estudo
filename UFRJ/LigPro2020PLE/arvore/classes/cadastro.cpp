#include "cadastro.h"
#include "arvore.h"
cadastro::cadastro(){
    erroBD = lerBD();
    if (erroBD!=ok){
        saida = iniciarBD();
    }
}
cadastro::~cadastro(){
    erroBD = escreverBD();
    if (erroBD!=ok){
        saida = iniciarBD();
    }
}


paciente*
cadastro::inserir(string Nome)
{
    paciente novo(Nome);

    if (buscar(Nome)){
        return NULL;
    }
    arvore2.push_back(novo);
    /*if (!(arvore += paciente)){
        cout << "falha na incersão";
        return NULL;
    }*/
    
    return &arvore2.back(); 
}

paciente*
cadastro::buscar(string Nome)
{
    for (unsigned index = 0;index < arvore2.size();index++){
        if (arvore2[index].getNome()==Nome){
            return &arvore2[index];
        }
    }

    /*        
    paciente *p = arvore(Nome);
    if(!p){
        cout << Não achado << endl;
    }
    return p;
    */

    return NULL; 
}

string
cadastro::imprimir(){
    string U="";
    for (unsigned index = 0;index < arvore2.size();index++){
        U += arvore2[index].getNome() + "\n";
        //cout << paciente;
        //cout << endl;
    }
    //cout << arvore;

    return U;
}

tipoErro
cadastro::getErroBD(){
    return erroBD;
}

tipoErro
cadastro::lerBD(){

    string b;
    ifstream fin(ARQUIVO);
    if (fin){
        while (fin >> b){
            
            if ( b!= "\0"){
                paciente novo(b);
                arvore2.push_back(novo);
                //arvore += escrita[indice];
            }
        }
    }
    else {
        return bancoDeDadosNaoAchado;
    }
    
    return ok;
}
tipoErro
cadastro::escreverBD(){

    ofstream fin(ARQUIVO);
    if (fin){
        for (unsigned index = 0; index < arvore2.size(); index++){
            string saida = arvore2[index].getNome() + "\n";
            fin << saida;
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
        return bancoDeDadosNaoAchado;
    }
    
    return ok;
}

string
cadastro::iniciarBD(){
    string U = "Iremos criar o diretorio \"BD\" onde se encontrará o arquivo\nÉ nesse diretório onde está os dados os programa.\nSe mover o programa de lugar, lembre de mover o diretorio BD se desejar ter persistência\nRode o programa novamente que deverá funcionar do \"zero\"\n";
    system("mkdir BD");
    string comando = "touch ";
    comando += ARQUIVO;
    /*
    char *c;
    c = (char *) comando.c_str();
    system(c);
    *///no trabalho anterior eu usei o malloc pq não conhecia o método c_str()...
    system(comando.c_str());

    return U;
}
