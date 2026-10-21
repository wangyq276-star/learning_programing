a,l,s=0,[],0
for i in range(1,11):
    a=int(input(f"student {i}"))
    l.append(a)
    s+=a
s=s/10
for j in range(0,10):
    print(f"studemt {j+1}:{l[j]-s}")
