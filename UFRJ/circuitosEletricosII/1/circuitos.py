class resistor:
    def __init__(self,lista):
        self.nome= lista[0]
        self.resistencia = lista[3]
        self.noPositivo = lista[1]
        self.noNegativo = lista[2]

    def mostrar(self):
        print(self.nome,self.resistencia,self.noPositivo,self.noNegativo)

class fonteTensao:
    def __init__(self,lista):
        self.nome= lista[0]
        self.tipo = lista[3]
        self.tensao = lista[4]
        self.noPositivo = lista[1]
        self.noNegativo = lista[2]
    
    def mostrar(self):
        print(self.nome,self.tensao,self.noPositivo,self.noNegativo,self.tipo)

class fonteCorrente:
    def __init__(self,lista):
        self.nome= lista[0]
        self.tipo = lista[3]
        self.corrente = lista[4]
        self.noPositivo = lista[1]
        self.noNegativo = lista[2]

    def mostrar(self):
        print(self.nome,self.corrente,self.noPositivo,self.noNegativo)


class transCondutancia: #fonte de corrente controlada pela tensão de algum nó
    def __init__(self,lista):
        self.nome= lista[0]
        self.ganhoCorrente = lista[5]
        self.noPositivo = lista[1]
        self.noNegativo = lista[2]
        self.noControlePositivo = lista[3]
        self.noControleNegativo = lista[4]
    
    def mostrar(self):
        print(self.nome,self.ganhoCorrente,self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)

class ganhoTensao:  #fonte de tensão controlada pela tensão de algum no
    def __init__(self,lista):
        self.nome= lista[0]
        self.ganhoTensao = lista[5]
        self.noPositivo = lista[1]
        self.noNegativo = lista[2]
        self.noControlePositivo = lista[3]
        self.noControleNegativo = lista[4]
    
    def mostrar(self):
        print(self.nome,self.ganhoTensao,self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)


class ganhoCorrente:  #fonte de corrente controlada pela corrente de algum no
    def __init__(self,lista):
        self.nome= lista[0]
        self.ganhoCorrente = lista[5]
        self.noPositivo = lista[1]
        self.noNegativo = lista[2]
        self.noControlePositivo = lista[3]
        self.noControleNegativo = lista[4]

    def mostrar(self):
        print(self.nome,self.ganhoCorrente,self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)

class transresistencia:  #fonte de corrente controlada pela tensao de algum no
    def __init__(self,lista):
        self.nome= lista[0]
        self.ganhoTensao = lista[5]
        self.noPositivo = lista[1]
        self.noNegativo = lista[2]
        self.noControlePositivo = lista[3]
        self.noControleNegativo = lista[4]

    def mostrar(self):
        print(self.nome,self.ganhoTensao,self.noPositivo,self.noNegativo,self.noControlePositivo,self.noControleNegativo)


def selecionador(elementos):
    NRIG = 0
    c = elementos[0][0]
    #letra que define componentes
    if c == 'R':
        selecionado = resistor(elementos)
    elif c == 'G':
        selecionado = transCondutancia(elementos)
    elif c == 'E':
        selecionado = ganhoTensao(elementos)
        NRIG = 1
    elif c == 'F':
        selecionado = ganhoCorrente(elementos)
        NRIG = 1
    elif c == 'H':
        selecionado = transresistencia(elementos)
        NRIG = 1
    elif c == 'I':
        selecionado = fonteCorrente(elementos)
    elif c == 'V':
        selecionado = fonteTensao(elementos)
        NRIG = 1
    else:
        selecionado = False #netlist corrompida
    
    return selecionado,NRIG