n,l=1,[x for x in range(1,1989)]
while True:
    m=int(input("重复次数 : "))
    while n<m+1:
        for i in range(2,len(l)+1,2):
            l.remove(i)
        l=[y for y in range(1,len(l)+1)]
        n+=1
    print(f"站着的有 : {1989-len(l)}个")