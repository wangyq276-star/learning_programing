for x in range(1,101):
    for y in range(1,101):
        for z in range(1,101):
            if 5*x+3*y+z*(1/3)==100 and x+y+z==100:
                print(f"x:{x} ; y:{y} ; z:{z}")