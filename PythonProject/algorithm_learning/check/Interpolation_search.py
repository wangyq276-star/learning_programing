ls = [1,3,5,8,10,34,45,56,64]
ls = sorted(ls)#需要有顺序
key = int(input())
left = 0
right =len(ls)-1

count = 0
while ls[left] <= key <= ls[right]:
    count += 1
    #中间变量采用近似均匀分布的方式选取
    mid = int(left + (right - left) * ((key - ls[left]) / (ls[right] - ls[left])))

    if ls[mid] == key:
        print(ls[mid],mid)
        break
    elif ls[mid] < key:
        left = mid + 1
    elif ls[mid] > key:
        right = mid - 1
else:print("NO")
print(count)