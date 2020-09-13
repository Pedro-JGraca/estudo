#ifndef NACIONAL_H
#define NACIONAL_H


#include <vector>
#include <string>
#include "estadual.h"

using namespace std;

class Nacional
{
	private:
		string nomePais;
		unsigned short N;
    
		vector <Estadual> estados;
		

	public:
  	Nacional(string nome,unsigned short N, vector<string> nomeEstado);

    vector <unsigned>
    acumulados();

    vector <unsigned> 
		somaMovel();

    vector <float> 
		porcentagemMovel();

		//vector <Estadual>


};

#endif
