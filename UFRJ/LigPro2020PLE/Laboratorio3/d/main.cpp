#include <iostream>
#include "agenda.h"

using namespace std;


int main(int argc, char const *argv[])
{
    Agenda agenda(2);
    bool sair = false;
    string confirmar;
    unsigned short idade;

    while(!sair){
        cout << "1.Inserir cadastro" << "   " << "2.Listar Agenda" << "   " << "3.Sair" <<endl;
        cin >> confirmar;
        if (confirmar == "1"){
            Cadastro entrar;
            cout << endl<< "Nome:";
            cin >> confirmar;
            entrar.setNome(confirmar);
            cout<< "Profissao:";
            cin >> confirmar;
            entrar.setProfissao(confirmar);
            cout<< "Idade:";
            cin >> idade;
            entrar.setIdade(idade);
            agenda.insereCadastro(entrar);
            cout << endl << endl;
        }
        else if (confirmar == "2")
        {
            cout << endl;
            agenda.mostraCadrastro();
            cout << endl;
        }
        else if (confirmar == "3"){

            cout << "Deseja Sair? [S,s,Y,Y for yes/ outher for not]";
            cin >> confirmar;
            if
            (
                (confirmar == "S") or 
                (confirmar == "s") or 
                (confirmar == "Y") or 
                (confirmar == "y")
            )
            {
                sair = true;
            }
        }
        else {
            cout << endl << "Não entendi, por favor insira 1, 2 ou 3" << endl << endl;
        }
        


    }

    return 0;
}
