#import sys


def fibonacci():
    #n = int(sys.argv[1])
    n = int(input("fibonacci:"))
    primeiro = 0
    segundo = 1
    resultado = primeiro

    if n > 1:
        resultado = segundo

    while ( n > 2):
        resultado = segundo + primeiro
        n-=1
        primeiro = segundo
        segundo = resultado

    return resultado