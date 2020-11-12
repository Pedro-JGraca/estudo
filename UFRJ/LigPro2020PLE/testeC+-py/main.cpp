#include <iostream>
#include <stdio.h>
#include <python3.8/Python.h>
#include "pyhelper.hpp"

using namespace std;


int 
main(int argc, char const *argv[])
{
	CPyInstance hInstance;

	CPyObject pModule =  PyImport_Import(PyUnicode_FromString("fibonacci"));//arquivo.py

	if(pModule)
	{
		CPyObject elemento1 = PyLong_FromLong(10);

		CPyObject tupla = PyTuple_New((Py_ssize_t)1);
		PyTuple_SetItem(tupla,0,elemento1); // insere elemento1 na posição 0

		CPyObject classe=  PyObject_GetAttrString(pModule, "create");
		CPyObject pObjeto = PyObject_CallObject(classe, NULL);//classe
		
		
		
		CPyObject metodo = PyObject_CallMethod(pObjeto,"fazer", NULL);

		CPyObject n2 = PyUnicode_FromString("100000");
		
		CPyObject pValue = PyObject_CallMethodObjArgs(pObjeto, metodo, tupla);//metodo
		
		
		cout << "C: getInteger() = " << PyLong_AsLong(pValue) << endl ;
	}
	else
	{
		printf("ERROR: Modulo nao importado\n");
	}	
	
	PyTuple_ClearFreeList();
	return 0;
}