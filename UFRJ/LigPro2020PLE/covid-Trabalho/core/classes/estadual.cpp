#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

#include "estadual.h"

using namespace std;


Estadual::Estadual(string estado,string file, unsigned n) {
	nomeEstado=estado;
	fileName=file;
	importarDados();
	medias = porcentagemMovel(n);
	
}

void Estadual::importarDados()
{
	ifstream file;
	unsigned line;
	
	string path="dados/estados/"+fileName+".txt";
	file.open(path);

	if (!file.is_open()){
		cerr << "Unable to open " << path <<endl;
	}
	else{
		file >> initDate;	
		while(file >> line){
			dadosLidos.push_back(line);
		}
	}
	file.close();

}


template <class T> 
T computePercentage(T a,T b){
		T res;
		if (b==0){//pq nao tem divisao por zero
			res=std::numeric_limits<T>::infinity();
		}
		else{
			res=((a-b)/b)*100;
		}
		return res;
}


vector <float> Estadual::porcentagemMovel(unsigned short N=3)
{
	vector <float> porcentagemMovel;
	float last,temp;

	if (N>dadosLidos.size()){
		cerr<< "Atencao, Maximo o total da amostra eh " << dadosLidos.size() << endl;
	}
	
	porcentagemMovel=mediaMovel(N);

	//raise from 0
	last=0;
	for (int i=0;i<porcentagemMovel.size();i++){
		temp=porcentagemMovel[i];
		porcentagemMovel[i]=computePercentage<float>(porcentagemMovel[i],last);
		last=temp;
	}

	return porcentagemMovel;
}
//let mediaMovel as a separadted method for reuse in Nacional class
vector <float> Estadual::mediaMovel(unsigned short N=3){
    
		vector <float> medias;
		vector <unsigned long> somados;
		somados = somaMovel(N);

		for (int i=0;i<somados.size();i++){
				medias.push_back(((float)somados[i])/3.0);
		}	
    return medias;
}

vector <unsigned long> 
Estadual::somaMovel(unsigned short N=3){
    
		vector <unsigned long> somados;
    	unsigned hoje;
		unsigned somado;
    	// complexidade M 
		// M = Numero de dias N = janela

		//inicializa o dia anterior
    somados.push_back((float)dadosLidos[0]);
    
		for (hoje=1; hoje<dadosLidos.size();hoje++){

				//construir ate N
				if(hoje<N){
        	somado=somados[hoje-1]+dadosLidos[hoje];
				}
				else{
        	somado=somados[hoje-1]+dadosLidos[hoje]-dadosLidos[hoje-(N)];
    		}
				somados.push_back((float)somado);
		}
    return somados;
}


vector <unsigned long>
Estadual::acumulados(){
	return somaMovel(dadosLidos.size());
}

