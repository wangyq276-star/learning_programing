while True:
   m=0
   s=0
   n=int(input("input n: "))
   a=[]
   while n!=0:
       s=float(input(f"input number{n}: "))
       a.append(s)
       n-=1
   a=sorted(a)
   print(f"min: {a[0]},max: {a[len(a)-1]}")
    
