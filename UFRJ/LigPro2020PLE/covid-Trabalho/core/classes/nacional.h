#ifndef NACIONAL_H
#define NACIONAL_H


#include <vector>
#include "estadual.h"

using namespace std;

class Nacional
{
private:
    string nome;
    
    vector <Estadual> Estados;
public:
    Nacional(string, ...);

    vector <unsigned long> //10 bilhao da quanto
    acumulados();

    vector <float>  
    mediaMovel(unsigned short);

    vector <unsigned long> 
	somaMovel(unsigned short);
};

#endif