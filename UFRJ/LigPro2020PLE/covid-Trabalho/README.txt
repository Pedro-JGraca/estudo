projeto de estatística com covid

Sobre o software:
    Esse software é aplicado em CLI. Vc passará argumentos via linha de comando para conseguir obter as informações desejadas.

Como compilar:
    dentro do diretório do programa
    $ make

Como remover os arquivos compilados:
    dentro do diretório do prgrama
    $ make clean

Como usar:
    Ao compilar o programa ele estará contido dentro do arquivo binário "analiseCovid".

    Se você rodar esse programa dessa forma:

    $ ./analiseCovid

    O programa fará uma breve descrição de como rodar o programa bem como uma lista de todas as funções possíveis


	ENTRADA DE DADOS
	O programa é alimentado através de uma pasta chamada dados/estados com um arquivo txt por estado.
	Cada linha do arquivo do estado significa o número de óbitos ocorridos no dia X+linha, onde X é o dia inicial das mediçoes, comum a todos os estados.
    O dia inicial das mediçoes é encontrado dentro do arquivo dataInicio.txt.