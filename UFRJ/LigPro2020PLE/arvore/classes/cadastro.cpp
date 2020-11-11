#include "cadastro.h"
#include "arvore.h"
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

    

    /*if (buscar(Nome))
    {
        return NULL;
    }
    arvore2.push_back(novo);
    */


    if (!(arvore += &novo)){
        return NULL;
    }
    escreverBD(Nome);



    //return &arvore2.back();
    return arvore(&novo);
}

paciente *
cadastro::buscar(string Nome)
{
    /*for (unsigned index = 0; index < arvore2.size(); index++)
    {
        if (arvore2[index].getNome() == Nome)
        {
            return &arvore2[index];
        }
    }*/

            
    paciente p(Nome);
    paciente *a = arvore(&p);
    return a;
    

    //return NULL;
}

void
cadastro::imprimir()
{
    /*for (unsigned index = 0; index < arvore2.size(); index++)
    {
        cout << arvore2[index];
    }*/
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
                //arvore2.push_back(novo);
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
        /*for (unsigned index = 0; index < arvore2.size(); index++)
        {
            //ANTES ELE ESCREVIA NO FINAL TODA A ESTRUTURA
            //AGORA ELE ESCREVE SEMPRE QUE RECEBE UMA LINHA NOVA
            //ASSIM ELE MANTEM A MESMA ESTRUTURA NA INSERÇÃO
            string saida = arvore2[index].getNome() + "\n";
            fin << saida;
        }*/

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
