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
		
		void
		somaMovel(vector <unsigned> *);


	public:

  		Nacional(string nome,unsigned short N, vector<string> nomeEstado);

		void
		acumulados(vector <unsigned> *);

    	void
		porcentagemMovel(vector <float> *);


		void
		sortEstados();

		float
		tendency();

		void
		stateTendency(vector <float>*);

};

#endif
