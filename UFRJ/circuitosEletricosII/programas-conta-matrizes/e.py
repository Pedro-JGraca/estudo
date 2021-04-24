import numpy as np

j = np.complex(1j)

Y = np.zeros((3,3),dtype=type(j))

Y[0,0] = 1 +((1499)/75) *j
Y[0,1] = Y[1,0] = (-1/150 )*j
Y[1,1] = 1/2 - (1/750)*j
Y[2,2] = 1/2 - (1/10)*j
Y[2,1] = Y[1,2] = -1/2
print(Y)

I = np.zeros((3),dtype=type(j))

I[2] = 2
#I[1] = 0

E = np.linalg.solve(Y,I)

print  (E[2])