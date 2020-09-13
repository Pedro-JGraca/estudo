#include <iostream>
#include "classes/estadual.h"
#include "classes/nacional.h"

using namespace std;


int main(int argc,char **argv,char **envp){

	vector <float> res;
	Estadual estado("Rio de janeiro","TESTE",3);

	res=estado.porcentagemMovel();
	for(float elt : res){
		cout << elt << endl;
	}

	Nacional pais("Brasil",7,{"TESTE"});





	
}
