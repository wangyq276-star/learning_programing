def judge(a):
    try:
        int(a)
        if int(a)>0:
            return True
    except:return False
while True:
    a,b=input("play 1 money: "),input("play 2 money: ")
    while not judge(a):a=input("[no]play 1 money: ")
    while not judge(b):b=input("[no]play 2 money: ")
    a,b=int(a),int(b)
    if a-b==1:b+=20
    if b-a==1:a+=20
    print(f"play 1 have {a} yuan;play 2 have {b} yuan")
