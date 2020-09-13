#ifndef ESTADUAL_H
#define ESTADUAL_H

#include <vector>
#include <string>
using namespace std;

template <class T>
T computePercentage(T a,T b);


class Estadual
{
	private:
		unsigned short N;
		
		string fileName;
		string initDate;
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
		string nomeEstado;
		Estadual(string estado,string file, unsigned short);

		vector <unsigned> 
		getSomaMovel(unsigned short);

		vector <unsigned> //aguenta ate 4Bi, vamos ser positivos : D 
		getAcumulados();

		vector <float>  
		porcentagemMovel();

		float 
		tendency();

		unsigned getDataSize();


};

#endif
