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

    bool achouComando = false;

    if ((argc < 1 ) or (argc==4) or (argc>5)){
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
                        cout << "rode Listar Catalogo: " << comando << endl;
                        break;

                    case 2:
                        cout << "rode Listar Filmes: " << comando << endl;
                        break;

                    case 3:
                        cout << "rode Melhor Filme: " << comando << endl;
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
                if(!(((rang[1] <= aux) and (aux < rang[2])) or (aux == 0))){
                    cout << "Numero errado de argumentos pro comando." << endl;
                    cout << catalogo.help(argv[0],comando) << endl;
                    return numeroArgumentosInvalidoParaComando;
                }

                switch (aux){
                    case 0:
                    case 4:
                        cout << catalogo.help(argv[0],filme) << endl;
                        break;

                    case 5:
                        cout << "rode remover Filme: " << comando << " " << filme << endl;
                        break;

                    case 6:
                        cout << "rode Buscar Filme: " << comando << " " <<filme << endl;
                        break;

                    case 7:
                        cout << "rode Listar Filme: " << comando << " " <<filme << endl;
                        break;

                    default:
                        cout << "Erro indesperado: " << comando<< " " <<filme << endl;
                        return erroDesconhecido;
                        break;
                }


            }

            if (argc == 5) {//"InserirFilme","EditarFilme"

                string filme = argv[2];
                string produtora = argv[3];
                string nota = argv[4];

                if(!((rang[2] <= aux) and (aux < rang[3]))){
                    cout << "Numero de argumentos pro comando errado" << endl;
                    cout << catalogo.help(argv[0],comando) << endl;
                    return numeroArgumentosInvalidoParaComando;
                }

                switch (aux){
                    case 8:
                        cout << catalogo.inserirFilme(filme,produtora,nota) << endl;
                        break;

                    case 9:
                        cout << "rode Editar Filme: " << comando << " " << filme << produtora << " " << nota  << endl;
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


    return ok;
}