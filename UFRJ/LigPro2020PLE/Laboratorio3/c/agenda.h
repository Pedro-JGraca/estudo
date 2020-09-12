#include <string>
#include <array>

using namespace std;

class Cadastro
{
private:
    string nome;
    string profissao;
    unsigned short idade;

    string
    substr(string,unsigned);

public:
    //Cadastro(string,string,unsigned short);
    Cadastro();

    void
    setNome(string);

    void
    setProfissao(string);

    void
    setIdade(unsigned short);

    string
    getNome();

    string
    getProfissao();

    unsigned short
    getIdade();

};


class Agenda
{
private:
    static const unsigned maxNomes = 10;
    static unsigned numerosNomes;
    array <Cadastro, maxNomes> cadastro;

public:

    Agenda();

    void
    insereCadastro(Cadastro &);

    void
    mostraCadrastro();
};
