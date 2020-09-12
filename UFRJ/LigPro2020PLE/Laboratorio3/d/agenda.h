#include <string>
#include <vector>

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
    unsigned maxNomes;
    vector <Cadastro> cadastro;
    
public:

    Agenda(unsigned short);

    void
    insereCadastro(Cadastro &);

    void
    mostraCadrastro();
};
