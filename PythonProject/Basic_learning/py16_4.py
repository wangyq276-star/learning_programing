a,l=0,[1,1]
while l[len(l)-1]<=2000000:
    l.append(l[a]+l[a+1])
    a+=1
print(f"斐波那切数列小于200万的最大一项是{l[len(l)-2]},该项是整个数列的第{len(l)-1}项")