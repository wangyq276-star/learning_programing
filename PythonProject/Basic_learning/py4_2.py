a=int(input("分别输入三角形三边长度"))
b=int(input("分别输入三角形三边长度"))
c=int(input("分别输入三角形三边长度"))
p=(a+b+c)/2
from math import sqrt
S=sqrt(p*(p-a)*(p-b)*(p-c))
print("三角形面积是：",s)
