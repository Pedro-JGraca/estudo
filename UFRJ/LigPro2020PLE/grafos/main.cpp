#include "tratamento.h"
#include "classes/grafo.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

#define EOS                                              '\0'
#define COMANDO                                            1
#define ARQUIVO                                            2
#define NUMERO                                             3

int
main(int argc, char const *argv[])
{  
    unsigned numero;
    bool maior = false;
    bool sequencia = false;
    if ((argc < (NUMERO_ARGUMENTOS - 1)) or (argc > (NUMERO_ARGUMENTOS+1))) {
        cout << "Numero de argumentos incorreto" << endl
        << "Para saber como o programa funciona;" << endl << "formato:" << endl<<
        argv[0] << "\t<arquivo-texto> " << comandos[0] << endl; 
        return numeroArgumentosInvalido;
    }

    if (argv[COMANDO] == comandos[0]){//help
        if (argc == 2){
            cout << "Comandos:" << endl <<
            comandos[0] << 
            "\t\t\tExplica o funcionamento do programa de forma geral ou de um comando" << endl <<
            comandos[1] << 
            "\t\t\tDiz a palavra mais citada no texto" << endl <<
            comandos[2] << 
            "\t\tDiz a sequencia mais citada no texto" << endl
            ;
            cout << endl << "Para saber funcionamento de qualquer comando rode:" << endl << endl <<
            argv[0] << " " << comandos[0] << " [COMANDOS]" << endl<< endl;
            
            ;
        }
        else if (argc ==3 ){
            if (argv[COMANDO+1]== comandos[0]){
                cout << "Explica o funcionamento do programa de forma geral ou de um comando" << endl <<
                "Há duas formas de usar, a geral e a expecifica" << endl <<
                "Geral:\tDescreve o funcionamento do programa" << endl <<
                "Uso:" << endl <<
                argv[0] << " " << comandos[0] << endl<< endl;
                cout << "Especifica:\tDescreve o funcionamento de um comando do programa" << endl <<
                "Uso:" << endl <<
                argv[0] << " " << comandos[0] << " [COMANDO]" << endl<< endl;
                ;
            }
            
            else if (argv[COMANDO+1] == comandos[1]){//palavra
                cout << "Diz a palavra mais citada no texto" << endl << 
                "Uso:" << endl <<
                argv[0] << " " << comandos[1] << " ARQUIVO" << endl << endl;
                ;
            }
            else if (argv[COMANDO +1] == comandos[2]){//sequencia
                cout << "Diz a sequencia de palavras mais citada no texto a partir de um numero forncecido (entre 2 e 5)" << endl << 
                "Uso:" << endl <<
                argv[0] << " " << comandos[2] << " ARQUIVO <numero-inteiro-sem-sinal>"  << endl << endl;
                ;
            }
            

            else {
                cout<< "Comando não encontrado" << endl <<
                "uso:" << endl << 
                argv[0] << " " << comandos[0] << " [COMANDOS]" << endl<< endl;
                cout << "Para saber a lista de comando:" << endl <<
                argv[0] << " " << comandos[0] << endl<< endl;
                return comandoNaoAchado;

            }
        }
        else {
            cout << "Numero de argumentos incorreto" << endl
            << "Para saber como o programa funciona;" << endl << "formato:" << endl<<
            argv[0] << "\t<arquivo-texto> " << comandos[0] << endl; 
            return numeroArgumentosInvalido;

        }
        return ok;

    }
    else if (argv[COMANDO] == comandos[1]){//palavra
        if (argc != NUMERO_ARGUMENTOS){
            cout << "Numero de argumentos invalido" << endl;
            
            cout << "Uso:" << endl <<
            argv[0] << " " << comandos[1] << " ARQUIVO"  << endl << endl;
            ;
            return numeroArgumentosInvalido;
        }
        maior = true;
    }
    else if (argv[COMANDO] == comandos[2]){//sequencia
        if (argc != (NUMERO_ARGUMENTOS+1)){
            cout << "Numero de argumentos invalido" << endl;
            
            cout << "Uso:" << endl <<
            argv[0] << " " << comandos[2] << " ARQUIVO <numero-inteiro-sem-sinal>"  << endl << endl;
            ;
            return numeroArgumentosInvalido;
        }
        sequencia = true;
        char *validacao;
        if (argv[NUMERO][0]=='-') {
            cout << "Nao e permitido numero negativo. Tente outro." << endl;
            return Ninvalido;
        }
        numero = strtoul(argv[NUMERO],&validacao,10);
        if (*validacao != EOS){
            cout << "Nao e permitido: " << *validacao  << endl;
            return Ninvalido;
        }
    }


    else {
        cout<< "Comando não encontrado" << endl <<
        "Para saber como usar:" << endl <<
        argv[0] << " " << comandos[0] << endl<< endl;
        return comandoNaoAchado;

    }

    string entrada = "";
    char a[BUFFER];
    ifstream fin(argv[ARQUIVO]);
    if (fin){
        while (fin){
            fin.getline(a,BUFFER);
            if (strlen(a)){
                entrada += a;
            }
        }
    }
    else {

        cout << "Arquivo nao achado" << endl;
        cout << "O Arquivo deve se encontrar dentro do mesmo diretorio do programa: " << argv[0] << endl;
        return erroAbrirArquivo;
    }
    grafo g(entrada);
    if (maior) {
        cout << g.getMaior() << endl;
    }
    if (sequencia){
        cout << g.getSequencia(numero) << endl;
    }
    
    return ok;
}