
print("%30s"%"A")
for  i  in  range(1,26) :
    for  j  in  range(1,30-i) :
        print(" ",end="")
    for  j  in  range(1,i+1) :
        print(chr(64+j),end="")
    for  j  in  range(i+1,0,-1) :
        print(chr(64+j),end="")
    print("")
