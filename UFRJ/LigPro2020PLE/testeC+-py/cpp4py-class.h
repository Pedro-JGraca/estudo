#include <iostream>
#include <stdio.h>
#include <vector>
#include <python3.8/Python.h>
#include "pyhelper.hpp"

using namespace std;

	//ModuloPythonParaC++("CAMINHO/arquivo.py","funcao", "numero de argumentos","vetor de argumentos")

class cpp4pyClass
{
private:
    string path;
    string funcao;
    unsigned numeroArgumentos;
    vector <string> argumentos; 
public:
    cpp4pyClass(/* args */);
    ~cpp4pyClass();
    
    void
    setPath(string);

    
    
};
