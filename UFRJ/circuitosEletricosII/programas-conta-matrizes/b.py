import sympy as sy

s = sy.Symbol('s')


Y = sy.zeros(7,7)
Y[0,0] = 1
Y[0,1] = Y[1,0] = -1
Y[1,1] = 1 + 2*s
Y[2,2] = 1/2
Y[2,3] = Y[3,2] = -1/2
Y[3,3] = 1/2 + 1/s
Y[4,0] = Y[5,1] = Y[6,2] = -1
Y[0,4] = Y[1,5] = Y[2,6] = 1

Y[5,5] = s
Y[5,6] = Y[6,5] = 5*s
Y[6,6] = 100*s


I = sy.zeros(7,1)
I[4] = -1/s
I[1] = 2

E = Y.LUsolve(I)

#E[0] -= (s**3 + (100/64)*s)/((s**4)+(100/32)*(s**2)+100/64)
#E[0] -= 1 / (s + 25/(16*s))



#a = E[2]/x
#sy.pprint(a)
#print(a)
sy.pprint(E[3])

print(E[3])

