#ifndef MY_CLASSES_H
#define MY_CLASSES_H

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
		
		void 
		importarDados();
    
		
		/* data */
	public:
    Estadual(string estado,string file);
    
		vector <float>  
		mediaMovel(unsigned short);
    
		vector <float>  
		porcentagemMovel(unsigned short);
};

#endif
