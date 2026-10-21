a=float(input("输入单价："))
b=float(input("输入购买数量："))
if(b>10):
    print("您需付款",(0.8*b*a),"元",sep="")
else:
    print("您需付款",(b*a),"元",sep="")
