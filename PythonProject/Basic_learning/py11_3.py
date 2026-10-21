s=0
i=1
#n=int(input("input how many item you want "))
while 1/(i**2)>=0.000001:
    s=s+1/(i**2)
    i+=1
print((s*6)**0.5)
