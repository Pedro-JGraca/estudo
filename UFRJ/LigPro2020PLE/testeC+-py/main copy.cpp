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
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append(\".\")");

	if(CPyObject cNome= PyUnicode_FromString("fibonacci")){
		pModule = PyImport_Import(cNome);
	}
	else {
		cout << "nulo" << endl;
	}

	//ModuloPythonParaC++("CAMINHO/arquivo.py","funcao", "numero de argumentos","vetor de argumentos")

    CPyObject elemento1 = PyLong_FromLong(10);
	CPyObject elemento2 =  PyUnicode_FromString("1000000");
	CPyObject tupla = PyTuple_New((Py_ssize_t)2);
	PyTuple_SetItem(tupla,0,elemento1); // insere elemento1 na posição 0
	PyTuple_SetItem(tupla,1,elemento2); // insere elemento2 na posição 1

	if(pModule)
	{
		CPyObject pFunc = PyObject_GetAttrString(pModule, "fibonacci");
		if(pFunc && PyCallable_Check(pFunc))
		{
			CPyObject pValue = PyObject_CallObject(pFunc, tupla);

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
 	//PyObject* PyObject_CallMethodObjArgs(PyObject *o, PyObject *name, ..., NULL)¶
	
	PyTuple_ClearFreeList();
	return 0;
}