import numpy as np
from numpy.core.numeric import indices
j = np.complex(1j)

def Complexificador(a):
    continuo = float(a[0])
    amplitude = float(a[1])
    freq = float(a[2])
    atraso = float(a[3])
    A = amplitude #*cos(atraso) = 1
    B = 0 #*cos(atraso) = 1
    R = complex(continuo) + complex(A) + B*j

    return R,freq#frequencia

class resistor:
    def __init__(self,lista):
        self.nome= lista[0]
        self.resistencia = float(lista[3])
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])

    def mostrar(self):
        print(self.nome,self.resistencia,self.noPositivo,self.noNegativo)

    def estampa(self,G,I,index,w):
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

class fonteTensao:
    def __init__(self,lista): #V<nome> <vo+> <vo-> <tipo de fonte> #SIN (<nível contínuo> <amplitude> <frequência> <atraso> <atenuação> <ângulo> <ciclos>) DC <valor>
        self.nome= lista[0]
        self.tipo = lista[3]
        self.tensao = lista[4:] 
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])

    def setTipo(self):
        if (self.tipo=='SIN') :
            self.tensao,freq = Complexificador(self.tensao)
            return True,freq
        elif (self.tipo=='DC'):
            self.tensao = complex(self.tensao[0])
            return True,0
        return False,''

    def mostrar(self):
        print(self.nome,self.tensao,self.noPositivo,self.noNegativo)
    
    def estampa(self,G,I,index,w):
        
        I[index-1] -= self.tensao
        if (self.noPositivo > 0):
            G[self.noPositivo-1,index-1] +=1
            G[index-1,self.noPositivo-1] -=1
        if (self.noNegativo > 0):
            G[self.noNegativo-1,index-1] -=1
            G[index-1,self.noNegativo-1] +=1

    def maiorNo(self):
        return max(self.noNegativo,self.noPositivo)
    
class fonteCorrente: 
    def __init__(self,lista):
        self.nome= lista[0]
        self.tipo = lista[3]
        self.corrente = lista[4:]
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])
    
    def setTipo(self):
        if (self.tipo=='SIN'):
            self.corrente, freq = Complexificador(self.corrente)
            return True, freq
        elif (self.tipo=='DC'):
            self.corrente= complex(self.corrente[0])
            return True, 0
        return False, ''

    def mostrar(self):
        print(self.nome,self.corrente,self.noPositivo,self.noNegativo)
    
    def estampa(self,G,I,index,w):
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

    
    def estampa(self,G,I,index,w):
        
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

    def estampa(self,G,I,index,w):
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
    
    def estampa(self,G,I,index,w):
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



class transresistencia:  #fonte de corrente controlada pela tensao de algum no 
    def __init__(self,lista):
        self.nome= lista[0]
        self.transResistencia = float(lista[5])
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])
        self.noControlePositivo = int(lista[3])
        self.noControleNegativo = int(lista[4])

    def mostrar(self):
        print(self.nome,self.transResistencia,self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)
    
    def estampa(self,G,I,index,w):
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



class Indutor: # L<nome> <nó+> <nó-> <indutância> [IC=<corrente inicial>]
    def __init__(self,lista):
        self.nome= lista[0]
        self.Indutancia = float(lista[3])
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])

    def mostrar(self):
        print(self.nome,self.Indutancia,self.noPositivo,self.noNegativo)

    def estampa(self,G,I,index,w):
        if (self.noPositivo>0):
            G[self.noPositivo-1][self.noPositivo-1] += 1/(j*w*self.Indutancia)
        if (self.noNegativo>0):
            G[self.noNegativo-1][self.noNegativo-1] += 1/(j*w*self.Indutancia)

        if (self.noPositivo>0) and (self.noNegativo>0):
            G[self.noPositivo-1][self.noNegativo-1] -= 1/(j*w*self.Indutancia)
            G[self.noNegativo-1][self.noPositivo-1] -= 1/(j*w*self.Indutancia)
    
    def maiorNo(self):
        return max(self.noNegativo,self.noPositivo)
    

    
class Capacitor: #  C<nome> <nó+> <nó-> <capacitância> [IC=<tensão inicial>]
    def __init__(self,lista):
        self.nome= lista[0]
        self.capacitancia = float(lista[3])
        self.noPositivo = int(lista[1])
        self.noNegativo = int(lista[2])

    def mostrar(self):
        print(self.nome,self.capacitancia,self.noPositivo,self.noNegativo)

    def estampa(self,G,I,index,w):
        if (self.noPositivo>0):
            G[self.noPositivo-1][self.noPositivo-1] += (j*w*self.capacitancia)
        if (self.noNegativo>0):
            G[self.noNegativo-1][self.noNegativo-1] += (j*w*self.capacitancia)

        if (self.noPositivo>0) and (self.noNegativo>0):
            G[self.noPositivo-1][self.noNegativo-1] -= (j*w*self.capacitancia)
            G[self.noNegativo-1][self.noPositivo-1] -= (j*w*self.capacitancia)

    
    def maiorNo(self):
        return max(self.noNegativo,self.noPositivo)
    


class AmpOpId: #Amplificador Operacional Ideal 
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
    
    def estampa(self,G,I,index,w):
        if (self.C > 0): # - 
            if (self.D > 0): # +
                for i in range(0,len(I)):
                    G[i][self.C] += G[i][self.D]
        
        #tirar coluna self.D e linha self.A
        if(self.D>0): # +, linha
            G = np.delete(G,[self.D-1],1) 
        if (self.A>0): # -, colona
            G = np.delete(G,self.A-1,0)
            I = np.delete(I,self.A-1,0)

                

    def maiorNo(self):
        return max(self.A,self.B,self.C,self.D)



class TransformadorIdeal: #Transformador ideal 
    def __init__(self,lista):
        self.nome= lista[0]
        self.A = int(lista[1])
        self.B = int(lista[2])
        self.C = int(lista[3])
        self.D = int(lista[4])
        self.n = int(lista[5])
        self.corrente = 0

    def mostrar(self):
        print(self.nome,self.A,self.B,self.C,self.D,self.n)
    
    def estampa(self,G,I,index,w):
        self.corrente=index-1
        if(self.A>0):
            G[index-1][self.A-1] -= self.n
            G[self.A-1][index-1] += self.n
        if(self.B>0):
            G[index-1][self.B-1] += self.n
            G[self.B-1][index-1] -= self.n
        if(self.C>0):
            G[index-1][self.C-1] += 1
            G[self.C-1][index-1] -= 1
        if(self.D>0):
            G[index-1][self.D-1] -= 1
            G[self.D-1][index-1] += 1

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
            selecionado = fonteCorrente(componente)
        except:
            selecionado = False
    elif c == 'V':
        try:
            selecionado = fonteTensao(componente)
        except:
            selecionado = False
        NRIG = 1
    elif c == 'O':
        try:
            selecionado = AmpOpId(componente)
        except:
            selecionado = False
    elif c == 'L':
        try:
            selecionado = Indutor(componente)
        except:
            selecionado = False
    elif c == 'C':
        try:
            selecionado = Capacitor(componente)
        except:
            selecionado = False
    elif c == 'K': 
        try:
            selecionado = TransformadorIdeal(componente)
        except:
            selecionado = False
        NRIG = 1
    else:
        selecionado = False #netlist corrompida
    
    return selecionado,NRIG


def isRGIO(componente):
    if type(componente) == resistor:
        return True
    elif type(componente) == fonteCorrente:
        return True
    elif type(componente) == transCondutancia:
        return True
    elif type(componente) == AmpOpId:
        return True
    elif type(componente) == Capacitor:
        return True
    elif type(componente) == Indutor:
        return True
    else:
        return False