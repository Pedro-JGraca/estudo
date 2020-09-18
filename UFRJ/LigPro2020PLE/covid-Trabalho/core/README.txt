projeto de estatística com covid

Sobre o software:
    Esse software é aplicado em CLI. Vc passará argumentos via linha de comando para conseguir obter as informações desejadas.

Como compilar:
    dentro do diretório XDIR
    $ make

Como remover os arquivos compilados:
    dentro do diretório XDIR
    $ make clean

Como usar:
    Ao compilar o programa ele estará contido dentro do arquivo binário "analiseCovid".

    Se você rodar esse programa dessa forma:

    $ ./analiseCovid

    O programa fará uma breve descrição de como rodar o programa bem como uma lista de todas as funções possíveis:

    $./analiseCovid <comando> [estado] [-n=tamanho (padrao: 7)]

    Onde o primeiro colchete implica em um comando obrigatório o segundo implica no nome do estado passado como argumento para algumas chamdas. É possível alterar o parametro de dias utilizados na média móvel através da opção -n=DIAS.

    formato: ./analiseCovid <comando> [estado] [-n=tamanho (padrao: 7)]
    Comandos:
    [help]                      -> Dá uma orientação genérica ou orientada do uso do programa.
    [porcentagemEstado]           -> Faz a série histórica da porcentagem em relação ao valor de obitos anterior do estado pedido.
    [porcentagemNacao]            -> Faz a série histórica da porcentagem em relação ao valor de obitos anterior do país.
    [categoriaEstado]             -> Informa uma lista de estados para cada situação: queda, estavel ou crescente.
    [categoriaNacao]              -> Diz se o país está em queda, estável em crescente.
    [extremos]                     -> Diz o estado que está com maior crescente e maior queda
    [acumuladoEstado]            -> Faz a série histórica dos valor acumulados do estado pedido.
    [acumuladoNacao]             -> Faz a série histórica dos valor acumulados da nação.

    Sobre erros:
        Se você passar como argumentos qualquer valor não previsto o programa falará o erro encontrado, bem como mostrará o menu de ajuda.
        
    As opções porcentagemEstado e acumuladoEstado requerem obrigatóriamente um estado como argumento.

