m=float(input(""))
h=float(input(""))
if 40<=m<=120 and 1.4<=h<=2:
    bmi=m/h**2
    if bmi<18.5:
        print(bmi,"underweight")
    elif 18.5<=bmi<24:
        print("normal")
    elif bmi>=24:
        print("",bmi,"\noverweight")
else: print("none")
