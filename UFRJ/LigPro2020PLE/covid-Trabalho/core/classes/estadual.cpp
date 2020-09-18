#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <ctime>
#include <iomanip>
#include <string>

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

Estadual::Estadual(string estado,string file, unsigned short n, time_t t) {
	
	N=n;
	nomeEstado=estado;
	fileName=file;
	dataSize=importarDados();
	startTime=t;
}

unsigned Estadual::importarDados()
{
	ifstream file;
	unsigned line;
	string initDate;
	string path="dados/estados/"+fileName+".txt";
	file.open(path);

	if (!file.is_open()){
		cerr << "Unable to open " << path <<endl;
		throw invalid_argument("O arquivo nao existe");
	}
	else{
		while(file >> line){
			dadosLidos.push_back(line);
		}
	}
	file.close();
	
	return dadosLidos.size();

}


float Estadual::percentageAtDay(unsigned day){
		
	vector <unsigned> soma;
	soma=getSomaMovel(N);
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

//not cached cost M
vector <float>
Estadual::porcentagemMovel()
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


}

float
Estadual::tendency(){
	return percentageAtDay(dataSize-1);
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

vector <unsigned>
Estadual::getAcumulados(){

	//caching: after first calling solves with cost 1
	if (acumulado.size()==0){
	  //computeSomaMovel(dataSize); tirar
	  acumulado=computeSomaMovel(dataSize);
	}
	return acumulado;
}


void showTime(time_t t){
	tm *date=gmtime(&t);

	string date_str;
	if (!date){
		throw std::invalid_argument( "received invalid ptr");
	}
	date_str= to_string(date->tm_mday) + "/" + to_string(date->tm_mon+1) + "/" + to_string(date->tm_year+1900);

	cout <<"|"<< left << setfill(' ') << setw(20) << date_str <<"|"; 
}

void
Estadual::showPorcentagem(){
	vector<float>	porcentagem;
	unsigned c;

	cout << "Porcentagem movel  " << nomeEstado << endl;
	porcentagem= porcentagemMovel();


	c=0;
	for (auto x : porcentagem){
		showTime(startTime+c*(60*60*24));
		cout <<setw(20) << x <<"|" << endl;
		c++;
	}

}

void Estadual::showTendency(){
	cout << "Tendencia " << nomeEstado << endl;
	cout << setprecision(5) << tendency() << "%"<< endl;

}

void Estadual::showAcumulados(){
	unsigned c;
	vector<unsigned>	acumulados;

	cout << "obitos Acumulados  " << nomeEstado << endl;
	acumulados= getAcumulados();
	
	c=0;
	for (auto x : acumulados){
		showTime(startTime+c*(60*60*24));
		cout <<setw(20) << x <<"|" << endl;
		c++;
	}


}



















