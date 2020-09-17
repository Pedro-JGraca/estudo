#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

#include "estadual.h"

using namespace std;

template <class T> 
T computePercentage(T a,T b){
		T res;
		if (b==0){
			//pq nao tem divisao por zero
			res=std::numeric_limits<T>::infinity();
		}
		else{
			res=((a-b)/b)*100;
		}
		return res;
}

Estadual::Estadual(string estado,string file, unsigned short n) {
	
	N=n;
	nomeEstado=estado;
	fileName=file;
	dataSize=importarDados();
	
}

unsigned Estadual::importarDados()
{
	ifstream file;
	unsigned line;
	
	string path="dados/estados/"+fileName+".txt";
	file.open(path);

	if (!file.is_open()){
		cerr << "Unable to open " << path <<endl;
		return 0;
	}
	else{
		file >> initDate;	
		while(file >> line){
			dadosLidos.push_back(line);
		}
	}
	file.close();
	
	return dadosLidos.size();

}


float Estadual::percentageAtDay(unsigned day){
		
	vector <unsigned> soma;
	getSomaMovel2(N,&soma);
	float dayAvg,lastAvg;

	
	if (day==0){
		lastAvg=0;
	}
	else{
		lastAvg=((float)soma[day-1])/N;
	}
	dayAvg=((float)soma[day])/N;

	return computePercentage<float>(dayAvg,lastAvg);
}
/*
//not cached cost M
vector <float> Estadual::porcentagemMovel()
{

	//dont waste time calling realloc, total size is already known
	vector <float> porcentagemMovel(dataSize,0);
	if (N>dataSize){
		cerr<< "Atencao, Maximo o total da amostra eh " << dataSize << endl;
	}
	
	for (int i=0;i<dataSize;i++){
		porcentagemMovel[i]=percentageAtDay(i);
	}

	return porcentagemMovel;
}
*/

void
Estadual::porcentagemMovel2(vector <float> *ptr)
{

	//dont waste time calling realloc, total size is already known
	vector <float> porcentagemMovel(dataSize,0);
	if (N>dataSize){
		cerr<< "Atencao, Maximo o total da amostra eh " << dataSize << endl;
	}
	
	for (int i=0;i<dataSize;i++){
		porcentagemMovel[i]=percentageAtDay(i);
	}

	*ptr= porcentagemMovel;
}




vector <unsigned> 
Estadual::computeSomaMovel(unsigned short n){
  
	vector <unsigned> somados;
  unsigned hoje;
	unsigned somado;
  // complexidade M 
	// M = Numero de dias N = janela

	//inicializa o dia anterior
	somados.push_back(dadosLidos[0]);
	for (hoje=1; hoje<dadosLidos.size();hoje++){

			//construir ate N
			if(hoje<N){
       	somado=somados[hoje-1]+dadosLidos[hoje];
			}
			else{
       	somado=somados[hoje-1]+dadosLidos[hoje]-dadosLidos[hoje-(N)];
   		}
			somados.push_back(somado);
	}
  return somados;
}
/*
vector <unsigned>
Estadual::getSomaMovel(unsigned short n=0){
	
	//check if its default
	if (n==0){
		n==N;
	}
	
	//caching default N responses
	if (somaMovel.size()==0 && n==N){
		somaMovel=computeSomaMovel(N);
		return somaMovel;
	}
	else if(n==N){
		return somaMovel;
	}
	else{
		return computeSomaMovel(n);
	}

}//tirar
*/
void
Estadual::getSomaMovel2(unsigned short n, vector <unsigned> *local){
	

	vector <unsigned>*ptr = local;
	
	//check if its default
	if (n==0){
		n==N;
	}

	//caching default N responses

	if (somaMovel.size()==0 && n==N){
		somaMovel=computeSomaMovel(N);
	}
	else if(n==N){
		;
	}
	else{
		somaMovel=computeSomaMovel(n);
	}

	*ptr = somaMovel;

}

float
Estadual::tendency(){
	return percentageAtDay(dataSize);
}

unsigned 
Estadual::getDataSize()
{	
	return dataSize;
}
unsigned short 
Estadual::getN(){
	return N;
}

/*vector <unsigned>
Estadual::getAcumulados(){

	//caching: after first calling solves with cost 1
  if (acumulado.size()==0){
		acumulado=computeSomaMovel(dataSize);
	}
	return acumulado;
}//tirar
*/

void
Estadual::getAcumulados2(vector <unsigned> * local){

	vector <unsigned> * ptr = local;

	//caching: after first calling solves with cost 1
  if (acumulado.size()==0){
		acumulado=computeSomaMovel(dataSize);
	}
	*ptr= acumulado;
}






