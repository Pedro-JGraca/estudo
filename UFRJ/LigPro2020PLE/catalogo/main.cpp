#include "classes/proxyCatalogo.h"
#include "classes/catalogo.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

#define EOS                                              '\0'
#define COMANDO                                            1
#define FILME                                              2
#define PRODUTORA                                          3
#define NOTA                                               4

int
main(int argc, char const *argv[])
{

    proxyCatalogo catalogo;
    if (catalogo.getErro()){
        return catalogo.getErro();
    }

    bool achouComando = false;

    if (argc>5){
        if (argc > 1){
            for (unsigned short i =0; i < comandos.size() ; i++){
                if (argv[COMANDO] == comandos[i]){
                    cout << "Numero errado de argumentos pro comando" << endl;
                    cout << catalogo.help(argv[0],argv[COMANDO]) << endl;
                    return numeroArgumentosInvalidoParaComando;
                }
            } 
        }

        cout << "Numero argumentos errado." << endl;
        cout << "Para saber como usar a função, por favor use o comando:" << endl;
        cout << argv[0] << " help" << endl;
        return numeroArgumentosInvalido;
    }

    unsigned index = 0;
    for (;index < comandos.size();index ++){
        if (argc == 1){
                cout << "Para saber como usar a função, por favor use o comando:" << endl;
                cout << argv[0] << " help" << endl;
                return ok;
        }
            
        if (argv[COMANDO] == comandos[index]){
            unsigned short aux = index;
            index =  comandos.size() + 1;
            achouComando = true;//achou

            string comando = argv[COMANDO];

            if (argc == 2){ //help, ListarCatalogo , ListarFilmes , MelhorFilme
                if(!((rang[0] <= aux) and (aux < rang[1])))
                {
                    cout << "Numero de argumentos pro comando " << comando << " errado" << endl;
                    cout << catalogo.help(argv[0],comando) << endl;
                    return numeroArgumentosInvalidoParaComando;
                }
                switch (aux){
                    case 0:
                        cout << catalogo.help(argv[0],"") << endl;
                        break;

                    case 1:
                        catalogo.listarCatalogo();
                        break;

                    case 2:
                        catalogo.listarFilmes();
                        break;

                    case 3:
                        cout << catalogo.melhorFilme();
                        break;

                    default:
                        cout << "Erro indesperado "<< endl;
                        return erroDesconhecido;
                        break;
                }

                return ok;
            }

            if (argc == 3) {//,"help","removerFilme","buscarFilme","ListarFilme"
                string filme = argv[2];
                tipoErro erro;
                if(!(((rang[1] <= aux) and (aux < rang[2])) or (aux == 0))){
                    cout << "Numero errado de argumentos pro comando." << endl;
                    cout << catalogo.help(argv[0],comando) << endl;
                    return numeroArgumentosInvalidoParaComando;
                }

                switch (aux){
                    case 0://pq temos 2 helps, em 0 e 4. Ele irá encontrar primeiro o help em 0
                    case 4:
                        cout << catalogo.help(argv[0],filme) << endl;
                        break;

                    case 5:
                        catalogo.removerFilme(filme);
                        break;

                    case 6:
                        cout << "O filme \""<< filme << "\" " << 
                        (catalogo.buscarFilme(filme)?"":"nao ")
                        << "foi encontrado" << endl;
                        break;

                    case 7:
                        erro = catalogo.listarFilme(filme);
                        if (erro!=ok){
                            return erro;
                        }
                        break;

                    default:
                        cout << "Erro indesperado: " << comando<< " " <<filme << endl;
                        return erroDesconhecido;
                        break;
                }


            }

            if (argc == 4) {// "editarNome","editarProdutora","editarNota"
                string filme = argv[2];
                string troca = argv[3];
                tipoErro erro;
                if(!((rang[2] <= aux) and (aux < rang[3]))){
                    cout << "Numero de argumentos pro comando errado" << endl;
                    cout << catalogo.help(argv[0],comando) << endl;
                    return numeroArgumentosInvalidoParaComando;
                }

                switch (aux){
                    case 8:
                        erro = catalogo.editarNome(filme,troca);
                        if (erro!=ok){
                            return erro;
                        }
                        break;

                    case 9:
                        erro = catalogo.editarProdutora(filme,troca);
                        if (erro!=ok){
                            return erro;
                        }
                        break;
                    case 10:
                        erro = catalogo.editarNota(filme,troca);
                        if (erro!=ok){
                            return erro;
                        }
                        break;
                    default:
                        cout << "Erro inesperado:" << comando << " " << filme << " " << troca<< endl;   
                        return erroDesconhecido;
                        break;
                }

            }

            if (argc == 5) {//"InserirFilme"

                string filme = argv[2];
                string produtora = argv[3];
                string nota = argv[4];

                if(!((rang[3] <= aux) and (aux < rang[4]))){
                    cout << "Numero de argumentos pro comando errado" << endl;
                    cout << catalogo.help(argv[0],comando) << endl;
                    return numeroArgumentosInvalidoParaComando;
                }

                switch (aux){
                    case 11:
                        cout << catalogo.inserirFilme(filme,produtora,nota) << endl;
                        break;
                    
                    default:
                        cout << "Erro indesperado: " << comando<< " " <<filme << produtora << " " << nota<< endl;
                        return erroDesconhecido;
                        break;
                }
            }


        }
    }

    if (!achouComando){
        cout << "roda erro de comando nao encontrado" << endl;
        return comandoNaoAchado;
    }

    catalogo.escreverBD();
    return ok;
}


//cout<<catalogo, cout<<filme , cin >> filme 