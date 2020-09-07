#include <iostream>
#include "Paralelepipedo.h"

using namespace std;

int 
main(int argc, char const *argv[])
{
    int entrada;
    bool saida = false;
    Paralelepipedo rocha;
     
    while (!saida) 
    {
        cout << "entre com X: ";
        cin >> entrada;
        rocha.setX(entrada);
        cout << "entre com Y: ";
        cin >> entrada;
        rocha.setY(entrada);
        cout << "entre com Z: ";
        cin >> entrada;
        rocha.setZ(entrada);   

        cout << "Seu X ficou como: " << rocha.getX() << endl ;
        cout << "Seu Y ficou como: " << rocha.getY() << endl;
        cout << "Seu Z ficou como: " << rocha.getZ() << endl;
        cout << "Seu Volume ficou como: " << rocha.getVolume() << endl;


        string confirmar;
        cout << "Deseja sair? [S,s,Y,Y for yes/ outher for not]";
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

    return 0;
}