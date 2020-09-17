#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <bits/stdc++.h>

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

/*vector <unsigned>
Nacional::acumulados(){
	
	unsigned stateDataSize=estados[0].getDataSize();

	vector<unsigned> result(stateDataSize,0);
	vector<unsigned> estadoAcumulado;
	

	for(Estadual estado : estados){
		if (estado.getDataSize()!=stateDataSize){
			throw std::out_of_range("Os Estados possuem listas incompativeis o tamanho nao bate");
		}

		//shallow copy
		//estadoAcumulado=estado.getAcumulados();
		estado.getAcumulados2(&estadoAcumulado);

		for (int i=0;i<estadoAcumulado.size();i++){
			result[i]=result[i]+estadoAcumulado[i];
		}

	}

	return result;
}*/

void
Nacional::acumulados2(vector <unsigned> *ptr){
	
	unsigned stateDataSize=estados[0].getDataSize();

	vector<unsigned> result(stateDataSize,0);
	vector<unsigned> estadoAcumulado;
	

	for(Estadual estado : estados){
		if (estado.getDataSize()!=stateDataSize){
			throw std::out_of_range("Os Estados possuem listas incompativeis o tamanho nao bate");
		}

		//shallow copy
		//estadoAcumulado=estado.getAcumulados();
		estado.getAcumulados2(&estadoAcumulado);

		for (int i=0;i<estadoAcumulado.size();i++){
			result[i]=result[i]+estadoAcumulado[i];
		}

	}

	*ptr= result;
}


/*
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

		//estadoSomaMovel=estado.getSomaMovel(estado.getN());
		estado.getSomaMovel2(estado.getN(),&estadoSomaMovel);

		for (int i=0;i<stateDataSize;i++){
			result[i]=result[i]+estadoSomaMovel[i];
		}
	}

	return result;
}*/


void
Nacional::somaMovel2(vector <unsigned> *ptr){
	
	unsigned stateDataSize=estados[0].getDataSize();

	vector<unsigned> result(stateDataSize,0);
	vector<unsigned> estadoSomaMovel;

	for(Estadual estado : estados){
		if (estado.getDataSize()!=stateDataSize){
			throw std::out_of_range("Os Estados possuem listas incompativeis o tamanho nao bate");
		}

		//shallow copy by NRVO

		//estadoSomaMovel=estado.getSomaMovel(estado.getN());
		estado.getSomaMovel2(estado.getN(),&estadoSomaMovel);

		for (int i=0;i<stateDataSize;i++){
			result[i]=result[i]+estadoSomaMovel[i];
		}
	}

	*ptr= result;
}





/*vector <float>
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
}*/

void
Nacional::porcentagemMovel2(vector <float>* ptr){

	vector<unsigned>somaNacional;
	somaMovel2(&somaNacional);
	unsigned last;

	//initialize res vector w somaNacional size , avoid realloc
	vector<float> res(somaNacional.size(),0);
	
	last=0;
	for (unsigned i=0;i<somaNacional.size();i++){
		res[i]=computePercentage<float>((float)somaNacional[i],(float)last);
		last=somaNacional[i];
	}

	*ptr= res;
}

bool 
compareTendency(Estadual a, Estadual b){
	float t1,t2;
	t1=a.tendency();
	t2=b.tendency();
	return (t1 < t2);
}

void
Nacional::sortEstados(){	
	sort(estados.begin(),estados.end(),compareTendency);
}

float 
Nacional::tendency(){	
	vector <float> res;
	porcentagemMovel2(&res);
	return res.back();
}
/*
vector <float> 
Nacional::stateTendency(){
	sortEstados();

	vector<float> res;
		
	for (auto x: estados){
		res.push_back(x.tendency());
	}

	return res;
}*/

void
Nacional::stateTendency2(vector <float> *ptr){
	sortEstados();

	vector<float> res;
		
	for (auto x: estados){
		res.push_back(x.tendency());
	}

	*ptr= res;
}







