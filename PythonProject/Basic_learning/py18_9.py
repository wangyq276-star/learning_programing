def cycle(a,l):
    if a>len(l)-1:a=a%10
    return a
s,hole=10,[1,2,3,4,5,6,7,8,9,10]
for i in range(1,1001):
    s+=i
    hole[cycle(s-1,hole)]=0
print(hole)