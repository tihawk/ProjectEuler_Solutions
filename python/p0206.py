for a in range(1389026630, 1010101010, -10):
    square = a*a
    isIt = True
    #square = 1020304050607080900
    
    everyOther = 0
    for i in [0, 9, 8, 7, 6, 5, 4, 3, 2, 1]:
        everyOther = everyOther*10 + square%10
        if square%10 != i:
            isIt = False
            break
        square = square//100
        
    if(isIt):
        print(a, a*a)
        break