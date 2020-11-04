#include "proxyCatalogo.h"
#include "catalogo.h"

#include <cstring>
#include <stdlib.h>
#include <fstream>


proxyCatalogo::proxyCatalogo(){
    erro = lerBD();
}

tipoErro 
proxyCatalogo::lerBD(){
    //le do arquivo
    string entrada = "";
    char a[BUFFER];
    ifstream fin(ARQUIVO);
    vector<filme> escrita;
    if (fin){
        unsigned short i=0;
        const unsigned short index=0;
        while (((bool)fin)+(!(i==1))){
            filme novo;
            if (i == 0){
                escrita.push_back(novo);
            }
            if (i==3){
                i=0;
                if (Catalogo.isEmpty(escrita[index])){
                    cout << "Arquivo corrompido" << endl;
                    return arquivoCorrompido;
                }
                else {
                    Catalogo+=escrita[index];
                    filme novo;
                    escrita[index] = novo;
                }
            }
            if (fin.getline(a,BUFFER));
            else {
                a[0] = EOS;
            }
            switch (i){
                    case 0://nome
                        escrita[index].nome=a;
                        break;
                    case 1://produtora
                        escrita[index].produtora=a;
                        break;
                    case 2:
                        escrita[index].nota=paraDouble((string)a);
                        break;
            }
            i++;
        }
    }
    else {

        cout << "Arquivo nao achado" << endl;
        cout << "Iremos criar o diretorio \"BD\" onde se encontrará o arquivo" << endl
        << "É nesse diretório onde está os dados os programa" << endl
        << "Se mover o programa de lugar, lembre de mover o diretorio BD se desejar ter persistência" << endl
        << "Rode o programa novamente que deverá funcionar do \"zero\"" << endl;
        system("mkdir BD");
        string comando = "touch ";
        comando += ARQUIVO;
        char *c;
        c = (char *) malloc(sizeof(char *) * comando.size());
        c = &comando[0];
        system(c);
        return erroAbrirArquivo;
    }
    return ok;
}

tipoErro
proxyCatalogo::getErro(){
    return erro;
}

double
proxyCatalogo::paraDouble(string entrada){
    char * validacao;
    char * a;
    a= (char *) malloc(sizeof(char)*BUFFER);
    a = &entrada[0];
    double saida;
    if (*a == '-'){
        cout << "nota negativa" << endl;
        return -1;
    }
    else if(*a == EOS){
        cout << "nota vazia" << endl;
        return -1;
    }

    saida = strtod(a,&validacao);

    if (*validacao!=EOS){
        cout << "caracter não permitido:" << *validacao << endl;
        return -1;
    }

    if (saida > 10){
        cout << "Nota acima de 10 não permitida." << endl;
        return -1;
    }

    return saida;
}


string 
proxyCatalogo::help(string argv,string comando){

    if (comando.size()==0){

        string saida = "Este programa é um gerenciador de filmes para um catálogo via CLI.\n";
        saida+="Seu funcionamento básico está ligado a comandos.\n";
        saida+="Uso:\n\n";
        saida+="$" + argv + " [comando] [argumento1] ... [argumentoN]\n\n";
        saida+="Onde N é a quantidade de argumentos que o comando precisa, podendo ir de 0 a 4\n";
        saida+="Abaixo está a lista de comandos existentes, bem como uma explicação de cada uma.\n";
        saida+="Se desejar entender como usar o comando escreva na linha de comando:\n\n";
        saida+="$./catalogo help [argumento]\n\n";
        saida+="Onde o argumento do comando acima é um dos comandos.\n\n";

        saida+="help\t\t\t\t\tDescreve o programa como um todo ou apenas um comando.\n";
        saida+="listarCatalogo\t\t\t\tLista todos os filmes com seus detalhes.\n";
        saida+="listarFilmes\t\t\t\tLista o nome de todos os filmes\n";
        saida+="melhorFilme\t\t\t\tInforma qual filme tem a maior nota\n";
        saida+="removerFilme\t\t\t\tRemove um filme informado\n";
        saida+="buscarFilme\t\t\t\tBusca o filme e diz se achou ou não. Se achar ele printa os detalhes.\n";
        saida+="listarFilme\t\t\t\tRetorna os dados de um filme específico\n";
        saida+="editarNome\t\t\t\tBusca o filme a partir do nome dado e troca pelo nome pedido. Se falhar, informa \n";
        saida+="editarProdutora\t\t\t\tBusca o filme a partir do nome dado e troca pela produtora pedida. Se falhar, informa \n";
        saida+="editarNota\t\t\t\tBusca o filme a partir do nome dado e troca pela nota pedida. Se falhar, informa \n";
        saida+="inserirFilme\t\t\t\tInsere um filme novo no catálogo\n";
             
       return saida;
    }

    if (comando == comandos[0]){//"help"
        string saida ="Descreve o programa como um todo ou apenas um comando.\n";
        saida+="Se for para descreve o programa todo:\n";
        saida+="Uso: \n\n";
        saida+="$" + argv + " help \n\n";
        saida+="Se for para descrever um comando:\n";
        saida+="$" + argv + " help [comando] \n\n";

        return saida;
    }
    else if (comando  == comandos[1]){//ListarCatalogo
        string saida ="Lista todos os filmes com seus detalhes.";
        saida+="\nUso: \n\n";
        saida+="$" + argv + "ListarCatalogo\n\n";
        return saida;
    }
    else if (comando  == comandos[2]){//ListarFilmes
        string saida ="Lista o nome de todos os filmes";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " listarFilmes\n\n";
        return saida;        
    }
    else if (comando  == comandos[3]){//melhorFilme
        string saida ="Informa qual filme tem a maior nota";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " melhorFilme\n\n";
        return saida;        
    }
    else if (comando  == comandos[5]){//removerFilme
        string saida ="Remove um filme informado";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " removerFilme [FILME]\n\n";
        return saida; 
    }
    else if (comando  == comandos[6]){//"buscarFilme"
        string saida ="Busca o filme e diz se achou ou não. Se achar ele printa os detalhes.";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " buscarFilme [FILME]\n\n";
        return saida; 
    }
    else if (comando  == comandos[7]){//listarFilme
        string saida ="Retorna os dados de um filme específico";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " listarFilme [FILME]\n\n";
        return saida; 
    }
    else if (comando == comandos[8]){//editaNome
        string saida ="Busca o filme a partir do nome dado e troca pelo nome pedido. Se falhar, informa";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " editarNome [FILME-QUE-DESEJA-TROCAR] [NOVO NOME]\n\n";
        return saida;
    }
    else if (comando == comandos[9]){//editarProdutora
        string saida ="Busca o filme a partir do nome dado e troca pela produtora pedida. Se falhar, informa";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " editarNome [FILME-QUE-DESEJA-TROCAR] [NOVA PRODUTORA]\n\n";
        return saida;
    }
    else if (comando == comandos[10]){//editaNota
        string saida ="Busca o filme a partir do nome dado e troca pela nota pedida. Se falhar, informa";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " editarNome [FILME-QUE-DESEJA-TROCAR] [NOVA NOTA]\n\n";
        return saida;
    }

    else if (comando  == comandos[11]){//inserirFilme
        string saida ="Insere um filme novo no catálogo";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " inserirFilme [FILME] [PRODUTORA] [NOTA]\n\n";
        return saida; 
    }

    return "Erro.";
}

void
proxyCatalogo::listarCatalogo(){
    cout << Catalogo;
}

ostream & operator<<(ostream &output, const catalogo A){//precisa ser global
    string saida = "";
    proxyCatalogo cat;
    for (unsigned short index = 0; index < cat.getCatalogo().getTamanho(); index++){
        saida += to_string(index+1);
        saida += ": Nome: " + cat.getCatalogo().getFilmebyIndex(index).nome + "\t|\tProdutora: " + cat.getCatalogo().getFilmebyIndex(index).produtora + "\t|\tNota: " + to_string(cat.getCatalogo().getFilmebyIndex(index).nota) + "\n";
    }

    output << saida;
    return output;    
}

ostream & operator<<(ostream &output, const filme A){//precisa ser global
    string saida = "";
    proxyCatalogo cat;
    filme * ptr = cat.getCatalogo()(A.nome);
    saida += "Nome: " + ptr->nome + "\t\t\tProdutora: "+ ptr->produtora + "\t\t\tNota: " + to_string(ptr->nota);
    output << saida;
    return output;    
}

istream & operator>>(istream &input, filme &saida) {
    string Nota;
    double n;
    input >> saida.nome;
    input >> saida.produtora;
    input >> Nota;
    n = proxyCatalogo().paraDouble(Nota);
    if (n>0){
        saida.nota = n;
    }
    else {
        cout << "Não conseguiu escrever no filme";
    }
    return input;
}

catalogo
proxyCatalogo::getCatalogo(){
    return Catalogo;
}

string
proxyCatalogo::inserirFilme(string Filme, string Produtora, string Nota){//como nao quero escrever os dados por menu, não usarei cin >> filme. Porêm essa opção foi desenvolvida dentro do catalogo.cpp e testada.

    filme novo;
    novo.nome = Filme;
    novo.produtora = Produtora;
    novo.nota = paraDouble(Nota);
    string saida ;
    saida +=( Catalogo+=novo);
    return saida;
}

tipoErro 
proxyCatalogo::escreverBD(){
    string entrada = "";
    ofstream fin(ARQUIVO);
    if (fin){
        fin << Catalogo.getFilmes();
    }
    else {
        cout << "Arquivo nao achado" << endl;
        cout << "Iremos criar o diretorio \"BD\" onde se encontrará o arquivo" << endl
        << "É nesse diretório onde está os dados os programa" << endl
        << "Se mover o programa de lugar, lembre de mover o diretorio BD se desejar ter persistência" << endl
        << "Rode o programa novamente que deverá funcionar do \"zero\"" << endl;
        system("mkdir BD");
        string comando = "touch ";
        comando += ARQUIVO;
        char *c;
        c = (char *) malloc(sizeof(char *) * comando.size());
        c = &comando[0];
        system(c);
        return erroAbrirArquivo;
    }
    return ok;
}

void
proxyCatalogo::listarFilmes(){
    cout << Catalogo.getNomes();
}

tipoErro
proxyCatalogo::listarFilme(string Nome){
    if(buscarFilme(Nome)){
        cout << *Catalogo(Nome);
        cout << endl;
        return ok;
    }
    else {
        cout << "Filme não achado" << endl;
        return filmeNaoAchado;
    }
}

string
proxyCatalogo::melhorFilme(){
    filme * maior = Catalogo.getFilmeMaiorNota();
    return "Maior filme: " +maior->nome + "\nCom a nota: " + to_string(maior->nota) + "\n" ;
}

void
proxyCatalogo::removerFilme(string Filme){
    
    filme novo;

    Catalogo.getFilmeByNome(Filme,&novo);

    cout << (Catalogo-= novo) << endl;
    
}

bool 
proxyCatalogo::buscarFilme(string nome){
    if (Catalogo(nome)){
        return true;
    }
    return false;
}

tipoErro
proxyCatalogo::editarFilme(string Filme, string Produtora, string Nota){
    filme * filme= Catalogo(Filme);
    
    if(filme!=nullptr){
        cout << "Filme cuja produtora foi editada:" << endl;
        cout << filme->nome << endl ;
        return ok;
    }
    else {
        cout << "editora não pode ser editada";
        return filmeNaoAchado;
    }


}

tipoErro
proxyCatalogo::editarProdutora(const string Filme, string produtora){
    filme * filme= Catalogo(Filme,produtora);
    
    if(filme!=nullptr){
        cout << "Filme cuja produtora foi editada:" << endl;
        cout << filme->nome << endl ;
        return ok;
    }
    else {
        cout << "editora não pode ser editada";
        return filmeNaoAchado;
    }

}

tipoErro
proxyCatalogo::editarNota(const string Filme, string Nota){
    double nota = paraDouble(Nota);
    if (nota < 0){
        cout << "Nota não pode ser editada." << endl;
        return Ninvalido;
    }
    filme * filme= Catalogo(Filme,nota);
    
    if(filme!=nullptr){
        cout << "Filme cuja nota foi editada:" << endl;
        cout << filme->nome << endl ;
    }

    return ok;
}

tipoErro
proxyCatalogo::editarNome(const string Filme, string Nome){
    filme * ptrF = Catalogo(Filme);
    filme novo;
    
    if(ptrF!=nullptr){
        novo.nome = Nome;
        novo.produtora = ptrF->produtora;
        novo.nota = ptrF->nota;
        Catalogo-=*ptrF;
        Catalogo+=novo;
        cout << "Filme cujo nome foi editado:" << endl;
        cout << Filme << endl ;
        cout << "Novo Nome:" << endl;
        cout << Nome << endl;
    }
    else {
        cout << "filme não achado" << endl;
        cout << "Nome do filme não pode ser editado" << endl;
    }

    return ok;

}