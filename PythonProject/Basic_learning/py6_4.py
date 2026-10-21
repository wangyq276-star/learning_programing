a=int(input("输入边："))
b=int(input("输入边："))
c=int(input("输入边："))
if (a<=0 or b<=0 or c<=0):
    print("这不是三角形")
elif ((a+b)<=c or (a+c)<=b or (b+c)<=a):
    print("这不是三角形")
elif (a==c and a==b and b==c):
    print("这是等边三角形")
elif (a==c or a==b or b==c):
    print("这是等腰三角形")
else:
    print("这是一般三角形")
