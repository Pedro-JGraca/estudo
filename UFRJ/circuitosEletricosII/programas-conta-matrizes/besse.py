import scipy.special as sp
import numpy as np
l = {}
for index in range(1,90000):
    i = index/10000.00
    A0 = np.abs((0.568**(1/2))/sp.jv(0,i)) # A = sqrt(0.565)/J_0(B) 
    A2 = np.abs((0.088**(1/2))/sp.jv(2,i)) # A = sqrt(0.088)/J_2(B)
    A4 = np.abs((1.2272**(1/2))/sp.jv(4,i)) # A = sqrt(1.2272)/J_2(B)

    r1 = ((np.abs(A2-A0))/A0)*100
    r2 = ((np.abs(A4-A0))/A0)*100
    r3 = ((np.abs(A2-A4))/A4)*100
    r4 = ((np.abs(A2-A4))/A2)*100
    ref = 10
    if (r4 <= ref and r3 <= ref and r2 <= ref and r1 <=ref):
        media = (r4 + r3 + r2 + r1)/4
        l[media] = [(A0+A2+A4)/3,A0,A2,A4,i]

menor = 500.00
for a in l:
    if menor > a:
        menor = a
print(l[menor])

i = 484.00/100.00
A0 = sp.jv(0,i)
#A2 = np.abs((0.088**(1/2))/sp.jv(2,i))
#A4 = np.abs((1.2272**(1/2))/sp.jv(4,i))


print(A0)
#print(A2)
#print(A4)
#print(i)