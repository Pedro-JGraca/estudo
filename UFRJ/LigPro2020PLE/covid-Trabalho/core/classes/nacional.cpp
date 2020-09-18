#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <algorithm>
#include <bits/stdc++.h>
#include <ctime>
#include <map>

#include "nacional.h"
#include "estadual.h"

using namespace std;

Nacional::Nacional(string nome,unsigned short N,vector<string> nomeEstado){

	ifstream file;
	nomePais=nome;
	
	time_t begin;
		
	file.open("dados/estados/DATE.txt");
  if (!file.is_open()){
	  cerr << "Unable to open DATE.txt" <<endl;
	  throw invalid_argument("O arquivo nao existe");
	}
	file >> begin;
	file.close();
 	


	startTime= begin;
	
	if (nomeEstado.size()==0){
		throw std::invalid_argument("lista de estados deve ser maior que 0");
	}

	for(string nomeEstadual : nomeEstado){
		estados.push_back(Estadual(nomeEstadual,nomeEstadual,N,startTime));
	}

	
	sortEstados();
}

vector <unsigned>
Nacional::acumulados(){
	
	unsigned stateDataSize;
	stateDataSize=estados[0].getDataSize();

	vector<unsigned> estadoAcumulado;	
	vector<unsigned> result(stateDataSize,0);

	for(Estadual estado : estados){
		if (estado.getDataSize()!=stateDataSize){
			throw std::out_of_range("Os Estados possuem listas incompativeis o tamanho nao bate");
		}

		//shallow copy
		//estadoAcumulado=estado.getAcumulados();
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

	vector<unsigned>somaNacional;
	somaNacional=somaMovel();
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

bool 
compareTendency(Estadual a, Estadual b){
	float t1,t2;
	t1=a.tendency();
	t2=b.tendency();
	return (t1 > t2);
}

void
Nacional::sortEstados(){	
	sort(estados.begin(),estados.end(),compareTendency);
}

float 
Nacional::tendency(){	
	vector <float> res;
	res=porcentagemMovel();
	return res.back();
}

void 
Nacional::showPorcentagemMovel(){
	vector<float> porcentagem;
	unsigned c;
	cout << "Porcentagem movel  " << nomePais << endl;
	porcentagem= porcentagemMovel();
	c=0;
	for (auto x : porcentagem){
		showTime(startTime+c*(60*60*24));
    cout <<setw(20) << x <<"|" << endl;
  	c++;
	}

 
}




string 
generateTendencyName(float tendencia){
	string res;
	if (tendencia>10.0){
		res="Subida";
	}
	else if (tendencia<10.0 && tendencia>-10.0){
		res="Estavel";
	}
	else{
		res="queda";
	}
	return res;
}

void 
Nacional::showEstadosTendency(){

	cout << "Tendencia dos estados " << nomePais << endl; 	
	for (auto x : estados){			
		cout <<"|" <<setw(20) << x.nomeEstado <<"|" << setw(20) << x.tendency() << "|" << setw(20) << generateTendencyName(x.tendency()) << "|" <<endl;	

	}

}

void
Nacional::showPaisTendency(){
	float tendencia;
	string res;
	tendencia=tendency();
	res=generateTendencyName(tendencia);

	cout<< "Tendencia do Pais" << endl;
	cout <<"|" <<setw(20) << nomePais <<"|" << setw(20) << tendency() << "|" << setw(20)<< res << "|"<<endl;	
}


void
Nacional::showExtremes(){

	Estadual *estado;
	float tendency;
	
	estado=&estados[0];
	tendency=estado->tendency();
	
	cout<< "Casos extremos: " << nomePais<< endl;
	cout <<"|" <<setw(20) << estado->nomeEstado <<"|" << setw(20) << tendency << "|" << setw(20)<< generateTendencyName(tendency) << "|" <<endl;	
	
	estado=&estados[estados.size()-1];
	tendency=estado->tendency();

	cout <<"|" <<setw(20) << estado->nomeEstado <<"|" << setw(20) << tendency << "|" << setw(20)<< generateTendencyName(tendency) << "|" <<endl;	
}

void
Nacional::showAcumulados(){
	vector<unsigned> acumulado;
	unsigned c;

	cout << "Obitos acumulados  " << nomePais << endl;
	acumulado=acumulados();
	
	c=0;
	for (auto x : acumulado){
		showTime(startTime+c*(60*60*24));
    cout <<setw(20) << x <<"|" << endl;
		c++;
  }
 

}

























