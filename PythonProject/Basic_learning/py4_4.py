from random import randint
a=randint(0,9)
b=randint(0,9)
c=a+b
d=float(input("请输入您猜的数字："))
f=abs(c-d)
print("您离答案只差：",f)
