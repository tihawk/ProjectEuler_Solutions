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
	
primes = findPrimesUpTo(10000)
	
N = 10**6
phi = np.zeros(N)
ratio = np.zeros((N, 2))
for i in range(0, N):
    phi[i] = eulerTotient(i+2, primes)
    ratio[i, 0] = i+2
    ratio[i, 1] = (i+2) / phi[i]

result = ratio[np.argmax(ratio[:, 1])][0]
print(result)