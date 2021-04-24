import numpy as np

#j = np.complex(1j)

Y = np.zeros((2,2))

Y[0,0] = 1
Y[0,1] = 5
Y[1,1] = 100
Y[1,0] = 5

print(np.linalg.inv(Y)*75)

