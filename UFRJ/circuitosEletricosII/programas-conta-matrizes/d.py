import numpy as np

j = np.complex(1j)

Y = np.zeros((7,7),dtype=type(j))

Y[0,0] = 1
Y[0,1] = -1
Y[1,1] = 1+(20)*j
Y[1,0] = -1
Y[2,2] = 1/2
Y[2,3] = -1/2
Y[3,3] = 1/2-(1/10)*j
Y[3,2] = -1/2
Y[6,0] = Y[4,1] = Y[5,-2] = -1
Y[0,6] = Y[1,4] = Y[-2,5] = +1
Y[4,4] = 10*j
Y[4,5] = Y[5,4] = 50*j
Y[5,5] = 1000*j

#print(Y)

I = np.zeros((7),dtype=type(j))

I[6] = -2
#I[1] = 0

E = np.linalg.solve(Y,I)

print  (E)