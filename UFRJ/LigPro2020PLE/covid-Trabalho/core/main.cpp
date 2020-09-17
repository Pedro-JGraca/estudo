#include <iostream>
#include "classes/estadual.h"
#include "classes/nacional.h"

using namespace std;


int main(int argc,char **argv,char **envp){

	vector <float> res;
	Estadual estado("Rio de janeiro","TESTE",3);

	//res=estado.porcentagemMovel(); tirar
	estado.porcentagemMovel(&res);

	for(float elt : res){
		cout << elt << endl;
	}

	Nacional pais("Brasil",3,{"TESTE","TESTE"});
	vector <float> res2;
	pais.porcentagemMovel(&res2);
	for(unsigned elt : res2){
		cout << elt << endl;
	}

}
