#include <iostream>
#include "agenda.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Agenda agenda(3);
    bool sair = false;
    string confirmar;

    while(!sair){
        cout << "1.Inserir Nome" << "   " << "2.Listar Agenda" << "   " << "3.Sair" <<endl;
        cin >> confirmar;
        if (confirmar == "1"){
            cout << endl<< "Nome:";
            cin >> confirmar;
            cout << endl;
            agenda.insereNomes(confirmar);
        }
        else if (confirmar == "2")
        {
            cout << endl;
            agenda.mostraNomes();
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
