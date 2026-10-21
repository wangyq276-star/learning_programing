def n(a):
    l=[]
    for i in range(1,101):
        if i%a==0:l.append(i)
    return l
def change(a,l):
    if l[a]==0:l[a]=1
    else:l[a]=0
def show(l):
    for i in range(0,len(l)-1):
        if l[i]==0:print("第%02d号门"%(i+1),end=" ")
    print("是打开的")    
door=[0 for i in range(100)]
for i in range(2,101):
    print(f"{i}的倍数: ")
    for i in n(i):
        change(i-1,door)        
    show(door)       