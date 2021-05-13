import sympy as sy

s = sy.Symbol('s')

Y = sy.zeros(4,4)
Y[0,0] = s+2
Y[0,1] = Y[1,0] = -2
Y[1,1] = 2 + 2/(s)
Y[1,2] = Y[2,1] = -(2/s)
Y[2,2] = 4 + s + s/2
Y[0,2] = Y[2,0] = 1/s
Y[3,0] = 1
Y[0,3] = -1
sy.pprint(Y)


I = sy.zeros(4,1)
I[0] = 1/s
I[1] = 14/s
I[3] = 3/s
#sy.pprint(I)

E = Y.LUsolve(I)

#E[0] -= (s**3 + (100/64)*s)/((s**4)+(100/32)*(s**2)+100/64)
#E[0] -= 1 / (s + 25/(16*s))

for a in E:
    print(a)
    print()


#a = E[2]/x
#sy.pprint(a)
#print(a)
#sy.pprint(E[0] - E[1])

#print(E[0])

