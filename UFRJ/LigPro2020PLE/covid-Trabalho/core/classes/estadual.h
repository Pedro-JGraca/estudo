#ifndef ESTADUAL_H
#define ESTADUAL_H

#include <vector>
#include <string>
using namespace std;

class Estadual
{
	private:
		string nomeEstado;
		string fileName;
		string initDate;
		vector <unsigned>  dadosLidos;
		vector <float> medias;
		
		void 
		importarDados();
		
		/* data */
		Estadual(string estado,string file, unsigned n);
    
		vector <float>  
		mediaMovel(unsigned short);
    
		vector <float>  
		porcentagemMovel(unsigned short);

		vector <unsigned long> //10 bilhao da quanto?
		acumulados();

		vector <unsigned long> 
		somaMovel(unsigned short);
		
	public:




};

#endif
