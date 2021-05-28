from circuitos import *
from funcoesBasicas import *
import sys
import numpy as np

#import sympy as sy
#s = sy.Symbol('s')
#j = np.complex(1j)
#Y = np.zeros((2,2),dtype=type(j))
#I[0] = 31/(4*s)
#sy.pprint(E[0] - E[1])

netlist = open(sys.argv[1], 'r')

circuito = netlist.readlines()

componentes = []
AmpOps = []

Neq = 0 #numero de equações extras definidas = numero de componentes não RIG

#let o arquivo e add nos componentes
for line in circuito:
    componente=limpaStrings(line.split(' '))

    colocar,NRIG = selecionador(componente)
    Neq += NRIG
    if (colocar==False):
        print("netlist corrompida")
        exit()
    elif (colocar != AmpOpId):
        componentes.append(colocar)
    else:
        if not(colocar.OK()):
            print('não fui projetado para AmpOp com B fora do Terra')
            exit()
        AmpOps.append(colocar)

nos = 0

for AmpOP in AmpOps:
    componentes.append(AmpOP)
AmpOps = 0 #apagar

for componente in componentes:
    nos = max(nos,componente.maiorNo())

G = np.zeros((nos + Neq,nos + Neq), dtype=float)
I = np.zeros((nos + Neq),  dtype=float)

index = nos
for componente in componentes:
    if not(isRGIO(componente)):
        index+=1
    #componente.mostrar()
    componente.estampa(G,I,index)



#print(G)
#print(I)

E = np.linalg.solve(G,I)
index = 1
for e in E:
    if (index<=nos):
        print("e"+str(index)+": <" + '{:.2f}'.format(e) + "> V")
    else:
        print("j"+str(index-nos)+": <" +'{:.2f}'.format(e)+ "> A")
    index+=1