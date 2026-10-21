a,b=map(int,input("").split())
c,d=map(int,input("").split())
n=(60*c+d-60*a-b)//60
m=(60*c+d-60*a-b)%60
print(f"共花了{n}小时{m}分钟")    
