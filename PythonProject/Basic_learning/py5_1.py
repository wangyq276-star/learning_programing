from random import randint
num1=randint(10,99)
num2=randint(0,9)
res=num1+num2
input_num=float(input("input num:"))
print("您的答案是",input_num)
print("您离正确答案就差",abs(res-input_num),"了")
