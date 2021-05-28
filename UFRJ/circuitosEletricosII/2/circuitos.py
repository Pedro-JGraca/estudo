import numpy as np
class resistor:
    def __init__(self,lista):
        self.nome= lista[0]
        self.resistencia = float(lista[3])
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])

    def mostrar(self):
        print(self.nome,self.resistencia,self.noPositivo,self.noNegativo)

    def estampa(self,G,I,index):
        #comdutancias ligadas ao No K
        i= self.noNegativo
        if (i>0):
            G[i-1,i-1] += 1.0/self.resistencia
        k=self.noPositivo
        if (k>0):
            G[k-1,k-1] += 1.0/self.resistencia
        
        #condutancias ligadas de K a I       
        if (k>0) and (i>0):
            G[k-1,i-1] -= 1.0/self.resistencia
            G[i-1,k-1] -= 1.0/self.resistencia
    
    def maiorNo(self):
        return max(self.noNegativo,self.noPositivo)

class fonteTensaoDC:
    def __init__(self,lista):
        self.nome= lista[0]
        self.tipo = lista[3]
        self.tensao = float(lista[4])
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])

    def DC(self):
        if (self.tipo!='DC'):
            return False
        return True

    def mostrar(self):
        print(self.nome,self.tensao,self.noPositivo,self.noNegativo)
    
    def estampa(self,G,I,index):
        I[index-1] -= self.tensao
        if (self.noPositivo > 0):
            G[self.noPositivo-1,index-1] +=1
            G[index-1,self.noPositivo-1] -=1
        if (self.noNegativo > 0):
            G[self.noNegativo-1,index-1] -=1
            G[index-1,self.noNegativo-1] +=1

    def maiorNo(self):
        return max(self.noNegativo,self.noPositivo)
    
class fonteCorrenteDC: 
    def __init__(self,lista):
        self.nome= lista[0]
        self.tipo = lista[3]
        self.corrente = float(lista[4])
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])
    
    def DC(self):
        if (self.tipo!='DC'):
            return False
        return True

    def mostrar(self):
        print(self.nome,self.corrente,self.noPositivo,self.noNegativo)
    
    def estampa(self,G,I,index):
        if self.noPositivo > 0:
            I[self.noPositivo-1] -= self.corrente
        
        if self.noNegativo > 0:
            I[self.noNegativo-1] += self.corrente

    def maiorNo(self):
        return max(self.noNegativo,self.noPositivo)

class transCondutancia: #fonte de corrente controlada pela tensão de algum nó
    def __init__(self,lista):
        self.nome= lista[0]
        self.ganhoCorrente = float(lista[5])
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])
        self.noControlePositivo = int(lista[3])
        self.noControleNegativo = int(lista[4])

    
    def estampa(self,G,I,index):
        
        if self.noPositivo> 0:
            if (self.noControlePositivo>0):
                G[self.noPositivo-1,self.noControlePositivo-1] += self.ganhoCorrente
        
            if (self.noControleNegativo>0):
                G[self.noPositivo-1,self.noControleNegativo-1] -= self.ganhoCorrente
        
        
        if self.noNegativo> 0:
            if (self.noControlePositivo>0):
                G[self.noNegativo-1,self.noControlePositivo-1] -= self.ganhoCorrente

            if (self.noControleNegativo!=0):
                G[self.noNegativo-1,self.noControleNegativo-1] += self.ganhoCorrente

    def mostrar(self):
        print(self.nome,self.ganhoCorrente,self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)

    def maiorNo(self):
        return max(self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)

class ganhoTensao:  #fonte de tensão controlada pela tensão de algum no
    def __init__(self,lista):
        self.nome= lista[0]
        self.ganhoTensao = float(lista[5])
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])
        self.noControlePositivo = int(lista[3])
        self.noControleNegativo = int(lista[4])
    
    def mostrar(self):
        print(self.nome,self.ganhoTensao,self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)

    def estampa(self,G,I,index):
        if (self.noControlePositivo>0):
            G[index-1,self.noControlePositivo-1] += self.ganhoTensao
        if (self.noControleNegativo>0):
            G[index-1,self.noControleNegativo-1] -= self.ganhoTensao
        if (self.noPositivo>0):
            G[self.noPositivo-1,index-1] +=1
            G[index-1,self.noPositivo-1] -=1
        if (self.noNegativo>0):
            G[self.noNegativo-1,index-1] -=1
            G[index-1,self.noNegativo-1] +=1

    def maiorNo(self):
        return max(self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)

class ganhoCorrente:  #fonte de corrente controlada pela corrente de algum no 
    def __init__(self,lista):
        self.nome= lista[0]
        self.ganhoCorrente = float(lista[5])
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])
        self.noControlePositivo = int(lista[3])
        self.noControleNegativo = int(lista[4])

    def mostrar(self):
        print(self.nome,self.ganhoCorrente,self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)
    
    def estampa(self,G,I,index):
        if (self.noPositivo>0):
            G[self.noPositivo-1,index-1] += self.ganhoCorrente
        if (self.noNegativo>0):
            G[self.noNegativo-1,index-1] -= self.ganhoCorrente
        if (self.noControlePositivo>0):
            G[self.noControlePositivo-1,index-1] +=1
            G[index-1,self.noControlePositivo-1] -=1
        if (self.noControleNegativo>0):
            G[self.noControleNegativo-1,index-1] -=1
            G[index-1,self.noControleNegativo-1] +=1

    def maiorNo(self):
        return max(self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)

class transresistencia:  #fonte de corrente controlada pela tensao de algum no #######################################################################################
    def __init__(self,lista):
        self.nome= lista[0]
        self.transResistencia = float(lista[5])
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])
        self.noControlePositivo = int(lista[3])
        self.noControleNegativo = int(lista[4])

    def mostrar(self):
        print(self.nome,self.transResistencia,self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)
    
    def estampa(self,G,I,index):
        G[index,index] += self.transResistencia
        if (self.noPositivo>0):
            G[index,self.noPositivo-1] +=1
            G[self.noPositivo-1,index] -=1

        if (self.noNegativo>0):
            G[index,self.noNegativo-1] +=1
            G[self.noNegativo-1,index] -=1

        if (self.noControlePositivo>0):
            G[index-1,self.noControlePositivo-1] +=1
            G[self.noControlePositivo-1,index-1] -=1

        if (self.noControleNegativo>0):
            G[index-1,self.noControleNegativo-1] +=1
            G[self.noControleNegativo-1,index-1] -=1


    def maiorNo(self):
        return max(self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)

class AmpOpId: #Amplificador Operacional Ideal #######################################################################################
    def __init__(self,lista):
        self.nome= lista[0]
        self.A = int(lista[1])
        self.B = int(lista[2])
        self.C = int(lista[3])
        self.D = int(lista[4])

    def mostrar(self):
        print(self.nome,self.A,self.B,self.C,self.D)
    
    def OK(self):
        if self.B == 0:
            return True
        return False
    
    def estampa(self,G,I,index):
        if (self.C > 0):
            if (self.D > 0):
                for i in range(0,len(I)):
                    G[i][self.C] += G[i][self.D]
        
        #tirar coluna self.D e linha self.A
        if(self.D>0):
            G = np.delete(G,[self.D-1],1)
        if (self.A>0):
            G = np.delete(G,self.A-1,0)
            I = np.delete(I,self.A-1,0)

                

    def maiorNo(self):
        return max(self.A,self.B,self.C,self.D)


def selecionador(componente):
    NRIG = 0
    c = componente[0][0]
    #letra que define componente
    if c == 'R':
        try:
            selecionado = resistor(componente)
        except:
            selecionado = False
    elif c == 'G':
        try:
            selecionado = transCondutancia(componente)
        except:
            selecionado = False
    elif c == 'E':
        try:
            selecionado = ganhoTensao(componente)
        except:
            selecionado = False
        NRIG = 1
    elif c == 'F':
        try:
            selecionado = ganhoCorrente(componente)
        except:
            selecionado = False
        NRIG = 1
    elif c == 'H':
        try:
            selecionado = transresistencia(componente)
        except:
            selecionado = False
        NRIG = 2
    elif c == 'I':
        try:#fazer selecao DC AC
            selecionado = fonteCorrenteDC(componente)
        except:
            selecionado = False
    elif c == 'V':
        try:
            selecionado = fonteTensaoDC(componente)
        except:
            selecionado = False
        NRIG = 1
    elif c == 'O':
        try:
            selecionado = AmpOpId(componente)
        except:
            selecionado = False
    else:
        selecionado = False #netlist corrompida
    
    return selecionado,NRIG


def isRGIO(componente):
    if type(componente) == resistor:
        return True
    elif type(componente) == fonteCorrenteDC:
        return True
    elif type(componente) == transCondutancia:
        return True
    elif type(componente) == AmpOpId:
        return True
    else:
        return False