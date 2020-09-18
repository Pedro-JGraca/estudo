#ifndef ESTADUAL_H
#define ESTADUAL_H

#include <vector>
#include <string>
#include <ctime>

using namespace std;

template <class T>
T computePercentage(T a,T b);

void showTime(time_t t);

class Estadual
{
	private:
		unsigned short N;
		time_t startTime;
		string fileName;
		unsigned dataSize;
		
		//caching: assuming memory is cheap but cpu isnt
		vector <unsigned> dadosLidos;
		vector <unsigned> somaMovel;
		vector <unsigned> acumulado;

		vector <unsigned>
		computeSomaMovel(unsigned short);
		
		unsigned 
		importarDados();

		float
		percentageAtDay(unsigned day);
		
	public:
		
		Estadual(string estado,string file, unsigned short,time_t);
		
		string nomeEstado;

		vector <unsigned>
		getSomaMovel(unsigned short);


		vector <unsigned>
		getAcumulados();


		vector <float>
		porcentagemMovel();

		void
		showPorcentagem();
		
		void
		showTendency();
	
		void 
		showAcumulados();

		//get percentage changed on the last day
		float 
		tendency();

		unsigned 
		getDataSize();

		unsigned short
		getN();


};

#endif
