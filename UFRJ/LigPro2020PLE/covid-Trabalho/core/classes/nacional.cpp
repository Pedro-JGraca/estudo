#include <iostream>
#include <string>
#include <exception>
#include <algorithm>

#include "nacional.h"
#include "estadual.h"

using namespace std;

Nacional::Nacional(string nome,unsigned short N,vector<string> nomeEstado){

	nomePais=nome;
	if (nomeEstado.size()==0){
		throw std::invalid_argument("lista de estados deve ser maior que 0");
	}

	for(string nomeEstadual : nomeEstado){
		estados.push_back(Estadual(nomeEstadual,nomeEstadual,N));
	}

}

vector <unsigned>
Nacional::acumulados(){
	
	unsigned stateDataSize=estados[0].getDataSize();

	vector<unsigned> result(stateDataSize,0);
	vector<unsigned> estadoAcumulado;
	

	for(Estadual estado : estados){
		if (estado.getDataSize()!=stateDataSize){
			throw std::out_of_range("Os Estados possuem listas incompativeis o tamanho nao bate");
		}

		//shallow copy
		estadoAcumulado=estado.getAcumulados();
		for (int i=0;i<estadoAcumulado.size();i++){
			result[i]=result[i]+estadoAcumulado[i];
		}

	}

	return result;
}


vector <unsigned>
Nacional::somaMovel(){
	
	unsigned stateDataSize=estados[0].getDataSize();

	vector<unsigned> result(stateDataSize,0);
	vector<unsigned> estadoSomaMovel;

	for(Estadual estado : estados){
		if (estado.getDataSize()!=stateDataSize){
			throw std::out_of_range("Os Estados possuem listas incompativeis o tamanho nao bate");
		}

		//shallow copy by NRVO 
		estadoSomaMovel=estado.getSomaMovel(estado.getN());
		for (int i=0;i<stateDataSize;i++){
			result[i]=result[i]+estadoSomaMovel[i];
		}
	}

	return result;
}

vector <float>
Nacional::porcentagemMovel(){

	vector<unsigned>somaNacional = somaMovel();
	unsigned last;

	//initialize res vector w somaNacional size , avoid realloc
	vector<float> res(somaNacional.size(),0);
	
	last=0;
	for (unsigned i=0;i<somaNacional.size();i++){
		res[i]=computePercentage<float>((float)somaNacional[i],(float)last);
		last=somaNacional[i];
	}

	return res;
}





