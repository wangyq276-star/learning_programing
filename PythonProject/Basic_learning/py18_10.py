l=[]
for a1 in range(1,10):
    for a2 in range(1,10):
        if a2 not in [a1]:
            for a3 in range(1,10):
                if a3 not in [a1,a2]:
                    for a4 in range(1,10):
                        if a4 not in [a1,a2,a3]:
                            for a5 in range(1,10):
                                if a5 not in [a1,a2,a3,a4]:
                                    for a6 in range(1,10):
                                        if a6 not in [a1,a2,a3,a4,a5]:
                                            for b1 in range(1,10):
                                                if b1 not in[a1,a2,a3,a4,a5,a6]:
                                                    for b2 in range(1,10):
                                                        if b2 not in [a1,a2,a3,a4,a5,a6,b1]:
                                                            for b3 in range(1,10):
                                                                if b3 not in [a1,a2,a3,a4,a5,a6,b1,b2]:
                                                                    l.append([a1*10**5+a2*10**4+a3*10**3+a4*10**2+a5*10+a6,b1*100+b2*10+b3])
for i in range(0,len(l)-1):
    if (l[i][0])**0.5==l[i][1]:
        print(f"{l[i][0]}**0.5={l[i][1]}")                 