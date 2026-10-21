price=66;name=["波克","粉色糖果","泡泡糖","蓝色夏日","蘑菇","独角兽","小寿星"]
from random import randint
while True:
    money=float(input("how much money do you have: "));like=int(input("请输入心仪款式的编号（0-6的整数）\n"));pick=-1;count=0
    while pick!=like and money>=price:
        count+=1;pick=randint(0,6);money-=price
        print(f"开始买第{count}个盲盒,拆盒：{name[pick]}")
    if pick==like:
        print(f"恭喜你抽中了心仪的款式,累计买了{count}个盲盒,共花费{count*price}元")
    else:print("sorry")

        
        
        
        
