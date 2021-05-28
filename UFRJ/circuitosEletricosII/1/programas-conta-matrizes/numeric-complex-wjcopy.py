import numpy as np


j = np.complex(1j)

Y = np.zeros((2,2),dtype=type(j))

Y[0,0] = 10 + 2*j
Y[0,1] = -2*j
Y[1,1] = 30+8*j
Y[1,0] = -2*j

#Y[0,0] = 21/20 + 20*j
#Y[0,1] = -1/2
#Y[1,1] = 1/2-(1/10)*j
#Y[1,0] = -1/20

I = np.zeros((2),dtype=type(j))

I[0] = 10
#I[1] = 0

E = np.linalg.solve(Y,I)

#print  (E[1]*10**2)

def magPhase(E):
    A = np.abs(E)
    R = np.real(E)
    J = np.real((E - R)*(-1*j))
    P = np.arctan(J/R)*(180/np.pi)
    return A,P

a = magPhase(-181.5 - 80.82*j)
print(a)

#print(magPhase(E[1]))
