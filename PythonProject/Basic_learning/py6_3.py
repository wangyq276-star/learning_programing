a=int(input("输入数字："))
b=a%3
c=a%5
if (b==0 and c==0):
    print(a,"既是3的倍数又是5的倍数",sep="")
else:
    print(a,"既不是3的倍数又不是5的倍数",sep="")
