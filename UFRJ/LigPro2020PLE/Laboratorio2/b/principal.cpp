#include <iostream>
#include "algebraLinear.h"

using namespace std;

int 
main(int argc, char const *argv[])
{
    Ponto Um,Dois;
    int entrada;
    bool saida = false;

    string confirmar;
    while (!saida) 
    {
        cout << "entre com X do Primeiro Ponto: ";
        cin >> entrada;
        Um.setX(entrada);
        cout << "entre com Y do Primeiro Ponto: ";
        cin >> entrada;
        Um.setY(entrada);
        cout << "entre com Z do Primeiro Ponto: ";
        cin >> entrada;
        Um.setZ(entrada); 

        cout << "entre com X do Segundo Ponto: ";
        cin >> entrada;
        Dois.setX(entrada);
        cout << "entre com Y do Segundo Ponto: ";
        cin >> entrada;
        Dois.setY(entrada);
        cout << "entre com Z do Segundo Ponto: ";
        cin >> entrada;
        Dois.setZ(entrada);
        
        Um.printCoordenadas();
        Dois.printCoordenadas();

        cout << "Tudo certo? [S,s,Y,Y for yes/ outher for not]";
        cin >> confirmar;
        if
        (
            (confirmar == "S") or 
            (confirmar == "s") or 
            (confirmar == "Y") or 
            (confirmar == "y")
        )
        {
            saida = true;
        }
    }
    
    Linha segmento(Um,Dois);


    cout << "Distancia: " << segmento.getComprimento() << endl;
    Um.printCoordenadas();
    Dois.printCoordenadas();
    return 0;
}