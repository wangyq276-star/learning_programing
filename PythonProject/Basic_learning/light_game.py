l1=["■","■","■","■","■"]
l2=["■","■","■","■","■"]
l3=["■","■","■","■","■"]
l4=["■","■","■","■","■"]
l5=["■","■","■","■","■"]
line={1:l1,2:l2,3:l3,4:l4,5:l5}
def show(a):
    print("-",end="")
    for k in range(0,len(a)+1):
        print(f"{k}",end="-")
    print()
    for i in range(1,len(a)+1):
        print(f"-{i}-",end="")
        for j in range(0,len(a[i])):
             print(a[i][j],end="-")
        print()
def click(a,b,l):
    for i in range(a-1,a+2):
        if not (i>len(l) or b>len(l) or i<=0 or b<=0):
            if l[b][i-1]=="□":
                l[b][i-1]="■"     
            else:
                l[b][i-1]="□"
    for i in range(b-1,b+2):
        if not (a>len(l) or i>len(l) or a<=0 or i<=0 or i==b):
            if l[i][a-1]=="□":
                l[i][a-1]="■"     
            else:
                l[i][a-1]="□"        
show(line)
while True:
    a,b=input("请输入开关灯坐标: ").split()
    a,b=int(a),int(b)
    while a>len(line) or b>len(line) or a<=0 or b<=0:
        print("该坐标超出游戏边界，请重新输入: ")
        a,b=input(" ").split()
    click(a,b,line)
    show(line)