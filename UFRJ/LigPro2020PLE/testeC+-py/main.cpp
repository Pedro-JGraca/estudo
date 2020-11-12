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
		CPyObject pFunc = PyObject_GetAttrString(pModule, "create");//chama classe
		CPyObject elemento1 = PyLong_FromLong(10);
		CPyObject tupla = PyTuple_New((Py_ssize_t)1);
		PyTuple_SetItem(tupla,0,elemento1);
		CPyObject pObjeto = PyObject_CallObject(pFunc, tupla); //instancia objeto, a tupla insere os argumentos passados para a classe

		CPyObject pValue2 = PyObject_CallMethodObjArgs(pObjeto, PyUnicode_FromString("fazer"),PyLong_FromLong(10),NULL);//metodo

		cout << "C: getInteger() = " << PyLong_AsLong(pValue2) << endl ;

	}
	else
	{
		printf("ERROR: Modulo nao importado\n");
	}	
	CPyObject lista = PyList_New (10);
	

	PyTuple_ClearFreeList();
	return 0;
}