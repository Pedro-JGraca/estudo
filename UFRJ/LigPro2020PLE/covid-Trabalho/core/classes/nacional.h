#ifndef NACIONAL_H
#define NACIONAL_H


#include <vector>
#include <string>
#include <ctime>
#include "estadual.h"

using namespace std;

string
generateTendencyName(float tendencia);

bool
compareTendency(Estadual a, Estadual b);

class Nacional
{
	private:
		string nomePais;
		
		time_t startTime;
		unsigned short N;
    
		vector <Estadual> estados;

		vector <string> ListaEstados;
		
		vector<unsigned>
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


		vector <string>
		getListaEstados();

		void
		showPorcentagemMovel();

		void
		showEstadosTendency();
		
		void
		showPaisTendency();

		void
		showExtremes();
	
		void
		showAcumulados();

};

#endif
