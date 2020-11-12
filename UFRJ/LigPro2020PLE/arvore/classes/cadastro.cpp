#include "cadastro.h"

cadastro::cadastro()
{
    erroBD = lerBD();
    if (erroBD != ok)
    {
        saida = iniciarBD();
    }
}
cadastro::~cadastro()
{
}

paciente *
cadastro::inserir(string Nome)
{
    paciente novo(Nome);

    if (!(arvore += &novo)){
        return NULL;
    }
    escreverBD(Nome);

    return arvore(&novo);
}

paciente *
cadastro::buscar(string Nome)
{
    paciente p(Nome);
    paciente *a = arvore(&p);
    return a;
    
}

void
cadastro::imprimir()
{
    cout << arvore;
}

tipoErro
cadastro::getErroBD()
{
    return erroBD;
}

tipoErro
cadastro::lerBD()
{

    string b;
    ifstream fin(ARQUIVO);
    if (fin)
    {
        while (fin >> b)
        {
            if (b != "\0")
            {
                paciente novo(b);
                arvore += &novo;
            }
        }
    }
    else
    {
        return bancoDeDadosNaoAchado;
    }

    return ok;
}
tipoErro
cadastro::escreverBD(string escrever)
{

    ofstream fin(ARQUIVO,ios_base::app);
    if (fin)
    {
        fin << escrever << endl;
    }
    else
    {
        return bancoDeDadosNaoAchado;
    }

    return ok;
}

string
cadastro::iniciarBD()
{
    string U = "Iremos criar o diretorio \"BD\" onde se encontrará o arquivo\nÉ nesse diretório onde está os dados os programa.\nSe mover o programa de lugar, lembre de mover o diretorio BD se desejar ter persistência\nRode o programa novamente que deverá funcionar do \"zero\"\n";
    system("mkdir BD");
    string comando = "touch ";
    comando += ARQUIVO;
    system(comando.c_str());
    return U;
}
