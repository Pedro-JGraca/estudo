#include "proxyCatalogo.h"

string 
proxyCatalogo::help(string argv,string comando){

    if (comando.size()==0){

        string saida = "Este programa é um gerenciador de filmes para um catálogo via CLI.\n";
        saida+="Seu funcionamento básico está ligado a comandos.\n";
        saida+="Uso:\n\n";
        saida+="$" + argv + " [comando] [argumento1] ... [argumentoN]\n\n";
        saida+="Onde N é a quantidade de argumentos que o comando precisa, podendo ir de 0 a 4\n";
        saida+="Abaixo está a lista de comandos existentes, bem como uma explicação de cada uma.\n";
        saida+="Se desejar entender como usar o comando escreva na linha de comando:\n\n";
        saida+="$./catalogo help [argumento]\n\n";
        saida+="Onde o argumento do comando acima é um dos comandos.\n\n";

        saida+="help\t\t\t\t\tDescreve o programa como um todo ou apenas um comando.\n";
        saida+="listarCatalogo\t\t\t\tLista todos os filmes com seus detalhes.\n";
        saida+="listarFilmes\t\t\t\tLista o nome de todos os filmes\n";
        saida+="melhorFilme\t\t\t\tInforma qual filme tem a maior nota\n";
        saida+="removerFilme\t\t\t\tRemove um filme informado\n";
        saida+="buscarFilme\t\t\t\tBusca o filme e diz se achou ou não. Se achar ele printa os detalhes.\n";
        saida+="listarFilme\t\t\t\tRetorna os dados de um filme específico\n";
        saida+="inserirFilme\t\t\t\tInsere um filme novo no catálogo\n";
        saida+="editarFilme\t\t\t\tBusca um Filme e edita ele se for possível, se não encontrar, ele informa.\n";
     
       return saida;
    }

    if (comando == comandos[0]){//"help"
        string saida ="Descreve o programa como um todo ou apenas um comando.\n";
        saida+="Se for para descreve o programa todo:\n";
        saida+="Uso: \n\n";
        saida+="$" + argv + " help \n\n";
        saida+="Se for para descrever um comando:\n";
        saida+="$" + argv + " help [comando] \n\n";

        return saida;
    }
    else if (comando  == comandos[1]){//ListarCatalogo
        string saida ="Lista todos os filmes com seus detalhes.";
        saida+="\nUso: \n\n";
        saida+="$" + argv + "ListarCatalogo\n\n";
        return saida;
    }
    else if (comando  == comandos[2]){//ListarFilmes
        string saida ="Lista o nome de todos os filmes";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " listarFilmes\n\n";
        return saida;        
    }
    else if (comando  == comandos[3]){//melhorFilme
        string saida ="Informa qual filme tem a maior nota";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " melhorFilme\n\n";
        return saida;        
    }
    else if (comando  == comandos[5]){//removerFilme
        string saida ="Remove um filme informado";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " removerFilme [FILME]\n\n";
        return saida; 
    }
    else if (comando  == comandos[6]){//"buscarFilme"
        string saida ="Busca o filme e diz se achou ou não. Se achar ele printa os detalhes.";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " buscarFilme [FILME]\n\n";
        return saida; 
    }
    else if (comando  == comandos[7]){//ListarFilme
        string saida ="Retorna os dados de um filme específico";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " listarFilme [FILME]\n\n";
        return saida; 
    }
    else if (comando  == comandos[8]){//InserirFilme
        string saida ="Insere um filme novo no catálogo";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " inserirFilme [FILME] [PRODUTORA] [NOTA]\n\n";
        return saida; 
    }
    else if (comando  == comandos[9]){//EditarFilme
        string saida ="Busca um Filme e edita ele se for possível, se não encontrar, ele informa.";
        saida+="\nUso: \n\n";
        saida+="$" + argv + " editarFilme [FILME] [PRODUTORA] [NOTA]\n\n";
        return saida; 
    }

    return "Erro.";
}

void
proxyCatalogo::listarCatalogo(){
    cout << Catalogo.getLista() << endl;
}

string
proxyCatalogo::inserirFilme(string Filme, string Produtora, string Nota){
    filme novo;
    novo.nome = Filme;
    novo.produtora = Produtora;
    //converter int(Nota)
    novo.nota = 0;

    Catalogo+=novo;
    Catalogo+=novo;


    listarCatalogo();

    return "foi";
}