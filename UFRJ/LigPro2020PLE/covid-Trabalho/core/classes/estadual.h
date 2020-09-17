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
		
		Estadual(string estado,string file, unsigned short);
		
		string nomeEstado;

/*		vector <unsigned> 
		getSomaMovel(unsigned short );//tirar
*/
		void
		getSomaMovel2(unsigned short, vector <unsigned>*);
/*
		vector <unsigned> //aguenta ate 4Bi, vamos ser positivos : D 
		getAcumulados(); //tirar*/

		void
		getAcumulados2(vector <unsigned>*);
/*
		vector <float>  
		porcentagemMovel();//tirar*/

		void
		porcentagemMovel2(vector <float> *);


		//get percentage changed on the last day
		float 
		tendency();

		unsigned 
		getDataSize();

		unsigned short
		getN();


};

#endif
