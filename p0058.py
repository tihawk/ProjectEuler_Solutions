import numpy as np
from math import sqrt
#Grann square of nine?

def checkPrime(n):

    isPrime = True
    for i in range( 2, round(sqrt(n)+1) ):
        if(n%i==0):
            isPrime = False
    return isPrime
    
primesCount = 0
numOfDiag = 1

sideLength = 3
while True:

    diff = sideLength-1
    bigCorner = pow(sideLength, 2)
    corners = [ bigCorner, (bigCorner-diff), (bigCorner-2*diff), (bigCorner-3*diff) ]

    numOfDiag += 4

    for corner in corners:
        if checkPrime(corner) == True:
            primesCount += 1
    if( primesCount/numOfDiag < 0.10 ):
        print(primesCount/numOfDiag)
        print(sideLength)
        break
    sideLength += 2