inls = [34,45,56,6,41,3,5,8,10,1,43,86,33,76]
#建立哈希函数和哈希表
def haxe(inlist):
    length = len(inlist)
    ls = [[] for _ in range(length)]
    for i in inlist:
        ls[i % length].append(i)
    return ls
#通过哈希查找函数进行查找
def haxe_find(key,ls):
    index = key % len(ls)
    for i in range(0,len(ls[index])):
        if ls[index][i] == key:
            return index,i
    return None

print(haxe(inls))
print(haxe_find(43, haxe(inls)))