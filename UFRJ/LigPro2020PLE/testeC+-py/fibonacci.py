#import sys


class fibonacci:
    def __init__(self):
        pass
        
    def fazer(self,n1):
        n=int(n1)
        #print (n2)
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

def create(n):
    return fibonacci(n)

