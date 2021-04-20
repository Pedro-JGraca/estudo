from circuitos import *
from funcoesBasicas import *
import sys
import numpy as np


netlist = open(sys.argv[1], 'r')
try:
    argumento = sys.argv[2]
    if argumento == "debug":
        print("[modo debug]")
    elif argumento == "verboso":
        print("[modo verboso]")
    else:
        argumento = "avançado"
        print('[modo avançado]')
except:
    print('[modo simples]')
    argumento = 'nao'
circuito = netlist.readlines()

nos = {}
componentesNRGI = []

Neq = 0 #numero de equações extras definidas = numero de componentes não RIG

#add os componentes nos nos
for componente in circuito:
    elementos=limpaStrings(componente.split(' '))
    temP,temN = False,False
    for no in nos:
        if no == elementos[1]:
            temP=True

        if no == elementos[2]:
            temN=True
    
    colocar,NRIG = selecionador(elementos)
    Neq += NRIG
    if (colocar==False):
        print("netlist corrompida")
        exit()

    if temP == True:
        nos[elementos[1]].append(colocar)
    else:
        nos[elementos[1]] = []
        nos[elementos[1]].append(colocar)

    if temN == True:
        nos[elementos[2]].append(colocar)
    else:
        nos[elementos[2]] = []
        nos[elementos[2]].append(colocar)
    
    if NRIG == 1:
        componentesNRGI.append(colocar)

nos = ordenar(nos)
if nos == False:
    print("netlist corrompida")
    exit()

if (argumento == 'verboso') or (argumento == 'avançado'):
    print("Netlist analisada, tudo certo")

if (argumento == 'debug') or (argumento == 'avançado'):
    print("leitura dos nos:")
    for no in nos:
        print(no, end=': \n')
        lista = nos[no]
        for i in lista:
            i.mostrar()
        print()


G = np.zeros((len(nos) -1 + Neq,len(nos) -1 + Neq))
I = np.zeros((len(nos) -1 + Neq))

for no in nos:
    if(no>0):
        for elemento in nos[no]:#matriz de condutancias
            if type(elemento) == resistor:
                G[no-1][no-1] += 1/float(elemento.resistencia) #Mii = soma de todos os resistores em i

                if (int(elemento.noNegativo) != 0 ) and (int(elemento.noPositivo)!=0): #mki = soma de todos os resistores entre i e k
                    if no==int(elemento.noPositivo):
                        G[int(elemento.noNegativo)-1][int(elemento.noPositivo)-1] -= 1/float(elemento.resistencia)
                    elif no==int(elemento.noNegativo):
                        G[int(elemento.noPositivo)-1][int(elemento.noNegativo)-1] -= 1/float(elemento.resistencia)
                    else:
                        print("Erro no nó <" + str(no) + "> e no componente:")
                        elemento.mostrar()
                        print("saindo da execução")
                        exit()
            
            elif type(elemento)==fonteCorrente: #analise da matriz de correntes
                if no == int(elemento.noPositivo):
                    I[no-1] -= int(elemento.corrente)
                elif no == int(elemento.noNegativo):
                    I[no-1] -= -int(elemento.corrente)
                else:
                    print("Erro no nó <" + str(no) + "> e no componente:")
                    elemento.mostrar()
                    print("saindo da execução")
                    exit()
            
            elif type(elemento) == transCondutancia: #modificando matriz de condutancias adicionando transcondutancias
                if no == int(elemento.noPositivo): #corrente está entrando #G*(ep-en) -(*-1)> -Gep + Gen
                    if int(elemento.noControlePositivo) != 0:
                        G[no-1][int(elemento.noControlePositivo)-1] -= int(elemento.ganhoCorrente)
                    if int(elemento.noControleNegativo) != 0:
                        G[no-1][int(elemento.noControleNegativo)-1] += int(elemento.ganhoCorrente)
                
                elif no == int(elemento.noNegativo): #corrente está saindo # -G*(ep-en) -(*-1)> Gep - Gen
                    if int(elemento.noControleNegativo) != 0:
                        G[no-1][int(elemento.noControleNegativo)-1] += int(elemento.ganhoCorrente)
                    if int(elemento.noControlePositivo) != 0:
                        G[no-1][int(elemento.noControlePositivo)-1] -= int(elemento.ganhoCorrente)
                else:
                    print("Erro no nó <" + str(no) + "> e no componente:")
                    elemento.mostrar()
                    print("saindo da execução")
                    exit()


####################################### 
index = 0
for elemento in componentesNRGI: 
    if type(elemento) == fonteTensao:
        
        if int(elemento.noPositivo)!=0:
            G[len(nos)-1 + index][int(elemento.noPositivo)-1]+=-1
            G[int(elemento.noPositivo)-1][len(nos)-1 + index]+=1
        if int(elemento.noNegativo)!=0:
            G[len(nos)-1 + index][int(elemento.noNegativo)-1]+=1
            G[int(elemento.noNegativo)-1][len(nos)-1 + index]+=-1

        I[len(nos)-1 + index]-=int(elemento.tensao)
        index+=1
    elif type(elemento) == ganhoTensao:
        if int(elemento.noPositivo)!=0:
            G[len(nos)-1 + index][int(elemento.noPositivo)-1]+=-1
            G[int(elemento.noPositivo)-1][len(nos)-1 + index]+=1
        if int(elemento.noNegativo)!=0:
            G[len(nos)-1 + index][int(elemento.noNegativo)-1]+=1
            G[int(elemento.noNegativo)-1][len(nos)-1 + index]+=-1
            
        if int(elemento.noControlePositivo)!=0:
            G[len(nos)-1 + index][int(elemento.noControlePositivo)-1]+=int(elemento.ganhoTensao)
        if int(elemento.noControleNegativo)!=0:
            G[len(nos)-1 + index][int(elemento.noControleNegativo)-1]-=int(elemento.ganhoTensao)
        
        index+=1
    
    elif type(elemento) == ganhoCorrente:
        if (int(elemento.noPositivo)!=0):
            G[int(elemento.noPositivo)-1][len(nos) -1 + index] +=int(elemento.ganhoCorrente)
        if (int(elemento.noNegativo)!=0):
            G[int(elemento.noNegativo)-1][len(nos) -1 + index] -=int(elemento.ganhoCorrente)
        if (int(elemento.noControlePositivo)!=0):
            G[int(elemento.noControlePositivo)-1][len(nos) -1 + index] -=1
            G[len(nos) + index -1][int(elemento.noControlePositivo)-1] +=1

        if (int(elemento.noControleNegativo)!=0):
            G[int(elemento.noControleNegativo)-1][len(nos) - 1 + index] +=1
            G[len(nos) + index -1][int(elemento.noControleNegativo)-1] -=1
        
        index+=1

    elif type(elemento) == transresistencia:
        if (int(elemento.noPositivo)!=0):
            G[int(elemento.noPositivo)-1][len(nos) + index] +=1
            G[len(nos) + index][int(elemento.noPositivo)-1] -=1
        if (int(elemento.noNegativo)!=0):
            G[int(elemento.noNegativo)-1][len(nos) + index] -=1
            G[len(nos) + index][int(elemento.noNegativo)-1] -=1

        if (int(elemento.noControlePositivo)!=0):
            G[int(elemento.noControlePositivo)-1][len(nos) + index-1] +=1
            G[len(nos) + index-1][int(elemento.noControlePositivo)-1] -=1

        if (int(elemento.noControleNegativo)!=0):
            G[int(elemento.noControleNegativo)-1][len(nos) + index-1] -=1
            G[len(nos) + index-1][int(elemento.noControleNegativo)-1] +=1
        
        G[len(nos) + index][len(nos) + index-1] += int(elemento.ganhoTensao)
        index +=2
                

if (argumento == 'verboso') or (argumento == 'avançado'):
    print("matriz de condutancias concluída")
if (argumento == 'debug') or (argumento == 'avançado'):
    for line in G:
        print("|",end=' ')
        for el in line:
            print('{:.2f}'.format(el),end=' ; ')
        print('|')

    print(I)

E = np.linalg.solve(G,I)
index = 1
for e in E:
    if (index<len(nos)):
        print("e"+str(index)+": <" + '{:.2f}'.format(e) + "> V")
    else:
        print("j"+str(index-len(nos)+1)+": <" +'{:.2f}'.format(e)+ "> A")
    index+=1

netlist.close()