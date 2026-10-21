from random import *
cc,pc,t,w,l,jud=0,0,0,0,0,{"jian dao":"bu","shi tou":"jian dao","bu":"shi tou"}
def judge(cc,pc):
    if cc==pc:return "it is a tie"
    elif cc==jud[pc]:return "you win"
    else:return "you lost"
while pc!="over":
    cc,pc=choice(["jian dao","shi tou","bu"]),input("input your gesture: ").lower()
    while pc not in ["jian dao","shi tou","bu","over"]:
        pc=input("none\ninput your gesture again: ").lower()
    if pc!="over":
        print(f"computer shows {cc};you shows {pc}:{judge(cc,pc)}")
        if judge(cc,pc)=="it is a tie":t+=1
        elif judge(cc,pc)=="you win":w+=1
        else:l+=1
print(f"in this game:\nyou win {w} times\nyou lost {l} times\n have {t} times tie")

    
