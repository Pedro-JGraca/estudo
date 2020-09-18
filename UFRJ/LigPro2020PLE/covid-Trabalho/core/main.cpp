#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include "classes/estadual.h"
#include "classes/nacional.h"

using namespace std;

#define OK 0
#define ERROR -1

void showHelp(){
	cout << "formato: ./analiseCovid <comando> [estado] [-n=tamanho (padrao: 7)]" << endl;
	cout << "Comandos:" << endl;
	cout <<"[help]                      -> Dá uma orientação genérica ou orientada do uso do programa."<< endl 
	<<"[porcentagemEstado]           -> Faz a série histórica da porcentagem em relação ao valor de obitos anterior do estado pedido."<<endl
	<<"[porcentagemNacao]            -> Faz a série histórica da porcentagem em relação ao valor de obitos anterior do país."<<endl
	<<"[categoriaEstado]             -> Informa uma lista de estados para cada situação: queda, estavel ou crescente."<<endl
	<<"[categoriaNacao]              -> Diz se o país está em queda, estável em crescente."<<endl
	<<"[extremos]                     -> Diz o estado que está com maior crescente e maior queda"<< endl
	<<"[acumuladoEstado]            -> Faz a série histórica dos valor acumulados do estado pedido."<<endl
	<<"[acumuladoNacao]             -> Faz a série histórica dos valor acumulados da nação." <<endl;
	exit(OK);
	
}

string getEstado(int argc , char **argv){
	if (argc<=2){
		cerr << "E necessario passar o nome do estado"<< endl;
		exit(ERROR);
	}
	else{
		return string(argv[2]);
	}
}

int main(int argc,char **argv,char **envp){
	
	int n_option=7;
	vector<string> states={"AC","AL","AM","AP","BA","CE","DA","DF","ES","GO","MA","MG","MS","MT","PA","PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP"};
	

	string parameter;
	for (int i=0;i<argc;i++){	
		parameter=argv[i];	
		if (parameter=="help"){
			showHelp();
		}
		if (parameter.substr(0,3)=="-n="){
			n_option=stoi(parameter.substr(3));
			if (n_option<=0){
				cerr<< "O valor de N deve ser positivo" << endl;
				exit(ERROR);
			}
		}
	}

	cout << "Usando N=" << n_option << endl;
	
	Nacional brasil("Brasil",n_option,states);

	if (argc<=1){
		cerr << "Quantidade de Argumentos invalida" << endl;
		showHelp();
	}
	
	parameter=argv[1];
	if (parameter=="porcentagemEstado"){
		string estado=getEstado(argc,argv);
		brasil.getEstadoByName(estado).showPorcentagem();
	}
	else if(parameter=="porcentagemNacao"){
		brasil.showPorcentagemMovel();
	}
	else if(parameter=="categoriaEstado"){
		brasil.showEstadosTendency();
	}
	else if(parameter=="categoriaNacao"){
		brasil.showPaisTendency();
	}
	else if(parameter=="extremos"){
		brasil.showExtremes();
	}
	else if(parameter=="acumuladoEstado"){
		string estado=getEstado(argc,argv);
		brasil.getEstadoByName(estado).showAcumulados();
	}
	else if(parameter=="acumuladoNacao"){
		brasil.showAcumulados();
	}
	else{
		cout << "Comando Invalido." << endl;
		showHelp();
	}

}



	
