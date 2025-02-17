from math import modf
import numpy as np

listOfNums = []
for i in range(2, 10**6):
    sumOfPows = 0
    for j in range(len(str(i))):
        if(sumOfPows<=i):
            sumOfPows += int(modf((i/10**j) %10)[1])**5
        elif(sumOfPows>i):
            break
    if(sumOfPows == i):
        print(sumOfPows, i)
        listOfNums.append(i)
    
result = np.sum(listOfNums)
print(result)