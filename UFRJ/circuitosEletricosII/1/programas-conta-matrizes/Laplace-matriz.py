import sympy as sy

s = sy.Symbol('s')
#x = sy.Symbol('x')
mi = (10**(6))
Y = sy.zeros(2,2)
Y[0,0] = (s**2 + 100*s + 2*mi)
Y[0,1] = Y[1,0] = s**2+100*s
#Y[0,2] = 0
#Y[0,3] = 1

#Y[1,0] = -(mi)/(s)
Y[1,1] = s**2+120*s
#Y[1,2] = 0
#Y[1,3] = 0

#Y[2,0] = 0
#Y[2,1] = -(10 +5*s)*mi
#Y[2,2] = (20 +5*s)*mi
#Y[2,3] = 0

#Y[3,0] = -1
#Y[3,1] = 0
#Y[3,2] = 0
#Y[3,3] = 0
sy.pprint(Y)


I = sy.zeros(2,1)
I[0] = s - 8
I[1] = s+2
sy.pprint(I)

E = Y.LUsolve(I)

#E[0] -= (s**3 + (100/64)*s)/((s**4)+(100/32)*(s**2)+100/64)
#E[0] -= 1 / (s + 25/(16*s))

for a in E:
    print(a)
    print()

sy.pprint(E[0])
sy.pprint(E[1])


#a = E[2]/x
#sy.pprint(a)
#print(a)
#sy.pprint(E[0] - E[1])

#print(E[0])

