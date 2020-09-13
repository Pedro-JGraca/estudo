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

	for(Estadual estado : estados){
		if (estado.getDataSize()!=stateDataSize){
			throw std::out_of_range("Os Estados possuem listas incompativeis o tamanho nao bate");
		}

		//shallow copy
		//for (estado.getAcumulados().begin()
		//for(unsigned i : acumulados)
	}

	return result;

}





