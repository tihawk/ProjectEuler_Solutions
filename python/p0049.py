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
primes = findPrimesUpTo(10**4)
print("Have primes")

primes = np.array([*primes])
primes = primes[np.where(primes > 999)]

for i in range(len(primes)):
    if i%100 == 0:
        print("Reached index {}/{}".format(i, len(primes)))
    for j in range(i+1, len(primes)):
        if( sorted( str(primes[i]) ) == sorted( str(primes[j]) ) ):
            
            diff = abs(primes[j] - primes[i])
            lower = primes[i] - diff
            higher = primes[j] + diff
            if( higher in primes and sorted( str(higher) ) == sorted( str(primes[j]) ) ):
                print(primes[i], primes[j], higher)
            elif( lower in primes and sorted( str(lower) ) == sorted( str(primes[j]) ) ):
                print(primes[i], primes[j], lower)