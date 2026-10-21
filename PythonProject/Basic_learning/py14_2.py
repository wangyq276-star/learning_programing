l,n=[],0
for i in range(1,201):l.append(str(i))
for j in range(0,199):
    if "3" in l[j]:
        if "33" in l[j]: n+=2
        else: n+=1
print(f"数码三总共有{n}个")