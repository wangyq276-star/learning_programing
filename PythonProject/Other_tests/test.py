N = 30
def fac(t):
    l = []
    for i in range(1,t):
        if t % i == 0:l.append(i)
    return l
for i in range(1,N+1):
    if sum(fac(i)) == i:print(i)