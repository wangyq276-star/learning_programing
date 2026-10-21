from math import *
n=int(input(""))
s=0
dx=3.1415926535897932384626/n
for i in range(1,n+1):
    s=s+dx*sin(dx*i)
print(s)
