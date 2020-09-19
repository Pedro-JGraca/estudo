#include "util.h"


ultil::ultil()
{
}




void
ultil::showInicial () {
    cout << 
    "formato padrão: ./analiseCovid <comando> [N=base-para-media-movel (padrao: 3)] [estado]" << endl <<
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


