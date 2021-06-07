from circuitosRPS import *
from funcoesBasicas import *
import sys
import numpy as np
j = np.complex(1j)

netlist = open(sys.argv[1], 'r')

circuito = netlist.readlines()

componentes = []
AmpOps = []
freq = 0
Neq = 0 #numero de equações extras definidas = numero de componentes não RIG

#let o arquivo e add nos componentes
for line in circuito:
    componente=limpaStrings(line.split(' '))

    colocar,NRIG = selecionador(componente)
    Neq += NRIG
    if (colocar==False):
        print("netlist corrompida")
        exit()
    elif (type(colocar) != AmpOpId):
        if (type(colocar) != fonteTensao) and (type(colocar) != fonteCorrente):
            componentes.append(colocar)
        else:#é uma fonte
            if (freq == 0):
                tipoValido, freq = colocar.setTipo()
            else:#freq já setada
                tipoValido, freqNaoUsada = colocar.setTipo()
            if (tipoValido):
                componentes.append(colocar)
            else:
                print('Não fui projetado para esse tipo de fonte')
                exit()
    else:#é AMpOp
        if not(colocar.OK()):
            print('não fui projetado para AmpOp com B fora do Terra')
            exit()
        AmpOps.append(colocar)


nos = 0

for AmpOP in AmpOps:
    componentes.append(AmpOP)

for componente in componentes:
    nos = max(nos,componente.maiorNo())

G = np.zeros((nos + Neq,nos + Neq), dtype=type(j))
I = np.zeros((nos + Neq),  dtype=type(j))

index = nos
for componente in componentes:
    if not(isRGIO(componente)):
        index+=1
    componente.estampa(G,I,index,freq)



#print(G)
#print(I)

E = np.linalg.solve(G,I)

for componente in componentes:
    if type(componente) == TransformadorIdeal:
        E[componente.corrente] = - E[componente.corrente]

index = 1

#for e in E:
#    if (index<=nos):
#        print("e"+str(index)+": <" + '{:.2f}'.format(e) + "> V")
#    else:
#        print("j"+str(index-nos)+": <" +'{:.2f}'.format(e)+ "> A")
#    index+=1
#
#index = 1
for e in E:
    x = np.real(e)
    y = np.imag(e)

    rho = np.sqrt(x**2 + y**2)
    phi = np.arctan2(y, x)
    phi = phi*180/np.pi
    

    if (index<=nos):
        print("e"+str(index)+":" +'{:.2f}'.format(rho) +  "cos("+str(freq)+"t + " + '{:.2f}'.format(phi) +"°)" +"> V")
    else:
        print("j"+str(index-nos)+":" +'{:.2f}'.format(rho) +  "cos("+str(freq)+"t + " + '{:.2f}'.format(phi)+"°)" +"> A")
    index+=1