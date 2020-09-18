#include <iostream>
#include "classes/estadual.h"
#include "classes/nacional.h"

using namespace std;


int main(int argc,char **argv,char **envp){

	//vector <float> res;
	//Estadual estado("Rio de janeiro","TESTE",3);
	//estado.showPorcentagem();
	//estado.showTendency();
	//estado.showAcumulados();
	Nacional brasil("Brasil",3,{"TESTE", "TESTE2"});
	brasil.showPorcentagemMovel();
	brasil.showEstadosTendency();
	brasil.showPaisTendency();
	brasil.showExtremes();
	brasil.showAcumulados();

	//res=estado.porcentagemMovel(); tirar

	//estado.porcentagemMovel(&res);


}
