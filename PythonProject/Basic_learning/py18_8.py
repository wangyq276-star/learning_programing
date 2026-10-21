def cycle(a,l):
    if a>len(l)-1:a-=len(l)+1
    return a
s,maxn,an=0,[],[11,19,9,12,5,20,1,18,4,16,6,10,15,2,17,3,14,7,13,15,8]
for i in range(0,21):
    for j in range(i,i+4):
        s+=an[cycle(j,an)]
    maxn.append(s)
    s=0
print(len(maxn))
print(f"最大的和是: {max(maxn)}，分别是由第{cycle((maxn.index(max(maxn)))+1,an)},{cycle((maxn.index(max(maxn)))+2,an)},{cycle((maxn.index(max(maxn)))+3,an)},{cycle((maxn.index(max(maxn)))+4,an)}个数求得的和")