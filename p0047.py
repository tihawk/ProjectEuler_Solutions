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

print("Calculating primes...")
primes = findPrimesUpTo(10**3)
print("Have primes")

def getPrimeFactors(n):
    reducable = n
    primeFactors = []
    powers = []
    for p in primes:
        #check only for p < sqrt(n)
        if(p*p > reducable):
            break
        #check of p is a prime factor
        if(reducable%p == 0):
            primeFactors.append(p)
            #check if it occurs more than once
            counter = 0
            while(reducable%p == 0):
                counter += 1
                reducable //= p
            #add the power of the factor to a list
            powers.append(counter)
    #check if there's one more prime factor beyond sqrt(n)
    if(reducable>1):
        primeFactors.append(int(reducable))
        powers.append(1)
        
    return primeFactors, powers
	
arr = []
for i in range(10**6):
    factors = getPrimeFactors(i)
    arr.append([i, factors[0]])

for i in range(len(arr)):
    x = 4
    if( len(arr[i][1]) == x and len(arr[i+1][1]) == x and len(arr[i+2][1]) == x and len(arr[i+3][1]) == x ):
        print(arr[i], arr[i+1], arr[i+2], arr[i+3])
        break