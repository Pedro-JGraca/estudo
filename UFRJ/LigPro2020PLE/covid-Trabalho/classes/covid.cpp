#include <fstream>
#include <math.h>
#include "covid.h"
#include "estadual.h"
#include "nacional.h"

covid::covid()
{
    if (setData()!=ok){
        cout <<"data Corrompida"<< endl;
        dia = 01;
        mes = 03;
        ano = 2020;
        cout << "usando: " << dia << "/" << mes << "/" << ano << endl;
    }
}


void
covid::showInicial () {
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

unsigned char
covid::nizador(string entrada){
    unsigned short a = 3;
    bool digito = false;
    if (entrada.size()<3){
        cout 
        << "Erro: Formato do N invalido." << endl 
        << "formato do N: n=<numero-inteiro-sem-sinal>" <<endl;
        cout << "Considerado N=" << a << endl;
        return a;
    }
    if (entrada.substr(2).size()>3){
        cout 
        << "Erro: N muito grande." << endl 
        << "formato do N: n=<numero-inteiro-sem-sinal-menor-que-255>" <<endl;
        cout << "Considerado N=" << a << endl;
        return a;
    }
    
    if (entrada.size()>2){
    if (entrada.substr(0,2) == "n=") {
    if ((entrada.substr(2)).size()<4) {
        digito = isDigit(entrada.substr(2));
    }}}

    if (digito){
        a = stoi(entrada.substr(2));
    }
    else {
        cout 
        << "Erro: N não é numero natural." << endl
        << "formato do N: n=<numero-inteiro-sem-sinal-menor-que-255>" <<endl;
        cout << "Considerado N=" << a << endl;
        return a;

    }

    if (a > 255) {
        cout 
        << "Erro: N muito grande." << endl 
        << "formato do N: n=<numero-inteiro-sem-sinal-menor-que-255>" <<endl;
        a=3;
    }

    if (a == 0) {
        cout 
        << "Erro: N nao pode ser zero" << endl 
        << "formato do N: n=<numero-inteiro-sem-sinal-menor-que-255>" <<endl;
        a=3;
    }    

    cout << "Considerado N=" << a << endl;

    return (unsigned char) a;
}

bool
covid::isDigit(string a) {
    for (unsigned char i; i < a.size();i++) {
        if (!isdigit(a[i])){
            return false;
        }
    }
    if (!a.size()){
        return false;
    }
    return true;
}

unsigned short
covid::strTouc(string a){
    unsigned short b=0;
    for (unsigned char i = 0; i<a.size() ;i++){
        b += ((a[i] - '0')*pow(10,(a.size() - (i+1))));
    }
    return b;
}

tipoErro
covid::setData(){
    char a[11];
    ifstream fin("./dados/dataInicio.txt");
    if (fin){
        fin.getline(a,11);
        string b = a;
        if (isDigit(b.substr(0,2))){
            dia = strTouc(b.substr(0,2));
        }
        else
        {
            cout << "dia" << endl;
            return dataInvalida;
        }

        if (isDigit(b.substr(3,2))){
            mes = strTouc(b.substr(3,2));
        }
        else
        {
            cout << "mes" << endl;
            return dataInvalida;
        }
            
        if (isDigit(b.substr(6,4))){
            ano = strTouc(b.substr(6,4));
        }
        else
        {
            cout << "ano" << endl;
            return dataInvalida;
        }
    }
    else {
        cout << "arquivo" << endl;
        return dataInvalida;
    }

    return ok;

}

string
covid::datar(unsigned entrada){
    unsigned short D = dia;
    unsigned short M = mes;
    unsigned A = ano;
    //cout << entrada << " " << D<<  " " << M << " " <<  A << endl;
    D += entrada;
    unsigned limite_dia ;
    if (M==1 or M == 3 or M == 5 or M == 7 or M == 8 or M == 10 or M == 12){
        limite_dia =31;
    }
    else if (M == 2){
        if (A%4 != 0){
            limite_dia = 29;
        }
        else {
            limite_dia = 28;
        }
    }
    else {
        limite_dia = 30;
    }
    while (D>limite_dia){
        D-=limite_dia;
        M +=1;
        if (M==1 or M == 3 or M == 5 or M == 7 or M == 8 or M == 10 or M == 12){
            limite_dia =31;
        }
        else if (M == 2){
            if (A%4 != 0){
                limite_dia = 29;
            }
            else {
                limite_dia = 28;
            }
        }
        else {
            limite_dia = 30;
        }
    }
    while (M > 12){
        M -=12;
        A +=1;
    }
    string todo = to_string(D) + "/" + to_string(M) + "/" + to_string(A);
    return todo;
}
         


tipoErro
covid::entrada(vector <string> argv, int numeroArgumentos){
    
    if (argv[0]=="help") {
        return showH(argv,numeroArgumentos);
    }
    else if (argv[0] == "mediaMovelEstado")
    {
        if (numeroArgumentos!=4){
            cout << "Erro: numero de argumentos invalido" << endl << "Uso:"<<endl;
            cout <<"\t ./analiseCovid "<< argv[0] <<" [estado] [N=base-para-media-movel (padrao: 3)]" <<endl;
            return numeroArgumentosInvalido;
        }
        unsigned short n;
        n = nizador(argv[2]);
        estadual estado(argv[1],n);
        if (estado.getSizeDados()!=0){
            if (estado.getEstado().size()!=0){
                vector <float> porcentagem;
                estado.porcentagemMovel(&porcentagem);

                for (unsigned i=0 ; i < porcentagem.size(); i++){
                    cout << datar(i) << " " << porcentagem[i] << "%"  << endl;
                }
            }
            else {
                return estadoNaoAchado;
            }
        }
        else {
            return erroAbrirArquivo;
        }
    }
    else if (argv[0] == "mediaMovelNacao")
    {
        if (numeroArgumentos != 3){
            cout << "Uso:" << endl;
            cout <<"\t ./analiseCovid "<< argv[0] <<" [N=base-para-media-movel (padrao: 3)]" <<endl;
            return numeroArgumentosInvalido;
        }
        unsigned short n= nizador(argv[1]);
        nacional pais(n);
        vector <float> porcent;
        pais.porcentagemMovel(&porcent);
        for (unsigned i = 0; i < porcent.size(); i++){
            cout << datar(i) << " " << porcent[i] << "%" << endl;
        }
    }
    else if (argv[0] == "categoriaEstado")
    {
        if (numeroArgumentos != 3){
            cout << "Uso:" << endl;
            cout <<"\t ./analiseCovid "<< argv[0] <<" [N=base-para-media-movel (padrao: 3)]" <<endl;
            return numeroArgumentosInvalido;
        }
        unsigned short n= nizador(argv[1]);
        nacional pais(n);

        vector <string> alto,medio,baixo;

        pais.categoria(&alto,&medio,&baixo);

        cout << "Estados em alta:" << endl;
        for (unsigned i = 0; i < alto.size() ; i++){
            cout << alto[i];
        }
        cout << endl;

        cout << "Estados estaveis:" << endl;
        for (unsigned i = 0; i < medio.size() ; i++){
            cout << medio[i];
        }
        cout << endl;
            
        cout << "Estados em baixa:" << endl;
        for (unsigned i = 0; i < baixo.size() ; i++){
            cout << baixo[i];
        }
        cout << endl;

    }
    else if (argv[0] == "categoriaNacao")
    {
        if (numeroArgumentos != 3){
            cout << "Uso:" << endl;
            cout <<"\t ./analiseCovid "<< argv[0] <<" [N=base-para-media-movel (padrao: 3)]" <<endl;
            return numeroArgumentosInvalido;
        }
        unsigned short n= nizador(argv[1]);
        nacional pais(n);
        
        cout << "Brasil: "<< pais.situacaoNacional() << endl;
    }
    else if (argv[0] == "extremos")
    {
        if (numeroArgumentos != 3){
            cout << "Uso:" << endl;
            cout <<"\t ./analiseCovid "<< argv[0] <<" [N=base-para-media-movel (padrao: 3)]" <<endl;
            return numeroArgumentosInvalido;
        }
        unsigned short n= nizador(argv[1]);
        nacional pais(n);
        vector <string> lixo;
        cout << pais.categoria(&lixo,&lixo,&lixo) << endl;
    }
    else if (argv[0] == "acumuladoEstado")
    {
        if (numeroArgumentos!=3){
            cout << "Erro: numero de argumentos invalido" << endl << "Uso:"<<endl;
            cout <<"\t ./analiseCovid "<< argv[0] <<" [estado]" <<endl;
            return numeroArgumentosInvalido;
        }
        else {
            estadual estado(argv[1],0); // zero é a entrada para quando se quer calcular o acomulado do estado, pois nao pode exitir n = 0 para a media movel

            if (estado.getSizeDados()!=0){
                if (estado.getEstado().size()!=0){
                    vector <unsigned> acumulado;
                    estado.somaMovel(&acumulado);
                    for (unsigned short i = 0 ;i < acumulado.size();i++){
                        cout << datar(i) << " " << acumulado[i] << endl;
                    }
                }
                else {
                    return estadoNaoAchado;
                }
            }
            else {
                return erroAbrirArquivo;
            }
        }
    }
    else if (argv[0] == "acumuladoNacao")
    {
        if (numeroArgumentos != 2){
            cout << "Uso:" << endl;
            cout <<"\t ./analiseCovid "<< argv[0] <<endl;
            return numeroArgumentosInvalido;
        }

        nacional pais(0);
        vector <unsigned> soma;
        pais.somaMovel(&soma);
        for (unsigned i = 0; i < soma.size(); i++){
            cout << datar(i) << " " << soma[i] << endl;
        }

    }

    else {
        cout<< "comando nao achado" << endl;
        cout << "Se você colocar apenas:" << endl <<"./analiseCovid"<< endl <<"Então terá a lista de comandos aceitos" << endl;
        return comandoNaoAchado;
    }
    return ok;
}


tipoErro
covid::showH(vector <string> argv, int numeroArgumentos){
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
                    cout << "comando para ver os estados com a melhor e a pior situação"<< endl;
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