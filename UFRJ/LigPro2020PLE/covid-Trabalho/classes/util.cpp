#include "util.h"


util::util()
{
}

void
util::showInicial () {
    cout << 
    "formato padrão: ./analiseCovid <comando> [estado] [N=base-para-media-movel (padrao: 3)]" << endl <<
    "Comandos:" << endl <<
    "[help]                       -> Dá uma orientacao do uso dos comandos" << endl <<
    "[mediaMovelEstado]           -> Plota a tabela da série histórica da media movel de N dias do numero de mortos do estado pedido." << endl <<
    "[mediaMovelNacao]            -> Ploca o mesmo que a tabela acima, só que do país." << endl <<
    "[categoriaEstado]            -> Para cada situação(crescente, estabilidade, queda), plota uma lista dos estados" << endl <<
    "[categoriaNacao]             -> Informa se o país está em queda, estável em crescente." << endl <<
    "[extremos]                   -> Informa o estado que está com maior crescente e maior queda" << endl <<
    "[acumuladoEstado]            -> Faz a série histórica dos valor acumulado do estado pedido." << endl <<
    "[acumuladoNacao]             -> Faz a série histórica dos valor acumulado da nação." << endl;
}


tipoErro
util::entrada(vector <string> argv, int numeroArgumentos){
    if (argv[0]=="help") {
        return showH(argv,numeroArgumentos);
    }
    else if (argv[0] == "mediaMovelEstado")
    {
        cout << "executar: " << argv[0];
    }
    else if (argv[0] == "mediaMovelNacao")
    {
        cout << "executar: " << argv[0];
    }
    else if (argv[0] == "categoriaEstado")
    {
        cout << "executar: " << argv[0];
    }
    else if (argv[0] == "categoriaNacao")
    {
        cout << "executar: " << argv[0];
    }
    else if (argv[0] == "extremos")
    {
        cout << "executar: " << argv[0];
    }
    else if (argv[0] == "acumuladoEstado")
    {
        cout << "executar: " << argv[0];
    }
    else if (argv[0] == "acumuladoNacao")
    {
        cout << "executar: " << argv[0];
    }

    else {
        cout<< "comando nao achado" << endl;
        cout << "Se você colocar apenas:" << endl <<"./analiseCovid"<< endl <<"Então terá a lista de comandos aceitos" << endl;
        return comandoNaoAchado;
    }
    return ok;
}


tipoErro
util::showH(vector <string> argv, int numeroArgumentos){
    numeroArgumentos--;
    if (argv[0] != "help"){
        cout<< "condicao nao prevista" << endl;
        
        return erroDesconhecido;
    }
    else {
        if (numeroArgumentos!=2) {
            cout << "Erro: numero de argumentos invalido" << endl << "Uso:"<<endl;
            cout <<"\t ./analiseCovid [help] [comando desejado]"<<endl;
            return numeroArgumentosInvalido;
        }
        else {
            string PossivelComando = argv[1];
            bool achou = false;
            for (unsigned char index = 0; index< comandos.size(); index++){
                if (PossivelComando == comandos[index])
                    achou = true;
            }
            if (achou == false){
                cout << "Erro: Comando não achado" << endl << "Uso:"<<endl;
                cout <<"\t ./analiseCovid [help] [comando desejado]"<<endl << endl;
                cout << "Se você colocar apenas:" << endl <<"./analiseCovid"<< endl <<"Então terá a lista de comandos aceitos" << endl;
                return comandoNaoAchado;
            }
            else
            {
                if (PossivelComando == "help"){
                    cout << "Uso:" << endl;
                    cout <<"\t ./analiseCovid "<< PossivelComando <<" [comando]" <<endl ;
                    cout << "comando para ajudar a entender cada comando"<< endl;
                }
                else if (PossivelComando == "mediaMovelEstado")
                {
                    cout << "Uso:" << endl;
                    cout <<"\t ./analiseCovid "<< PossivelComando <<" [estado] [N=base-para-media-movel (padrao: 3)]" <<endl;
                    cout << "comando para ver a tabela de media movel a partir do estado pedido com o N solicitado"<< endl;
                }
                else if (PossivelComando == "mediaMovelNacao")
                {
                    cout << "Uso:" << endl;
                    cout <<"\t ./analiseCovid "<< PossivelComando <<" [N=base-para-media-movel (padrao: 3)]" <<endl;
                    cout << "comando para ver a tabela da media movel do país com o N solicitado"<< endl;
                }
                else if (PossivelComando == "categoriaEstado")
                {
                    cout << "Uso:" << endl;
                    cout <<"\t ./analiseCovid "<< PossivelComando <<" [N=base-para-media-movel (padrao: 3)]" <<endl;
                    cout << "comando para ver a situação de cada estado"<< endl;
                }
                else if (PossivelComando == "categoriaNacao")
                {
                    cout << "Uso:" << endl;
                    cout <<"\t ./analiseCovid "<< PossivelComando <<" [N=base-para-media-movel (padrao: 3)]" <<endl;
                    cout << "comando para ver a situação do pais"<< endl;
                }
                else if (PossivelComando == "extremos")
                {
                    cout << "Uso:" << endl;
                    cout <<"\t ./analiseCovid "<< PossivelComando <<" [N=base-para-media-movel (padrao: 3)]" <<endl;
                    cout << "comando para ver a situação dos 2 piores estados"<< endl;
                }
                else if (PossivelComando == "acumuladoEstado")
                {
                    cout << "Uso:" << endl;
                    cout <<"\t ./analiseCovid "<< PossivelComando <<" [estado] " <<endl;
                    cout << "comando para ver a tabela dos numero acumulado de mortes em consequencia do COVID para o estado solicitado"<< endl;
                }
                else if (PossivelComando == "acumuladoNacao")
                {
                    cout << "Uso:" << endl;
                    cout <<"\t ./analiseCovid "<< PossivelComando <<endl << endl;
                    cout << "comando para ver a tabela dos numero acumulado de mortes em consequencia do COVID no país"<< endl;
                }
                else {
                    cout<< "condicao nao prevista" << endl;
                    return erroDesconhecido;
                }
                
            }
            
        }

    }
    return ok;
}


