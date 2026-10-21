def fac(a):
    l=[]
    for i in range(1,a+1):
        if a%i==0:
            l.append(i)
    return l
m,l,n=0,[],int(input("你要寻找多少以内的质数: "))
print(f"从2至{n}以内的质数有 : ")
for j in range(2,n+1):
#    if (j in fac(j)) and (1 in fac(j)) and ([x for x in fac(j) if (x!=1 and x!=j)]==[]):
    if len(fac(j))==2:
        m+=1
        l.append(j)        
        print(f"第{m}位质数为{j}")
 