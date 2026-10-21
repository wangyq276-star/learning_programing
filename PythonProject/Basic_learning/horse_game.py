from random import randint
player=[]
computer=[]
horse=[1,2,3,4,5]

i=0
while i<=4:
    a=int(input("请输入马的等级："))
    if a not in horse:
        print("没有这等级的马！")
        continue
    elif a in player:
        print("该级马已经在梯队中！")
        continue
    else:
        player.append(a)
    i=i+1


i=0
while i<=4:
    a=randint(1,5)
    if a in computer:        
        continue
    else:
        computer.append(a)
    i=i+1

#公示

print("玩家： ",end="")
for i in range(5):
    print(player[i],end=" ")

print()
print("电脑： ",end="")
for i in range(5):
    print(computer[i],end=" ")
print()

#PK
win=0
lose=0
print("结果：",end="")
for i in range(5):
    if player[i]==computer[i]:
        print("=",end=" ")
    elif player[i]<computer[i]:
        print("√",end="")
        win=win+1
    else:
        print("×",end="")
        lose=lose+1

print()
#评价        
if win==lose:
    print("平局！")
elif win>lose:
    print("胜利！")
else:
    print("失败！")


    
    
