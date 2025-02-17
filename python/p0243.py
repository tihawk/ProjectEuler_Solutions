import numpy as np
from math import sqrt

def findPrimesUpTo(N):
    
    primes = []
    for n in range(2, N+1):
        isPrime = True
        for i in range( 2, round(sqrt(n)+1) ):
            if(n%i==0):
                isPrime = False
        if(isPrime):
            primes.append(n)
            
    return primes

primes = findPrimesUpTo(100)


def eulerTotient(n, primes):
    
    res = n
    reducable = n
    
    for p in primes:
        #check only up to p = sqrt(n)
        if p*p > reducable:
            break
        #check if prime factor
        if(reducable%p==0):
            #check if occurs more than once as factor
            while True:
                reducable /= p
                if(reducable%p!=0):
                    break
            #remove prime from result(only once)
            res -= res/p
    #correction in case there is another prime factor just beyond sqrt(n):
    if(reducable>1):
        res -= res/reducable
        
    return res
        
def lookBack(n):
    mult = 1
    while True:
        #newToCheck = n
        newToCheck = n*mult
        mult += 1
        resil = eulerTotient(newToCheck, primes)
        if( resil*94744 < (newToCheck-1)*15499 ):
            print(mult)
            return newToCheck

        
#it seems that the ratio drops most significantly when the number is a multiple of all consecutive primes up to n
index = 0
numToCheck = 1
for i in range(index):
    numToCheck *= primes[i]
    
while True:
    
    numToCheck *= primes[index]
    index += 1
    
    resil = eulerTotient(numToCheck, primes)
    
    if( resil*94744 < (numToCheck-1)*15499 ):
        print(numToCheck, primes[index])
        index -= 1
        numToCheck = int(numToCheck/primes[index])
        print(numToCheck, primes[index])
        result = lookBack(numToCheck)
        print(result)
        break