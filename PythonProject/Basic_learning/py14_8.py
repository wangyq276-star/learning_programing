s,t,zmb="","",["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
for i in range(1,26):
    for j in range(0,i):
        s=s+zmb[j]
        if (i-j-2)!=-1:t=t+zmb[i-j-2]
    print(" "*int((49-len(s+t))/2)+s+t+" "*int((49-len(s+t))/2))
    s,t="",""