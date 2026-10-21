def fac(a):
    factors=[]
    for j in range(1,a+1):
        if a%j==0 and a!=j:
            factors.append(j)
    return factors
l,n=[],int(input("你要寻找多少以内的完全数(除了1):"))
for i in range(2,n+1):
    if sum(fac(i))==i:
        l.append(i)
print(f"2至{n}以内的完全数有{l}")
for n in l:
    print(f"{n}的因数分别是{fac(n)}(不包含数{n}本身)")