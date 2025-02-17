import numpy as np
from math import sqrt

def checkPrime(n):

    isPrime = True
    for i in range( 2, round(sqrt(n)+1) ):
        if(n%i==0):
            isPrime = False
    return isPrime

rightDigits = [1, 3, 7, 9]
starter = [2, 3, 5, 7]
rightTrunc = []

while True:
    for left in starter:
        for digit in rightDigits:
            tryThis = left*10 + digit
            if checkPrime(tryThis) == True:
                newOnes.append(tryThis)
                rightTrunc.append(tryThis)
    if len(newOnes) == 0:
        break
    starter = newOnes
    newOnes = []
    
leftRightTrunc = []

for prime in rightTrunc:
    expo = 1
    
    while True:
        
        tryThis = prime%(10**expo)
        expo += 1
        if checkPrime(tryThis) == False or tryThis == 1:
            break
        if tryThis == prime:
            leftRightTrunc.append(prime)
            break
            
print(leftRightTrunc)
print(np.sum(leftRightTrunc))