#include "catalogo.h"
#include <algorithm>

string  
catalogo::operator+=(filme novo){
   
    string saida = "";
    
    if (isEmpty(novo)){ //verificar se novo é vazio
        saida +="filme com seus campos não preenchidos. Não adicionado.\n";
    }
    else{//verificar se novo já existe ( implementar == para filmes, verificando o nome)
        if (filmeIn(novo)){
            saida+="filme já presente. Não adicionado\n";
        }
        else{
            if (filmes.size() == MAXIMO){
                saida +="limite de filmes no catalogo. Não adicionado.\n";
            }
            else {
                filmes.push_back(novo);
                saida +="adicionado.\n";
                if (filmes.size()>2)
                    ordenar();
            }
        }
    }
    return saida;
}

string 
catalogo::operator+=(vector<filme> rajada){
    for (unsigned short index=0;index<rajada.size();index++){
        operator+=(rajada[index]);
    }
    return "";
}

string
catalogo::operator-=(filme novo){

    unsigned short index = 0;
    for (; index< filmes.size(); index++){
        if(filmes[index]==novo){
            filmes.erase(filmes.begin()+index);
            index = filmes.size() +2;
            return "removido";
        }
    }
    if (index == filmes.size()){
        return  "Não removido";
    }

    return "removido";

}


unsigned short 
catalogo::getTamanho(){
    return filmes.size();
}

filme
catalogo::getFilmebyIndex(unsigned short index){
    return filmes[index];
}


void
catalogo::getFilmeByNome(string Nome, filme * local){

    unsigned short index = 0;
    for (; index< filmes.size(); index++){
        if(filmes[index].nome==Nome){
            *local =  filmes[index];
            index = filmes.size() +2;
        }
    }
    if (index == filmes.size()){
        cout << "Filme não encontrado" << endl;

        local = nullptr;
    }
    
}



bool
operator==(filme novo, filme outro){//global para esse contexto
    
    if(novo.nome.size()!=outro.nome.size())
    {
        return false;
    }
    for (unsigned short i = 0 ;i < novo.nome.size();i++){
        if(novo.nome[i]!=outro.nome[i]){
            return false;
        }
    }
    
    return true;
}

bool 
operator<(filme novo, filme outro){//global para esse contexto
    
    unsigned short menor;
    if(novo.nome.size()<outro.nome.size())
    {
        menor = novo.nome.size();
    }
    else{
        menor = outro.nome.size();
    }

    for (unsigned short i=0 ; i < menor ; i++){
        if (novo.nome[i]<outro.nome[i]){  //a é menor que b?
            return true;
        }
        else if (novo.nome[i]>outro.nome[i]){
            return false;
        }
    }
    
    if (novo.nome.size() == menor){
        return true;
    }
    else{
        return false;
    }
}

bool
operator>(filme novo, filme outro){//global para esse contexto

    unsigned short menor;
    if(novo.nome.size()<outro.nome.size())
    {
        menor = novo.nome.size();
    }
    else{
        menor = outro.nome.size();
    }

    for (unsigned short i=0 ; i < menor ; i++){
        if (novo.nome[i]<outro.nome[i]){  //a é menor que b?
            return false;
        }
        else if (novo.nome[i]>outro.nome[i]){
            return true;
        }
    }
    
    if (novo.nome.size() == menor){
        return false;
    }
    else{
        return true;
    }

}


filme*
catalogo::operator()(string nome){//busca sobrecarregada
    if (nome.size() == 0){
        return nullptr;
    }
    for (unsigned short index = 0; index< filmes.size(); index++){
        if(filmes[index].nome==nome){
            return &filmes[index];
        }
    }
    return nullptr;//se nao achar
}


filme*
catalogo::operator()(const string nome, string novaProdutora){//sobrecarga de alterar produtora
    filme *ptr = operator()(nome);
    if (ptr != nullptr){
        ptr->produtora=novaProdutora;
        return ptr;
    }
    else {
        cout << "Não encontrado" << endl;
        return nullptr;
    }
    
}

filme*
catalogo::operator()(const string nome, double novaNota){//sobrecarga de alterar nota
    filme *ptr = operator()(nome);
    if (ptr != nullptr){
        ptr->nota=novaNota;
        return ptr;
    }
    else {
        cout << "Não encontrado" << endl;
        return nullptr;
    }
}


void
catalogo::ordenar(){
    
    unsigned short isOrdered = 0; 
   
    unsigned short tamanho = filmes.size();
    while(isOrdered == 0){ 
     
        isOrdered = 1; //presume ordem
     
        for(unsigned short i=0; i < tamanho-1; i++){
            if(filmes[i] > filmes[i+1]){ //se não estiver em ordem, troca
                filme temp = filmes[i];
                filmes[i] = filmes[i+1];
                filmes[i+1] = temp;
        
                isOrdered = 0; // informa falta de ordem
            }
        }
    }
    
    //sort(filmes[0], filmes[filmes.size()-1]); 
}



bool
catalogo::isEmpty(filme novo){

    bool nomeIsEmpty = novo.nome.empty();
    bool produtoraIsEmpty = novo.produtora.empty();
    bool notaIsEmpty = (novo.nota<0);
    return nomeIsEmpty || produtoraIsEmpty || notaIsEmpty;

}

string
catalogo::getLista(){
    string saida = "";
    for (unsigned short index = 0; index < filmes.size(); index++){
        saida += to_string(index+1);
        saida += ": Nome: " + filmes[index].nome + "\t|\tProdutora: " + filmes[index].produtora + "\t|\tNota: " + to_string(filmes[index].nota) + "\n";
    }
    return saida;
}

string
catalogo::getFilmes(){
    string saida ="";
    for (unsigned short index = 0; index < filmes.size(); index++){
        if (index!=0) saida +="\n";
        saida += filmes[index].nome + "\n";
        saida += filmes[index].produtora + "\n";
        saida += to_string(filmes[index].nota);
    }
    return saida;
}

string
catalogo::getNomes(){
    string saida ="";
    for (unsigned short index = 0; index < filmes.size(); index++){
        saida += filmes[index].nome + "\n";
    }
    return saida;
}


bool 
catalogo::filmeIn(filme novo){

    if (filmes.size()==0){
        return false;
    }
    for (unsigned short index = 0; index< filmes.size(); index++){
        if(filmes[index]==novo){
            return true;
        }
    }
    
    return false;
}

filme* 
catalogo::getFilmeMaiorNota(){ // como é impossivel eu sobrescrever > e < para o mesmo contexto, só que para nota por simples lógica, irei simplesmente ignorar o pedido de ser por > e <, por que eu já implementei isso para ordenar por ordem alfabética.
    unsigned maiorNota = 0;
    filme * maior;
    for (unsigned short index = 0; index < filmes.size(); index++){
        if (maiorNota<filmes[index].nota){
            maiorNota = filmes[index].nota;
            maior = &filmes[index];
        }
    }

    return maior;

}