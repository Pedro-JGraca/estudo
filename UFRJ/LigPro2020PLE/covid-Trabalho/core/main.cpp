#include <iostream>
#include "classes/classes.h"

using namespace std;


int main(int argc,char **argv,char **envp){

	vector <float> res;
	Estadual estado("Rio de janeiro","TESTE");

	res=estado.porcentagemMovel(100);
	for(float elt : res){
		cout << elt << endl;
	}





	
}
