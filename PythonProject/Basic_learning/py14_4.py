for i in range(100,1000):
    a,b,c=int(str(i)[0]),int(str(i)[1]),int(str(i)[2])
    if a**3+b**3+c**3==i:
        print(i)
