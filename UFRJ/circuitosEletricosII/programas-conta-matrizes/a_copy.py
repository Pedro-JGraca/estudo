import numpy as np


j = np.complex(1j)

Y = np.zeros((2,2),dtype=type(j))

Y[0,0] = 201/200 + 20*j
Y[0,1] = -1/20
Y[1,1] = 1/20-(1/10)*j
Y[1,0] = -1/200

#Y[0,0] = 21/20 + 20*j
#Y[0,1] = -1/2
#Y[1,1] = 1/2-(1/10)*j
#Y[1,0] = -1/20

I = np.zeros((2),dtype=type(j))

I[0] = 2
#I[1] = 0

E = np.linalg.solve(Y,I)

print  (E[1]*10**3)
