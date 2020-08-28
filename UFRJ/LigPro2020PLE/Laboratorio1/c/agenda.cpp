#include "agenda.h"

void 
agenda::setNames() {
    for (unsigned i = 0; i < TAMANHO_STRING; i++)
    {
        cout << "Digite o nome: ";
        cin >> names[i];
        if (names[i].length()>10)
        {
            cout << "Maior que 10, FOI TRUNCADO!" << endl;
            names[i]=names[i].substr(0,10);
        }
            
    }
}
void
agenda::getNames() {
    for (unsigned i = 0; i < TAMANHO_STRING; i++)
    {
        cout << names[i] << endl;
    }
}

