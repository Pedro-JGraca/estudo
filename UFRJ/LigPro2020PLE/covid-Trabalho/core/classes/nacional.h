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
		somaMovel2(vector <unsigned> *);


	public:

  		Nacional(string nome,unsigned short N, vector<string> nomeEstado);

		void
		acumulados2(vector <unsigned> *);

    	void
		porcentagemMovel2(vector <float> *);


		void
		sortEstados();

		float
		tendency();

		void
		stateTendency2(vector <float>*);

};

#endif
