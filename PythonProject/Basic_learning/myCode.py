def cal(a,b):
    nums=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"]

    if a[0]=="-":
        sign_a="-"
        a=a.replace("-","")
    elif a[0]=="+":
        sign_a="+"
        a=a.replace("+","")
    else:sign_a="+"

    if b[0]=="-":
        sign_b="-"
        b=b.replace("-","")
    elif b[0]=="+":
        sign_b="+"
        b=b.replace("+","")
    else:sign_b="+"

    num_a,num_b=0,0
    for i in range(0,len(a)):
        num_a+=(nums.index(a[i]))*16**(len(a)-i-1)
    for i in range(0,len(b)):
        num_b+=(nums.index(b[i]))*16**(len(b)-i-1)
    res,reshex=int(sign_a+str(num_a))+int(sign_b+str(num_b)),""

    if res==0:return 0
    else:
        sign_res="-" if res<0 else ""
        res=int(str(res).replace("-",""))
    while res != 0:
        reshex=nums[res%16]+reshex
        res=res//16
    return sign_res+reshex
try:
    while True:
        a, b = map(str, input().split())
        print(cal(a, b))
except:exit
