#ifndef NACIONAL_H
#define NACIONAL_H


#include <vector>
#include <string>
#include "estadual.h"

using namespace std;

bool
compareTendency(Estadual a, Estadual b);

class Nacional
{
	private:
		string nomePais;
		unsigned short N;
    
		vector <Estadual> estados;
		
    	vector <unsigned> 
		somaMovel();


	public:
  	Nacional(string nome,unsigned short N, vector<string> nomeEstado);

    vector <unsigned>
    acumulados();

    vector <float> 
		porcentagemMovel();

		void
		sortEstados();

		float
		tendency();

		vector <float>
		stateTendency();


};

#endif
