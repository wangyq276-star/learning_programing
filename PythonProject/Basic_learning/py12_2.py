from math import *
from random import randint
i,x,y,m,pi=0,0,0,0,3.141592653589793238462643382795
n=int(input("how many point do you want : "))
while m<=n:
    x=randint(0,pi*10**30)/10**30
    y=randint(0,pi*10**30)/10**30
    if y<=sin(x):
        i+=1
    m+=1
print(pi*(i/n))
