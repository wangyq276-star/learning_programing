l=[1,9,8,9]
for i in range(1,1995):
    l.append(int(str(l[i-1]*l[i])[-1]))
print(f"第1998个数字是{l[1997]}")