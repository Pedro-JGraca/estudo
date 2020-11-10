#include <iostream>
#include <vector>
#include <string>

using namespace std;


#include "main.h"
#include "classes/cadastro.h"
#include "classes/paciente.h"

//arvore paciente paciente-especial cadastro

#define EOS                                              '\0'
#define PROGRAMA                                           0
#define COMANDO                                            1
#define NOME                                               2
#define NUMERO_ARGUMENTOS_LIMITE                           3
//./cadastro-pacientes comando nome/comando/""

int
main(int argc, char const *argv[])
{
    cadastro sistema;

    if (sistema.getErroBD()!= ok){
        cout << "erroBD" << endl;
        return sistema.getErroBD();
    }


    bool achouComando = false;

    if ((argc>NUMERO_ARGUMENTOS_LIMITE) or (argc<=(PROGRAMA+1))){
        if (argc > (PROGRAMA+1)){
            for (unsigned index = 0; index < comandos.size() ; index ++){
                if (argv[COMANDO] == comandos[index]){
                    cout << "Numero errado de argumentos pro comando" << endl << endl;
                    cout << argv[COMANDO] << ":" << endl;
                    cout << help(argv[PROGRAMA],argv[COMANDO]) << endl;
                    return numeroArgumentosInvalidoParaComando;
            }
        }
        }
        //else
        cout << "Numero argumentos errado." << endl;
        cout << "Para saber como usar a função, por favor use o comando:" << endl;
        cout << argv[0] << " help" << endl;
        return numeroArgumentosInvalido;
    }
    for (unsigned index = 0; index < comandos.size() ; index ++){
        if (argv[COMANDO] == comandos[index]){
            
            achouComando = true;
            switch (index)
            {
            case 0: // help
                if (argc == 2){// $./cadastro-pacientes help
                    cout << help(argv[PROGRAMA],"");
                }
                else if (argc == 3){// $./cadastro-pacientes help [comando]
                    bool nomeComando = false;
                    for ( unsigned aux = 0 ; aux <comandos.size(); aux ++ ){
                        if (argv[NOME] == comandos [ aux]){
                            cout << help(argv[PROGRAMA],argv[NOME]);
                            nomeComando = true;
                        }
                    }
                    if (!nomeComando){
                        cout << help(argv[PROGRAMA],"naoAchado"); 
                        return comandoNaoAchado;
                    }
                    
                }
                else {//argc = 1 ou >3, não deveria entrar
                    cout << "Não deveria acontecer";
                    return erroDesconhecido;
                }
                break;

            case 1: //inserir
                if (argc == (NOME+1)){
                    cout << "Inserir: " << argv[NOME] << endl;
                    paciente* ptr_paciente =  sistema.inserir(argv[NOME]);
                    if (ptr_paciente == NULL){
                        //tratamento
                        cout << "erro - what" << endl;
                    }
                
                }
                else {
                    cout << "Numero de Argumentos para o comando fornecido errado. Abaixo o uso correto." << endl;
                    cout << help(argv[PROGRAMA],argv[COMANDO]);
                    return numeroArgumentosInvalidoParaComando;
                }
                
                break;
            
            case 2: //buscar
                if (argc == (NOME+1)){
                    cout << "Buscar: " << argv[NOME] << endl;

                    paciente* ptr_paciente =  sistema.inserir(argv[NOME]);
                    if (ptr_paciente == NULL){
                        //tratamento
                        cout << "erro - what" << endl;
                    }
                    

                }
                else {
                    cout << "Numero de Argumentos para o comando fornecido errado. Abaixo o uso correto." << endl;
                    cout << help(argv[PROGRAMA],argv[COMANDO]);
                    return numeroArgumentosInvalidoParaComando;
                }
                break;

            case 3: //imprimir
                if (argc == (COMANDO+1)){
                    cout << "Imprimir" << endl;
                    sistema.imprimir();
                }
                else {
                    cout << "Numero de Argumentos para o comando fornecido errado. Abaixo o uso correto." << endl;
                    cout << help(argv[PROGRAMA],argv[COMANDO]);
                    return numeroArgumentosInvalidoParaComando;
                }

                break;
            default:
                cout  << "Erro desconhecido." << endl;
                return erroDesconhecido;
                break;
            }
        }
    }
    
    if (!achouComando){
        cout << "Comando não encontrado" << endl;
        cout << "Para saber como usar a função, por favor use o comando:" << endl;
        cout << argv[0] << " help" << endl;
        return comandoNaoAchado;
    }

    return ok;
}



string 
help(string argv,string comando){

    if (comando.size()==0){
        string saida = "Este programa é um gerenciador de pacientes para hospitais via CLI.\n";
        saida+="Seu funcionamento básico está ligado a comandos.\n\n";
        saida+="$" + argv + " [comando] [argumento1]\n\n";
        saida+="Nesse caso o argumento 1 pode existir ou não de acordo com o comando.\n";
        saida+="Abaixo está a lista de comandos existentes, bem como uma explicação de cada uma.\n";
        saida+="Se desejar entender como usar o comando escreva na linha de comando:\n\n";
        saida+="$" + argv + " help [argumento]\n\n";
        saida+="Onde o argumento do comando acima é um dos comandos que vamos citar abaixo.\n\n";

        saida+="help\t\t\t\tDescreve o programa como um todo ou apenas um comando.\n";
        saida+="inserir\t\t\t\tInsere um paciente novo\n";
        saida+="buscar\t\t\t\tDiz se o paciente buscado está cadastrado\n";
        saida+="imprimir\t\t\tDiz o nome de todos os pacientes cadastrados\n";

             
       return saida;
    }

    if (comando == comandos[0]){//"help"
        string saida ="Descreve o programa como um todo ou apenas um comando.\n";
        saida+="Se for para descrever o programa todo:\n\b";
        saida+="$" + argv + " help \n\n";
        saida+="Se for para descrever um comando:\n\n";
        saida+="$" + argv + " help [comando] \n";

        return saida;
    }
    else if (comando  == comandos[1]){//inserir
        string saida ="Insere um paciente novo";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " inserir [nome-do-paciente]\n\n";
        return saida;
    }
    else if (comando  == comandos[2]){//buscar
        string saida ="Diz se o paciente buscado está cadastrado";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " buscar [nome-do-paciente]\n\n";
        return saida;        
    }
    else if (comando  == comandos[3]){//imprimir
        string saida ="Diz o nome de todos os pacientes cadastrados";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " imprimir\n\n";
        return saida;        
    }
    string saida;
    saida = "Comando pedido não listado.";
    saida += "Por favor escreva:\n\n";
    saida += "$" + argv + " help\n\n";
    saida += "Com isso temos a lista de todos os comandos aceitos\n";
    return saida;
}

