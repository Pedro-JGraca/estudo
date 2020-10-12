#ifndef aresta_H
#define aresta_H

#include <iostream>
#include <vector>
using namespace std;

class aresta
{
private:
    string base;
    string ponta;
    unsigned short sit;

public:

    aresta(string, string);

    string
    getBase();
    string
    getPonta();

    unsigned
    getSit();
    
    void
    setSit(unsigned); //quantidade de vezes que essa aresta foi chamada

};



#endif