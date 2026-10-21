a=float(input(""))
b=float(input(""))
c=float(input(""))
delta=b**2-4*a*c
if delta<0:
    print('1')
else:
    x1=(-b+delta**0.5)/(2*a)
    x2=(-b-delta**0.5)/(2*a)
    print(x1,x2)

