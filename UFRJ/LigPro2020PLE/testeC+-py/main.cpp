#include <iostream>
#include <stdio.h>
#include <python3.8/Python.h>
#include "pyhelper.hpp"

using namespace std;


int 
main(int argc, char const *argv[])
{
	CPyInstance hInstance;

	CPyObject pModule;	

	//String_FromPyUnicode


	if(CPyObject cNome= PyUnicode_FromString("fibonacci")){
		pModule = PyImport_Import(cNome);
	}
	else {
		cout << "nulo" << endl;
	}

	if(pModule)
	{
		CPyObject pFunc = PyObject_GetAttrString(pModule, "fibonacci");
		if(pFunc && PyCallable_Check(pFunc))
		{
			CPyObject pValue = PyObject_CallObject(pFunc, NULL);

			cout << "C: getInteger() = " << PyLong_AsLong(pValue) << endl ;
		}
		else
		{
			cout << "Erro: funcao()" << endl;
		}

	}
	else
	{
		printf("ERROR: Modulo nao importado\n");
	}

	return 0;
}