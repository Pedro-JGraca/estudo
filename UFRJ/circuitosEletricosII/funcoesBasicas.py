from numpy.lib.index_tricks import _fill_diagonal_dispatcher


def removeVazios(lista):
    somelist = [x for x in lista if x!=""]
    return somelist

def limpaStrings(lista):

    saida = []

    for l in lista:
        saida.append(l.strip())

    return saida

def ordenar(nos):
    saida = {}
    index = 0
    while (index < len(nos)):
        ok = False

        for no in nos:
            if (int(no) ==index):
                saida[index]=nos[no]
                index+=1
                ok=True
        
        if(ok==False):
            saida = False
            break
    return saida
