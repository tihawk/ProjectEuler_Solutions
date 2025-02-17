import numpy as np
from math import sqrt
from numba import jit

#Brute-forcing it...
#Note, optimising this would be expanding phi(x) as (p1 - 1)(p2 - 1). 
#Highest possible primes would work best. Consider either around x=10**7 or around sqrt(x)

@jit(nopython=True)
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
primes = findPrimesUpTo(10**6)
print("Have primes")

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
    if(reducable > 1):
        res -= res/reducable
        
    return res

N = 10**7
offset = 10**4
phi = np.zeros(N, dtype=np.int64)
ratio = []#np.zeros((N, 2))
for i in range(0, N):
    phi[i] = eulerTotient(i+offset, primes)
    if( sorted( str(phi[i]) ) == sorted( str( i+offset ) ) ):
        ratio.append([ i+offset, phi[i], (i+offset) / phi[i] ])
        print(ratio[-1:])


ratio = np.array([ *ratio ], dtype=np.float64)
print(ratio[ np.argmin( ratio[:, 2] ) ][0])