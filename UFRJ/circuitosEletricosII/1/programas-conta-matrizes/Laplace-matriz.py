import sympy as sy

s = sy.Symbol('s')
a = sy.Symbol('a')
b = sy.Symbol('b')

z1 = 2 + 16/(5*s)
z2= (42*s + 16) / (s**2 + 15*s + 2)

Y = sy.zeros(4,4)
Y[0,0] =  1/z1
Y[0,1] = Y[1,0] = -1/z1
#Y[0,2] = 0
#Y[0,3] = 1

#Y[1,0] = -(mi)/(s)
Y[1,1] = 1/z1 + 1/z2
Y[0,2] = 1
Y[1,3] = 1
Y[2,0] = -1
Y[3,1] = -1


#Y[2,0] = 0
#Y[2,1] = -(10 +5*s)*mi
#Y[2,2] = (20 +5*s)*mi
#Y[2,3] = 0

#Y[3,0] = -1
#Y[3,1] = 0
#Y[3,2] = 0
#Y[3,3] = 0
sy.pprint(Y)


I = sy.zeros(4,1)
I[0] = 0
I[1] = 0
I[2] = -a
I[3] = -b

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

