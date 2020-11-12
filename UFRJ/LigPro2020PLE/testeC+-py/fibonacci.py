#import sys


def fibonacci(n,n2):
    #n = int(sys.argv[1])
    #n = int(input("fibonacci:"))
    n=int(n)
    print (n2)
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

#print(fibonacci(10,"20"))