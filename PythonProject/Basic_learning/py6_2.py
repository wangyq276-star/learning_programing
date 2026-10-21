a=int(input("输入年份："))
b=a%4
c=a%100
d=a%400
if (b==0 and c!=0):
    print(a,"年是闰年",sep="")
elif (b==0 and c==0 and d==0):
    print(a,"年是闰年",sep="")
else:
    print(a,"年是平年",sep="")
