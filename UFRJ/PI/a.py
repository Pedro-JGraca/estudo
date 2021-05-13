def polinizador(stri):
  a = stri
  stri = stri.replace(' ','')
  stri = stri.replace('.','')
  stri = stri.replace('POLI','')
  

  if (len(stri)<5):
    return '-',a
  elif (stri.isdigit()) and (len(stri)==5):
    return 'POLI' + stri,'-'
  elif (stri.find('ª')!=-1) and ((stri[:5]).isdigit()):
    return ('POLI' + stri[:5]),stri[5:]
  elif (stri.find('º')!=-1) and ((stri[:5]).isdigit()):
    return ('POLI' + stri[:5]),stri[5:]

  elif ((stri.find('PARCELA')!=-1) or (stri.find('QUIT')!=-1) or ((stri.find('VIA')!=-1))) and ((stri[:5]).isdigit()):
    l = a.split(' ')
    saida = []
    for el in l:
      if (el.isdigit()) and (len(el)==5):
        saida.append('POLI' + str(el))
    
    status = ""
    for el in l:
      if(len(saida)==0):
          saida.append('')
      if (el!='POLI') and (el!=saida[0].replace('POLI','')):
        status += el + ' '

    return saida[0],status

  else:
    l = []
    numero = ""
    for char in stri:
      if char.isdigit():
        numero+=char
      else:
        if (len(numero)==5):
          l.append(numero)
        numero=''
    if len(numero)==5:
      l.append(numero)


    if (len(l)>1):
      return 'POLI' + l[0], stri.replace('POLI','')
    elif (len(l)==1):
      return 'POLI' + l[0],(stri.replace(str(l[0]),'')).replace('POLI','')
    else:
      return '-',a

print(polinizador('POLI 20462 '))
print(polinizador('POLI 19114 24 PARCELA'))
print(polinizador('POLI 19258 4ª VIA'))
print(polinizador('POLI 21841 2 VIA'))