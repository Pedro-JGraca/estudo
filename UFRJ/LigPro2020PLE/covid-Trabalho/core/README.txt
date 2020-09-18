projeto de estatística com covid

Sobre o software:
    Esse software é aplicado em CLI. Vc passará argumentos via linha de comando para conseguir obter as informações desejadas.
    O motivo é para uma possível aplicação back-end em um programa (não produzido) que mostrasse essas informações de forma visual.

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

    $./analiseCovid [-h:-H::-pe::-pn::-ce::-cn::-m::-n::-ae::-an] [opções::nada]

    Onde o primeiro colchete implica uma flag possível e o segundo implica opções que essa flag necessita para o correto funcionamento.

    Lista de flags:
    
    [-h:-H:--help]                      -> Dá uma orientação genérica ou orientada do uso do programa.
    [-pe:--porcentagemEstado]           -> Faz a série histórica da porcentagem em relação ao valor de obitos anterior do estado pedido.
    [-pn:--porcentagemNacao]            -> Faz a série histórica da porcentagem em relação ao valor de obitos anterior do país.
    [-ce:--categoriaEstado]             -> Informa uma lista de estados para cada situação: queda, estavel ou crescente.
    [-cn:--categoriaNacao]              -> Diz se o país está em queda, estável em crescente.
    [-e:--extremos]                     -> Diz o estado que está em maior crescente e maior queda.
    [-ae:--acumuladosEstado]            -> Faz a série histórica dos valor acumulados do estado pedido.
    [-an:--acumuladosNacao]             -> Faz a série histórica dos valor acumulados da nação.

    Sobre erros:
        Se você passar como argumentos qualquer valor não previsto o programa falará o erro encontrado, bem como mostrará uma descrição de uso correto dentro do contexto.
    
    Nota:
        Só serão aceitos 2 conjunto de argumentos. O primeiro conjunto é composto de uma unica flag dentro das opções listadas. O segundo será o conjunto de opções pedidas para cada flag. O motivo para essa aplicação diferente do padrão do linux é pela natureza do programa, onde o interesse é no dado mostrado, se você pedir muitos dados, não faria muito sentido para exibição. Dessa forma fica organizado, cada comando dá uma resposta. Colocar mais flags por chamada seria como colocar duas respostas na mesma chamada, o que queremos evitar.

    Para as flags: [-h:-H:--help] (mesmo comportamento para qlqr um das flags apresentadas)
        descrição:
            flag que busca ajudar o usuário a usar esse programa.
        uso:
            ./analiseCovid [-h:-H:--help] [opção::nada]
        
        Se não passar um segundo argumento:
            descreverá o programa como um todo e como usa-lo.
        
        Se a opção for uma das flags do programa (podendo ter ou não um "-" no corpo da opção).

        exemplo:
            ./analiseCovid [-h:-H:--help] [-a::a::--nomeCompletoDaFlag-a]
        irá descrever o funcionamento do programa usando a flag "a" e o uso esperado.
        
    Para as flags: [-pe:--porcentagemEstado]
        descrição:
            flag que mostra uma série histórica da média móvel (a partir de um N fornecido pela linha de comando) de obtos cometidos em decorrência da covid-19 no estado selecionado pela linha de comando.

        uso:
            ./analiseCovid [-pe:--porcentagemEstado] [Estado] [Tamanho da media móvel]

        [Estado]
            string falando o nome do estado desejado.
    
        nota:
            os estados estão descritos segundo os dois últimos caracteres dos seus nomes na ISO 3166-2:BR.

            exemplos:
        
            Rio de Janeiro -> RJ
            Bahia -> BA

            Link para referencia:
            https://www.iso.org/obp/ui/#iso:code:3166:BR
            https://pt.wikipedia.org/wiki/ISO_3166-2:BR
    
        [Tamanho da media movel]
        numero inteiro sem sinal (unsigned short) que representa a quantidade que o programa usa para calcular a porcentagem.

    Para: [-pn:--porcentagemNacao]

        descrição:
            flag que mostra uma série histórica da média móvel (a partir de um N fornecido pela linha de comando) de óbitos cometidos em decorrência da covid-19 no país.

        uso:
            ./analiseCovid [-pn:--porcentagemNacao] [Tamanho da media movel]
    
        Essa flag é muito parecida com a anterior, a diferença é que não é necessário descrever o Estado, pois você já solicitou a do nação.

    Para: [-ce:--categoriaEstado]
        descrição:
            dá a lista de todos os estados categorizados no banco de dados e sua situação atual em relação a média movel (a partir do N fornecido) do covid-19. Se estiver com um crescimento acima de 15% estará associado a string "crescendo", se queda acima de 15%, então "em queda", se estiver entre 15% de crescente e 15% de queda, então "estável".
            Cada estado então estará em uma lista com as 3 categorias.

        uso: 
            ./analiseCovid [-ce:--categoriaEstado] [Tamanho da media movel]
    Para: [-cn:--categoriaNacao]
        descrição:
            essa flag se parece com a anterior, só que não é a lista de estados do país e sim se o país está crescendo, estável ou em queda.
        uso: 
            ./analiseCovid [-cn:--categoriaNacao] [Tamanho da media movel]

    Para: [-m:--maior]
        descrição:
            essa flag usa a lista da flag "--categoriaEstado" e diz qual é o estado de maior crescente e o de maior queda.
        uso: 
            ./analiseCovid [-e:--extremos] [Tamanho da media móvel]
    
    Para: [-ae:--acumuladosEstado] 
        descrição:
            faz a série histórica dos valor acumulados do estado pedido.
        uso:
            ./analiseCovid [-ae:--acumuladosEstado] [Estado]

    Para: [-an:--acumuladosNacao]
        descrição:
            faz a série histórica dos valor acumulados da nação.
        uso:
            ./analiseCovid [-an:--acumuladosNacao] 