import sympy as sy

s = sy.Symbol('s')

Y = sy.zeros(7,7)
Y[0,0] = 1/s + 1/4
Y[0,1] = Y[1,0] = 1/4
Y[1,1] = 3/4 + s/2
sy.pprint(Y)


I = sy.zeros(2,1)
I[0] = 31/(4*s)
I[1] = (32*s+27)/(4*s)
sy.pprint(I)

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

