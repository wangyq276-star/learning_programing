def n(a):
    if a==1:
        return 200
    else:
        return 2*200*(0.5**(a-1))+n(a-1)
i=int(input(""))
print(n(i))
