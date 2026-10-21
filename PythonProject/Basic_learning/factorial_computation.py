a=int(input("你要计算那个数的阶乘？\n"))
def n(a):
    if a==1:
        return 1
    else:
        return a*n(a-1)
print(n(3))
