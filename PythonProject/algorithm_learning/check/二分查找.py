ls = [1,3,5,8,10,34,45,56,64]
ls = sorted(ls)#需要有顺序
key = int(input())

left = 0
right =len(ls)-1

court = 0
while ls[left] <= key <= ls[right]:
    court += 1
    mid = (left+right)//2
    if ls[mid] == key:
        print(ls[mid],mid)
        break
    elif ls[mid] < key:
        left = mid
    elif ls[mid] > key:
        right = mid
else:print("NO")
print(court)
